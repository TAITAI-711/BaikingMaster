// �H�ו��p

#define CONIOEX
#include <time.h>
#include "food.h"
#include "timer.h"


// �\���̕ϐ��錾
// �S�p8�����܂�
FOOD Food[] = {
	{"�X�e�[�L"			,	BROWN,		3,	4300	}, {"���͂�"			,	WHITE,		1,	200		},
	{"�������[����"		,	WHITE,		4,	800		}, {"���傤�䃉�[����"	,	LIGHTRED,	4,	1000	},
	{"�݂����[����"		,	BROWN,		4,	1200	}, {"�Ƃ񂱂��[����"	,	YELLOW,		4,	1500	},
	{"���ǂ�"			,	YELLOW,		4,	500		}, {"�g�}�g�T���_"		,	RED,		1,	400		},
	{"�t�J�T���_"		,	GREEN,		1,	300		}, {"�؂���ԃT���_"	,	GREEN,		1,	500		},
	{"�`�����M�T���_"	,	GREEN,		1,	360		}, {"�R�[���T���_"		,	GREEN,		1,	310		}, 
	{"�J�j"				,	RED,		2,	4100	}, {"���₵"			,	WHITE,		1,	50		},
	{"���炠��"			,	BROWN,		1,	500		}, {"�J�c�J���["		,	BROWN,		3,	800		},
	{"��؃J���["		,	BROWN,		3,	770		}, {"�L�q"				,	YELLOW,		2,	260		},
	{"�`���[�n��"		,	YELLOW,		3,	700		}, {"��񂲃W���[�X"	,	RED,		1,	300		},
	{"�Ԃǂ��W���[�X"	,	LIGHTMAGENTA,1,	350		}, {"�I�����W�W���[�X"	,	YELLOW,		1,	300		},
	{"�v����"			,	YELLOW,		1,	350		}, {"���[�X�g�r�[�t"	,	BROWN,		1,	2500	},
	{"�ǐm����"			,	WHITE,		1,	300		}, {"�H�p��"			,	WHITE,		1,	150		},
	{"�N�����b�T��"		,	BROWN,		1,	200		}, {"�V�Ղ�"			,	YELLOW,		2,	820		},
	{"�܂�����i"		,	RED,		1,	500		}, {"�T�[�������i"		,	LIGHTRED,	1,	450		},
	{"�n���o�[�O"		,	BROWN,		3,	1000	}, {"�~�l�X�g���[�l"	,	LIGHTRED,	2,	380		},
	{"���܂��X�[�v"		,	YELLOW,		2,	310		}, {"�Ă�����"			,	BROWN,		3,	600		},
	{"����"				,	LIGHTGRAY,	3,	1100	}, {"���q����"			,	YELLOW,		2,	550		},
	{"�܂��똥"			,	RED,		4,	1500	}, {"�J���{�i�[��"		,	YELLOW,		3,	880		},
	{"�~�[�g�p�X�^"		,	RED,		3,	630		}, {"�R�[�q�["			,	DARKGRAY,	1,	500		},
	{"�L���r�A"			,	DARKGRAY,	1,	3000	}, {"�g�����t�X�e�[�L"	,	DARKGRAY,	5,	6000	},
	{"�t����"			,	YELLOW,		2,	270		}, {"���܂�"			,	LIGHTGRAY,	2,	300		},
	{"�V���E�}�C"		,	WHITE,		1,	350		}, {"�}�J���j�O���^��"	,	YELLOW,		3,	850		},
	{"���ڂ���R���b�P"	,	BROWN,		2,	200		}, {"�Ђ����R���b�P"	,	BROWN,		2,	310		},
	{"���܂��Ă�"		,	YELLOW,		2,	200		}, {"���[�O���g"		,	WHITE,		2,	200		},
	{"�킩�߂̖��X�`"	,	BROWN,		1,	350		}, {"�؏`"				,	BROWN,		1,	420		},
	{"�|�e�g"			,	BROWN,		1,	300		}, {"�z�^�e���i"		,	WHITE,		1,	410		},
	{"�g�����t�T���_"	,	GREEN,		1,	600		}, {"�`�[�Y�s�U"		,	YELLOW,		3,	1100	},
	{"�x�[�R���s�U"		,	LIGHTRED,	3,	1300	}, {"�R�[�q�[�[���["	,	DARKGRAY,	1,	350		},
	{"������"			,	LIGHTGREEN,	2,	1200	}, {"�V�F�t�̂�������"	,	RED,		2,	5000	},
	{"�N���[�v"			,	YELLOW,		2,	550		}, {"�e�B���~�X"		,	BROWN,		2,	450		},
	{"�~�[�g�p�C"		,	YELLOW,		3,	610		}, {"�}�J����"			,	LIGHTRED,	1,	300		},
	{"�Ԃǂ�"			,	MAGENTA,	1,	450		}, {"�݂���"			,	YELLOW,		1,	200		},
	{"�}�X�J�b�g"		,	GREEN,		1,	650		}, {"����"				,	LIGHTRED,	1,	350		},
	{"�p�G���A"			,	YELLOW,		2,	1000	}, {"���[���[�n��"		,	BROWN,		2,	600		},
	{"�^�s�I�J�e�B�["	,	LIGHTGRAY,	1,	500		}, {"�`�[�Y�^�b�J���r"	,	YELLOW,		4,	800		},
	{"�`�[�Y�P�[�L"		,	YELLOW,		2,	450		}, {"�g�������N��"		,	RED,		3,	900		},
	{"�`���R�P�[�L"		,	LIGHTGRAY,	2,	450		}, {"�k���_�b�N"		,	BROWN,		4,	3500	},
	{"���D�ݏĂ�"		,	BROWN,		3,	850		}, {"�G�b�O�^���g"		,	YELLOW,		2,	250		},
	{"�G�r�s���t"		,	WHITE,		3,	630		}, {"�v���R�M"			,	BROWN,		3,	830		},
	{"�r�[�t�V�`���["	,	BROWN,		3,	860		}, {"�^�R�X"			,	GREEN,		2,	600		},
	{"�����Ⴊ"			,	BROWN,		2,	640		}, {"���N�T"			,	LIGHTRED,	3,	540		},
	{"�������t���X�Y��"	,	LIGHTRED,	2,	2500	}, {"���t����"			,	GREEN,		2,	560		},
	{"�J�I�}���K�C"		,	LIGHTGRAY,	3,	1100	}, {"�t�J�q���X�[�v"	,	YELLOW,		2,	4000	},
	{"�}���Q���[�^"		,	RED,		3,	1200	}, {"�����"			,	WHITE,		2,	1000	},
	{"�t�H�["			,	LIGHTGRAY,	2,	720		}, {"���q"				,	WHITE,		2,	700		},
	{"�o�C���~�["		,	GREEN,		2,	530		}, {"�i�V�S����"		,	BROWN,		3,	830		},
	{"�s�N���X"			,	GREEN,		1,	250		}, {"�V���N������"		,	YELLOW,		3,	750		},
	{"���r�[��"			,	YELLOW,		1,	630		}, {"�ԃ��C��"			,	LIGHTRED,	1,	1200	}, 
	{"�����C��"			,	WHITE,		1,	1200	}, {"���{��"			,	WHITE,		1,	850		}, 
	{"�E�B�X�L�["		,	BROWN,		1,	1300	}, {"�J���[�A�E�~���N"	,	DARKGRAY,	1,	800		},
	{"�}�e�B�[�j"		,	WHITE,		1,	1100	}, {"���X�R�~���[��"	,	WHITE,		1,	780		},
	{"�J�V�X�I�����W"	,	YELLOW,		1,	800		},
};
FOOD_INFO Food_info;
FOOD_KIRIKAE Food_kirikae;
RANDOM Random;
OTHER_POS Food_pos[6];
OTHER_POS Food_pre_pos[6];
OTHER_POS Food_nedan_pos[6];
OTHER_POS Food_nedan_pre_pos[6];
OTHER_POS Food_amount_pos[6];
OTHER_POS Food_kuhaku_pos[6];

