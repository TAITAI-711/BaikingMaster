// ゲーム画面用ヘッダ

#ifndef _GAME_H_	// ２重インクルード防止のマクロ定義
#define _GAME_H_

#include "game.h"
#include "conioex.h"

//-------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------
#define FONT_SIZE	18								// フォントのサイズ
#define SCREEN_X	120								// 最大画面サイズX
#define SCREEN_Y	30								// 最大画面サイズY

#define GAME_TIME	61000							// ゲーム時間
#define COUNT_TIME	3000							// ゲームのカウント時間

#define PLAYER_S_POS_X			(FOOD_EAT_X + 5)	// プレイヤーの初期座標X
#define PLAYER_S_POS_Y			15					// プレイヤーの初期座標Y
#define PLAYER_MOVE_X			0.5f				// プレイヤーの移動量X
#define PLAYER_MOVE_Y			0.25f				// プレイヤーの移動量Y

#define UI_X		99								// UIの色替えのX座標
#define UI_TIME_Y	3								// UIの制限時間の文字Y座標
#define UI_RYOURI_Y	18								// UIの持っている料理の数の文字Y座標

#define FOOD_EAT_X	10								// 料理の食べるところのX座標

#define RYOURI_WAKU_1_4_POS_X		25				// 料理の枠1,4の表示X座標
#define RYOURI_WAKU_2_5_POS_X		50				// 料理の枠2,5の表示X座標
#define RYOURI_WAKU_3_6_POS_X		75				// 料理の枠3,6の表示X座標

#define AA_SYURUI	8								// AAの種類(プレイヤー,料理の枠...)

#define RYOURI_HAVE_COLOR_1		BLUE				// 持っている料理の数の文字の色
#define RYOURI_HAVE_COLOR_2		LIGHTBLUE			// 持っている料理の数の色

//---------------------------------------------------------
// 構造体
//---------------------------------------------------------
// プレーヤー
typedef struct {
	int food_have;				// プレーヤーの持っている料理の量
	int food_uketori_num[5];	// 受け取った料理の番号
	int uketori_num;			// 受け取った料理の番号更新用
	int food_eat_num[150];		// 食べた料理の番号
	int eat_num;				// 食べた料理の番号更新用
}PLAYER;

// プレーヤーの座標
typedef struct {
	int	muki;			// プレイヤーの向き(0:右, 1:左)
	int zanzou;			// プレーヤーの残像を消す用(0:消さない, 1:上, 2:下, 4:左, 8:右)
	float x;			// プレーヤーのX座標
	float y;			// プレーヤーのY座標
	float previous_x;	// プレーヤーの１つ前のX座標
	float previous_y;	// プレーヤーの１つ前のY座標
	float limit_L;		// 限界座標左
	float limit_R;		// 限界座標右
	float limit_U;		// 限界座標上
	float limit_D;		// 限界座標下
}PLAYER_POS;

// その他の表示座標
typedef struct {
	int x;
	int y;
}OTHER_POS;

// AAの高さと幅
typedef struct {
	int tate;
	int yoko;
}AA_SIZE;

// 料理の受け取り状態
typedef struct {
	int iti;		// 受け取り可能位置か判定(-1:不可,0:料理１の位置,1:料理２の位置...)
	int waku_color[6];	// 料理の枠の受け取り部分の色
	bool ok[6];		// 受け取り可能か判定
	bool eat_iti;	// 食べるところの位置にいるか判定
}RYOURI_UKETORI;

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void game_Init(void);
void game_End(void);
void game_Update(void);
void game_Draw(void);
void player_set_Init(void);
void player_move_Update(void);
void player_Draw(void);
void ui_waku_Init(void);
void ui_waku_Draw(void);
void ui_Draw(void);
void ryouri_waku_Draw(void);
void ryouri_waku_uketori_Update(void);
void ryouri_waku_uketori_Draw(void);
void p_zanzou_kesu_Update(void);
void p_zanzou_kesu_Draw(void);
void AA_info_Init(void);
void player_food_have_Update(void);
void food_eat_Update(void);
void food_eat_Draw(void);
void AA_size_input(const char* p[], AA_SIZE AA_size[], int AA_num);
void player_uketori_iti(void);
void p_pos_limit_input(void);
void AA_count_END_Draw(void);
void AA_count_NUM_Draw(void);
const char* eat_ryouri_name(int i);
const int eat_ryouri_num(void);
const int eat_ryouri_nedan(int i);
const int eat_ryouri_color(int i);

#endif /*_GAME_H_*/