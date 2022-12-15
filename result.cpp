// ���ʕ\��

#define CONIOEX

#include "result.h"
#include "game.h"
#include "main.h"
#include "SOUND.h"

// �\���̕ϐ��錾
AA_SIZE AA_result_size;
AA_SIZE AA_kingaku_size;
AA_SIZE AA_title_modoru_size;
OTHER_POS AA_result_pos;
OTHER_POS AA_kingaku_pos;
OTHER_POS AA_title_modoru_pos;
OTHER_POS Ryouri_name_pos;
RESULT Result;

//---------------------------------------------------------
// ���U���g��AA
//---------------------------------------------------------
// ���ʔ��\
const char* AA_result[] = {
	"=======================================",
	"+       ��     ��     ��     �\       +",
	"=======================================",
	NULL
};
// ���v���z
const char* AA_kingaku[] = {
	"     ���v���z        \\                 ",
	"  -  �o�C�L���O��    \\ 20000           ",
	"�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\",
	"             \\                         ",
	NULL
}; 
// �^�C�g���ɖ߂�
const char* AA_title_modoru[] = {
	"�� �^�C�g���ɖ߂� ��",
	NULL
};

//---------------------------------------------------------
// �O���[�o���ϐ��錾
//---------------------------------------------------------
static bool draw_one = true;		// �ŏ��̂P��̂ݕ\���̔���p
static bool end = false;			// �I������p
static int time = 0;				// ���Ԍv���p
static int color = 0;				// �����̐F���͗p

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------

void result_Init(void)
{
	clrscr();
	// �J�[�\����\��
	setcursortype(NOCURSOR);
	// ������
	Result = {};
	Result.name_hyouji = true;
	draw_one = true;
	end = false;
	time = 0;
	// AA�T�C�Y����
	AA_result_size.tate = AA_size_tate(AA_result);
	AA_result_size.yoko = AA_size_yoko(AA_result);
	AA_kingaku_size.tate = AA_size_tate(AA_kingaku);
	AA_kingaku_size.yoko = AA_size_yoko(AA_kingaku);
	AA_title_modoru_size.tate = AA_size_tate(AA_title_modoru);
	AA_title_modoru_size.yoko = AA_size_yoko(AA_title_modoru);
	// AA���W����
	AA_result_pos.x = ((SCREEN_X + 1) - AA_result_size.yoko) / 2;
	AA_result_pos.y = 2;
	AA_kingaku_pos.x = ((SCREEN_X + 1) - AA_kingaku_size.yoko) / 2;
	AA_kingaku_pos.y = 24;
	AA_title_modoru_pos.x = ((SCREEN_X + 1) - AA_title_modoru_size.yoko) / 2;
	AA_title_modoru_pos.y = 29;
	// �H�ׂ������\���̍��W����
	Ryouri_name_pos.x = RYOURI_NAME_POS_X;
	Ryouri_name_pos.y = RYOURI_NAME_POS_Y;
	// �H�ׂ������̐�����
	Result.eat_ryouri_num = eat_ryouri_num();
	// ���y
	SoundPlayLoop(SOUND_RESULT_BGM);
}

void result_End(void)
{
	SoundStop(SOUND_RESULT_BGM);
	scene_kirikae(1);
}

void result_Update(void)
{
	// �H�ׂ�������S�ĕ\��������
	if ((Result.eat_ryouri_num <= Result.ryouri_num) && Result.name_hyouji)
	{
		// �H�ׂ������̕\���I��
		Result.name_hyouji = false;
		// �����̍��v���z����
		if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) < 0)
		{
			color = LIGHTBLUE;
		}
		else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) > 0)
		{
			color = RED;
		}
		else
		{
			color = WHITE;
		}

		time = 0;
	}
	else if (Result.name_hyouji || (!Result.name_hyouji && time < 500))
	{
		time += 1; // ���� +1
	}
		
	if ((time % 30) == 0 && Result.name_hyouji)
	{
		strcpy(Result.eat_ryouri_name, eat_ryouri_name(Result.ryouri_num));
		Result.eat_ryouri_nedan = eat_ryouri_nedan(Result.ryouri_num);
		Result.eat_ryouri_goukei += Result.eat_ryouri_nedan;
		Result.eat_ryouri_color = eat_ryouri_color(Result.ryouri_num);
		Result.ryouri_num += 1;
		// ���y
		SoundPlayOnce(SOUND_OKANE);
	}
	if (end)
	{
		if (inport(PK_ENTER) || inport(PK_SP))
		{
			// ���y
			SoundPlayOnce(SOUND_KETTEI);
			scene_kirikae_hantei_on();
		}
	}
}

