// サウンドモジュール
// 作成日：
// 作成者：
#define CONIOEX
#include "conioex.h"
#include "SOUND.h"

//-------------------------------------------------------------------
// 構造体タグ宣言
//-------------------------------------------------------------------
typedef struct {
	const char* fname;		// 別スレッドでオープンする時に使用
	int			sound_id;	// 音出しのためのID(オープン後はこちらを使用)
} sound_t;

//-------------------------------------------------------------------
// グローバル変数宣言
//-------------------------------------------------------------------
// ファイル名の順番は、ヘッダファイルの列挙定数と合わせる事
// ※ 音源ファイルはDOVA-SYNDROME[https://dova-s.jp/]OtoLogic[https://otologic.jp/]を利用
static const char* fname[] = {
	"title.mp3",		// SOUND_TITLE_BGM
	"rule.mp3",			// SOUND_RULE_BGM
	"result.mp3",		// SOUND_RESULT_BGM
	"game.mp3",			// SOUND_GAME_BGM
	"kettei.mp3",		// SOUND_KETTEI
	"sentaku.mp3",		// SOUND_SENTAKU
	"uketori.mp3",		// SOUND_UKETORI
	"taberu.mp3",		// SOUND_TABERU
	"okane.mp3",		// SOUND_OKANE
	"count.mp3",		// SOUND_COUNT
	//"STAR_1（OK音、アイテム発見など）.mp3",	// SOUND_START
	"end.mp3",			// SOUND_END
};
static const int	sound_num = sizeof(fname) / sizeof(fname[0]);
static sound_t		sound[sound_num] = { 0 };

//---------------------------------------------------------
// 別スレッド化した音出し処理
// 　conioexのサウンド関連処理はMCIを使用している
// 　MCIはオープンしたスレッド以外からは操作できない
// 　このため、別スレッドで音を出す場合、
// 　このスレッドでオープンとクローズをしなければならない
//---------------------------------------------------------
static DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	int		sound_id;
	const char* fname = ((sound_t*)lpParameter)->fname;
	
	if (fname != NULL) {
		sound_id = opensound((char*)fname);
		if (sound_id != 0) {
			playsound(sound_id, 0);
			msleep(5000);	// すぐにクローズすると音が消えるためスリープする
			closesound(sound_id);
		}
	}
	return 0;
}
//----------------------------------------------------------
// サウンド初期処理
//----------------------------------------------------------
void SoundInit(void)
{
	bool err = false;

	for (int i = 0; i < sound_num; i++) {
		if (sound[i].sound_id == 0) {
			sound[i].sound_id = opensound((char*)fname[i]);
			if (sound[i].sound_id == 0) {
				printf("%sがオープンできません\n", fname[i]);
				err = true;
			}
			else {
				sound[i].fname = fname[i];
			}
		}
	}
	if (err) {
		printf("オープンできなかったファイルの音は鳴りません\n");
		printf("何かキーを押してください\n");
		(void)_getch();
	}
}
//----------------------------------------------------------
// サウンド終了処理
//----------------------------------------------------------
void SoundEnd(void)
{
	for (int i = 0; i < sound_num; i++) {
		if (sound[i].sound_id != 0) {
			closesound(sound[i].sound_id);
		}
	}
}
//----------------------------------------------------------
// １回だけ音を出す(音を鳴らすと一瞬止まるので別スレッド化した)
//----------------------------------------------------------
void SoundPlayOnce(int sound_no)
{
	HANDLE hThread;			// スレッド生成するためのハンドル値
	DWORD dwThreadId;		// CreateThread(スレッド生成)関数の引数用

	// 直接呼ぶと遅延するの別スレッドでplaysoundする
	// playsound(sound[sound_no].sound_id, 0);
	hThread = CreateThread(NULL, 0, ThreadProc, &sound[sound_no], 0, &dwThreadId);
	if (hThread != NULL) {
		CloseHandle(hThread);	// CloseHandleでhThreadを閉じる.
	}
}
//----------------------------------------------------------
// ループ再生する
//----------------------------------------------------------
void SoundPlayLoop(int sound_no)
{
	playsound(sound[sound_no].sound_id, 1);
}
//----------------------------------------------------------
// 再生した音を止める
//----------------------------------------------------------
void SoundStop(int sound_no)
{
	stopsound(sound[sound_no].sound_id);
}
