// 画面用ヘッダ

#ifndef _GAMEN_H_	// ２重インクルード防止のマクロ定義
#define _GAMEN_H_

#include "gamen.h"

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void gamen_Init(void);
void gamen_End(void);
void MyLastErrorPrint(const char* mes);
void MySetEnableVirtualTreminal(void);
void MySetFontSize(int font_size);
void MySetWindowInfo(int width, int height);
void MyResetTextAttr(void);

#endif
