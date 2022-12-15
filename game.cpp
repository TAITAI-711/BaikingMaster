// ゲーム本編

#define CONIOEX
#include "game.h"
#include "main.h"
#include "timer.h"
#include "food.h"
#include "SOUND.h"

// 構造体変数宣言
PLAYER Player;
PLAYER_POS Player_pos;
OTHER_POS UI_moji_pos[4];
OTHER_POS FOOD_moji;
OTHER_POS AA_count_pos[4];
AA_SIZE	AA_size[AA_SYURUI];
RYOURI_UKETORI Ryouri_uketori;

//---------------------------------------------------------
// キャラクターのAA
//---------------------------------------------------------
// プレーヤー(AAの種類:0)
const char* AA_player_0[] = {
	" ∧,,∧   ",
	"(*・ω・) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_0_1[] = {
	"   ∧,,∧ ",
	" (・ω・*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};
const char* AA_player_1[] = {
	" ∧,,∧   ",
	"(*・ω■) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_1_1[] = {
	"   ∧,,∧ ",
	" (■ω・*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};
const char* AA_player_2[] = {
	" ∧,,∧   ",
	"(*・■■) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_2_1[] = {
	"   ∧,,∧ ",
	" (■■・*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};
const char* AA_player_3[] = {
	" ∧,,■   ",
	"(*・■■) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_3_1[] = {
	"   ■,,∧ ",
	" (■■・*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};
const char* AA_player_4[] = {
	" ∧■■   ",
	"(*・■■) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_4_1[] = {
	"   ■■∧ ",
	" (■■・*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};
const char* AA_player_5[] = {
	" ∧■■   ",
	"(*◆■■) ",
	"(つ￣￣￣O",
	" 〇   〇  ",
	NULL
};
const char* AA_player_5_1[] = {
	"   ■■∧ ",
	" (■■◆*)",
	"O￣￣￣⊂)",
	"  〇   〇 ",
	NULL
};

// 料理の枠(AAの種類:1)
const char* AA_ryouri_0[] = {
	"||      ごはん      ||",
	"||    サラダ付き    ||",
	"||                  ||",
	"||      6000 円     ||",
	"||  ● ● ● ● ●  ||",
	"======================",
	NULL
};
const char* AA_ryouri_1[] = {
	"======================",
	"||      ごはん      ||",
	"||    サラダ付き    ||",
	"||                  ||",
	"||      6000 円     ||",
	"||  ● ● ● ● ●  ||",
	NULL
};
const char* AA_ryouri_2[] = {
	"======================",
	NULL
};

// UIの枠(AAの種類:2)
const char* AA_UI_0[] = {
	"制限時間",
	"持っている料理の数",
	NULL
};
const char* AA_UI_1[] = {
	"                ",
	"     60  秒     ",
	"                ",
	NULL
};
const char* AA_UI_2[] = {
	"                ",
	" ○ ○ ○ ○ ○ ",
	"                ",
	NULL
};
const char* AA_UI_2_1[] = {
	"                ",
	" ● ○ ○ ○ ○ ",
	"                ",
	NULL
};
const char* AA_UI_2_2[] = {
	"                ",
	" ● ● ○ ○ ○ ",
	"                ",
	NULL
};
const char* AA_UI_2_3[] = {
	"                ",
	" ● ● ● ○ ○ ",
	"                ",
	NULL
};
const char* AA_UI_2_4[] = {
	"                ",
	" ● ● ● ● ○ ",
	"                ",
	NULL
};
const char* AA_UI_2_5[] = {
	"                ",
	" ● ● ● ● ● ",
	"                ",
	NULL
};

// 食べるところ(AAの種類:3)
const char* AA_EAT_0[] = {
	"||",
	NULL
};

// 食べるところの文字
const char* AA_EAT_MOJI[] = {
	"テ",
	"  ",
	"｜",
	"  ",
	"ブ",
	"  ",
	"ル",
	NULL
};

// カウント(AAの種類:4)
const char* AA_COUNT_NUM_1[] =
{
	"    ■",
	"    ■",
	"    ■",
	"    ■",
	"    ■",
	NULL
};
const char* AA_COUNT_NUM_2[] =
{
	"■■■",
	"    ■",
	"■■■",
	"■    ",
	"■■■",
	NULL
};
const char* AA_COUNT_NUM_3[] =
{
	"■■■",
	"    ■",
	"■■■",
	"    ■",
	"■■■",
	NULL
};
// (AAの種類:5)
const char* AA_COUNT_END[] =
{
	"    ■  ■      ■          ■    ■",
	"■■■■  ■  ■■■■■    ■    ■",
	"  ■■■        ■■  ■    ■■  ■",
	"■  ■  ■    ■■    ■          ■",
	"■■■  ■      ■  ■        ■■■",
	NULL
};
// (AAの種類:6)
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
// (AAの種類:7)
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
// グローバル変数宣言
//---------------------------------------------------------
static DWORD time;						// 残り時間
static int game_start_count = 4;		// ゲームのカウント表示用
static bool draw_one = true;			// 最初の１回のみ表示の判定用
static bool PK_SP_ET_on = false;		// スペースボタンが押されているか判定用
static bool game_end_hantei = false;	// ゲームの終了判定
static bool game_start_hantei = false;	// ゲームの開始判定

//---------------------------------------------------------
// 関数定義
//---------------------------------------------------------

void game_Init(void)
{
	system("cls");
	// カーソル非表示
	setcursortype(NOCURSOR);
	// 構造体初期化
	Player = {};
	Player_pos = {};
	FOOD_moji = {};
	Ryouri_uketori = {};
	// 判定初期化
	game_start_hantei = false;
	game_end_hantei = false;
	game_start_count = 4;
	draw_one = true;
	// タイマーセット
	TimerInit();
	setTimerRemaining(GAME_TIME + COUNT_TIME);
	// AAの情報入力
	AA_info_Init();
	// プレーヤーの初期設定
	player_set_Init();
	// UIの座標設定
	ui_waku_Init();
	// 食べ物の情報入力
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
	// タイマーの残り時間
	time = getTimerRemaining();
	if (!game_start_hantei && (time <= GAME_TIME))
	{
		// 音楽
		SoundPlayLoop(SOUND_GAME_BGM);
		game_start_hantei = true;
	}
	if (!game_end_hantei)
	{
		if (game_start_hantei)
		{
			// プレーヤー移動
			player_move_Update();
			// プレーヤーの残像消す処理
			p_zanzou_kesu_Update();
		}
		// 料理の処理
		food_Update(time);
		// 料理の枠の受け取り部分更新
		ryouri_waku_uketori_Update();
		// プレイヤーの持っている料理の数
		player_food_have_Update();
	}
	// 終了
	if (time == 0 && !game_end_hantei)
	{
		// 音楽
		SoundPlayOnce(SOUND_END);
		// タイマー時間セット
		setTimerRemaining(2000);
		// ゲームの終了判定オン
		game_end_hantei = true;
		// 最初の1回のみ表示の判定オン
		draw_one = true;
	}
	else if (time == 0 && game_end_hantei)
	{
		scene_kirikae_hantei_on();
	}
}

void game_Draw(void)
{
	// カウント表示
	AA_count_NUM_Draw();
	
	if (!game_end_hantei)
	{
		if (draw_one) // 最初の1回のみ表示
		{
			draw_one = false;
			// 料理の枠表示
			ryouri_waku_Draw();
			// UIの枠表示
			ui_waku_Draw();
			// 食べるところの文字表示
			print_x_y_all(4, 13, AA_EAT_MOJI, WHITE);
		}

		// プレーヤーの残像消す空白表示
		p_zanzou_kesu_Draw();
		// プレーヤー表示
		player_Draw();
		// 料理の枠の受け取り部分表示
		ryouri_waku_uketori_Draw();
		// 食べるところの表示
		food_eat_Draw();
		// UI表示
		ui_Draw();
		// 料理表示
		food_Draw();
	}
	else
	{
		if (draw_one)
		{
			// 終わりの位置入力
			AA_count_END_Draw();
			draw_one = false;
		}
	}
}

//---------------------------------------------------------
// プレーヤーの移動処理
//---------------------------------------------------------
void player_move_Update(void)
{
	// ボタン入力で移動
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

	// プレイヤーが限界座標を超えたら戻す
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
// 料理を食べる位置にいるか判定処理
//---------------------------------------------------------
void food_eat_Update(void)
{
	// 食べる位置にいるか判定
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
// プレイヤーの持っている料理の数
//---------------------------------------------------------
void player_food_have_Update(void)
{
	//プレーヤーが受け取り可能な位置か判定
	player_uketori_iti();
	// 料理を食べる位置にいるか判定処理
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
				// 音楽
				SoundPlayOnce(SOUND_UKETORI);
				// 持っている料理の量更新
				Player.food_have += ryouri_amount(i);
				// 受け取った料理の番号取得
				Player.food_uketori_num[Player.uketori_num] = ryouri_uketori(i);
				Player.uketori_num += 1;
				
				PK_SP_ET_on = true;
			}
		}
	}
	// 料理を食べる
	if ((Ryouri_uketori.eat_iti) && (Player.food_have > 0))
	{
		// 音楽
		SoundPlayOnce(SOUND_TABERU);
		// 持っている料理の量を0にする
		Player.food_have = 0;
		// 受け取った料理を食べた料理にする
		for (int i = 0; i < Player.uketori_num; i++)
		{
			Player.food_eat_num[Player.eat_num] = Player.food_uketori_num[i];
			Player.eat_num += 1;
		}
		// 受け取った料理の数を0にする
		Player.uketori_num = 0;
	}
	// (テスト)料理の持てる限界
	if (Player.food_have > 5)
	{
		Player.food_have = 5;
	}
}

//---------------------------------------------------------
// プレイヤーの初期設定
//---------------------------------------------------------
void player_set_Init(void)
{
	// 初期座標設定
	Player_pos.x = PLAYER_S_POS_X;
	Player_pos.y = PLAYER_S_POS_Y;
	Player_pos.previous_x = PLAYER_S_POS_X;
	Player_pos.previous_y = PLAYER_S_POS_Y;
	// 初期向き設定
	Player_pos.muki = 0;
	// 限界座標入力
	p_pos_limit_input();
}

//---------------------------------------------------------
// プレーヤーの限界座標入力
//---------------------------------------------------------
void p_pos_limit_input(void)
{
	Player_pos.limit_L = (float)(FOOD_EAT_X + AA_size[3].yoko);	// 左の限界
	Player_pos.limit_R = (float)(UI_X - AA_size[0].yoko);		// 右の限界
	Player_pos.limit_U = (float)(AA_size[1].tate + 1);			// 上の限界
	Player_pos.limit_D = (float)((SCREEN_Y + 1) -
		(AA_size[0].tate + AA_size[1].tate));					// 下の限界
}

//---------------------------------------------------------
// プレーヤーが受け取り可能な位置か判定
//---------------------------------------------------------
void player_uketori_iti(void)
{
	// 条件に当てはまらなかったら受け取り不可
	Ryouri_uketori.iti = -1;

	if ((int)Player_pos.y <= (int)Player_pos.limit_U)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 0; // 料理１の位置
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 1; // 料理２の位置
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 2; // 料理３の位置
		}
	}
	else if ((int)Player_pos.y >= (int)Player_pos.limit_D)
	{
		if (((int)Player_pos.x >= RYOURI_WAKU_1_4_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_1_4_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 3; // 料理４の位置
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_2_5_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_2_5_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 4; // 料理５の位置
		}
		else if (((int)Player_pos.x >= RYOURI_WAKU_3_6_POS_X) &&
			((int)Player_pos.x + (AA_size[0].yoko - 1) <=
				RYOURI_WAKU_3_6_POS_X + (AA_size[1].yoko - 1)))
		{
			Ryouri_uketori.iti = 5; // 料理６の位置
		}
	}
}

//---------------------------------------------------------
// UIの表示
//---------------------------------------------------------
void ui_Draw(void)
{
	int food_have_x = UI_moji_pos[3].x;// 持っている料理の数表示X座標
	int food_have_y = UI_moji_pos[3].y;// 持っている料理の数表示Y座標

	// 残り時間表示
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
	// 持っている料理の数表示
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
// プレーヤーの表示
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
// 料理の枠表示
//---------------------------------------------------------
void ryouri_waku_Draw(void)
{
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, 1, AA_ryouri_0, WHITE); //枠1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, 1, AA_ryouri_0, WHITE); //枠2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, 1, AA_ryouri_0, WHITE); //枠3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //枠4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //枠5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X,
		(SCREEN_Y + 1) - AA_size[1].tate, AA_ryouri_1, WHITE); //枠6
}

//---------------------------------------------------------
// 料理の枠の受け取り部分更新
//---------------------------------------------------------
void ryouri_waku_uketori_Update(void)
{
	for (int i = 0; i < 6; i++)
	{
		if (((Player.food_have + ryouri_amount(i)) > 5) || 
			ryouri_kirikae_hantei(i)) // 受け取り不可
		{
			Ryouri_uketori.waku_color[i] = RED;
			Ryouri_uketori.ok[i] = false;
		}
		else // 受け取り可能
		{
			Ryouri_uketori.waku_color[i] = GREEN;
			Ryouri_uketori.ok[i] = true;
		}
	}
}

//---------------------------------------------------------
// 料理の枠の受け取り部分表示
//---------------------------------------------------------
void ryouri_waku_uketori_Draw(void)
{	
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[0]); //枠1
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[1]); //枠2
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[2]); //枠3
	print_x_y_all(RYOURI_WAKU_1_4_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[3]); //枠4
	print_x_y_all(RYOURI_WAKU_2_5_POS_X, (SCREEN_Y + 1) - AA_size[1].tate, 
		AA_ryouri_2, Ryouri_uketori.waku_color[4]); //枠5
	print_x_y_all(RYOURI_WAKU_3_6_POS_X, (SCREEN_Y + 1) - AA_size[1].tate,
		AA_ryouri_2, Ryouri_uketori.waku_color[5]); //枠6
}

