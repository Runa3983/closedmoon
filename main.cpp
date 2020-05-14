#include "DxLib.h"		// Dxlibﾗｲﾌﾞﾗﾘを使用する
#include"main.h"
#include"effect.h"
#include"keycheck.h"
#include"player.h"
// 変数
int sceneCounter;

SCENE_ID sceneID;		// シーン管理用
SCENE_ID sceneIDpre;		// 前回のシーン管理用
KEY_ID keyID;



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
		keyCheck();						// キー情報の所得
		ClsDrawScreen();				// 画面消去

		switch (sceneID)
		{
		case SCENE_ID_INIT:				// 初期化シーン
			InitScene();
			sceneID = SCENE_ID_TITLE;
			break;
		case SCENE_ID_TITLE:			// タイトルシーン
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// フェードインが終了した後に行う処理を書く
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトが終了した後に行う処理書く
					fadeIn = true;
					sceneID = SCENE_ID_GAME;
				}

			}

			TitleScene();
			break;
		case SCENE_ID_GAME:			// ゲームシーン
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// フェードインが終了した後に行う処理を書く
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトが終了した後に行う処理書く
					fadeIn = true;
					sceneID = SCENE_ID_GAMEOVER;
				}
			}

			GameScene();
			break;
		case SCENE_ID_GAMEOVER:			// ゲームオーバーシーン
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{
					// フェードインが終了した後に行う処理を書く
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトが終了した後に行う処理書く
					fadeIn = true;
					sceneID = SCENE_ID_INIT;
				}
			}

			GameOverScene();
			break;
		default:
			break;
		}

		// メイン処理

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

	keyInit();

	// グラフィックの登録

	// 変数初期化
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	sceneIDpre = SCENE_ID_MAX;

	EffectInit();			// エフェクト用初期化処理

	PlayerSystemInit();
	return true;
}

// 初期化シーン
void InitScene(void)
{

}

// タイトルシーン
void TitleScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	TitleDraw();
}
void TitleDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene = %d", sceneCounter);
}

// ゲームシーン
void GameScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	if (!keyDownTrigger[KEY_ID_PAUSE])
	{
		testcnt++;
	}

	GameDraw();
}
void GameDraw(void)
{
	PlayerGameDraw();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameScene = %d", sceneCounter);
	DrawFormatString(50, 50, GetColor(255, 255, 255), "test = %d", testcnt);

}

// ゲームオーバーシーン
void GameOverScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}

	GameOverDraw();
}
void GameOverDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOverScene = %d", sceneCounter);
}