//---------------------------------------------------------
// �L�����N�^�[��AA
//---------------------------------------------------------
const char* AA_AMOUNT_0[] = {
	"        ��        ",
	NULL
};
const char* AA_AMOUNT_1[] = {
	"      ��  ��      ",
	NULL
};
const char* AA_AMOUNT_2[] = {
	"    ��  ��  ��    ",
	NULL
};
const char* AA_AMOUNT_3[] = {
	"  ��  ��  ��  ��  ",
	NULL
};
const char* AA_AMOUNT_4[] = {
	"��  ��  ��  ��  ��",
	NULL
};
const char* AA_URIKIRE[] = {
	"  �����؂�ւ���  ",
	NULL
};

//---------------------------------------------------------
// �O���[�o���ϐ��錾
//---------------------------------------------------------
static DWORD game_time;		// �Q�[������
static int AA_waku_tate;	// ������\������g�̏c�̒���
static int AA_waku_yoko;	// ������\������g�̉��̒���

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------
void food_Init(int waku_tate, int waku_yoko)
{
	// �\���̏�����
	Food_info = {};
	Food_kirikae = {};
	Random = {};
	// ������\������g�̒�������
	AA_waku_tate = waku_tate;
	AA_waku_yoko = waku_yoko;
	// �����_���ϐ�����
	random_Init();
	// �������������߂̋󔒍��W����
	food_kuhaku_pos_Init();
	// �����̗ʕ\�����W����
	food_amount_pos_Init();
}

