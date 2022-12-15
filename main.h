#ifndef _MAIN_H_	// ２重インクルード防止のマクロ定義
#define _MAIN_H_

#include "main.h"

//-------------------------------------------------------------------
// 関数プロトタイプ宣言
//-------------------------------------------------------------------
void Init(void);
void End(void);
void Update(void);
void Draw(void);
void scene_kirikae_hantei_on(void);
void scene_kirikae(int i);

#endif /*_MAIN_H_*/