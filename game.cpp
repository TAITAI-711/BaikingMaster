// �Q�[���{��

#define CONIOEX
#include "game.h"
#include "main.h"
#include "timer.h"
#include "food.h"
#include "SOUND.h"

// �\���̕ϐ��錾
PLAYER Player;
PLAYER_POS Player_pos;
OTHER_POS UI_moji_pos[4];
OTHER_POS FOOD_moji;
OTHER_POS AA_count_pos[4];
AA_SIZE	AA_size[AA_SYURUI];
RYOURI_UKETORI Ryouri_uketori;

//---------------------------------------------------------
// �L�����N�^�[��AA
//---------------------------------------------------------
// �v���[���[(AA�̎��:0)
const char* AA_player_0[] = {
	" ��,,��   ",
	"(*�E�ցE) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_0_1[] = {
	"   ��,,�� ",
	" (�E�ցE*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};
const char* AA_player_1[] = {
	" ��,,��   ",
	"(*�E�ց�) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_1_1[] = {
	"   ��,,�� ",
	" (���ցE*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};
const char* AA_player_2[] = {
	" ��,,��   ",
	"(*�E����) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_2_1[] = {
	"   ��,,�� ",
	" (�����E*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};
const char* AA_player_3[] = {
	" ��,,��   ",
	"(*�E����) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_3_1[] = {
	"   ��,,�� ",
	" (�����E*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};
const char* AA_player_4[] = {
	" �ȁ���   ",
	"(*�E����) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_4_1[] = {
	"   ������ ",
	" (�����E*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};
const char* AA_player_5[] = {
	" �ȁ���   ",
	"(*������) ",
	"(�P�P�PO",
	" �Z   �Z  ",
	NULL
};
const char* AA_player_5_1[] = {
	"   ������ ",
	" (������*)",
	"O�P�P�P��)",
	"  �Z   �Z ",
	NULL
};

// �����̘g(AA�̎��:1)
const char* AA_ryouri_0[] = {
	"||      ���͂�      ||",
	"||    �T���_�t��    ||",
	"||                  ||",
	"||      6000 �~     ||",
	"||  �� �� �� �� ��  ||",
	"======================",
	NULL
};
const char* AA_ryouri_1[] = {
	"======================",
	"||      ���͂�      ||",
	"||    �T���_�t��    ||",
	"||                  ||",
	"||      6000 �~     ||",
	"||  �� �� �� �� ��  ||",
	NULL
};
const char* AA_ryouri_2[] = {
	"======================",
	NULL
};

// UI�̘g(AA�̎��:2)
const char* AA_UI_0[] = {
	"��������",
	"�����Ă��闿���̐�",
	NULL
};
const char* AA_UI_1[] = {
	"                ",
	"     60  �b     ",
	"                ",
	NULL
};
const char* AA_UI_2[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};
const char* AA_UI_2_1[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};
const char* AA_UI_2_2[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};
const char* AA_UI_2_3[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};
const char* AA_UI_2_4[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};
const char* AA_UI_2_5[] = {
	"                ",
	" �� �� �� �� �� ",
	"                ",
	NULL
};

// �H�ׂ�Ƃ���(AA�̎��:3)
const char* AA_EAT_0[] = {
	"||",
	NULL
};

// �H�ׂ�Ƃ���̕���
const char* AA_EAT_MOJI[] = {
	"�e",
	"  ",
	"�b",
	"  ",
	"�u",
	"  ",
	"��",
	NULL
};

// �J�E���g(AA�̎��:4)
const char* AA_COUNT_NUM_1[] =
{
	"    ��",
	"    ��",
	"    ��",
	"    ��",
	"    ��",
	NULL
};
const char* AA_COUNT_NUM_2[] =
{
	"������",
	"    ��",
	"������",
	"��    ",
	"������",
	NULL
};
const char* AA_COUNT_NUM_3[] =
{
	"������",
	"    ��",
	"������",
	"    ��",
	"������",
	NULL
};
// (AA�̎��:5)
const char* AA_COUNT_END[] =
{
	"    ��  ��      ��          ��    ��",
	"��������  ��  ����������    ��    ��",
	"  ������        ����  ��    ����  ��",
	"��  ��  ��    ����    ��          ��",
	"������  ��      ��  ��        ������",
	NULL
};
// (AA�̎��:6)
const char* AA_COUNT_WAKU_1[] =
{
	"==========================",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"||                      ||",
	"==========================",
	NULL
};
const char* AA_COUNT_WAKU_1_KUHAKU[] =
{
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	"                          ",
	NULL
};
// (AA�̎��:7)
const char* AA_COUNT_WAKU_2[] =
{
	"============================================",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"||                                        ||",
	"============================================",
	NULL
};


//---------------------------------------------------------
// �O���[�o���ϐ��錾
//---------------------------------------------------------
static DWORD time;						// �c�莞��
static int game_start_count = 4;		// �Q�[���̃J�E���g�\���p
static bool draw_one = true;			// �ŏ��̂P��̂ݕ\���̔���p
static bool PK_SP_ET_on = false;		// �X�y�[�X�{�^����������Ă��邩����p
static bool game_end_hantei = false;	// �Q�[���̏I������
static bool game_start_hantei = false;	// �Q�[���̊J�n����

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------

void game_Init(void)
{
	system("cls");
	// �J�[�\����\��
	setcursortype(NOCURSOR);
	// �\���̏�����
	Player = {};
	Player_pos = {};
	FOOD_moji = {};
	Ryouri_uketori = {};
	// ���菉����
	game_start_hantei = false;
	game_end_hantei = false;
	game_start_count = 4;
	draw_one = true;
	// �^�C�}�[�Z�b�g
	TimerInit();
	setTimerRemaining(GAME_TIME + COUNT_TIME);
	// AA�̏�����
	AA_info_Init();
	// �v���[���[�̏����ݒ�
	player_set_Init();
	// UI�̍��W�ݒ�
	ui_waku_Init();
	// �H�ו��̏�����
	food_Init(AA_size[1].tate, AA_size[1].yoko);	
}

void game_End(void)
{
	food_End();
	SoundStop(SOUND_GAME_BGM);
	scene_kirikae(3);
}

void game_Update(void)
{
	// �^�C�}�[�̎c�莞��
	time = getTimerRemaining();
	if (!game_start_hantei && (time <= GAME_TIME))
	{
		// ���y
		SoundPlayLoop(SOUND_GAME_BGM);
		game_start_hantei = true;
	}
	if (!game_end_hantei)
	{
		if (game_start_hantei)
		{
			// �v���[���[�ړ�
			player_move_Update();
			// �v���[���[�̎c����������
			p_zanzou_kesu_Update();
		}
		// �����̏���
		food_Update(time);
		// �����̘g�̎󂯎�蕔���X�V
		ryouri_waku_uketori_Update();
		// �v���C���[�̎����Ă��闿���̐�
		player_food_have_Update();
	}
	// �I��
	if (time == 0 && !game_end_hantei)
	{
		// ���y
		SoundPlayOnce(SOUND_END);
		// �^�C�}�[���ԃZ�b�g
		setTimerRemaining(2000);
		// �Q�[���̏I������I��
		game_end_hantei = true;
		// �ŏ���1��̂ݕ\���̔���I��
		draw_one = true;
	}
	else if (time == 0 && game_end_hantei)
	{
		scene_kirikae_hantei_on();
	}
}

void game_Draw(void)
{
	// �J�E���g�\��
	AA_count_NUM_Draw();
	
	if (!game_end_hantei)
	{
		if (draw_one) // �ŏ���1��̂ݕ\��
		{
			draw_one = false;
			// �����̘g�\��
			ryouri_waku_Draw();
			// UI�̘g�\��
			ui_waku_Draw();
			// �H�ׂ�Ƃ���̕����\��
			print_x_y_all(4, 13, AA_EAT_MOJI, WHITE);
		}

		// �v���[���[�̎c�������󔒕\��
		p_zanzou_kesu_Draw();
		// �v���[���[�\��
		player_Draw();
		// �����̘g�̎󂯎�蕔���\��
		ryouri_waku_uketori_Draw();
		// �H�ׂ�Ƃ���̕\��
		food_eat_Draw();
		// UI�\��
		ui_Draw();
		// �����\��
		food_Draw();
	}
	else
	{
		if (draw_one)
		{
			// �I���̈ʒu����
			AA_count_END_Draw();
			draw_one = false;
		}
	}
}

//---------------------------------------------------------
// �v���[���[�̈ړ�����
//---------------------------------------------------------
void player_move_Update(void)
{
	// �{�^�����͂ňړ�
	if (inport(PK_A) || inport(PK_LEFT))
	{
		Player_pos.x -= PLAYER_MOVE_X;
	}
	if (inport(PK_D) || inport(PK_RIGHT))
	{
		Player_pos.x += PLAYER_MOVE_X;
	}
	if (inport(PK_W) || inport(PK_UP))
	{
		Player_pos.y -= PLAYER_MOVE_Y;
	}
	if (inport(PK_S) || inport(PK_DOWN))
	{
		Player_pos.y += PLAYER_MOVE_Y;
	}

	// �v���C���[�����E���W�𒴂�����߂�
	if (Player_pos.x < Player_pos.limit_L)
	{
		Player_pos.x = Player_pos.limit_L;
	}
	if (Player_pos.x > Player_pos.limit_R)
	{
		Player_pos.x = Player_pos.limit_R;
	}
	if (Player_pos.y < Player_pos.limit_U)
	{
		Player_pos.y = Player_pos.limit_U;
	}
	if (Player_pos.y > Player_pos.limit_D)
	{
		Player_pos.y = Player_pos.limit_D;
	}
}

//---------------------------------------------------------
// ������H�ׂ�ʒu�ɂ��邩���菈��
//---------------------------------------------------------
void food_eat_Update(void)
{
	// �H�ׂ�ʒu�ɂ��邩����
	if ((int)Player_pos.x <= Player_pos.limit_L)
	{
		Ryouri_uketori.eat_iti = true;
	}
	else
	{
		Ryouri_uketori.eat_iti = false;
	}
}

//---------------------------------------------------------
// �v���C���[�̎����Ă��闿���̐�
//---------------------------------------------------------
void player_food_have_Update(void)
{
	//�v���[���[���󂯎��\�Ȉʒu������
	player_uketori_iti();
	// ������H�ׂ�ʒu�ɂ��邩���菈��
	food_eat_Update();

	if (!inport(PK_SP) && !inport(PK_ENTER))
	{
		PK_SP_ET_on = false;
	}
	else if (!(PK_SP_ET_on))
	{
		for (int i = 0; i < 6; i++)
		{
			if (Ryouri_uketori.iti == i && Ryouri_uketori.ok[i])
			{
				// ���y
				SoundPlayOnce(SOUND_UKETORI);
				// �����Ă��闿���̗ʍX�V
				Player.food_have += ryouri_amount(i);
				// �󂯎���������̔ԍ��擾
				Player.food_uketori_num[Player.uketori_num] = ryouri_uketori(i);
				Player.uketori_num += 1;
				
				PK_SP_ET_on = true;
			}
		}
	}
	// ������H�ׂ�
	if ((Ryouri_uketori.eat_iti) && (Player.food_have > 0))
	{
		// ���y
		SoundPlayOnce(SOUND_TABERU);
		// �����Ă��闿���̗ʂ�0�ɂ���
		Player.food_have = 0;
		// �󂯎����������H�ׂ������ɂ���
		for (int i = 0; i < Player.uketori_num; i++)
		{
			Player.food_eat_num[Player.eat_num] = Player.food_uketori_num[i];
			Player.eat_num += 1;
		}
		// �󂯎���������̐���0�ɂ���
		Player.uketori_num = 0;
	}
	// (�e�X�g)�����̎��Ă���E
	if (Player.food_have > 5)
	{
		Player.food_have = 5;
	}
}

//---------------------------------------------------------
// �v���C���[�̏����ݒ�
//---------------------------------------------------------
void player_set_Init(void)
{
	// �������W�ݒ�
	Player_pos.x = PLAYER_S_POS_X;
	Player_pos.y = PLAYER_S_POS_Y;
	Player_pos.previous_x = PLAYER_S_POS_X;
	Player_pos.previous_y = PLAYER_S_POS_Y;
	// ���������ݒ�
	Player_pos.muki = 0;
	// ���E���W����
	p_pos_limit_input();
}

//---------------------------------------------------------
// �v���[���[�̌��E���W����
//---------------------------------------------------------
void p_pos_limit_input(void)
{
	Player_pos.limit_L = (float)(FOOD_EAT_X + AA_size[3].yoko);	// ���̌��E
	Player_pos.limit_R = (float)(UI_X - AA_size[0].yoko);		// �E�̌��E
	Player_pos.limit_U = (float)(AA_size[1].tate + 1);			// ��̌��E
	Player_pos.limit_D = (float)((SCREEN_Y + 1) -
		(AA_size[0].tate + AA_size[1].tate));					// ���̌��E
}

//---------------------------------------------------------
// �v���[���[���󂯎��\�Ȉʒu������
//---------------------------------------------------------
void player_uketori_iti(void)
{
	// �����ɓ��Ă͂܂�Ȃ�������󂯎��s��
	Ryouri_uketori.iti = -1;

	if ((int)Player_pos.y <= (int)Player_pos.limit_U)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 0; // �����P�̈ʒu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 1; // �����Q�̈ʒu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 2; // �����R�̈ʒu
		}
	}
	else if ((int)Player_pos.y >= (int)Player_pos.limit_D)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 3; // �����S�̈ʒu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 4; // �����T�̈ʒu
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 5; // �����U�̈ʒu
		}
	}
}

//---------------------------------------------------------
// UI�̕\��
//---------------------------------------------------------
void ui_Draw(void)
{
	int food_have_x = UI_moji_pos[3].x;// �����Ă��闿���̐��\��X���W
	int food_have_y = UI_moji_pos[3].y;// �����Ă��闿���̐��\��Y���W

	// �c�莞�ԕ\��
	if (time / 1000 < 10)
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, 0, WHITE);
		print_x_y_one_num(UI_moji_pos[1].x + 6, UI_moji_pos[1].y + 1, time / 1000, WHITE);
	}
	else if (time / 1000 < 61)
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, time / 1000, WHITE);
	}
	else
	{
		print_x_y_one_num(UI_moji_pos[1].x + 5, UI_moji_pos[1].y + 1, 60, WHITE);
	}
	// �����Ă��闿���̐��\��
	switch (Player.food_have)
	{
	case 0:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2, RYOURI_HAVE_COLOR_2);
		break;
	case 1:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_1, RYOURI_HAVE_COLOR_2);
		break;
	case 2:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_2, RYOURI_HAVE_COLOR_2);
		break;
	case 3:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_3, RYOURI_HAVE_COLOR_2);
		break;
	case 4:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_4, RYOURI_HAVE_COLOR_2);
		break;
	case 5:
		print_x_y_all(food_have_x, food_have_y, AA_UI_2_5, RYOURI_HAVE_COLOR_2);
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
// �v���[���[�̕\��
//---------------------------------------------------------
void player_Draw(void)
{
	const char* p;
	p = AA_player_0[0];
	switch (Player.food_have)
	{
	case 0:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_0, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_0_1, WHITE);
		}
		break;
	case 1:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_1, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_1_1, WHITE);
		}
		break;
	case 2:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_2, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_2_1, WHITE);
		}
		break;
	case 3:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_3, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_3_1, WHITE);
		}
		break;
	case 4:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_4, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_4_1, WHITE);
		}
		break;
	case 5:
		if (Player_pos.muki == 0)
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_5, WHITE);
		}
		else
		{
			print_x_y_all((int)Player_pos.x, (int)Player_pos.y, AA_player_5_1, WHITE);
		}
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
// �����̘g�\��
//---------------------------------------------------------
void ryouri_waku_Draw(void)
{
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, 1, AA_ryouri_0, WHITE); //�g1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, 1, AA_ryouri_0, WHITE); //�g2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, 1, AA_ryouri_0, WHITE); //�g3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //�g4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //�g5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //�g6
}

