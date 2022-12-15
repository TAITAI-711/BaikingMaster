// 食べ物用

#define CONIOEX
#include <time.h>
#include "food.h"
#include "timer.h"


// 構造体変数宣言
// 全角8文字まで
FOOD Food[] = {
	{"ステーキ"			,	BROWN,		3,	4300	}, {"ごはん"			,	WHITE,		1,	200		},
	{"しおラーメン"		,	WHITE,		4,	800		}, {"しょうゆラーメン"	,	LIGHTRED,	4,	1000	},
	{"みそラーメン"		,	BROWN,		4,	1200	}, {"とんこつラーメン"	,	YELLOW,		4,	1500	},
	{"うどん"			,	YELLOW,		4,	500		}, {"トマトサラダ"		,	RED,		1,	400		},
	{"春雨サラダ"		,	GREEN,		1,	300		}, {"豚しゃぶサラダ"	,	GREEN,		1,	500		},
	{"チョレギサラダ"	,	GREEN,		1,	360		}, {"コーンサラダ"		,	GREEN,		1,	310		}, 
	{"カニ"				,	RED,		2,	4100	}, {"もやし"			,	WHITE,		1,	50		},
	{"からあげ"			,	BROWN,		1,	500		}, {"カツカレー"		,	BROWN,		3,	800		},
	{"野菜カレー"		,	BROWN,		3,	770		}, {"餃子"				,	YELLOW,		2,	260		},
	{"チャーハン"		,	YELLOW,		3,	700		}, {"りんごジュース"	,	RED,		1,	300		},
	{"ぶどうジュース"	,	LIGHTMAGENTA,1,	350		}, {"オレンジジュース"	,	YELLOW,		1,	300		},
	{"プリン"			,	YELLOW,		1,	350		}, {"ローストビーフ"	,	BROWN,		1,	2500	},
	{"杏仁豆腐"			,	WHITE,		1,	300		}, {"食パン"			,	WHITE,		1,	150		},
	{"クロワッサン"		,	BROWN,		1,	200		}, {"天ぷら"			,	YELLOW,		2,	820		},
	{"まぐろ寿司"		,	RED,		1,	500		}, {"サーモン寿司"		,	LIGHTRED,	1,	450		},
	{"ハンバーグ"		,	BROWN,		3,	1000	}, {"ミネストローネ"	,	LIGHTRED,	2,	380		},
	{"たまごスープ"		,	YELLOW,		2,	310		}, {"焼きそば"			,	BROWN,		3,	600		},
	{"そば"				,	LIGHTGRAY,	3,	1100	}, {"茶碗蒸し"			,	YELLOW,		2,	550		},
	{"まぐろ丼"			,	RED,		4,	1500	}, {"カルボナーラ"		,	YELLOW,		3,	880		},
	{"ミートパスタ"		,	RED,		3,	630		}, {"コーヒー"			,	DARKGRAY,	1,	500		},
	{"キャビア"			,	DARKGRAY,	1,	3000	}, {"トリュフステーキ"	,	DARKGRAY,	5,	6000	},
	{"春巻き"			,	YELLOW,		2,	270		}, {"肉まん"			,	LIGHTGRAY,	2,	300		},
	{"シュウマイ"		,	WHITE,		1,	350		}, {"マカロニグラタン"	,	YELLOW,		3,	850		},
	{"かぼちゃコロッケ"	,	BROWN,		2,	200		}, {"ひき肉コロッケ"	,	BROWN,		2,	310		},
	{"たまご焼き"		,	YELLOW,		2,	200		}, {"ヨーグルト"		,	WHITE,		2,	200		},
	{"わかめの味噌汁"	,	BROWN,		1,	350		}, {"豚汁"				,	BROWN,		1,	420		},
	{"ポテト"			,	BROWN,		1,	300		}, {"ホタテ寿司"		,	WHITE,		1,	410		},
	{"トリュフサラダ"	,	GREEN,		1,	600		}, {"チーズピザ"		,	YELLOW,		3,	1100	},
	{"ベーコンピザ"		,	LIGHTRED,	3,	1300	}, {"コーヒーゼリー"	,	DARKGRAY,	1,	350		},
	{"メロン"			,	LIGHTGREEN,	2,	1200	}, {"シェフのおすすめ"	,	RED,		2,	5000	},
	{"クレープ"			,	YELLOW,		2,	550		}, {"ティラミス"		,	BROWN,		2,	450		},
	{"ミートパイ"		,	YELLOW,		3,	610		}, {"マカロン"			,	LIGHTRED,	1,	300		},
	{"ぶどう"			,	MAGENTA,	1,	450		}, {"みかん"			,	YELLOW,		1,	200		},
	{"マスカット"		,	GREEN,		1,	650		}, {"もも"				,	LIGHTRED,	1,	350		},
	{"パエリア"			,	YELLOW,		2,	1000	}, {"ルーローハン"		,	BROWN,		2,	600		},
	{"タピオカティー"	,	LIGHTGRAY,	1,	500		}, {"チーズタッカルビ"	,	YELLOW,		4,	800		},
	{"チーズケーキ"		,	YELLOW,		2,	450		}, {"トムヤムクン"		,	RED,		3,	900		},
	{"チョコケーキ"		,	LIGHTGRAY,	2,	450		}, {"北京ダック"		,	BROWN,		4,	3500	},
	{"お好み焼き"		,	BROWN,		3,	850		}, {"エッグタルト"		,	YELLOW,		2,	250		},
	{"エビピラフ"		,	WHITE,		3,	630		}, {"プルコギ"			,	BROWN,		3,	830		},
	{"ビーフシチュー"	,	BROWN,		3,	860		}, {"タコス"			,	GREEN,		2,	600		},
	{"肉じゃが"			,	BROWN,		2,	640		}, {"ラクサ"			,	LIGHTRED,	3,	540		},
	{"ラム肉フムス添え"	,	LIGHTRED,	2,	2500	}, {"生春巻き"			,	GREEN,		2,	560		},
	{"カオマンガイ"		,	LIGHTGRAY,	3,	1100	}, {"フカヒレスープ"	,	YELLOW,		2,	4000	},
	{"マルゲリータ"		,	RED,		3,	1200	}, {"あん肝"			,	WHITE,		2,	1000	},
	{"フォー"			,	LIGHTGRAY,	2,	720		}, {"白子"				,	WHITE,		2,	700		},
	{"バインミー"		,	GREEN,		2,	530		}, {"ナシゴレン"		,	BROWN,		3,	830		},
	{"ピクルス"			,	GREEN,		1,	250		}, {"シュクメルリ"		,	YELLOW,		3,	750		},
	{"生ビール"			,	YELLOW,		1,	630		}, {"赤ワイン"			,	LIGHTRED,	1,	1200	}, 
	{"白ワイン"			,	WHITE,		1,	1200	}, {"日本酒"			,	WHITE,		1,	850		}, 
	{"ウィスキー"		,	BROWN,		1,	1300	}, {"カルーア・ミルク"	,	DARKGRAY,	1,	800		},
	{"マティーニ"		,	WHITE,		1,	1100	}, {"モスコミュール"	,	WHITE,		1,	780		},
	{"カシスオレンジ"	,	YELLOW,		1,	800		},
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
// キャラクターのAA
//---------------------------------------------------------
const char* AA_AMOUNT_0[] = {
	"        ●        ",
	NULL
};
const char* AA_AMOUNT_1[] = {
	"      ●  ●      ",
	NULL
};
const char* AA_AMOUNT_2[] = {
	"    ●  ●  ●    ",
	NULL
};
const char* AA_AMOUNT_3[] = {
	"  ●  ●  ●  ●  ",
	NULL
};
const char* AA_AMOUNT_4[] = {
	"●  ●  ●  ●  ●",
	NULL
};
const char* AA_URIKIRE[] = {
	"  料理切り替え中  ",
	NULL
};

//---------------------------------------------------------
// グローバル変数宣言
//---------------------------------------------------------
static DWORD game_time;		// ゲーム時間
static int AA_waku_tate;	// 料理を表示する枠の縦の長さ
static int AA_waku_yoko;	// 料理を表示する枠の横の長さ

//---------------------------------------------------------
// 関数定義
//---------------------------------------------------------
void food_Init(int waku_tate, int waku_yoko)
{
	// 構造体初期化
	Food_info = {};
	Food_kirikae = {};
	Random = {};
	// 料理を表示する枠の長さ入力
	AA_waku_tate = waku_tate;
	AA_waku_yoko = waku_yoko;
	// ランダム変数入力
	random_Init();
	// 料理を消すための空白座標入力
	food_kuhaku_pos_Init();
	// 料理の量表示座標入力
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
		// 切り替えの時間
		if (Random.kirikae_time[i] <= ((GAME_TIME + COUNT_TIME) - game_time))
		{
			Food_info.uketori[i] = true;
		}
		else if (Food_info.uketori[i] == true) // 料理を受け取った
		{
			Random.kirikae_time[i] = ((GAME_TIME + COUNT_TIME) - game_time); // 切り替え時間更新
		}
		// 受け取り判定がオン
		if (Food_info.uketori[i] == true)
		{
			if (Random.pre_num_hantei[i])
			{
				// ひとつ前の料理座標入力
				ryouri_pre_pos_Update(i);
			}
			// ランダム変数更新
			random_Update(i);
			// 料理の表示座標更新
			food_pos_Update(i, Random.num[i], &Food_pos[i]);
			// 料理の値段表示座標更新
			food_nedan_pos_Update(i, Random.num[i], &Food_nedan_pos[i]);
			// 料理の量表示AA更新
			ryouri_amount_AA_Update(i);
			// 受け取り判定オフ
			Food_info.uketori[i] = false;
			// 切り替え判定オン
			Food_kirikae.hantei[i] = true;
			// 料理を表示するスクロールの判定オン
			Food_kirikae.scroll_hantei[i] = true;

			if (!Random.pre_num_hantei[i]) // 最初の1回
			{
				// ひとつ前の料理座標入力
				ryouri_pre_pos_Update(i);
				// ひとつ前の料理を入力する判定オン
				Random.pre_num_hantei[i] = true;
			}
		}
		if ((Food_kirikae.y[i] == -5 && i < 3) ||
			(Food_kirikae.y[i] == 5 && i >= 3))
		{
			// スクロール判定切り替え
			Food_kirikae.scroll_hantei[i] = false;
		}
		else if (Food_kirikae.y[i] == 0 && !Food_kirikae.scroll_hantei[i])
		{
			// 切り替え判定オフ
			Food_kirikae.hantei[i] = false;
		}
		if (Food_kirikae.hantei[i])
		{
			//切り替えスクロール間隔計測用の時間更新
			Food_kirikae.scroll_time[i] += 1;
		}
		else
		{
			// 切り替えスクロール間隔計測用の時間初期化
			Food_kirikae.scroll_time[i] = 0;
		}
	}
}

