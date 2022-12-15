#ifndef _RESULT_H_	// ２重インクルード防止のマクロ定義
#define _RESULT_H_

#include "result.h"
#include "conioex.h"

//-------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------
#define RYOURI_NAME_POS_X	10		// 料理の名前表示X座標
#define RYOURI_NAME_POS_Y	6		// 料理の名前表示Y座標
#define BAIKINGU_RYOUKIN	20000	// バイキングの料金

//---------------------------------------------------------
// 構造体
//---------------------------------------------------------
// リザルト
typedef struct {
	int eat_ryouri_num; // 食べた料理の数
	int ryouri_num;		// 食べた料理の数更新用
	int eat_ryouri_nedan;		// 食べた料理の値段
	int eat_ryouri_goukei;		// 食べた料理の合計金額
	int eat_ryouri_color;		// 食べた料理の名前の色
	char eat_ryouri_name[16 + 1];	// 食べた料理の名前
	bool name_hyouji;			// 食べた料理の名前表示判定
}RESULT;

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void result_Init(void);
void result_End(void);
void result_Update(void);
void result_Draw(void);

#endif