void food_End(void)
{

}

void food_Update(DWORD now_game_time)
{
	game_time = now_game_time;

	for (int i = 0; i < 6; i++)
	{
		// �؂�ւ��̎���
		if (Random.kirikae_time[i] <= ((GAME_TIME + COUNT_TIME) - game_time))
		{
			Food_info.uketori[i] = true;
		}
		else if (Food_info.uketori[i] == true) // �������󂯎����
		{
			Random.kirikae_time[i] = ((GAME_TIME + COUNT_TIME) - game_time); // �؂�ւ����ԍX�V
		}
		// �󂯎�蔻�肪�I��
		if (Food_info.uketori[i] == true)
		{
			if (Random.pre_num_hantei[i])
			{
				// �ЂƂO�̗������W����
				ryouri_pre_pos_Update(i);
			}
			// �����_���ϐ��X�V
			random_Update(i);
			// �����̕\�����W�X�V
			food_pos_Update(i, Random.num[i], &Food_pos[i]);
			// �����̒l�i�\�����W�X�V
			food_nedan_pos_Update(i, Random.num[i], &Food_nedan_pos[i]);
			// �����̗ʕ\��AA�X�V
			ryouri_amount_AA_Update(i);
			// �󂯎�蔻��I�t
			Food_info.uketori[i] = false;
			// �؂�ւ�����I��
			Food_kirikae.hantei[i] = true;
			// ������\������X�N���[���̔���I��
			Food_kirikae.scroll_hantei[i] = true;

			if (!Random.pre_num_hantei[i]) // �ŏ���1��
			{
				// �ЂƂO�̗������W����
				ryouri_pre_pos_Update(i);
				// �ЂƂO�̗�������͂��锻��I��
				Random.pre_num_hantei[i] = true;
			}
		}
		if ((Food_kirikae.y[i] == -5 && i < 3) ||
			(Food_kirikae.y[i] == 5 && i >= 3))
		{
			// �X�N���[������؂�ւ�
			Food_kirikae.scroll_hantei[i] = false;
		}
		else if (Food_kirikae.y[i] == 0 && !Food_kirikae.scroll_hantei[i])
		{
			// �؂�ւ�����I�t
			Food_kirikae.hantei[i] = false;
		}
		if (Food_kirikae.hantei[i])
		{
			//�؂�ւ��X�N���[���Ԋu�v���p�̎��ԍX�V
			Food_kirikae.scroll_time[i] += 1;
		}
		else
		{
			// �؂�ւ��X�N���[���Ԋu�v���p�̎��ԏ�����
			Food_kirikae.scroll_time[i] = 0;
		}
	}
}

