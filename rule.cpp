// ルール説明用

#define CONIOEX
#include "rule.h"
#include "game.h"
#include "main.h"
#include "SOUND.h"

// 構造体変数宣言
OTHER_POS AA_rule_pos[3];
AA_SIZE AA_rule_size[3];

//---------------------------------------------------------
// ルール説明のAA
//---------------------------------------------------------
const char* AA_rule[] =
{
	"　　　　　　　　　　======================================　　　　　　　　　　",
	"　　　　　　　　　　+             ルール説明             +　　　　　　　　　　",
	"　　　　　　　　　　======================================　　　　　　　　　　",
	NULL
};
const char* AA_rule_text_1[] =
{
	"      このゲームの目標は、リゾートホテルの高級バイキングの料理で              ",
	"                                                                              ",
	"              制限時間内に高いものを食し、よりお得になろうというものです。    ",
	"                                                                              ",
	"                                                                              ",
	"                 --------------細かいルール説明--------------                 ",
	"                                                                              ",
	"            その壱  制限時間は60秒。                                          ",
	"                                                                              ",
	"            その弐  料理の前でSPACEキー　or　ENTERキーで受け取り。            ",
	"                                                                              ",
	"            その参  テーブルに触れて料理を食べる。                            ",
	"                                                                              ",
	"            その肆  緑色は受け取り可、赤色は受け取り不可。                    ",
	"                                                                              ",
	"            その伍　料理の持てる限界は青い●５つまで                          ",
	"                                                                              ",
	"                       --------------目安--------------                       ",
	"                                                                              ",
	"    \\ 40000～ :               \\ 25000～ :           \\ 10000～ :            ",
	NULL
};
const char* AA_rule_text_2[] =
{
	"リゾートホテル",
	"お得になろう",
	"60秒",
	"緑色は受け取り可",
	"赤色は受け取り不可",
	"青い●５つ",
	"半端ない！！",
	"凄い！！",
	"そこそこ",
	"様々な種類の料理",
	NULL
};
const char* AA_rule_text_3[] =
{
	"■ タイトルに戻る ■",
	NULL
};
const char* AA_rule_neko[] = {
	"==========================",
	"||                      ||",
	"||  様々な種類の料理を  ||",
	"||                      ||",
	"||     ご堪能あれ!!     ||",
	"||                      ||",
	"==========================",
	"            ||∧,,∧      ",
	"            ||・ω・)     ",
	"           O￣￣￣⊂)     ",
	"             〇   〇      ",
	NULL
};

//---------------------------------------------------------
// グローバル変数宣言
//---------------------------------------------------------
bool draw_one = true; // 1回のみ表示の判定

//---------------------------------------------------------
// 関数定義
//---------------------------------------------------------
void rule_Init(void)
{
	system("cls");
	// カーソル非表示
	setcursortype(NOCURSOR);
	// 判定初期化
	draw_one = true;
	// AAのサイズ入力
	AA_size_input(AA_rule, AA_rule_size, 0);
	AA_size_input(AA_rule_text_1, AA_rule_size, 1);
	AA_size_input(AA_rule_text_3, AA_rule_size, 2);
	// AAの座標入力
	AA_rule_pos[0].x = ((SCREEN_X + 1) - AA_rule_size[0].yoko) / 2;
	AA_rule_pos[0].y = 2;
	AA_rule_pos[1].x = ((SCREEN_X + 1) - AA_rule_size[1].yoko) / 2;
	AA_rule_pos[1].y = AA_rule_pos[0].y + AA_rule_size[0].tate + 2;
	AA_rule_pos[2].x = ((SCREEN_X + 1) - AA_rule_size[2].yoko) / 2;
	AA_rule_pos[2].y = (SCREEN_Y + 1) - 2;
	// 音楽
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
		// 音楽
		SoundPlayOnce(SOUND_KETTEI);
		scene_kirikae_hantei_on();
	}
}

void rule_Draw(void)
{
	if (draw_one)
	{
		// リザルト文字
		print_x_y_all(AA_rule_pos[0].x, AA_rule_pos[0].y, AA_rule, YELLOW);
		// テキスト１
		print_x_y_all(AA_rule_pos[1].x, AA_rule_pos[1].y, AA_rule_text_1, WHITE);
		// 色付け
		print_x_y_one(AA_rule_pos[1].x + 26, AA_rule_pos[1].y, AA_rule_text_2[0], RED);
		print_x_y_one(AA_rule_pos[1].x + 46, AA_rule_pos[1].y + 2, AA_rule_text_2[1], RED);
		print_x_y_one(AA_rule_pos[1].x + 30, AA_rule_pos[1].y + 7, AA_rule_text_2[2], LIGHTBLUE);
		print_x_y_one(AA_rule_pos[1].x + 20, AA_rule_pos[1].y + 13, AA_rule_text_2[3], GREEN);
		print_x_y_one(AA_rule_pos[1].x + 38, AA_rule_pos[1].y + 13, AA_rule_text_2[4], RED);
		print_x_y_one(AA_rule_pos[1].x + 38, AA_rule_pos[1].y + 15, AA_rule_text_2[5], LIGHTBLUE);
		print_x_y_one(AA_rule_pos[1].x + 16, AA_rule_pos[1].y + 19, AA_rule_text_2[6], RED);
		print_x_y_one(AA_rule_pos[1].x + 42, AA_rule_pos[1].y + 19, AA_rule_text_2[7], YELLOW);
		print_x_y_one(AA_rule_pos[1].x + 64, AA_rule_pos[1].y + 19, AA_rule_text_2[8], WHITE);
		// ネコ
		print_x_y_all(AA_rule_pos[1].x + 72, AA_rule_pos[1].y + 11, AA_rule_neko, WHITE);
		print_x_y_one(AA_rule_pos[1].x + 76, AA_rule_pos[1].y + 13, AA_rule_text_2[9], LIGHTGREEN);

		textbackground(GREEN);
		print_x_y_one(AA_rule_pos[2].x, AA_rule_pos[2].y, AA_rule_text_3[0], YELLOW);
		textbackground(BLACK);
		draw_one = false;
	}
}