//---------------------------------------------------------
// �����̘g�̎󂯎�蕔���X�V
//---------------------------------------------------------
void ryouri_waku_uketori_Update(void)
{
	for (int i = 0; i < 6; i++)
	{
		if (((Player.food_have + ryouri_amount(i)) > 5) || 
			ryouri_kirikae_hantei(i)) // �󂯎��s��
		{
			Ryouri_uketori.waku_color[i] = RED;
			Ryouri_uketori.ok[i] = false;
		}
		else // �󂯎��\
		{
			Ryouri_uketori.waku_color[i] = GREEN;
			Ryouri_uketori.ok[i] = true;
		}
	}
}

//---------------------------------------------------------
// �����̘g�̎󂯎�蕔���\��
//---------------------------------------------------------
void ryouri_waku_uketori_Draw(void)
{	
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[0]); //�g1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[1]); //�g2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[2]); //�g3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[3]); //�g4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[4]); //�g5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, (SCREEN_Y + 1) - AA_size[1].tate,
		AA_ryouri_2, Ryouri_uketori.waku_color[5]); //�g6
}

//---------------------------------------------------------
// �H�ׂ�Ƃ���̕\��
//---------------------------------------------------------
void food_eat_Draw(void)
{
	int color; // �F

	if (Player.food_have > 0)
	{
		color = GREEN;
	}
	else
	{
		color = RED;
	}
	for (int i = 0; i < SCREEN_Y; i++)
	{
		print_x_y_one(10, 1 + i, AA_EAT_0[0], color);
	}
}