void food_Draw(void)
{
	for (int i = 0; i < 6; i++)
	{
		// �؂�ւ�����I���Ȃ�
		if (Food_kirikae.hantei[i] == true)
		{
			// �ŏ���1��
			if (Food_kirikae.scroll_time[i] == 1)
			{
				// �����̎c����������
				ryouri_kuhaku_Draw(i, false);
				// �����\��
				print_x_y_one(Food_pre_pos[i].x, Food_pre_pos[i].y, 
					Food[Random.pre_num[i]].name, Food[Random.pre_num[i]].color);
				// �����̒l�i�\��
				gotoxy(Food_nedan_pre_pos[i].x, Food_nedan_pre_pos[i].y);
				printf("\\");
				print_x_y_one_num(Food_nedan_pre_pos[i].x + 2, Food_nedan_pre_pos[i].y,
					Food[Random.pre_num[i]].nedan, WHITE);
				// �����؂�ւ����\��
				print_x_y_one(Food_amount_pos[i].x,
					Food_amount_pos[i].y,
					AA_URIKIRE[0], YELLOW);
			}
			if (Food_kirikae.scroll_time[i] % 8 == 0)
			{
				// �����̎c����������
				ryouri_kuhaku_Draw(i, true);

				if (Food_kirikae.scroll_hantei[i])
				{
					if (i < 3)
					{
						Food_kirikae.y[i] -= 1;
						if (Food_kirikae.y[i] >= -3)
						{
							// �����̒l�i�\��
							gotoxy(Food_nedan_pre_pos[i].x, 
								Food_nedan_pre_pos[i].y + Food_kirikae.y[i]);
							printf("\\");
							print_x_y_one_num(Food_nedan_pre_pos[i].x + 2, 
								Food_nedan_pre_pos[i].y + Food_kirikae.y[i],
								Food[Random.pre_num[i]].nedan, WHITE);
						}
					}
					else
					{
						Food_kirikae.y[i] += 1;
						if (Food_kirikae.y[i] <= 3)
						{
							// �����\��
							print_x_y_one(Food_pre_pos[i].x, Food_pre_pos[i].y + Food_kirikae.y[i],
								Food[Random.pre_num[i]].name, Food[Random.pre_num[i]].color);
						}
					}
				}
				else
				{
					if (i < 3)
					{
						Food_kirikae.y[i] += 1;
						if (Food_kirikae.y[i] >= -3)
						{
							// �����̒l�i�\��
							gotoxy(Food_nedan_pos[i].x,
								Food_nedan_pos[i].y + Food_kirikae.y[i]);
							printf("\\");
							print_x_y_one_num(Food_nedan_pos[i].x + 2,
								Food_nedan_pos[i].y + Food_kirikae.y[i],
								Food[Random.num[i]].nedan, WHITE);
						}
					}
					else
					{
						Food_kirikae.y[i] -= 1;
						if (Food_kirikae.y[i] <= 3)
						{
							// �����\��
							print_x_y_one(Food_pos[i].x, Food_pos[i].y + Food_kirikae.y[i],
								Food[Random.num[i]].name, Food[Random.num[i]].color);
						}
					}

				}
				if (Food_kirikae.y[i] == 0) // �\���I��
				{
					// �����̎c����������
					ryouri_kuhaku_Draw(i, false);
					// �����\��
					print_x_y_one(Food_pos[i].x, Food_pos[i].y,
						Food[Random.num[i]].name, Food[Random.num[i]].color);
					// �����̒l�i�\��
					gotoxy(Food_nedan_pos[i].x, Food_nedan_pos[i].y);
					printf("\\");
					print_x_y_one_num(Food_nedan_pos[i].x + 2, Food_nedan_pos[i].y,
						Food[Random.num[i]].nedan, WHITE);
					// �����̗ʕ\��
					print_x_y_one(Food_amount_pos[i].x,
						Food_amount_pos[i].y, Food_info.p[i], RYOURI_HAVE_COLOR_2);
				}
			}
		}
	}
}

