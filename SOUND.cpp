// �T�E���h���W���[��
// �쐬���F
// �쐬�ҁF
#define CONIOEX
#include "conioex.h"
#include "SOUND.h"

//-------------------------------------------------------------------
// �\���̃^�O�錾
//-------------------------------------------------------------------
typedef struct {
	const char* fname;		// �ʃX���b�h�ŃI�[�v�����鎞�Ɏg�p
	int			sound_id;	// ���o���̂��߂�ID(�I�[�v����͂�������g�p)
} sound_t;

//-------------------------------------------------------------------
// �O���[�o���ϐ��錾
//-------------------------------------------------------------------
// �t�@�C�����̏��Ԃ́A�w�b�_�t�@�C���̗񋓒萔�ƍ��킹�鎖
// �� �����t�@�C����DOVA-SYNDROME[https://dova-s.jp/]OtoLogic[https://otologic.jp/]�𗘗p
static const char* fname[] = {
	"title.mp3",		// SOUND_TITLE_BGM
	"rule.mp3",			// SOUND_RULE_BGM
	"result.mp3",		// SOUND_RESULT_BGM
	"game.mp3",			// SOUND_GAME_BGM
	"kettei.mp3",		// SOUND_KETTEI
	"sentaku.mp3",		// SOUND_SENTAKU
	"uketori.mp3",		// SOUND_UKETORI
	"taberu.mp3",		// SOUND_TABERU
	"okane.mp3",		// SOUND_OKANE
	"count.mp3",		// SOUND_COUNT
	//"STAR_1�iOK���A�A�C�e�������Ȃǁj.mp3",	// SOUND_START
	"end.mp3",			// SOUND_END
};
static const int	sound_num = sizeof(fname) / sizeof(fname[0]);
static sound_t		sound[sound_num] = { 0 };

//---------------------------------------------------------
// �ʃX���b�h���������o������
// �@conioex�̃T�E���h�֘A������MCI���g�p���Ă���
// �@MCI�̓I�[�v�������X���b�h�ȊO����͑���ł��Ȃ�
// �@���̂��߁A�ʃX���b�h�ŉ����o���ꍇ�A
// �@���̃X���b�h�ŃI�[�v���ƃN���[�Y�����Ȃ���΂Ȃ�Ȃ�
//---------------------------------------------------------
static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	int		sound_id;
	const char* fname = ((sound_t*)lpParameter)->fname;
	
	if (fname != NULL) {
		sound_id = opensound((char*)fname);
		if (sound_id != 0) {
			playsound(sound_id, 0);
			msleep(5000);	// �����ɃN���[�Y����Ɖ��������邽�߃X���[�v����
			closesound(sound_id);
		}
	}
	return 0;
}
//----------------------------------------------------------
// �T�E���h��������
//----------------------------------------------------------
void SoundInit(void)
{
	bool err = false;

	for (int i = 0; i < sound_num; i++) {
		if (sound[i].sound_id == 0) {
			sound[i].sound_id = opensound((char*)fname[i]);
			if (sound[i].sound_id == 0) {
				printf("%s���I�[�v���ł��܂���\n", fname[i]);
				err = true;
			}
			else {
				sound[i].fname = fname[i];
			}
		}
	}
	if (err) {
		printf("�I�[�v���ł��Ȃ������t�@�C���̉��͖�܂���\n");
		printf("�����L�[�������Ă�������\n");
		(void)_getch();
	}
}
//----------------------------------------------------------
// �T�E���h�I������
//----------------------------------------------------------
void SoundEnd(void)
{
	for (int i = 0; i < sound_num; i++) {
		if (sound[i].sound_id != 0) {
			closesound(sound[i].sound_id);
		}
	}
}
//----------------------------------------------------------
// �P�񂾂������o��(����炷�ƈ�u�~�܂�̂ŕʃX���b�h������)
//----------------------------------------------------------
void SoundPlayOnce(int sound_no)
{
	HANDLE hThread;			// �X���b�h�������邽�߂̃n���h���l
	DWORD dwThreadId;		// CreateThread(�X���b�h����)�֐��̈����p

	// ���ڌĂԂƒx������̕ʃX���b�h��playsound����
	// playsound(sound[sound_no].sound_id, 0);
	hThread = CreateThread(NULL, 0, ThreadProc, &sound[sound_no], 0, &dwThreadId);
	if (hThread != NULL) {
		CloseHandle(hThread);	// CloseHandle��hThread�����.
	}
}
//----------------------------------------------------------
// ���[�v�Đ�����
//----------------------------------------------------------
void SoundPlayLoop(int sound_no)
{
	playsound(sound[sound_no].sound_id, 1);
}
//----------------------------------------------------------
// �Đ����������~�߂�
//----------------------------------------------------------
void SoundStop(int sound_no)
{
	stopsound(sound[sound_no].sound_id);
}
