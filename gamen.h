// ��ʗp�w�b�_

#ifndef _GAMEN_H_	// �Q�d�C���N���[�h�h�~�̃}�N����`
#define _GAMEN_H_

#include "gamen.h"

//---------------------------------------------------------
// �֐��v���g�^�C�v�錾
//---------------------------------------------------------
void gamen_Init(void);
void gamen_End(void);
void MyLastErrorPrint(const char* mes);
void MySetEnableVirtualTreminal(void);
void MySetFontSize(int font_size);
void MySetWindowInfo(int width, int height);
void MyResetTextAttr(void);

#endif
