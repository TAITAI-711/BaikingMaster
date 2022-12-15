// �ۑ�@�F�@HEW�̃Q�[��
// �����@�F�@�����吔

#include "main.h"
#include "conioex.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "rule.h"
#include "SOUND.h"
#include "gamen.h"

//-------------------------------------------------------------------
// �O���[�o���ϐ�
//-------------------------------------------------------------------
static int g_nCountFPS;					// FPS�J�E���^
static int game_scene = 1;				// �Q�[���̏��(0: �I��, 1:�^�C�g��, 2:�Q�[��, 3:���U���g, 4:���[������)
static bool game_scene_kirikae = false;	// �Q�[���V�[���̐؂�ւ�����

//-------------------------------------------------------------------
// �又��
//-------------------------------------------------------------------
int main(void)
{
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	int nCountFrame;

	// ����\��ݒ�
	timeBeginPeriod(1);

	dwExecLastTime = 
	dwFPSLastTime = timeGetTime();
	dwCurrentTime =
	nCountFrame = 0;

	SoundInit();
	gamen_Init();

	do
	{
		// �f�[�^�̏����������̊֐�
		Init();

		// �Q�[�����[�v
		do
		{
			dwCurrentTime = timeGetTime();
			if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
			{
				g_nCountFPS = nCountFrame * 1000 / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;
				nCountFrame = 0;
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{
				dwExecLastTime = dwCurrentTime;

				// �X�V����
				Update();

				// �`�揈��
				Draw();

				nCountFrame++;
			}
		} while (!inport(PK_ESC) && !(game_scene_kirikae));

		// �I������
		End();

		game_scene_kirikae = false;
	} while (!inport(PK_ESC) && !(game_scene == 0));

	SoundEnd();
	gamen_End();

	// ����\��߂�
	timeEndPeriod(1);

	return 0;
}

void Init(void)
{
	switch (game_scene)
	{
	case 1:
		title_Init();
		break;
	case 2:
		game_Init();
		break;
	case 3:
		result_Init();
		break;
	case 4:
		rule_Init();
		break;
	default:
		break;
	}
}

void End(void)
{
	switch (game_scene)
	{
	case 1:
		title_End();
		break;
	case 2:
		game_End();
		break;
	case 3:
		result_End();
		break;
	case 4:
		rule_End();
		break;
	default:
		break;
	}
}

void Update(void)
{
	switch (game_scene)
	{
	case 1:
		title_Update();
		break;
	case 2:
		game_Update();
		break;
	case 3:
		result_Update();
		break;
	case 4:
		rule_Update();
		break;
	default:
		break;
	}
}

void Draw(void)
{
#ifdef _DEBUG
	// FPS�J�E���^�\��
	setcursortype(NOCURSOR);
	textcolor(WHITE);
	gotoxy(1, 1);
	printf("FPS : %d", g_nCountFPS);
#endif /*_DEBUG*/
	switch (game_scene)
	{
	case 1:
		title_Draw();
		break;
	case 2:
		game_Draw();
		break;
	case 3:
		result_Draw();
		break;
	case 4:
		rule_Draw();
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------------
// �V�[���؂�ւ�����I��
//-------------------------------------------------------------------
void scene_kirikae_hantei_on(void)
{
	game_scene_kirikae = true;
}

//-------------------------------------------------------------------
// �V�[���؂�ւ��p
//-------------------------------------------------------------------
void scene_kirikae(int i)
{
	game_scene = i;
}

