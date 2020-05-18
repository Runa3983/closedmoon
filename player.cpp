#include"DxLib.h"
#include"player.h"
#include"main.h"
#include"keycheck.h"

#define STATUS_NORMAL 0
#define STATUS_ATTCK 1
#define INIT_VELOCITY 70.0f			// ジャンプの初速度

// 変数
int P1StopImage[2];			// 停止中の画像
int P1RunImage;				// ダッシュ中の画像
int P1JumpImage[2];			// ジャンプ中の画像(攻撃も含める)

int P1DamegeImage;			// ダメージを受けた時の画像
int P1Attack1Image[2];			// 通常攻撃の画像
int P1Attack2Image[3];			// 特殊攻撃の画像


CHARACTER player1;

void PlayerSystemInit(void)
{
	// 攻撃状態
	P1Attack1Image[STATUS_NORMAL] = LoadGraph("image/attck1-1.png");
	P1Attack1Image[STATUS_ATTCK] = LoadGraph("image/attck1-2.png");
	P1StopImage[STATUS_NORMAL] = LoadGraph("image/Stop.png");

	// プレイヤーの初期値
	player1.pos = { 325,  325 };
	player1.moveDir = DIR_RIGHT;
	player1.size = { 100, 70 };
	player1.sizeOffset = { player1.size.x / 2, player1.size.y / 2 };
	player1.hitPosS = { 35,30 };
	player1.hitPosE = { 30, 120 };
	player1.moveSpeed = 4;
	player1.animCnt = 0;

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
	bool moveFlag = false;
	player1.runFlag = false;

	// ジャンプ押下の判断
	if (keyNew[KEY_ID_P1JUMP])
	{
		player1.jumpFlag = true;
	}

	// ジャンプ処理
	if (player1.jumpFlag)
	{
		XY player1PosCopy = player1.pos;			// プレイヤーの座標のコピー
		XY playerHitPos = player1.pos;				// プレイヤーの当たり判定用

		player1.velocity.y -= ACC_G * FRAME_TIME;
		player1PosCopy.y -= player1.velocity.y * FRAME_TIME;
		playerHitPos.y = player1PosCopy.y + player1.hitPosE.y;
		/*if (IsPass(playerHitPos))
		{
			player1.pos.y = player1PosCopy.y;
		}
		else
		{
			player1.jumpFlag = false;
			player1.velocity.y = INIT_VELOCITY;
		}*/
	}

	// 攻撃処理
	player1.attckFlag = false;
	if (keyNew[KEY_ID_P1ATTCK])
	{
		player1.attckFlag = true;
	}

	// プレイヤーの移動
	if (keyNew[KEY_ID_P1LEFT])
	{
		moveFlag = true;
		player1.moveDir = DIR_LEFT;
	}
	if (keyNew[KEY_ID_P1RIGHT])
	{
		moveFlag = true;
		player1.moveDir = DIR_RIGHT;
	}
	// キーが押されているなら移動する
	if (moveFlag)
	{
		player1.runFlag = true;

		if (player1.moveDir == DIR_LEFT)
		{
			player1.pos.x -= player1.moveSpeed;
		}
		if (player1.moveDir == DIR_RIGHT)
		{
			player1.pos.x += player1.moveSpeed;
		}
	}
}

void PlayerGameDraw(void)
{
	//DrawGraph(325, 325, P1Attack1Image, true);

	int p1attck = (player1.attckFlag) ? STATUS_ATTCK : STATUS_NORMAL;
	int p1Image = P1StopImage[p1attck];

	if (player1.attckFlag) p1Image = P1Attack1Image[p1attck];

	// キャラクタの表示
	if (player1.moveDir == DIR_RIGHT)
	{
		DrawGraph(player1.pos.x - player1.sizeOffset.x
			, player1.pos.y - player1.sizeOffset.y
			, p1Image
			, true);
	}

	if (player1.moveDir == DIR_LEFT)
	{
		DrawTurnGraph(player1.pos.x - player1.sizeOffset.x
			, player1.pos.y - player1.sizeOffset.y
			, p1Image
			, true);
	}

	// キャラクターの当たり判定の枠の表示
	DrawBox(player1.pos.x - player1.hitPosS.x, player1.pos.y - player1.hitPosS.y
		, player1.pos.x + player1.hitPosE.x, player1.pos.y + player1.hitPosE.y
		, GetColor(255, 0, 0)
		, false);
}