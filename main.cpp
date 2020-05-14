#include "DxLib.h"		// Dxlibﾗｲﾌﾞﾗﾘを使用する
#include"main.h"
// 変数
int sceneCounter;
int test;

// WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// システムの初期化
	if (!SystemInit())
	{
		return 0;
	}

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		ClsDrawScreen();				// 画面消去

		sceneCounter++;

		ScreenFlip();	 // 裏画面を表画面に瞬間ｺﾋﾟｰ
	}

	DxLib_End();	// DXﾗｲﾌﾞﾗﾘの終了処理
	return 0;		// このﾌﾟﾛｸﾞﾗﾑの終了
}

// システム初期化
bool SystemInit(void)
{
	// ｼｽﾃﾑ処理
	SetWindowText("Gekaisensou");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// グラフィックの登録

	// 変数初期化
	sceneCounter = 0;

	return true;
}

// 初期化シーン
void InitScene(void)
{

}

// タイトルシーン
void TitleScene(void)
{
	TitleDraw();
}
void TitleDraw(void)
{

}

// ゲームシーン
void GameScene(void)
{
	
	GameDraw();
}
void GameDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameScene = %d", sceneCounter);
}

// ゲームオーバーシーン
void GameOverScene(void)
{
	GameOverDraw();
}
void GameOverDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOverScene = %d", sceneCounter);
}