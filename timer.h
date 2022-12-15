#pragma once
// タイマーモジュール用ヘッダ(上田先生のプログラムから引用)

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void TimerInit(void);
void TimerEnd(void);
void setTimerRemaining(DWORD timer_value);
DWORD getTimerRemaining(void);