void result_Draw(void)
{
	if (draw_one)
	{
		// ���ʔ��\��AA�\��
		print_x_y_all(AA_result_pos.x, AA_result_pos.y, AA_result, YELLOW);
		draw_one = false;
	}
	if ((time % 30) == 0 && Result.name_hyouji)
	{
		int x = 0; // �H�ׂ������̕\��X���W�̒����p
		for (int i = 2; i <= 14; i = i + 2)
		{
			if ((int)strlen(Result.eat_ryouri_name) <= i)
			{
				x += 1;
			}
		}
		// �H�ׂ������̖��O�\��
		print_x_y_one((Ryouri_name_pos.x + x), Ryouri_name_pos.y,
			Result.eat_ryouri_name, Result.eat_ryouri_color);
		// �H�ׂ������̒l�i�\��
		gotoxy(Ryouri_name_pos.x + 5, Ryouri_name_pos.y + 1);
		printf("\\ %d\n", Result.eat_ryouri_nedan);
		if (!(Ryouri_name_pos.x + 17 + 12 + RYOURI_NAME_POS_X > (SCREEN_X + 1)))
		{
			Ryouri_name_pos.x += 17;
		}
		else
		{
			Ryouri_name_pos.x = RYOURI_NAME_POS_X;
			Ryouri_name_pos.y += 2;
		}
	}
	if (!Result.name_hyouji)
	{
		// ���v���z��AA�\��
		switch (time)
		{
		case 60:
			print_x_y_one(AA_kingaku_pos.x, AA_kingaku_pos.y, AA_kingaku[0], WHITE);
			break;
		case 120:
			// ���y
			SoundPlayOnce(SOUND_OKANE);
			gotoxy(AA_kingaku_pos.x + 23, AA_kingaku_pos.y);
			printf("%d", Result.eat_ryouri_goukei);
			break;
		case 180:
			// ���y
			SoundPlayOnce(SOUND_OKANE);
			print_x_y_one(AA_kingaku_pos.x, AA_kingaku_pos.y + 1, AA_kingaku[1], WHITE);		
			break;
		case 240:
			print_x_y_one(AA_kingaku_pos.x, AA_kingaku_pos.y + 2, AA_kingaku[2], WHITE);
			break;
		case 300:
			print_x_y_one(AA_kingaku_pos.x, AA_kingaku_pos.y + 3, AA_kingaku[3], color);
			break;
		case 370:
			// ���y
			SoundPlayOnce(SOUND_OKANE);
			textcolor(color);
			gotoxy(AA_kingaku_pos.x + 15, AA_kingaku_pos.y + 3);
			switch (color)
			{
			case LIGHTBLUE:
				printf("%d          ������...", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				break;
			case RED:
				if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 5000)
				{
					printf("%d          ���͎�����I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 10000)
				{
					printf("%d          �z�e���̗����͔������I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 15000)
				{
					printf("%d          ���\�H�ׂ����I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 20000)
				{
					printf("%d          �������[�[�I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 25000)
				{
					printf("%d          �������[�[�I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 30000)
				{
					printf("%d          ����Ȃɂ����ɂȂ��ėǂ��̂��H", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 35000)
				{
					printf("%d          ���ꂾ�������Ȃ當��Ȃ��I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 40000)
				{
					printf("%d          �����H�ޑ���肾�I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else
				{
					printf("%d          �z�e���j�Y�����I�I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				break;
			case WHITE:
				printf("%d          �v���}�C�[���I", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				break;
			default:
				break;
			}
			textcolor(WHITE);
			break;
		case 400:
			textbackground(GREEN);
			print_x_y_one(AA_title_modoru_pos.x, AA_title_modoru_pos.y, AA_title_modoru[0], YELLOW);
			textbackground(BLACK);
			end = true;
			break;
		default:
			break;
		}
	}
}