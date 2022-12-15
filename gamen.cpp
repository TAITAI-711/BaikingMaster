// ��ʗp

#define CONIOEX
#include "conioex.h"
#include "gamen.h"
#include "game.h"

//---------------------------------------------------------
// �֐���`
//---------------------------------------------------------
void gamen_Init(void)
{
	// ���z�^�[�~�i���V�[�P���X��L���ɂ���
	MySetEnableVirtualTreminal();
	// �t�H���g�T�C�Y���Z�b�g
	MySetFontSize(FONT_SIZE);
	// �E�B���h�E�T�C�Y���Z�b�g
	MySetWindowInfo(SCREEN_X, SCREEN_Y);
}

void gamen_End(void)
{
	// ���z�^�[�~�i���V�[�P���X�̃e�L�X�g���������Z�b�g
	MyResetTextAttr();
}

//-------------------------------------------------------------------
// WindowsAPI�̍Ō�̃G���[�̃��b�Z�[�W��\������
//-------------------------------------------------------------------
void MyLastErrorPrint(const char* mes)
{
	DWORD	err_no, ret;
	char	buf[512];			// �G���[���b�Z�[�W���󂯎�镶���z��

	err_no = GetLastError();	// WIndowsAPI�̍Ō�̃G���[�̔ԍ������
	ret = FormatMessageA(		// �G���[�ԍ��ɑΉ������G���[���b�Z�[�W�����
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, err_no, 0, buf, sizeof(buf) / sizeof(buf[0]), NULL);

	if (ret > 0) {
		// �G���[���b�Z�[�W���������ł����ꍇ�͓��肵�����b�Z�[�W��\��
		printf("%s(%d):%s", mes, err_no, buf);
	}
	else {
		// �G���[���b�Z�[�W���������ł��Ȃ������ꍇ�͎w�肳�ꂽ�����񂾂��\��
		printf("%s(%d)\n", mes, err_no);
	}
}

//-------------------------------------------------------------------
// ���z�^�[�~�i���V�[�P���X��L���ɂ���
//-------------------------------------------------------------------
void MySetEnableVirtualTreminal(void)
{
	DWORD mode;		// �R���\�[���̃��[�h�擾�p

	if (!GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode)) {
		MyLastErrorPrint("GetConsoleMode");
	}
	else {
		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;	// �G�X�P�[�v�V�[�P���X��L���ɂ���
		mode |= DISABLE_NEWLINE_AUTO_RETURN;	// ��ʉE���ɏo�͂������A�X�N���[�������Ȃ��ݒ�
		if (!SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode)) {
			MyLastErrorPrint("SetConsoleMode");
		}
	}
}

//-------------------------------------------------------------------
// �w�肵���t�H���g�T�C�Y��ݒ肷��
// �� SetCurrentConsoleFontEx�́A�]����Windows�R���\�[���ł�
//-------------------------------------------------------------------
void MySetFontSize(int font_size)
{
	const int	min_size = 6, max_size = 24;
	CONSOLE_FONT_INFOEX	sFont;	// �t�H���g�T�C�Y�ύX�p

	if (font_size < min_size) {
		printf("%d�͔͈͊O�̂���%d�ɕύX���܂���\n", font_size, min_size);
		font_size = min_size;
	}
	else if (font_size > max_size) {
		printf("%d�͔͈͊O�̂���%d�ɕύX���܂���\n", font_size, max_size);
		font_size = max_size;
	}

	// Release�r���h���AGetCurrentConsoleFontEx������SetCurrentConsoleFontEx�����
	// �t�H���g���Z�b�g�ł��Ȃ������̂�GetCurrentConsoleFontEx����l�ɂ���(2021.01.19 ��c)
	sFont.cbSize = sizeof(sFont);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &sFont);	// �t�H���g�������

	sFont.dwFontSize.X = font_size / 2;		// �t�H���g�T�C�Y�̔��������s�N�Z���l
	sFont.dwFontSize.Y = font_size;			// �c�s�N�Z���l�̓t�H���g�T�C�Y�Ɠ���
	if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &sFont)) {	// ����͉��z�[���V�[�P���X�𐄏�
		MyLastErrorPrint("SetCurrentConsoleFontEx");
	}
}

//-------------------------------------------------------------------
// �w�肵���E�B���h�E�T�C�Y��ݒ肷��
// �� SetConsoleWindowInfo,SetConsoleScreenBufferSize�́A�]����Windows�R���\�[���ł�
//    SetConsoleWindowInfo�́A�ȉ��̏ꍇ�A�G���[�ɂȂ�܂�
//    �E�o�b�t�@�T�C�Y���傫�ȃE�B���h�E�T�C�Y���w�肵��
//    �E�ő�o�b�t�@�T�C�Y���傫�ȃE�B���h�E�T�C�Y���w�肵��
//-------------------------------------------------------------------
void MySetWindowInfo(int width, int height)
{
	CONSOLE_SCREEN_BUFFER_INFO	nowInfo;// �E�B���h�E�̌���l����p
	SMALL_RECT					sScreen;// �E�B���h�E�T�C�Y�ύX�p
	COORD						sBuff;	// �o�b�t�@�ύX�p

	// ����o�b�t�@���傫�ȃE�B���h�E�T�C�Y���w�肵���ꍇ��
	// �o�b�t�@�T�C�Y���w�肵���E�B���h�E�T�C�Y�ɕύX����
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &nowInfo);		// �E�B���h�E�̌���l�����

	sBuff.X = (width > nowInfo.dwSize.X) ? width : nowInfo.dwSize.X;
	sBuff.Y = (height > nowInfo.dwSize.Y) ? height : nowInfo.dwSize.Y;

	if (!SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), sBuff)) {
		MyLastErrorPrint("SetConsoleScreenBufferSize");
	}

	// �ő�E�B���h�E���傫�ȃE�B���h�E�T�C�Y���w�肵���ꍇ��
	// �ő�E�B���h�E�T�C�Y�ɕύX����
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &nowInfo);		// �E�B���h�E�̌���l�����

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
// ���z�^�[�~�i���V�[�P���X�̃e�L�X�g���������Z�b�g
//-------------------------------------------------------------------
void MyResetTextAttr(void)
{
	printf("\033[0m");
}