//---------------------------------------------------------
// 食べるところの表示
//---------------------------------------------------------
void food_eat_Draw(void)
{
	int color; // 色

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
// UIの枠表示
//---------------------------------------------------------
void ui_waku_Draw(void)
{
	textbackground(LIGHTGRAY); // 灰色に変更
	// 全体を灰色にする
	for (int i = 1; i <= SCREEN_Y; i++)
	{
		for (int j = 0; j < (SCREEN_X + 1) - UI_X; j++)
		{
			gotoxy(UI_X + j, i);
			printf(" ");
		}
	}
	// 制限時間の文字表示
	print_x_y_one(UI_moji_pos[0].x, UI_moji_pos[0].y, AA_UI_0[0], BLACK);
	// 持っている料理の数の文字表示
	print_x_y_one(UI_moji_pos[2].x, UI_moji_pos[2].y, AA_UI_0[1], RYOURI_HAVE_COLOR_1);
	textbackground(BLACK); // 黒に変更

	// 制限時間
	print_x_y_all(UI_moji_pos[1].x, UI_moji_pos[1].y, AA_UI_1, WHITE);
	// 持っている料理の数
	print_x_y_all(UI_moji_pos[3].x, UI_moji_pos[3].y, AA_UI_2, RYOURI_HAVE_COLOR_2);
}
//---------------------------------------------------------
// UIの枠座標設定
//---------------------------------------------------------
void ui_waku_Init(void)
{
	// 制限時間の文字
	UI_moji_pos[0].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[0])) / 2);
	UI_moji_pos[0].y = UI_TIME_Y;
	// 制限時間
	UI_moji_pos[1].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[1].y = UI_TIME_Y + 2;
	// 持っている料理の数の文字
	UI_moji_pos[2].x = UI_X + (((SCREEN_X + 1) - UI_X - strlen(AA_UI_0[1])) / 2);
	UI_moji_pos[2].y = UI_RYOURI_Y;
	// 持っている料理の数
	UI_moji_pos[3].x = UI_X + (((SCREEN_X + 1) - UI_X - AA_size[2].yoko) / 2);
	UI_moji_pos[3].y = UI_RYOURI_Y + 2;
}

