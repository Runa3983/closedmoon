#include "DxLib.h"		// Dxlibﾗｲﾌﾞﾗﾘを使用する
#include "main.h"
#include "stage.h"
// 変数
int chipImage[13];

int map[MAP_Y][MAP_X] = {
{ 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1 },
{ 1,1,0,1,1,1,1,1, 1,0,1,1,1,1,0,1, 1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,0,1,1, 1,1,1,0,1,1,1,1, 0,1,1,1,0,1,1,1 },
{ 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1, 1,0,1,1,1,1,1,1, 1,1,0,1,1,1,1,1 },
{ 1,1,1,1,0,1,1,1, 1,1,1,1,0,1,1,1, 1,1,1,1,1,1,1,1 },
{ 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1 },
{ 6,7,6,7,6,7,6,7, 6,7,6,7,6,7,6,7, 8,6,7,6,7,6,7,6 },

{ 5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,3, 4,5,5,5,5,5,5,5 },
{ 5,5,5,5,5,5,5,5, 5,5,5,5,5,5,3,4, 5,5,5,5,9,5,5,5 },
{ 5,5,5,5,5,9,5,5, 5,5,5,5,5,3,4,9, 5,5,5,5,5,5,5,5 },
{ 5,5,5,9,5,5,5,5, 5,5,5,5,3,4,5,5, 5,5,9,5,5,5,5,5 },
{ 2,2,2,2,2,2,2,2, 2,2,2,2,12,2,2,2, 2,2,2,2,2,2,2,2 },
{ 10,10,10,10,10,10,10,10, 10,10,10,10,10,10,10,10, 10,10,10,10,10,10,10,10 },
{ 11,11,11,11,11,11,11,11, 11,11,11,11,11,11,11,11, 11,11,11,11,11,11,11,11 }
};
XY mapSize;			// マップの縦横のチップ数

// ステージ情報の初期化
void StageSystemInit(void)
{
	// マップチップを読み込む
	LoadDivGraph("image/Heigen.png", 13, 13, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, chipImage, false);
}

void StageGameInit(void)
{

}

void StageGameDraw(void)
{
	mapSize.y = MAP_Y;
	mapSize.x = MAP_X;
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			DrawGraph(x * CHIP_SIZE_X, y * CHIP_SIZE_Y, chipImage[map[y][x]], true);
		}
	}
}

// ピクセルの座標をマップ配列の座標に変換する
XY PosToIndex(XY pos)
{
	XY index;
	// posをIndexに変換する
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	// 戻り値を返す
	return index;
}

// マップ配列の座標をピクセルの座標に変換する
XY IndexToPos(XY index)
{
	XY pos;
	// Indexをposに変換する
	pos.x = index.x * CHIP_SIZE_X;
	pos.y = index.y * CHIP_SIZE_Y;
	// 戻り値を返す
	return pos;
}

bool IsPass(XY pos)
{
	XY index;
	index = PosToIndex(pos);
	switch (map[index.y][index.x])
	{
	case 11:
		return false;
		break;
	default:
		break;
	}
	return true;
}