//---------------------------------------------------------
// ��������(1��̂�)
//---------------------------------------------------------
void random_Init(void)
{
	srand((unsigned int)time(NULL));// �����̎평����;

	for (int i = 0; i < 6; i++)
	{
		Random.kirikae_time[i] = 0;
	}
}

//---------------------------------------------------------
// ��������
//---------------------------------------------------------
void random_Update(int i)
{
	// �����̐؂�ւ�����
	Random.kirikae_time[i] += (rand() % 4001) + 5000;
	// �����_���ȗ��������
	Random.num[i] = rand() % (sizeof(Food) / sizeof(Food[0]));
}

//---------------------------------------------------------
// �ЂƂO�̗������W����
//---------------------------------------------------------
void ryouri_pre_pos_Update(int i)
{
	// �ЂƂO�̃����_���ϐ�����
	Random.pre_num[i] = Random.num[i];
	// �ЂƂO�̗����̕\�����W����
	food_pos_Update(i, Random.pre_num[i], &Food_pre_pos[i]);
	// �ЂƂO�̗����̒l�i�\�����W����
	food_nedan_pos_Update(i, Random.pre_num[i], &Food_nedan_pre_pos[i]);
}
//---------------------------------------------------------
// �����̕\�����W����(i = i, j = random�ϐ�)
//---------------------------------------------------------
void food_pos_Update(int i, int j, OTHER_POS* p)
{
	int x = 0;
	int y = 0;

	x = (((AA_waku_yoko - 4) -
		strlen(Food[j].name)) / 2);
	switch (i)
	{
	case 0:
	case 3:
		x += RYOURI_WAKU_1_4_POS_X + 2;

		break;
	case 1:
	case 4:
		x += RYOURI_WAKU_2_5_POS_X + 2;
		break;
	case 2:
	case 5:
		x += RYOURI_WAKU_3_6_POS_X + 2;
		break;
	default:
		break;
	}
	if (i < 3)
	{
		y = 1;
	}
	else
	{
		y = ((SCREEN_Y + 1) - AA_waku_tate) + 1;
	}

	p->x = x;
	p->y = y;
}

//---------------------------------------------------------
// �����̋󔒕\�����W����
//---------------------------------------------------------
void food_kuhaku_pos_Init(void)
{
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
		case 3:
			Food_kuhaku_pos[i].x = RYOURI_WAKU_1_4_POS_X + 2;

			break;
		case 1:
		case 4:
			Food_kuhaku_pos[i].x = RYOURI_WAKU_2_5_POS_X + 2;
			break;
		case 2:
		case 5:
			Food_kuhaku_pos[i].x = RYOURI_WAKU_3_6_POS_X + 2;
			break;
		default:
			break;
		}
		if (i < 3)
		{
			Food_kuhaku_pos[i].y = 1;
		}
		else
		{
			Food_kuhaku_pos[i].y = ((SCREEN_Y + 1) - AA_waku_tate) + 1;
		}
	}	
}

//---------------------------------------------------------
// �c�������󔒕\��
//---------------------------------------------------------
void ryouri_kuhaku_Draw (int i, bool ue)
{
	if (ue)
	{
		for (int j = 0; j < (AA_waku_tate - 1) - 1; j++)
		{
			for (int k = 0; k < AA_waku_yoko - 4; k++)
			{
				gotoxy(Food_kuhaku_pos[i].x + k, Food_kuhaku_pos[i].y + j);
				printf(" ");
			}
		}
	}
	else
	{
		for (int j = 0; j < AA_waku_yoko - 4; j++)
		{
			gotoxy(Food_kuhaku_pos[i].x + j, (Food_kuhaku_pos[i].y + AA_waku_tate) - 2);
			printf(" ");
		}
	}
}

