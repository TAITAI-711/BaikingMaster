// �Q�[����ʗp�w�b�_

#ifndef _GAME_H_	// �Q�d�C���N���[�h�h�~�̃}�N����`
#define _GAME_H_

#include "game.h"
#include "conioex.h"

//-------------------------------------------------------------------
// �}�N����`
//-------------------------------------------------------------------
#define FONT_SIZE	18								// �t�H���g�̃T�C�Y
#define SCREEN_X	120								// �ő��ʃT�C�YX
#define SCREEN_Y	30								// �ő��ʃT�C�YY

#define GAME_TIME	61000							// �Q�[������
#define COUNT_TIME	3000							// �Q�[���̃J�E���g����

#define PLAYER_S_POS_X			(FOOD_EAT_X + 5)	// �v���C���[�̏������WX
#define PLAYER_S_POS_Y			15					// �v���C���[�̏������WY
#define PLAYER_MOVE_X			0.5f				// �v���C���[�̈ړ���X
#define PLAYER_MOVE_Y			0.25f				// �v���C���[�̈ړ���Y

#define UI_X		99								// UI�̐F�ւ���X���W
#define UI_TIME_Y	3								// UI�̐������Ԃ̕���Y���W
#define UI_RYOURI_Y	18								// UI�̎����Ă��闿���̐��̕���Y���W

#define FOOD_EAT_X	10								// �����̐H�ׂ�Ƃ����X���W

#define RYOURI_WAKU_1_4_POS_X		25				// �����̘g1,4�̕\��X���W
#define RYOURI_WAKU_2_5_POS_X		50				// �����̘g2,5�̕\��X���W
#define RYOURI_WAKU_3_6_POS_X		75				// �����̘g3,6�̕\��X���W

#define AA_SYURUI	8								// AA�̎��(�v���C���[,�����̘g...)

#define RYOURI_HAVE_COLOR_1		BLUE				// �����Ă��闿���̐��̕����̐F
#define RYOURI_HAVE_COLOR_2		LIGHTBLUE			// �����Ă��闿���̐��̐F

//---------------------------------------------------------
// �\����
//---------------------------------------------------------
// �v���[���[
typedef struct {
	int food_have;				// �v���[���[�̎����Ă��闿���̗�
	int food_uketori_num[5];	// �󂯎���������̔ԍ�
	int uketori_num;			// �󂯎���������̔ԍ��X�V�p
	int food_eat_num[150];		// �H�ׂ������̔ԍ�
	int eat_num;				// �H�ׂ������̔ԍ��X�V�p
}PLAYER;

// �v���[���[�̍��W
typedef struct {
	int	muki;			// �v���C���[�̌���(0:�E, 1:��)
	int zanzou;			// �v���[���[�̎c���������p(0:�����Ȃ�, 1:��, 2:��, 4:��, 8:�E)
	float x;			// �v���[���[��X���W
	float y;			// �v���[���[��Y���W
	float previous_x;	// �v���[���[�̂P�O��X���W
	float previous_y;	// �v���[���[�̂P�O��Y���W
	float limit_L;		// ���E���W��
	float limit_R;		// ���E���W�E
	float limit_U;		// ���E���W��
	float limit_D;		// ���E���W��
}PLAYER_POS;

// ���̑��̕\�����W
typedef struct {
	int x;
	int y;
}OTHER_POS;

// AA�̍����ƕ�
typedef struct {
	int tate;
	int yoko;
}AA_SIZE;

// �����̎󂯎����
typedef struct {
	int iti;		// �󂯎��\�ʒu������(-1:�s��,0:�����P�̈ʒu,1:�����Q�̈ʒu...)
	int waku_color[6];	// �����̘g�̎󂯎�蕔���̐F
	bool ok[6];		// �󂯎��\������
	bool eat_iti;	// �H�ׂ�Ƃ���̈ʒu�ɂ��邩����
}RYOURI_UKETORI;

//---------------------------------------------------------
// �֐��v���g�^�C�v�錾
//---------------------------------------------------------
void game_Init(void);
void game_End(void);
void game_Update(void);
void game_Draw(void);
void player_set_Init(void);
void player_move_Update(void);
void player_Draw(void);
void ui_waku_Init(void);
void ui_waku_Draw(void);
void ui_Draw(void);
void ryouri_waku_Draw(void);
void ryouri_waku_uketori_Update(void);
void ryouri_waku_uketori_Draw(void);
void p_zanzou_kesu_Update(void);
void p_zanzou_kesu_Draw(void);
void AA_info_Init(void);
void player_food_have_Update(void);
void food_eat_Update(void);
void food_eat_Draw(void);
void AA_size_input(const char* p[], AA_SIZE AA_size[], int AA_num);
void player_uketori_iti(void);
void p_pos_limit_input(void);
void AA_count_END_Draw(void);
void AA_count_NUM_Draw(void);
const char* eat_ryouri_name(int i);
const int eat_ryouri_num(void);
const int eat_ryouri_nedan(int i);
const int eat_ryouri_color(int i);

#endif /*_GAME_H_*/