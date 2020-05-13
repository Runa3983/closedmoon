// 定数
#define SCREEN_SIZE_X	765			// 画面の縦サイズ	
#define SCREEN_SIZE_Y	480			// 画面の横サイズ

// プロトタイプ宣言
// ----------
bool SystemInit(void);
// 初期化シーン
void InitScene(void);
// タイトルシーン
void TitleScene(void);
void TitleDraw(void);
// ゲームシーン
void GameScene(void);
void GameDraw(void);
// ゲームオーバーシーン
void GameOverScene(void);
void GameOverDraw(void);
