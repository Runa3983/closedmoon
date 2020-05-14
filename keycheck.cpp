#include "DxLib.h"
#include "keycheck.h"

// キー制御用
bool keyOld[KEY_ID_MAX];			// 1フレーム前のキー状態
bool keyNew[KEY_ID_MAX];			// 現在のキー状態
bool keyDownTrigger[KEY_ID_MAX];	// キー押下時のトリガー
bool keyUpTrigger[KEY_ID_MAX];		// キーアップ時のトリガー


									// キー制御配列の初期化
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

// キー情報の所得
void keyCheck(void)
{
	// １フレーム前のキー情報をコピー
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}

	// 現在のキー情報を所得する
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);

	// トリガー情報を所得する
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// トリガー情報の初期化
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
		// トリガー情報の所得
		// 押した瞬間
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