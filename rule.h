// ルール説明用ヘッダ

#ifndef _RULE_H_	// ２重インクルード防止のマクロ定義
#define _RULE_H_

#include "rule.h"
#include "conioex.h"

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void rule_Init(void);
void rule_End(void);
void rule_Update(void);
void rule_Draw(void);

#endif