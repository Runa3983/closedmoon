// �萔
#define SCREEN_SIZE_X	765			// ��ʂ̏c�T�C�Y	
#define SCREEN_SIZE_Y	480			// ��ʂ̉��T�C�Y

// �v���g�^�C�v�錾
// ----------
bool SystemInit(void);
// �������V�[��
void InitScene(void);
// �^�C�g���V�[��
void TitleScene(void);
void TitleDraw(void);
// �Q�[���V�[��
void GameScene(void);
void GameDraw(void);
// �Q�[���I�[�o�[�V�[��
void GameOverScene(void);
void GameOverDraw(void);