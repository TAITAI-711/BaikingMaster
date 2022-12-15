// 結果表示

#define CONIOEX

#include "result.h"
#include "game.h"
#include "main.h"
#include "SOUND.h"

// 構造体変数宣言
AA_SIZE AA_result_size;
AA_SIZE AA_kingaku_size;
AA_SIZE AA_title_modoru_size;
OTHER_POS AA_result_pos;
OTHER_POS AA_kingaku_pos;
OTHER_POS AA_title_modoru_pos;
OTHER_POS Ryouri_name_pos;
RESULT Result;

//---------------------------------------------------------
// リザルトのAA
//---------------------------------------------------------
// 結果発表
const char* AA_result[] = {
	"=======================================",
	"+       結     果     発     表       +",
	"=======================================",
	NULL
};
// 合計金額
const char* AA_kingaku[] = {
	"     合計金額        \\                 ",
	"  -  バイキング代    \\ 20000           ",
	"――――――――――――――――――――",
	"             \\                         ",
	NULL
}; 
// タイトルに戻る
const char* AA_title_modoru[] = {
	"■ タイトルに戻る ■",
	NULL
};

//---------------------------------------------------------
// グローバル変数宣言
//---------------------------------------------------------
static bool draw_one = true;		// 最初の１回のみ表示の判定用
static bool end = false;			// 終了判定用
static int time = 0;				// 時間計測用
static int color = 0;				// 文字の色入力用

//---------------------------------------------------------
// 関数定義
//---------------------------------------------------------

void result_Init(void)
{
	clrscr();
	// カーソル非表示
	setcursortype(NOCURSOR);
	// 初期化
	Result = {};
	Result.name_hyouji = true;
	draw_one = true;
	end = false;
	time = 0;
	// AAサイズ入力
	AA_result_size.tate = AA_size_tate(AA_result);
	AA_result_size.yoko = AA_size_yoko(AA_result);
	AA_kingaku_size.tate = AA_size_tate(AA_kingaku);
	AA_kingaku_size.yoko = AA_size_yoko(AA_kingaku);
	AA_title_modoru_size.tate = AA_size_tate(AA_title_modoru);
	AA_title_modoru_size.yoko = AA_size_yoko(AA_title_modoru);
	// AA座標入力
	AA_result_pos.x = ((SCREEN_X + 1) - AA_result_size.yoko) / 2;
	AA_result_pos.y = 2;
	AA_kingaku_pos.x = ((SCREEN_X + 1) - AA_kingaku_size.yoko) / 2;
	AA_kingaku_pos.y = 24;
	AA_title_modoru_pos.x = ((SCREEN_X + 1) - AA_title_modoru_size.yoko) / 2;
	AA_title_modoru_pos.y = 29;
	// 食べた料理表示の座標入力
	Ryouri_name_pos.x = RYOURI_NAME_POS_X;
	Ryouri_name_pos.y = RYOURI_NAME_POS_Y;
	// 食べた料理の数入力
	Result.eat_ryouri_num = eat_ryouri_num();
	// 音楽
	SoundPlayLoop(SOUND_RESULT_BGM);
}

void result_End(void)
{
	SoundStop(SOUND_RESULT_BGM);
	scene_kirikae(1);
}

void result_Update(void)
{
	// 食べた料理を全て表示したら
	if ((Result.eat_ryouri_num <= Result.ryouri_num) && Result.name_hyouji)
	{
		// 食べた料理の表示終了
		Result.name_hyouji = false;
		// 料理の合計金額判定
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
		time += 1; // 時間 +1
	}
		
	if ((time % 30) == 0 && Result.name_hyouji)
	{
		strcpy(Result.eat_ryouri_name, eat_ryouri_name(Result.ryouri_num));
		Result.eat_ryouri_nedan = eat_ryouri_nedan(Result.ryouri_num);
		Result.eat_ryouri_goukei += Result.eat_ryouri_nedan;
		Result.eat_ryouri_color = eat_ryouri_color(Result.ryouri_num);
		Result.ryouri_num += 1;
		// 音楽
		SoundPlayOnce(SOUND_OKANE);
	}
	if (end)
	{
		if (inport(PK_ENTER) || inport(PK_SP))
		{
			// 音楽
			SoundPlayOnce(SOUND_KETTEI);
			scene_kirikae_hantei_on();
		}
	}
}

void result_Draw(void)
{
	if (draw_one)
	{
		// 結果発表のAA表示
		print_x_y_all(AA_result_pos.x, AA_result_pos.y, AA_result, YELLOW);
		draw_one = false;
	}
	if ((time % 30) == 0 && Result.name_hyouji)
	{
		int x = 0; // 食べた料理の表示X座標の調整用
		for (int i = 2; i <= 14; i = i + 2)
		{
			if ((int)strlen(Result.eat_ryouri_name) <= i)
			{
				x += 1;
			}
		}
		// 食べた料理の名前表示
		print_x_y_one((Ryouri_name_pos.x + x), Ryouri_name_pos.y,
			Result.eat_ryouri_name, Result.eat_ryouri_color);
		// 食べた料理の値段表示
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
		// 合計金額のAA表示
		switch (time)
		{
		case 60:
			print_x_y_one(AA_kingaku_pos.x, AA_kingaku_pos.y, AA_kingaku[0], WHITE);
			break;
		case 120:
			// 音楽
			SoundPlayOnce(SOUND_OKANE);
			gotoxy(AA_kingaku_pos.x + 23, AA_kingaku_pos.y);
			printf("%d", Result.eat_ryouri_goukei);
			break;
		case 180:
			// 音楽
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
			// 音楽
			SoundPlayOnce(SOUND_OKANE);
			textcolor(color);
			gotoxy(AA_kingaku_pos.x + 15, AA_kingaku_pos.y + 3);
			switch (color)
			{
			case LIGHTBLUE:
				printf("%d          損した...", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				break;
			case RED:
				if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 5000)
				{
					printf("%d          元は取った！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 10000)
				{
					printf("%d          ホテルの料理は美味い！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 15000)
				{
					printf("%d          結構食べたぞ！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 20000)
				{
					printf("%d          お得だーー！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 25000)
				{
					printf("%d          超お得ーー！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 30000)
				{
					printf("%d          こんなにお得になって良いのぉ？", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 35000)
				{
					printf("%d          これだけお得なら文句なし！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else if ((Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN) <= 40000)
				{
					printf("%d          高級食材総取りだ！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				else
				{
					printf("%d          ホテル破産級だ！！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
				}
				break;
			case WHITE:
				printf("%d          プラマイゼロ！", Result.eat_ryouri_goukei - BAIKINGU_RYOUKIN);
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