void food_Draw(void)
{
	for (int i = 0; i < 6; i++)
	{
		// 切り替え判定オンなら
		if (Food_kirikae.hantei[i] == true)
		{
			// 最初の1回
			if (Food_kirikae.scroll_time[i] == 1)
			{
				// 料理の残像消す処理
				ryouri_kuhaku_Draw(i, false);
				// 料理表示
				print_x_y_one(Food_pre_pos[i].x, Food_pre_pos[i].y, 
					Food[Random.pre_num[i]].name, Food[Random.pre_num[i]].color);
				// 料理の値段表示
				gotoxy(Food_nedan_pre_pos[i].x, Food_nedan_pre_pos[i].y);
				printf("\\");
				print_x_y_one_num(Food_nedan_pre_pos[i].x + 2, Food_nedan_pre_pos[i].y,
					Food[Random.pre_num[i]].nedan, WHITE);
				// 料理切り替え中表示
				print_x_y_one(Food_amount_pos[i].x,
					Food_amount_pos[i].y,
					AA_URIKIRE[0], YELLOW);
			}
			if (Food_kirikae.scroll_time[i] % 8 == 0)
			{
				// 料理の残像消す処理
				ryouri_kuhaku_Draw(i, true);

				if (Food_kirikae.scroll_hantei[i])
				{
					if (i < 3)
					{
						Food_kirikae.y[i] -= 1;
						if (Food_kirikae.y[i] >= -3)
						{
							// 料理の値段表示
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
							// 料理表示
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
							// 料理の値段表示
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
							// 料理表示
							print_x_y_one(Food_pos[i].x, Food_pos[i].y + Food_kirikae.y[i],
								Food[Random.num[i]].name, Food[Random.num[i]].color);
						}
					}

				}
				if (Food_kirikae.y[i] == 0) // 表示終了
				{
					// 料理の残像消す処理
					ryouri_kuhaku_Draw(i, false);
					// 料理表示
					print_x_y_one(Food_pos[i].x, Food_pos[i].y,
						Food[Random.num[i]].name, Food[Random.num[i]].color);
					// 料理の値段表示
					gotoxy(Food_nedan_pos[i].x, Food_nedan_pos[i].y);
					printf("\\");
					print_x_y_one_num(Food_nedan_pos[i].x + 2, Food_nedan_pos[i].y,
						Food[Random.num[i]].nedan, WHITE);
					// 料理の量表示
					print_x_y_one(Food_amount_pos[i].x,
						Food_amount_pos[i].y, Food_info.p[i], RYOURI_HAVE_COLOR_2);
				}
			}
		}
	}
}

