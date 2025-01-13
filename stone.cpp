#include "lib.h"

// 创建游戏地形--石头
void CreateStone(int x, int y, int w, int h, int Mode)
{
	GUI_DrawRect(x, y, w, h, "■", Mode);
}