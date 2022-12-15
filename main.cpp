// 課題　：　HEWのゲーム
// 氏名　：　高平大数

#include "main.h"
#include "conioex.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "rule.h"
#include "SOUND.h"
#include "gamen.h"

//-------------------------------------------------------------------
// グローバル変数
//-------------------------------------------------------------------
static int g_nCountFPS;					// FPSカウンタ
static int game_scene = 1;				// ゲームの場面(0: 終了, 1:タイトル, 2:ゲーム, 3:リザルト, 4:ルール説明)
static bool game_scene_kirikae = false;	// ゲームシーンの切り替え判定

//-------------------------------------------------------------------
// 主処理
//-------------------------------------------------------------------
int main(void)
{
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	int nCountFrame;

	// 分解能を設定
	timeBeginPeriod(1);

	dwExecLastTime = 
	dwFPSLastTime = timeGetTime();
	dwCurrentTime =
	nCountFrame = 0;

	SoundInit();
	gamen_Init();

	do
	{
		// データの初期化処理の関数
		Init();

		// ゲームループ
		do
		{
			dwCurrentTime = timeGetTime();
			if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5秒ごとに実行
			{
				g_nCountFPS = nCountFrame * 1000 / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;
				nCountFrame = 0;
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{
				dwExecLastTime = dwCurrentTime;

				// 更新処理
				Update();

				// 描画処理
				Draw();

				nCountFrame++;
			}
		} while (!inport(PK_ESC) && !(game_scene_kirikae));

		// 終了処理
		End();

		game_scene_kirikae = false;
	} while (!inport(PK_ESC) && !(game_scene == 0));

	SoundEnd();
	gamen_End();

	// 分解能を戻す
	timeEndPeriod(1);

	return 0;
}

void Init(void)
{
	switch (game_scene)
	{
	case 1:
		title_Init();
		break;
	case 2:
		game_Init();
		break;
	case 3:
		result_Init();
		break;
	case 4:
		rule_Init();
		break;
	default:
		break;
	}
}

void End(void)
{
	switch (game_scene)
	{
	case 1:
		title_End();
		break;
	case 2:
		game_End();
		break;
	case 3:
		result_End();
		break;
	case 4:
		rule_End();
		break;
	default:
		break;
	}
}

void Update(void)
{
	switch (game_scene)
	{
	case 1:
		title_Update();
		break;
	case 2:
		game_Update();
		break;
	case 3:
		result_Update();
		break;
	case 4:
		rule_Update();
		break;
	default:
		break;
	}
}

void Draw(void)
{
#ifdef _DEBUG
	// FPSカウンタ表示
	setcursortype(NOCURSOR);
	textcolor(WHITE);
	gotoxy(1, 1);
	printf("FPS : %d", g_nCountFPS);
#endif /*_DEBUG*/
	switch (game_scene)
	{
	case 1:
		title_Draw();
		break;
	case 2:
		game_Draw();
		break;
	case 3:
		result_Draw();
		break;
	case 4:
		rule_Draw();
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------------
// シーン切り替え判定オン
//-------------------------------------------------------------------
void scene_kirikae_hantei_on(void)
{
	game_scene_kirikae = true;
}

//-------------------------------------------------------------------
// シーン切り替え用
//-------------------------------------------------------------------
void scene_kirikae(int i)
{
	game_scene = i;
}

