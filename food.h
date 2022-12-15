// �H�ו��p�w�b�_

#ifndef _FOOD_H_	// �Q�d�C���N���[�h�h�~�̃}�N����`
#define _FOOD_H_

#include "food.h"
#include "game.h"
#include "conioex.h"

//---------------------------------------------------------
// �\����
//---------------------------------------------------------
// �H�ו�
typedef struct {
	char name[16 + 1];		// �H�ו��̖��O
	int color;			// �H�ו��̖��O�̐F
	int amount;			// �H�ו��̗�
	int nedan;			// �H�ו��̒l�i
}FOOD;

// �H�ו��̏��
typedef struct {
	const char* p[6];		// �����̗ʕ\��AA�p
	bool uketori[6];		// �������󂯎����������p
}FOOD_INFO;

// �H�ו��̐؂�ւ�
typedef struct {
	DWORD scroll_time[6];		// �����̐؂�ւ��X�N���[���Ԋu
	int y[6];					// �����̕\��Y���W�����p
	bool hantei[6];				// �����̐؂�ւ�����p
	bool scroll_hantei[6];		// �X�N���[������p
}FOOD_KIRIKAE;

// �����_��
typedef struct {
	DWORD kirikae_time[6];	// �\����؂�ւ���Ԋu�p
	int num[6];				// �\�����闿���p
	int pre_num[6];			// �ЂƂO�̕\�����闿���p
	bool pre_num_hantei[6];	// pre_num����͂��锻��p
}RANDOM;

//---------------------------------------------------------
// �֐��v���g�^�C�v�錾
//---------------------------------------------------------
void food_Init(int waku_tate, int waku_yoko);
void food_End(void);
void food_Update(DWORD now_game_time);
void food_Draw(void);
void random_Update(int i);
void random_Init(void);
void food_pos_Update(int i, int j, OTHER_POS* p);
void food_kuhaku_pos_Init(void);
void ryouri_kuhaku_Draw(int i, bool ue);
void food_amount_pos_Init(void);
void ryouri_amount_AA_Update(int i);
void food_nedan_pos_Update(int i, int j, OTHER_POS* p);
void ryouri_pre_pos_Update(int i);
const int ryouri_amount(int i);
const int ryouri_uketori(int i);
const char* ryouri_name(int i);
const int ryouri_nedan(int i);
const bool ryouri_kirikae_hantei(int i);
const int ryouri_color(int i);

#endif