//---------------------------------------------------------
// 乱数入力(1回のみ)
//---------------------------------------------------------
void random_Init(void)
{
	srand((unsigned int)time(NULL));// 乱数の種初期化;

	for (int i = 0; i < 6; i++)
	{
		Random.kirikae_time[i] = 0;
	}
}

//---------------------------------------------------------
// 乱数入力
//---------------------------------------------------------
void random_Update(int i)
{
	// 料理の切り替え時間
	Random.kirikae_time[i] += (rand() % 4001) + 5000;
	// ランダムな料理を入力
	Random.num[i] = rand() % (sizeof(Food) / sizeof(Food[0]));
}

//---------------------------------------------------------
// ひとつ前の料理座標入力
//---------------------------------------------------------
void ryouri_pre_pos_Update(int i)
{
	// ひとつ前のランダム変数入力
	Random.pre_num[i] = Random.num[i];
	// ひとつ前の料理の表示座標入力
	food_pos_Update(i, Random.pre_num[i], &Food_pre_pos[i]);
	// ひとつ前の料理の値段表示座標入力
	food_nedan_pos_Update(i, Random.pre_num[i], &Food_nedan_pre_pos[i]);
}
//---------------------------------------------------------
// 料理の表示座標入力(i = i, j = random変数)
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
// 料理の空白表示座標入力
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
// 残像消す空白表示
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
// 料理の値段表示座標更新(i = i, j = Random変数)
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
	// 真ん中らへんに表示されるように調整
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
// 料理の量表示座標入力
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
// 料理の量表示AA更新
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
// 料理の量を返す(game.cpp用)
//---------------------------------------------------------
const int ryouri_amount(int i)
{
	return Food[Random.num[i]].amount;
}

//---------------------------------------------------------
// 料理を受け取った時の処理(game.cpp用)
//---------------------------------------------------------
const int ryouri_uketori(int i)
{
	Food_info.uketori[i] = true;

	return Random.num[i];
}

//---------------------------------------------------------
// 料理の名前を返す(game.cpp用)
//---------------------------------------------------------
const char* ryouri_name(int i)
{
	return Food[i].name;
}

//---------------------------------------------------------
// 料理の値段を返す(game.cpp用)
//---------------------------------------------------------
const int ryouri_nedan(int i)
{
	return Food[i].nedan;
}

//---------------------------------------------------------
// 料理の切り替え状態を返す(game.cpp用)
//---------------------------------------------------------
const bool ryouri_kirikae_hantei(int i)
{
	return Food_kirikae.hantei[i];
}

//---------------------------------------------------------
// 料理の切り替え状態を返す(game.cpp用)
//---------------------------------------------------------
const int ryouri_color(int i)
{
	return Food[i].color;
}