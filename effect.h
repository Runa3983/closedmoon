#include "DxLib.h"

// �ꎞ��~�����p
extern bool pauseFlag;			// �ꎞ��~�@�\�p(true : �ꎞ��~��)
extern int testcnt;

// �t�F�[�h�����p
extern bool fadeIn;			// �t�F�[�h�C��
extern bool fadeOut;		// �t�F�[�h�A�E�g

// �v���g�^�C�v��
// ----------
void EffectInit(void);						// �t�F�[�h�p����������
// �V�[�����񂢊֐�
bool FadeInScreen(int fadeStep);			// �t�F�[�h�C���p(�ߒl true= �t�F�[�h�C���� false= �t�F�[�h�C���I�� ���� fadestep = �t�F�[�h�̑��x)
bool FadeOutScreen(int fadeStep);			// �t�F�[�h�A�E�g