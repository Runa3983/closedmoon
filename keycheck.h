// �萔
enum KEY_ID {
	KEY_ID_SPACE
	, KEY_ID_PAUSE
	, KEY_ID_MOUSE_LEFT
	, KEY_ID_MOUSE_MIDDLE
	, KEY_ID_MOUSE_RIGHT
	, KEY_ID_MAX
};

// �v���g�^�C�v�錾
void keyInit(void);			// �L�[����z��̏�����
void keyCheck(void);		// �L�[���̏���

// �ϐ�
extern bool keyOld[KEY_ID_MAX];					// 1�t���[���O�̃L�[���
extern bool keyNew[KEY_ID_MAX];					// ���݂̃L�[���
extern bool keyDownTrigger[KEY_ID_MAX];			// �L�[�������̃g���K�[
extern bool keyUpTrigger[KEY_ID_MAX];			// �L�[�A�b�v���̃g���K�[