//---------------------------------------------------------
// プレーヤーの残像消す処理
//---------------------------------------------------------
void p_zanzou_kesu_Update(void)
{
	Player_pos.zanzou = 0;

	if ((int)Player_pos.previous_x != (int)Player_pos.x ||
		(int)Player_pos.previous_y != (int)Player_pos.y)
	{
		if ((int)Player_pos.previous_y > (int)Player_pos.y) // 上に移動
		{
			Player_pos.zanzou += 1;
		}
		if ((int)Player_pos.previous_y < (int)Player_pos.y) // 下に移動
		{
			Player_pos.zanzou += 2;
		}
		if ((int)Player_pos.previous_x > (int)Player_pos.x) // 左に移動
		{
			Player_pos.zanzou += 4;
			Player_pos.muki = 1; // 向きを左に変更
		}
		if ((int)Player_pos.previous_x < (int)Player_pos.x) // 右に移動
		{
			Player_pos.zanzou += 8;
			Player_pos.muki = 0; // 向きを右に変更
		}
	}
}

//---------------------------------------------------------
// プレーヤーの残像消す空白表示
//---------------------------------------------------------
void p_zanzou_kesu_Draw(void)
{
	// 下を消す(上に移動)
	if (Player_pos.zanzou == 1 || Player_pos.zanzou == 5 || Player_pos.zanzou == 9)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i,
				(int)Player_pos.previous_y + (AA_size[0].tate - 1));
			printf(" ");
		}
	}
	// 上を消す(下に移動)
	if (Player_pos.zanzou == 2 || Player_pos.zanzou == 6 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].yoko; i++)
		{
			gotoxy((int)Player_pos.previous_x + i, (int)Player_pos.previous_y);
			printf(" ");
		}
	}
	// 右を消す(左に移動)
	if (Player_pos.zanzou == 4 || Player_pos.zanzou == 5 || Player_pos.zanzou == 6)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x + (AA_size[0].yoko - 1), 
				(int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// 左を消す(右に移動)
	if (Player_pos.zanzou == 8 || Player_pos.zanzou == 9 || Player_pos.zanzou == 10)
	{
		for (int i = 0; i < AA_size[0].tate; i++)
		{
			gotoxy((int)Player_pos.previous_x, (int)Player_pos.previous_y + i);
			printf(" ");
		}
	}
	// プレイヤーの前の位置に現在地を入力
	Player_pos.previous_x = Player_pos.x;
	Player_pos.previous_y = Player_pos.y;
}