//---------------------------------------------------------
// �����̒l�i�\�����W�X�V(i = i, j = Random�ϐ�)
//---------------------------------------------------------
void food_nedan_pos_Update(int i, int j, OTHER_POS* p)
{
	int x = 0;
	int y = 0;

	switch (i)
	{
	case 0:
	case 3:
		x = RYOURI_WAKU_1_4_POS_X + 2;
		break;
	case 1:
	case 4:
		x = RYOURI_WAKU_2_5_POS_X + 2;
		break;
	case 2:
	case 5:
		x = RYOURI_WAKU_3_6_POS_X + 2;
		break;
	default:
		break;
	}
	// �^�񒆂�ւ�ɕ\�������悤�ɒ���
	if ((Food[j].nedan % 10) < 10)
	{
		x += (((AA_waku_yoko - 4) - 4) / 2);
	}
	else if ((Food[j].nedan % 10) < 100)
	{
		x += (((AA_waku_yoko - 4) - 5) / 2);
	}
	else if ((Food[j].nedan % 10) < 1000)
	{
		x += (((AA_waku_yoko - 4) - 6) / 2);
	}
	else
	{
		x += (((AA_waku_yoko - 4) - 7) / 2);
	}
	if (i < 3)
	{
		y = 4;
	}
	else
	{
		y = ((SCREEN_Y + 1) - AA_waku_tate) + 4;
	}
	p->x = x;
	p->y = y;
}

//---------------------------------------------------------
// �����̗ʕ\�����W����
//---------------------------------------------------------
void food_amount_pos_Init(void)
{
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
		case 3:
			Food_amount_pos[i].x = RYOURI_WAKU_1_4_POS_X + 2;
			break;
		case 1:
		case 4:
			Food_amount_pos[i].x = RYOURI_WAKU_2_5_POS_X + 2;
			break;
		case 2:
		case 5:
			Food_amount_pos[i].x = RYOURI_WAKU_3_6_POS_X + 2;
			break;
		default:
			break;
		}
		if (i < 3)
		{
			Food_amount_pos[i].y = 5;
		}
		else
		{
			Food_amount_pos[i].y = ((SCREEN_Y + 1) - AA_waku_tate) + 5;
		}
	}
}
//---------------------------------------------------------
// �����̗ʕ\��AA�X�V
//---------------------------------------------------------
void ryouri_amount_AA_Update(int i)
{
	switch (Food[Random.num[i]].amount) 
	{
	case 1:
		Food_info.p[i] = AA_AMOUNT_0[0];
		break;
	case 2:
		Food_info.p[i] = AA_AMOUNT_1[0];
		break;
	case 3:
		Food_info.p[i] = AA_AMOUNT_2[0];
		break;
	case 4:
		Food_info.p[i] = AA_AMOUNT_3[0];
		break;
	case 5:
		Food_info.p[i] = AA_AMOUNT_4[0];
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
// �����̗ʂ�Ԃ�(game.cpp�p)
//---------------------------------------------------------
const int ryouri_amount(int i)
{
	return Food[Random.num[i]].amount;
}

//---------------------------------------------------------
// �������󂯎�������̏���(game.cpp�p)
//---------------------------------------------------------
const int ryouri_uketori(int i)
{
	Food_info.uketori[i] = true;

	return Random.num[i];
}

//---------------------------------------------------------
// �����̖��O��Ԃ�(game.cpp�p)
//---------------------------------------------------------
const char* ryouri_name(int i)
{
	return Food[i].name;
}

//---------------------------------------------------------
// �����̒l�i��Ԃ�(game.cpp�p)
//---------------------------------------------------------
const int ryouri_nedan(int i)
{
	return Food[i].nedan;
}

//---------------------------------------------------------
// �����̐؂�ւ���Ԃ�Ԃ�(game.cpp�p)
//---------------------------------------------------------
const bool ryouri_kirikae_hantei(int i)
{
	return Food_kirikae.hantei[i];
}

//---------------------------------------------------------
// �����̐؂�ւ���Ԃ�Ԃ�(game.cpp�p)
//---------------------------------------------------------
const int ryouri_color(int i)
{
	return Food[i].color;
}