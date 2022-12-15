// 画面用

#define CONIOEX
#include "conioex.h"
#include "gamen.h"
#include "game.h"

//---------------------------------------------------------
// 関数定義
//---------------------------------------------------------
void gamen_Init(void)
{
	// 仮想ターミナルシーケンスを有効にする
	MySetEnableVirtualTreminal();
	// フォントサイズをセット
	MySetFontSize(FONT_SIZE);
	// ウィンドウサイズをセット
	MySetWindowInfo(SCREEN_X, SCREEN_Y);
}

void gamen_End(void)
{
	// 仮想ターミナルシーケンスのテキスト属性をリセット
	MyResetTextAttr();
}

//-------------------------------------------------------------------
// WindowsAPIの最後のエラーのメッセージを表示する
//-------------------------------------------------------------------
void MyLastErrorPrint(const char* mes)
{
	DWORD	err_no, ret;
	char	buf[512];			// エラーメッセージを受け取る文字配列

	err_no = GetLastError();	// WIndowsAPIの最後のエラーの番号を入手
	ret = FormatMessageA(		// エラー番号に対応したエラーメッセージを入手
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, err_no, 0, buf, sizeof(buf) / sizeof(buf[0]), NULL);

	if (ret > 0) {
		// エラーメッセージ文字列入手できた場合は入手したメッセージを表示
		printf("%s(%d):%s", mes, err_no, buf);
	}
	else {
		// エラーメッセージ文字列入手できなかった場合は指定された文字列だけ表示
		printf("%s(%d)\n", mes, err_no);
	}
}

//-------------------------------------------------------------------
// 仮想ターミナルシーケンスを有効にする
//-------------------------------------------------------------------
void MySetEnableVirtualTreminal(void)
{
	DWORD mode;		// コンソールのモード取得用

	if (!GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode)) {
		MyLastErrorPrint("GetConsoleMode");
	}
	else {
		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;	// エスケープシーケンスを有効にする
		mode |= DISABLE_NEWLINE_AUTO_RETURN;	// 画面右下に出力した時、スクロールさせない設定
		if (!SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode)) {
			MyLastErrorPrint("SetConsoleMode");
		}
	}
}

//-------------------------------------------------------------------
// 指定したフォントサイズを設定する
// ※ SetCurrentConsoleFontExは、従来のWindowsコンソールです
//-------------------------------------------------------------------
void MySetFontSize(int font_size)
{
	const int	min_size = 6, max_size = 24;
	CONSOLE_FONT_INFOEX	sFont;	// フォントサイズ変更用

	if (font_size < min_size) {
		printf("%dは範囲外のため%dに変更しました\n", font_size, min_size);
		font_size = min_size;
	}
	else if (font_size > max_size) {
		printf("%dは範囲外のため%dに変更しました\n", font_size, max_size);
		font_size = max_size;
	}

	// Releaseビルド時、GetCurrentConsoleFontExせずにSetCurrentConsoleFontExすると
	// フォントをセットできなかったのでGetCurrentConsoleFontExする様にした(2021.01.19 上田)
	sFont.cbSize = sizeof(sFont);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &sFont);	// フォント情報を入手

	sFont.dwFontSize.X = font_size / 2;		// フォントサイズの半分が横ピクセル値
	sFont.dwFontSize.Y = font_size;			// 縦ピクセル値はフォントサイズと同じ
	if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &sFont)) {	// 今後は仮想端末シーケンスを推奨
		MyLastErrorPrint("SetCurrentConsoleFontEx");
	}
}

//-------------------------------------------------------------------
// 指定したウィンドウサイズを設定する
// ※ SetConsoleWindowInfo,SetConsoleScreenBufferSizeは、従来のWindowsコンソールです
//    SetConsoleWindowInfoは、以下の場合、エラーになります
//    ・バッファサイズより大きなウィンドウサイズを指定した
//    ・最大バッファサイズより大きなウィンドウサイズを指定した
//-------------------------------------------------------------------
void MySetWindowInfo(int width, int height)
{
	CONSOLE_SCREEN_BUFFER_INFO	nowInfo;// ウィンドウの現状値入手用
	SMALL_RECT					sScreen;// ウィンドウサイズ変更用
	COORD						sBuff;	// バッファ変更用

	// 現状バッファより大きなウィンドウサイズを指定した場合は
	// バッファサイズを指定したウィンドウサイズに変更する
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &nowInfo);		// ウィンドウの現状値を入手

	sBuff.X = (width > nowInfo.dwSize.X) ? width : nowInfo.dwSize.X;
	sBuff.Y = (height > nowInfo.dwSize.Y) ? height : nowInfo.dwSize.Y;

	if (!SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), sBuff)) {
		MyLastErrorPrint("SetConsoleScreenBufferSize");
	}

	// 最大ウィンドウより大きなウィンドウサイズを指定した場合は
	// 最大ウィンドウサイズに変更する
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &nowInfo);		// ウィンドウの現状値を入手

	sScreen.Left = 0;
	sScreen.Right =
		((width > nowInfo.dwMaximumWindowSize.X) ? nowInfo.dwMaximumWindowSize.X : (SHORT)(width)) - 1;
	sScreen.Top = 0;
	sScreen.Bottom =
		((height > nowInfo.dwMaximumWindowSize.Y) ? nowInfo.dwMaximumWindowSize.Y : (SHORT)(height)) - 1;

	if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &sScreen)) {
		MyLastErrorPrint("SetConsoleWindowInfo");
	}
}

//-------------------------------------------------------------------
// 仮想ターミナルシーケンスのテキスト属性をリセット
//-------------------------------------------------------------------
void MyResetTextAttr(void)
{
	printf("\033[0m");
}