//---------------------------------------------------------
// AAの情報入力
//---------------------------------------------------------
void AA_info_Init(void)
{
	// プレイヤーの高さと幅
	AA_size_input(AA_player_0, AA_size, 0);
	// 料理の枠の高さと幅
	AA_size_input(AA_ryouri_0, AA_size, 1);
	// UIの高さと幅
	AA_size_input(AA_UI_1, AA_size, 2);
	// 食べるところの高さと幅
	AA_size_input(AA_EAT_0, AA_size, 3);
	// カウントの数字の高さと幅
	AA_size_input(AA_COUNT_NUM_1, AA_size, 4);
	// カウントの終わりの高さと幅
	AA_size_input(AA_COUNT_END, AA_size, 5);
	// カウントの枠1の高さと幅
	AA_size_input(AA_COUNT_WAKU_1, AA_size, 6);
	// カウントの枠2の高さと幅
	AA_size_input(AA_COUNT_WAKU_2, AA_size, 7);
	// AAカウントの表示座標入力
	// 数字
	AA_count_pos[0].x = ((SCREEN_X + 1) - AA_size[4].yoko) / 2;
	AA_count_pos[0].y = ((SCREEN_Y + 1) - AA_size[4].tate) / 2;
	// 終わり
	AA_count_pos[1].x = ((SCREEN_X + 1) - AA_size[5].yoko) / 2;
	AA_count_pos[1].y = ((SCREEN_Y + 1) - AA_size[5].tate) / 2;
	// 枠1
	AA_count_pos[2].x = ((SCREEN_X + 1) - AA_size[6].yoko) / 2;
	AA_count_pos[2].y = ((SCREEN_Y + 1) - AA_size[6].tate) / 2;
	// 枠2
	AA_count_pos[3].x = ((SCREEN_X + 1) - AA_size[7].yoko) / 2;
	AA_count_pos[3].y = ((SCREEN_Y + 1) - AA_size[7].tate) / 2;
}

