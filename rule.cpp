// ���[�������p

#define CONIOEX
#include "rule.h"
#include "game.h"
#include "main.h"
#include "SOUND.h"

// �\���̕ϐ��錾
OTHER_POS AA_rule_pos[3];
AA_SIZE AA_rule_size[3];

//---------------------------------------------------------
// ���[��������AA
//---------------------------------------------------------
const char* AA_rule[] =
{
	"�@�@�@�@�@�@�@�@�@�@======================================�@�@�@�@�@�@�@�@�@�@",
	"�@�@�@�@�@�@�@�@�@�@+             ���[������             +�@�@�@�@�@�@�@�@�@�@",
	"�@�@�@�@�@�@�@�@�@�@======================================�@�@�@�@�@�@�@�@�@�@",
	NULL
};
const char* AA_rule_text_1[] =
{
	"      ���̃Q�[���̖ڕW�́A���]�[�g�z�e���̍����o�C�L���O�̗�����              ",
	"                                                                              ",
	"              �������ԓ��ɍ������̂�H���A��肨���ɂȂ낤�Ƃ������̂ł��B    ",
	"                                                                              ",
	"                                                                              ",
	"                 --------------�ׂ������[������--------------                 ",
	"                                                                              ",
	"            ���̈�  �������Ԃ�60�b�B                                          ",
	"                                                                              ",
	"            ���̓�  �����̑O��SPACE�L�[�@or�@ENTER�L�[�Ŏ󂯎��B            ",
	"                                                                              ",
	"            ���̎Q  �e�[�u���ɐG��ė�����H�ׂ�B                            ",
	"                                                                              ",
	"            ������  �ΐF�͎󂯎��A�ԐF�͎󂯎��s�B                    ",
	"                                                                              ",
	"            ���̌ށ@�����̎��Ă���E�͐����T�܂�                          ",
	"                                                                              ",
	"                       --------------�ڈ�--------------                       ",
	"                                                                              ",
	"    \\ 40000�` :               \\ 25000�` :           \\ 10000�` :            ",
	NULL
};
const char* AA_rule_text_2[] =
{
	"���]�[�g�z�e��",
	"�����ɂȂ낤",
	"60�b",
	"�ΐF�͎󂯎���",
	"�ԐF�͎󂯎��s��",
	"�����T��",
	"���[�Ȃ��I�I",
	"�����I�I",
	"��������",
	"�l�X�Ȏ�ނ̗���",
	NULL
};
const char* AA_rule_text_3[] =
{
	"�� �^�C�g���ɖ߂� ��",
	NULL
};
const char* AA_rule_neko[] = {
	"==========================",
	"||                      ||",
	"||  �l�X�Ȏ�ނ̗�����  ||",
	"||                      ||",
	"||     �����\����!!     ||",
	"||                      ||",
	"==========================",
	"            ||��,,��      ",
	"            ||�E�ցE)     ",
	"           O�P�P�P��)     ",
	"             �Z   �Z      ",
	NULL
};

//---------------------------------------------------------
// �O���[�o���ϐ��錾
//---------------------------------------------------------
bool draw_one = true; // 1��̂ݕ\���̔���

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------
void rule_Init(void)
{
	system("cls");
	// �J�[�\����\��
	setcursortype(NOCURSOR);
	// ���菉����
	draw_one = true;
	// AA�̃T�C�Y����
	AA_size_input(AA_rule, AA_rule_size, 0);
	AA_size_input(AA_rule_text_1, AA_rule_size, 1);
	AA_size_input(AA_rule_text_3, AA_rule_size, 2);
	// AA�̍��W����
	AA_rule_pos[0].x = ((SCREEN_X + 1) - AA_rule_size[0].yoko) / 2;
	AA_rule_pos[0].y = 2;
	AA_rule_pos[1].x = ((SCREEN_X + 1) - AA_rule_size[1].yoko) / 2;
	AA_rule_pos[1].y = AA_rule_pos[0].y + AA_rule_size[0].tate + 2;
	AA_rule_pos[2].x = ((SCREEN_X + 1) - AA_rule_size[2].yoko) / 2;
	AA_rule_pos[2].y = (SCREEN_Y + 1) - 2;
	// ���y
	SoundPlayLoop(SOUND_RULE_BGM);
}

void rule_End(void)
{
	SoundStop(SOUND_RULE_BGM);
	scene_kirikae(1);
}

void rule_Update(void)
{
	if (inport(PK_SP) || inport(PK_ENTER))
	{
		// ���y
		SoundPlayOnce(SOUND_KETTEI);
		scene_kirikae_hantei_on();
	}
}

void rule_Draw(void)
{
	if (draw_one)
	{
		// ���U���g����
		print_x_y_all(AA_rule_pos[0].x, AA_rule_pos[0].y, AA_rule, YELLOW);
		// �e�L�X�g�P
		print_x_y_all(AA_rule_pos[1].x, AA_rule_pos[1].y, AA_rule_text_1, WHITE);
		// �F�t��
		print_x_y_one(AA_rule_pos[1].x + 26, AA_rule_pos[1].y, AA_rule_text_2[0], RED);
		print_x_y_one(AA_rule_pos[1].x + 46, AA_rule_pos[1].y + 2, AA_rule_text_2[1], RED);
		print_x_y_one(AA_rule_pos[1].x + 30, AA_rule_pos[1].y + 7, AA_rule_text_2[2], LIGHTBLUE);
		print_x_y_one(AA_rule_pos[1].x + 20, AA_rule_pos[1].y + 13, AA_rule_text_2[3], GREEN);
		print_x_y_one(AA_rule_pos[1].x + 38, AA_rule_pos[1].y + 13, AA_rule_text_2[4], RED);
		print_x_y_one(AA_rule_pos[1].x + 38, AA_rule_pos[1].y + 15, AA_rule_text_2[5], LIGHTBLUE);
		print_x_y_one(AA_rule_pos[1].x + 16, AA_rule_pos[1].y + 19, AA_rule_text_2[6], RED);
		print_x_y_one(AA_rule_pos[1].x + 42, AA_rule_pos[1].y + 19, AA_rule_text_2[7], YELLOW);
		print_x_y_one(AA_rule_pos[1].x + 64, AA_rule_pos[1].y + 19, AA_rule_text_2[8], WHITE);
		// �l�R
		print_x_y_all(AA_rule_pos[1].x + 72, AA_rule_pos[1].y + 11, AA_rule_neko, WHITE);
		print_x_y_one(AA_rule_pos[1].x + 76, AA_rule_pos[1].y + 13, AA_rule_text_2[9], LIGHTGREEN);

		textbackground(GREEN);
		print_x_y_one(AA_rule_pos[2].x, AA_rule_pos[2].y, AA_rule_text_3[0], YELLOW);
		textbackground(BLACK);
		draw_one = false;
	}
}

