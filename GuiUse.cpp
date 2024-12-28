#include "lib.h"
#include <windows.h>
using namespace std;

extern string OutPutMemory[30][120];


/// <summary>
/// 移动#方块
/// </summary>
void MoveCube(int x, int y, int w, int h,string c, int Mode)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			GUI_PaddingPart(x + i, y + j, w, h, c, 0);
		}
	}
	// 刷新更改后的显存
	if (Mode == 1)
	{
		for (int a = x; a < w; a++)
		{
			for (int j = y; j < h; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
	//system("cls");
}

