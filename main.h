// 定数
#define SCREEN_SIZE_X	765			// 画面の縦サイズ	
#define SCREEN_SIZE_Y	480			// 画面の横サイズ
#define ACC_G 10					// 重力加速度
#define FRAME_TIME 0.3f				// [s]

// シーン管理用
enum SCENE_ID {
	SCENE_ID_INIT				// 初期化シーン
	, SCENE_ID_TITLE			// タイトルシーン
	, SCENE_ID_GAME				// ゲームシーン
	, SCENE_ID_GAMEOVER			// ゲームオーバーシーン
	, SCENE_ID_MAX
};

enum DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

enum PlayerName {
	Name_TukikageRuna,
	Name_RunaKaos,
	Name_RunaBuled,
	Name_RunaMagic,
	Name_RunaBaret,
	Name_MeizukiZanki,
	Name_TukikageKoi,
	Name_YamikageRuna,
	Name_RunaDestroi
};

struct XY {
	int x;
	int y;
};

struct XY_F {
	float x;
	float y;
};

struct CHARACTER {
	DIR moveDir;				// 向いている方向
	XY pos;						// キャラクターの座標
	XY size;					// キャラクターの大きさ
	XY sizeOffset;				// キャラクターのオフセットサイズ
	XY hitPosS;					// 当たり判定
	XY hitPosE;					// 当たり判定
	int moveSpeed;				// キャラクターのスピード
	int life;					// キャラクターの体力
	int lifeMax;				// キャラクターの最大体力
	int animCnt;				// キャラクターのアニメーション

	bool runFlag;				// キャラクターの状態
	bool jumpFlag;				// キャラクターの状態
	bool attckFlag;				// キャラクターの状態
	bool damageFlag;			// キャラクターの状態
	int imgLockCnt;				// キャラクターのイメージ

	XY_F velocity;				// キャラクターの速度
};

// プロトタイプ宣言
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
