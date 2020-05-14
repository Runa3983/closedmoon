#include "DxLib.h"
#include "keycheck.h"

// �L�[����p
bool keyOld[KEY_ID_MAX];			// 1�t���[���O�̃L�[���
bool keyNew[KEY_ID_MAX];			// ���݂̃L�[���
bool keyDownTrigger[KEY_ID_MAX];	// �L�[�������̃g���K�[
bool keyUpTrigger[KEY_ID_MAX];		// �L�[�A�b�v���̃g���K�[


									// �L�[����z��̏�����
void keyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}

// �L�[���̏���
void keyCheck(void)
{
	// �P�t���[���O�̃L�[�����R�s�[
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}

	// ���݂̃L�[������������
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);

	// �g���K�[������������
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// �g���K�[���̏�����
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		// �g���K�[���̏���
		// �������u��
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}
	}
}