//---------------------------------------------------------
// UI�̘g�\��
//---------------------------------------------------------
void ui_waku_Draw(void)
{
	textbackground(LIGHTGRAY); // �D�F�ɕύX
	// �S�̂��D�F�ɂ���
	for (int i = 1; i <= SCREEN_Y; i++)
	{
		for (int j = 0; j < (SCREEN_X + 1) - UI_X; j++)
		{
			gotoxy(UI_X + j, i);
			printf(" ");
		}
	}
	// �������Ԃ̕����\��
	print_x_y_one(UI_moji_pos[0].x, UI_moji_pos[0].y, AA_UI_0[0], BLACK);
	// �����Ă��闿���̐��̕����\��
	print_x_y_one(UI_moji_pos[2].x, UI_moji_pos[2].y, AA_UI_0[1], RYOURI_HAVE_COLOR_1);
	textbackground(BLACK); // ���ɕύX

	// ��������
	print_x_y_all(UI_moji_pos[1].x, UI_moji_pos[1].y, AA_UI_1, WHITE);
	// �����Ă��闿���̐�
	print_x_y_all(UI_moji_pos[3].x, UI_moji_pos[3].y, AA_UI_2, RYOURI_HAVE_COLOR_2);
}
//---------------------------------------------------------
// UI�̘g���W�ݒ�
//---------------------------------------------------------
void ui_waku_Init(void)
{
	// �������Ԃ̕���
	UI_moji_pos[0].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[0])) / 2);
	UI_moji_pos[0].y = UI_TIME_Y;
	// ��������
	UI_moji_pos[1].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[1].y = UI_TIME_Y + 2;
	// �����Ă��闿���̐��̕���
	UI_moji_pos[2].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[1])) / 2);
	UI_moji_pos[2].y = UI_RYOURI_Y;
	// �����Ă��闿���̐�
	UI_moji_pos[3].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[3].y = UI_RYOURI_Y + 2;
}

