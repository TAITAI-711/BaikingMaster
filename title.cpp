// �^�C�g�����

#define CONIOEX

#include "title.h"
#include "main.h"
#include "game.h"
#include "SOUND.h"

// �\���̕ϐ��錾
AA_SIZE AA_size_menu;
OTHER_POS AA_menu_pos;

//---------------------------------------------------------
// �^�C�g����AA
//---------------------------------------------------------
const char* AA_title[] = {
	"                                                                                                                        ",
	"      ����  ����  ��  ��              ������      ����        ����    ����              ��      ������������  ��  ��    ",
	"      ����  ����  ��    ��          ������        ����    ������      ������            ��    ��������������  ��    ��  ",
	"      ����  ����    ��  ��        ������            ����������        ��������        ����  ������      ����    ��  ��  ",
	"    ������  ������  ��  ��      ������        ������������      ��      ������        ����  ����        ����    ��  ��  ",
	"    ����      ����          ����������      ������  ������  ������                  ������  ����        ����            ",
	"    ����      ����        ������  ����              ������������                  ��������              ����            ",
	"    ����      ����                ����        ��������������                    ��������              ������            ",
	"  ����        ����                ����      ��������    ����                  ��������              ������              ",
	"  ����        ������              ����      ��          ������      ����������������            ��������                ",
	"  ����        ������              ����                    ����      ��������������          ����������                  ",
	"  ����        ������              ����                    ����      ����������              ������                      ",
	"                                                                                                                        ",
	"                                                                                                                        ",
	"                                ��������������������  ��������������������        ��������������                        ",
	"                                ��������������������  ��������������������      ����������������                        ",
	"                                              ������                ������    ������        ����                        ",
	"                                            ������                ������      ��������      ����                        ",
	"                                ����      ������                ������        ����  ����  ������                        ",
	"                                ������  ������                ������                  ��������    ��������������������  ",
	"                                  ����������                ����������                  ������    ��������������������  ",
	"                                    ��������              ������  ������              ������                            ",
	"                                      ������            ������      ������        ��������                              ",
	"                                        ������        ������          ������  ����������                                ",
	"                                          ������      ������            ����  ������                                    ",
	"                                                                                                                        ",
	NULL
};

const char* AA_menu[] = {
	"  ==========================",
	"  ||    �Q�[���X�^�[�g    ||",
	"  ||                      ||",
	"  ||      ���[������      ||",
	"  ||                      ||",
	"  ||      �Q�[���I��      ||",
	"  ==========================",
	"        ��,,��||            ",
	"       (�E�ցE||            ",
	"       (�P�P�PO           ",
	"        �Z   �Z             ",
	NULL
};

const char* AA_menu_moji[] = {
	"   �Q�[���X�^�[�g   ",
	"   ���[������   ",
	"   �Q�[���I��   ",
	"�� �Q�[���X�^�[�g ��",
	"�� ���[������ ��",
	"�� �Q�[���I�� ��",
	"W,S or��,��",
	"�őI��",
	"           ",
	"�n�܂��",
	"���[������",
	"�I�������",
	NULL
};

//---------------------------------------------------------
// �O���[�o���ϐ��錾
//---------------------------------------------------------
static bool draw_one = true;		// �ŏ��̂P��̂ݕ\���̔���p
static bool select_draw_one = true; // �I�����̂P��̂ݕ\���̔���p
static bool menu_hyouji = true;		// ���j���[�̕\������p
static bool button_push = false;	// �{�^���������ꂽ������p
static bool select_kettei = false;	// �I�����̌��蔻��
static int time = 0;				// ���Ԍv���p
static int select_num = 0;			// ���j���[�̑I��ԍ�

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------
void title_Init(void)
{
	system("cls");
	// �J�[�\����\��
	setcursortype(NOCURSOR);
	// ������
	draw_one = true;
	select_draw_one = true;
	menu_hyouji = true;
	button_push = false;
	select_kettei = false;
	time = 0;
	select_num = 0;
	// AA_menu�̏c�E���̒�������
	AA_size_menu.tate = AA_size_tate(AA_menu);
	AA_size_menu.yoko = AA_size_yoko(AA_menu);
	// AA_menu�̍��W����
	AA_menu_pos.x = AA_MENU_POS_X;
	AA_menu_pos.y = AA_MENU_POS_Y;
	// ���y
	SoundPlayLoop(SOUND_TITLE_BGM);
}

void title_End(void)
{
	// �V�[���̐؂�ւ�
	int i = 0;
	switch (select_num)
	{
	case 0: // �Q�[���X�^�[�g
		i = 2;
		break;
	case 1: // ���[������
		i = 4;
		break;
	case 2: // �Q�[���I��
		i = 0;
		break;
	default:
		break;
	}
	SoundStop(SOUND_TITLE_BGM);
	scene_kirikae(i);
}

