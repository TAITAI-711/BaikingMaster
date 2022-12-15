// 食べ物用ヘッダ

#ifndef _FOOD_H_	// ２重インクルード防止のマクロ定義
#define _FOOD_H_

#include "food.h"
#include "game.h"
#include "conioex.h"

//---------------------------------------------------------
// 構造体
//---------------------------------------------------------
// 食べ物
typedef struct {
	char name[16 + 1];		// 食べ物の名前
	int color;			// 食べ物の名前の色
	int amount;			// 食べ物の量
	int nedan;			// 食べ物の値段
}FOOD;

// 食べ物の情報
typedef struct {
	const char* p[6];		// 料理の量表示AA用
	bool uketori[6];		// 料理を受け取ったか判定用
}FOOD_INFO;

// 食べ物の切り替え
typedef struct {
	DWORD scroll_time[6];		// 料理の切り替えスクロール間隔
	int y[6];					// 料理の表示Y座標調整用
	bool hantei[6];				// 料理の切り替え判定用
	bool scroll_hantei[6];		// スクロール判定用
}FOOD_KIRIKAE;

// ランダム
typedef struct {
	DWORD kirikae_time[6];	// 表示を切り替える間隔用
	int num[6];				// 表示する料理用
	int pre_num[6];			// ひとつ前の表示する料理用
	bool pre_num_hantei[6];	// pre_numを入力する判定用
}RANDOM;

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void food_Init(int waku_tate, int waku_yoko);
void food_End(void);
void food_Update(DWORD now_game_time);
void food_Draw(void);
void random_Update(int i);
void random_Init(void);
void food_pos_Update(int i, int j, OTHER_POS* p);
void food_kuhaku_pos_Init(void);
void ryouri_kuhaku_Draw(int i, bool ue);
void food_amount_pos_Init(void);
void ryouri_amount_AA_Update(int i);
void food_nedan_pos_Update(int i, int j, OTHER_POS* p);
void ryouri_pre_pos_Update(int i);
const int ryouri_amount(int i);
const int ryouri_uketori(int i);
const char* ryouri_name(int i);
const int ryouri_nedan(int i);
const bool ryouri_kirikae_hantei(int i);
const int ryouri_color(int i);

#endif