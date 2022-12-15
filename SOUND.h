#pragma once
// �T�E���h���W���[���p�w�b�_
// �쐬���F
// �쐬�ҁF(��c�搶�̃v���O����������p)

//---------------------------------------------------------
// �񋓒萔
// �� �t�@�C�����̕�����z��̏������ƍ��킹�鎖
//---------------------------------------------------------
enum {
	SOUND_TITLE_BGM,
	SOUND_RULE_BGM,
	SOUND_RESULT_BGM,
	SOUND_GAME_BGM,
	SOUND_KETTEI,
	SOUND_SENTAKU,
	SOUND_UKETORI,
	SOUND_TABERU,
	SOUND_OKANE,
	SOUND_COUNT,
	//SOUND_START,
	SOUND_END,
};

//---------------------------------------------------------
// �֐��v���g�^�C�v�錾
//---------------------------------------------------------
void SoundInit(void);
void SoundEnd(void);
void SoundPlayOnce(int sound_no);
void SoundPlayLoop(int sound_no);
void SoundStop(int sound_no);
