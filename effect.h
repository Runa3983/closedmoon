#include "DxLib.h"

// 一時停止処理用
extern bool pauseFlag;			// 一時停止機能用(true : 一時停止中)
extern int testcnt;

// フェード処理用
extern bool fadeIn;			// フェードイン
extern bool fadeOut;		// フェードアウト

// プロトタイプ宣
// ----------
void EffectInit(void);						// フェード用初期化処理
// シーンかんい関数
bool FadeInScreen(int fadeStep);			// フェードイン用(戻値 true= フェードイン中 false= フェードイン終了 引数 fadestep = フェードの速度)
bool FadeOutScreen(int fadeStep);			// フェードアウト
