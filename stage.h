// 定数
#define MAP_X 24			// マップの横サイズ
#define MAP_Y 15			// マップの縦サイズ
#define CHIP_SIZE_X 32			// マップチップの横サイズ
#define CHIP_SIZE_Y 32			// マップチップの縦サイズ

void StageSystemInit(void);
void StageGameInit(void);
void StageGameDraw(void);
XY PosToIndex(XY pos);				// ピクセルの座標をマップ配列の座標に変換する
XY IndexToPos(XY index);			// マップ配列の座標をピクセルの座標に変換する
bool IsPass(XY pos);