//---------------------------------------------------------
// AAおわりの表示
//---------------------------------------------------------
void AA_count_END_Draw(void)
{
	textbackground(GREEN);
	// 枠2表示
	print_x_y_all(AA_count_pos[3].x, AA_count_pos[3].y, AA_COUNT_WAKU_2, YELLOW);
	// 終わり表示
	print_x_y_all(AA_count_pos[1].x, AA_count_pos[1].y, AA_COUNT_END, WHITE);
	textbackground(BLACK);
}

//---------------------------------------------------------
// AAカウントの表示
//---------------------------------------------------------
void AA_count_NUM_Draw(void)
{
	if (!game_start_hantei)
	{
		if (time <= GAME_TIME + 1000 && game_start_count == 2)
		{
			// 音楽
			SoundPlayOnce(SOUND_COUNT);
			//枠1表示
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, RED);
			// 1表示
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_1, LIGHTRED);
			// カウント判定を1にする
			game_start_count = 1;
		}
		else if (time <= GAME_TIME + 2000 && game_start_count == 3)
		{
			// 音楽
			SoundPlayOnce(SOUND_COUNT);
			//枠1表示
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BROWN);
			// 2表示
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_2, YELLOW);
			// カウント判定を2にする
			game_start_count = 2;
		}
		else if (game_start_count == 4)
		{
			// 音楽
			SoundPlayOnce(SOUND_COUNT);
			//枠1表示
			print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1, BLUE);
			// 3表示
			print_x_y_all(AA_count_pos[0].x, AA_count_pos[0].y, AA_COUNT_NUM_3, LIGHTBLUE);
			// カウント判定を3にする
			game_start_count = 3;
		}
	}
	else if (game_start_count == 1)
	{
		// 音楽
		//SoundPlayOnce(SOUND_START);
		// カウント消す
		print_x_y_all(AA_count_pos[2].x, AA_count_pos[2].y, AA_COUNT_WAKU_1_KUHAKU, WHITE);
		// ゲームのカウント判定を0にする
		game_start_count = 0;
	}
}


//---------------------------------------------------------
// AAの高さと幅を測る処理
//---------------------------------------------------------
void AA_size_input(const char* p[], AA_SIZE AA_size[], int AA_num)
{
	AA_size[AA_num].tate = AA_size_tate(p);
	AA_size[AA_num].yoko = AA_size_yoko(p);
}

//---------------------------------------------------------
// 食べた料理の数を返す
//---------------------------------------------------------
const int eat_ryouri_num(void)
{
	return Player.eat_num;
}

//---------------------------------------------------------
// 食べた料理の名前を返す
//---------------------------------------------------------
const char* eat_ryouri_name(int i)
{
	return ryouri_name(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// 食べた料理の値段を返す
//---------------------------------------------------------
const int eat_ryouri_nedan(int i)
{
	return ryouri_nedan(Player.food_eat_num[i]);
}

//---------------------------------------------------------
// 食べた料理の名前の色を返す
//---------------------------------------------------------
const int eat_ryouri_color(int i)
{
	return ryouri_color(Player.food_eat_num[i]);
}