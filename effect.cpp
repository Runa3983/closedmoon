#include "DxLib.h"
#include "effect.h"

// �ϐ�
// �ꎞ��~�����p
bool pauseFlag;			// �ꎞ��~�@�\�p(true : �ꎞ��~��)
int testcnt;

// �t�F�[�h����
bool fadeIn;			// �t�F�[�h�C��
bool fadeOut;			// �t�F�[�h�A�E�g
int fadeCnt;			// �t�F�[�h�J�E���^

// �G�t�F�N�g�p����������
void EffectInit(void)
{
	// �ꎞ��~�����p
	pauseFlag = false;
	// �t�F�[�h�����p
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}
// �V�[�����񂢊֐�
						// �t�F�[�h�C���p(�ߒl: true= �t�F�[�h�C�����Afalse= �t�F�[�h�C���I�� ����: fadestep = �t�F�[�h�̑��x)
bool FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return  false;
	}
}
// �t�F�[�h�A�E�g(�ߒl: true= �t�F�[�h�C�����Afalse= �t�F�[�h�C���I�� ����: fadestep = �t�F�[�h�̑��x)
bool FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		fadeIn = true;
		return false;
	}
}