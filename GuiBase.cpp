#include <iostream>
#include "lib.h"
using namespace std;

// 设置显存    30行120列
string OutPutMemory[30][120];

/// <summary>
/// 显示初始化，基于更改显存的方式
/// </summary>
/// <param name="Mode">是否刷新显存</param>
void GUI_Init(int Mode)
{
	// 设置窗口大小
	system("mode con cols=120 lines=30");
	for (int i = 0; i < 120; i++) {
		OutPutMemory[0][i] = "-";
	}
	//cout << endl;
	for (int m = 1; m < 28; m++) {
		OutPutMemory[m][0] = "|";
		for (int j = 1; j < 119; j++) {
			OutPutMemory[m][j] = " ";
		}
		OutPutMemory[m][119]= "|";
	}
	//cout << endl;
	for (int n = 0; n < 120; n++) {
		OutPutMemory[28][n] = "-";
	}
	// 刷新显存
	if (Mode == 1)
	{
		for (int a = 0; a < 30; a++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
}


/// <summary>
/// 画矩形，操作显存
/// </summary>
/// <param name="x">起始x坐标</param>
/// <param name="y">起始y坐标</param>
/// <param name="w">矩形长度</param>
/// <param name="h">矩形高度</param>
/// <param name="arr">装填字符串</param>
/// <param name="Mode">是否刷新显存</param>
void GUI_DrawRect(int x, int y, int w, int h, string arr,int Mode)
{
	//GUI_Init(1);
	system("cls");

	for (int i = 0; i <= w; i++)
	{
		OutPutMemory[y][x + i] = "-";
		OutPutMemory[y + h][x + i] = "-";
	}

	for (int a = 0; a <= h; a++)
	{
		OutPutMemory[y + a][x] = "|";
		OutPutMemory[y + a][x + w] = "|";
	}

	for (int i = 0; i < arr.length(); i++)
	{
		OutPutMemory[y + 1][x + i + 1] = arr[i];
	}

	// 刷新显存
	if (Mode == 1)
	{
		for (int a = 0; a < 30; a++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
}


/// <summary>
/// 清除部分显示，基于显存
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <param name="Mode"></param>
void GUI_Clear(int x, int y, int w, int h, int Mode)
{
	//static string OldOutPutMemory[30][120];		// 保存旧的显存
	//// 保存旧的显存
	//memcpy(OldOutPutMemory, OutPutMemory, sizeof(OutPutMemory));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			OutPutMemory[y + i][x + j] = " ";
		}
	}
	// 刷新显存
	if (Mode == 1)
	{
		for (int a = 0; a < 30; a++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
	/*return OldOutPutMemory;*/
}

/// <summary>
/// 界面全填充#
/// </summary>
void GUI_PaddingAll(string c,int Mode)
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			// 略过边框
			if (i == 0 || i == 28 || j == 0 || j == 119)
			{
				continue;
			}
			OutPutMemory[i][j] = c;
		}
	}

	// 刷新显存
	if (Mode == 1)
	{
		for (int a = 0; a < 30; a++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
}

/// <summary>
/// 部分填充#
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <param name="Mode"></param>
void GUI_PaddingPart(int x,int y,int w,int h,string c,int Mode)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			OutPutMemory[y + i][x + j] = c;
		}
	}
	// 刷新显存
	if (Mode == 1)
	{
		for (int a = 0; a < 30; a++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << OutPutMemory[a][j];
			}
			cout << endl;
		}
	}
}
