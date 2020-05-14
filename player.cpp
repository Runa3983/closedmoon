#include"DxLib.h"
#include"player.h"
#include"main.h"

#define STATUS_NORMAL 0
#define STATUS_ATTCK 1
#define INIT_VELOCITY 70.0f			// ジャンプの初速度

// 変数
int P1StopImage;			// 停止中の画像
int P1RunImage;				// ダッシュ中の画像
int P1JunpImage[2];			// ジャンプ中の画像(攻撃も含める)

int P1DamegeImage;			// ダメージを受けた時の画像
int P1Attack1Image;			// 通常攻撃の画像
int P1Attack2Image[3];			// 特殊攻撃の画像


CHARACTER player1;

void PlayerSystemInit(void)
{
	// 攻撃状態
	P1Attack1Image = LoadGraph("image/ataack1.png");

	player1.attckFlag = false;			// キャラクターの状態
	player1.runFlag = false;			// キャラクターの状態
	player1.jumpFlag = false;			// キャラクターの状態
	player1.damageFlag = false;			// キャラクターの状態
	player1.imgLockCnt = 0;				// キャラクターの状態
	player1.velocity = { 0, INIT_VELOCITY };
}

void PlayerGameInit(void)
{
	// プレイヤーの初期値
	player1.attckFlag = false;			// キャラクターの攻撃状態
	player1.runFlag = false;			// キャラクターの歩き状態
	player1.jumpFlag = false;			// キャラクターのジャンプ状態
	player1.damageFlag = false;			// キャラクターのダメージ状態
	player1.imgLockCnt = 0;				// キャラクターの状態
	player1.velocity = { 0, INIT_VELOCITY };
}

void PlayerContol(void)
{

}

void PlayerGameDraw(void)
{
	DrawGraph(325, 325, P1Attack1Image, true);
}