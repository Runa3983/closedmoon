#include "DxLib.h"
#include "effect.h"

// 変数
// 一時停止処理用
bool pauseFlag;			// 一時停止機能用(true : 一時停止中)
int testcnt;

// フェード処理
bool fadeIn;			// フェードイン
bool fadeOut;			// フェードアウト
int fadeCnt;			// フェードカウンタ

// エフェクト用初期化処理
void EffectInit(void)
{
	// 一時停止処理用
	pauseFlag = false;
	// フェード処理用
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}
// シーンかんい関数
						// フェードイン用(戻値: true= フェードイン中、false= フェードイン終了 引数: fadestep = フェードの速度)
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
// フェードアウト(戻値: true= フェードイン中、false= フェードイン終了 引数: fadestep = フェードの速度)
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