//---------------------------------------------------------
// �v���[���[�̎c����������
//---------------------------------------------------------
void p_zanzou_kesu_Update(void)
{
	Player_pos.zanzou = 0;

	if ((int)Player_pos.previous_x != (int)Player_pos.x ||
		(int)Player_pos.previous_y != (int)Player_pos.y)
	{
		if ((int)Player_pos.previous_y > (int)Player_pos.y) // ��Ɉړ�
		{
			Player_pos.zanzou += 1;
		}
		if ((int)Player_pos.previous_y < (int)Player_pos.y) // ���Ɉړ�
		{
			Player_pos.zanzou += 2;
		}
		if ((int)Player_pos.previous_x > (int)Player_pos.x) // ���Ɉړ�
		{
			Player_pos.zanzou += 4;
			Player_pos.muki = 1; // ���������ɕύX
		}
		if ((int)Player_pos.previous_x < (int)Player_pos.x) // �E�Ɉړ�
		{
			Player_pos.zanzou += 8;
			Player_pos.muki = 0; // �������E�ɕύX
		}
	}
}

//---------------------------------------------------------
// �v���[���[�̎c�������󔒕\��
//---------------------------------------------------------
void p_zanzou_kesu_Draw(void)
{
	// ��������(��Ɉړ�)
	if (Player_pos.zanzou == 1 || Player_pos.zanzou == 5 || Player_pos.zanzou == 9)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i,
				(int)Player_pos.previous_y + (AA_size[0].tate - 1));
			printf(" ");
		}
	}
	// �������(���Ɉړ�)
	if (Player_pos.zanzou == 2 || Player_pos.zanzou == 6 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i, (int)Player_pos.previous_y);
			printf(" ");
		}
	}
	// �E������(���Ɉړ�)
	if (Player_pos.zanzou == 4 || Player_pos.zanzou == 5 || Player_pos.zanzou == 6)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x + (AA_size[0].yoko - 1), 
				(int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// ��������(�E�Ɉړ�)
	if (Player_pos.zanzou == 8 || Player_pos.zanzou == 9 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x, (int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// �v���C���[�̑O�̈ʒu�Ɍ��ݒn�����
	Player_pos.previous_x = Player_pos.x;
	Player_pos.previous_y = Player_pos.y;
}

//---------------------------------------------------------
// AA�̏�����
//---------------------------------------------------------
void AA_info_Init(void)
{
	// �v���C���[�̍����ƕ�
	AA_size_input(AA_player_0, AA_size, 0);
	// �����̘g�̍����ƕ�
	AA_size_input(AA_ryouri_0, AA_size, 1);
	// UI�̍����ƕ�
	AA_size_input(AA_UI_1, AA_size, 2);
	// �H�ׂ�Ƃ���̍����ƕ�
	AA_size_input(AA_EAT_0, AA_size, 3);
	// �J�E���g�̐����̍����ƕ�
	AA_size_input(AA_COUNT_NUM_1, AA_size, 4);
	// �J�E���g�̏I���̍����ƕ�
	AA_size_input(AA_COUNT_END, AA_size, 5);
	// �J�E���g�̘g1�̍����ƕ�
	AA_size_input(AA_COUNT_WAKU_1, AA_size, 6);
	// �J�E���g�̘g2�̍����ƕ�
	AA_size_input(AA_COUNT_WAKU_2, AA_size, 7);
	// AA�J�E���g�̕\�����W����
	// ����
	AA_count_pos[0].x = ((SCREEN_X + 1) - AA_size[4].yoko) / 2;
	AA_count_pos[0].y = ((SCREEN_Y + 1) - AA_size[4].tate) / 2;
	// �I���
	AA_count_pos[1].x = ((SCREEN_X + 1) - AA_size[5].yoko) / 2;
	AA_count_pos[1].y = ((SCREEN_Y + 1) - AA_size[5].tate) / 2;
	// �g1
	AA_count_pos[2].x = ((SCREEN_X + 1) - AA_size[6].yoko) / 2;
	AA_count_pos[2].y = ((SCREEN_Y + 1) - AA_size[6].tate) / 2;
	// �g2
	AA_count_pos[3].x = ((SCREEN_X + 1) - AA_size[7].yoko) / 2;
	AA_count_pos[3].y = ((SCREEN_Y + 1) - AA_size[7].tate) / 2;
}

//---------------------------------------------------------
// AA�����̕\��
//---------------------------------------------------------
void AA_count_END_Draw(void)
{
	textbackground(GREEN);
	// �g2�\��
	print_x_y_all(AA_count_pos[3].x, AA_count_pos[3].y, AA_COUNT_WAKU_2, YELLOW);
	// �I���\��
	print_x_y_all(AA_count_pos[1].x, AA_count_pos[1].y, AA_COUNT_END, WHITE);
	textbackground(BLACK);
}

//---------------------------------------------------------
// AA�J�E���g�̕\��
//---------------------------------------------------------
void AA_count_NUM_Draw(void)
{
	if (!game_start_hantei)
	{
		if (time <= GAME_TIME + 1000 && game_start_count == 2)
		{
			// ���y
			SoundPlayOnce(SOUND_COUNT);
			//�g1�\��
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, RED);
			// 1�\��
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_1, LIGHTRED);
			// �J�E���g�����1�ɂ���
			game_start_count = 1;
		}
		else if (time <= GAME_TIME + 2000 && game_start_count == 3)
		{
			// ���y
			SoundPlayOnce(SOUND_COUNT);
			//�g1�\��
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BROWN);
			// 2�\��
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_2, YELLOW);
			// �J�E���g�����2�ɂ���
			game_start_count = 2;
		}
		else if (game_start_count == 4)
		{
			// ���y
			SoundPlayOnce(SOUND_COUNT);
			//�g1�\��
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BLUE);
			// 3�\��
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_3, LIGHTBLUE);
			// �J�E���g�����3�ɂ���
			game_start_count = 3;
		}
	}
	else if (game_start_count == 1)
	{
		// ���y
		//SoundPlayOnce(SOUND_START);
		// �J�E���g����
		print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1_KUHAKU, WHITE);
		// �Q�[���̃J�E���g�����0�ɂ���
		game_start_count = 0;
	}
}


//---------------------------------------------------------
// AA�̍����ƕ��𑪂鏈��
//---------------------------------------------------------
void AA_size_input(const char* p[], AA_SIZE AA_size[], int AA_num)
{
	AA_size[AA_num].tate = AA_size_tate(p);
	AA_size[AA_num].yoko = AA_size_yoko(p);
}

//---------------------------------------------------------
// �H�ׂ������̐���Ԃ�
//---------------------------------------------------------
const int eat_ryouri_num(void)
{
	return Player.eat_num;
}

//---------------------------------------------------------
// �H�ׂ������̖��O��Ԃ�
//---------------------------------------------------------
const char* eat_ryouri_name(int i)
{
	return ryouri_name(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// �H�ׂ������̒l�i��Ԃ�
//---------------------------------------------------------
const int eat_ryouri_nedan(int i)
{
	return ryouri_nedan(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// �H�ׂ������̖��O�̐F��Ԃ�
//---------------------------------------------------------
const int eat_ryouri_color(int i)
{
	return ryouri_color(Player.food_eat_num[i]);
}