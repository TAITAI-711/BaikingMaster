#ifndef _RESULT_H_	// �Q�d�C���N���[�h�h�~�̃}�N����`
#define _RESULT_H_

#include "result.h"
#include "conioex.h"

//-------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------
#define RYOURI_NAME_POS_X	10		// �����̖��O�\��X���W
#define RYOURI_NAME_POS_Y	6		// �����̖��O�\��Y���W
#define BAIKINGU_RYOUKIN	20000	// �o�C�L���O�̗���

//---------------------------------------------------------
// �\����
//---------------------------------------------------------
// ���U���g
typedef struct {
	int eat_ryouri_num; // �H�ׂ������̐�
	int ryouri_num;		// �H�ׂ������̐��X�V�p
	int eat_ryouri_nedan;		// �H�ׂ������̒l�i
	int eat_ryouri_goukei;		// �H�ׂ������̍��v���z
	int eat_ryouri_color;		// �H�ׂ������̖��O�̐F
	char eat_ryouri_name[16 + 1];	// �H�ׂ������̖��O
	bool name_hyouji;			// �H�ׂ������̖��O�\������
}RESULT;

//---------------------------------------------------------
// �֐��v���g�^�C�v�錾
//---------------------------------------------------------
void result_Init(void);
void result_End(void);
void result_Update(void);
void result_Draw(void);

#endif