#pragma once
// サウンドモジュール用ヘッダ
// 作成日：
// 作成者：(上田先生のプログラムから引用)

//---------------------------------------------------------
// 列挙定数
// ※ ファイル名の文字列配列の初期化と合わせる事
//---------------------------------------------------------
enum {
	SOUND_TITLE_BGM,
	SOUND_RULE_BGM,
	SOUND_RESULT_BGM,
	SOUND_GAME_BGM,
	SOUND_KETTEI,
	SOUND_SENTAKU,
	SOUND_UKETORI,
	SOUND_TABERU,
	SOUND_OKANE,
	SOUND_COUNT,
	//SOUND_START,
	SOUND_END,
};

//---------------------------------------------------------
// 関数プロトタイプ宣言
//---------------------------------------------------------
void SoundInit(void);
void SoundEnd(void);
void SoundPlayOnce(int sound_no);
void SoundPlayLoop(int sound_no);
void SoundStop(int sound_no);