void title_Update(void)
{
	if (menu_hyouji == true)
	{
		time += 1; // ���� +1

		if ((time % 10) == 0)	AA_menu_pos.x += 2; // AA_menu X�ړ���
		if (AA_menu_pos.x >= 3)
		{
			menu_hyouji = false; // AA_menu �\���I��
			time = 0; // ���ԃ��Z�b�g
		}
	}
	else
	{
		// �I�����X�V
		if (!inport(PK_UP) && !inport(PK_DOWN) &&
			!inport(PK_W) && !inport(PK_S) && 
			!inport(PK_ENTER) && !inport(PK_SP) && !select_kettei)
		{
			button_push = false;
		}
		else if (!(button_push))
		{
			if (inport(PK_UP) || inport(PK_W))
			{
				// ���y
				SoundPlayOnce(SOUND_SENTAKU);
				select_num -= 1;
				button_push = true;
				select_draw_one = true;
			}
			if (inport(PK_DOWN) || inport(PK_S))
			{
				// ���y
				SoundPlayOnce(SOUND_SENTAKU);
				select_num += 1;
				button_push = true;
				select_draw_one = true;
			}
			if (inport(PK_ENTER) || inport(PK_SP))
			{
				// ���y
				SoundPlayOnce(SOUND_KETTEI);
				select_kettei = true;
				button_push = true;
				select_draw_one = true;
			}
			if (select_num < 0)	select_num = 2;
			if (select_num > 2)	select_num = 0;
		}
		else if (select_kettei)
		{
			time += 1; // ���� +1
			if (time >= 120) scene_kirikae_hantei_on();
		}
	}
}

void title_Draw(void)
{
	if (draw_one) // 1��̂ݕ\��
	{
		// �^�C�g���\��
		AA_title_Draw();
		draw_one = false;
	}
	if (((time % 10) == 0) && menu_hyouji)
	{
		// ���j���[�\��
		AA_menu_Draw();
	}
	if (menu_hyouji == false && select_draw_one == true)
	{
		// �I�����\��
		switch (select_num)
		{
		case 0:
			textbackground(GREEN);
			print_x_y_one(6, 18, AA_menu_moji[3], YELLOW);
			textbackground(BLACK);
			print_x_y_one(8, 20, AA_menu_moji[1], WHITE);
			print_x_y_one(8, 22, AA_menu_moji[2], WHITE);
			break;
		case 1:
			textbackground(GREEN);
			print_x_y_one(8, 20, AA_menu_moji[4], YELLOW);
			textbackground(BLACK);
			print_x_y_one(6, 18, AA_menu_moji[0], WHITE);
			print_x_y_one(8, 22, AA_menu_moji[2], WHITE);
			break;
		case 2:
			textbackground(GREEN);
			print_x_y_one(8, 22, AA_menu_moji[5], YELLOW);
			textbackground(BLACK);
			print_x_y_one(6, 18, AA_menu_moji[0], WHITE);
			print_x_y_one(8, 20, AA_menu_moji[1], WHITE);
			break;
		default:
			break;
		}
		if (select_kettei)
		{
			print_x_y_one(19, 25, AA_menu_moji[8], YELLOW);
			print_x_y_one(19, 26, AA_menu_moji[8], YELLOW);
			switch (select_num)
			{
			case 0:
				print_x_y_one(19, 25, AA_menu_moji[9], YELLOW);
				break;
			case 1:
				print_x_y_one(19, 25, AA_menu_moji[10], YELLOW);
				break;
			case 2:
				print_x_y_one(19, 25, AA_menu_moji[11], YELLOW);
				break;
			default:
				break;
			}
		}
		else
		{
			print_x_y_one(19, 25, AA_menu_moji[6], YELLOW);
			print_x_y_one(24, 26, AA_menu_moji[7], YELLOW);
		}
		select_draw_one = false;
	}
}

//---------------------------------------------------------
// �^�C�g���\��
//---------------------------------------------------------
void AA_title_Draw(void)
{
	textbackground(BROWN);
	print_x_y_all(1, 3, AA_title, LIGHTBLUE);
	textbackground(BLACK);
	for (int i = 0; i < AA_size_menu.tate + 1; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoxy(1 + j, (AA_MENU_POS_Y - 1) + i);
			printf(" ");
		}
	}
	textbackground(BLACK);
}

//---------------------------------------------------------
// �^�C�g���\��
//---------------------------------------------------------
void AA_menu_Draw(void)
{
	textcolor(WHITE);
	textbackground(BLACK);
	if (AA_menu_pos.x < 1 && (-AA_menu_pos.x <= AA_size_menu.yoko))
	{
		for (int i = 0; i < AA_size_menu.tate; i++)
		{
			for (int j = (-AA_menu_pos.x) + 1, k = 1;
				j < AA_size_menu.yoko; j++, k++)
			{
				gotoxy(k, AA_MENU_POS_Y + i);
				// �啶���̏ꍇ(���{��Ȃ�)
				if (!(AA_menu[i][j] >= 0 && AA_menu[i][j] <= 127))
				{
					printf("%c", AA_menu[i][j]);
					printf("%c", AA_menu[i][j + 1]);
					j++;
					k++;
				}
				// �������̏ꍇ
				else
				{
					printf("%c", AA_menu[i][j]);
				}
			}
		}
	}
	else if (AA_menu_pos.x >= 1)
	{
		for (int i = 0; i < AA_size_menu.tate; i++)
		{
			for (int j = AA_menu_pos.x, k = 0;
				j < (AA_size_menu.yoko + AA_menu_pos.x); j++, k++)
			{
				gotoxy(j, AA_MENU_POS_Y + i);
				// �啶���̏ꍇ(���{��Ȃ�)
				if (!(AA_menu[i][k] >= 0 && AA_menu[i][k] <= 127))
				{
					printf("%c", AA_menu[i][k]);
					printf("%c", AA_menu[i][k + 1]);
					j++;
					k++;
				}
				// �������̏ꍇ
				else
				{
					printf("%c", AA_menu[i][k]);
				}
			}
		}
	}
	textcolor(WHITE);
	textbackground(BLACK);
}
