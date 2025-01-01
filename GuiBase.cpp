#include <iostream>
#include "lib.h"
using namespace std;

// 设置显存    30行120列
CHAR_INFO OutPutMemory[30][120];

// 获取控制台窗口大小
COORD GetConsoleSize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		COORD size;
		size.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		size.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		return size;
	}
	return { 120, 30 }; // 默认大小
}


// 刷新显存
void RefreshScreen()
{
	COORD size = GetConsoleSize();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { size.X, size.Y };
	COORD bufferCoord = { 0, 0 };
	SMALL_RECT writeRegion = { 0, 0, bufferSize.X - 1, bufferSize.Y - 1 };
	WriteConsoleOutput(hConsole, (CHAR_INFO*)OutPutMemory, bufferSize, bufferCoord, &writeRegion);
}

/// <summary>
/// 显示初始化，基于更改显存的方式
/// </summary>
/// <param name="Mode">是否刷新显存</param>
void GUI_Init(int Mode)
{
	// 设置窗口大小
	COORD size = GetConsoleSize();
	for (int i = 0; i < size.X; i++) {
		OutPutMemory[0][i].Char.AsciiChar = '-';
		OutPutMemory[0][i].Attributes = FOREGROUND_RED;
	}
	for (int m = 1; m < size.Y-2; m++) {
		OutPutMemory[m][0].Char.AsciiChar = '|';
		OutPutMemory[m][0].Attributes = FOREGROUND_RED;
		for (int j = 1; j < size.X-1; j++) {
			OutPutMemory[m][j].Char.AsciiChar = ' ';
			OutPutMemory[m][j].Attributes = FOREGROUND_RED;
		}
		OutPutMemory[m][size.X - 1].Char.AsciiChar = '|';
		OutPutMemory[m][size.X - 1].Attributes = FOREGROUND_RED;
	}
	for (int n = 0; n < size.X; n++) {
		OutPutMemory[size.Y - 2][n].Char.AsciiChar = '-';
		OutPutMemory[size.Y - 2][n].Attributes = FOREGROUND_RED;
	}
	// 刷新显存
	if (Mode == 1)
	{
		RefreshScreen();
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

	for (int i = 0; i <= w; i++)
	{
		OutPutMemory[y][x + i].Char.AsciiChar = '-';
		OutPutMemory[y][x + i].Attributes = FOREGROUND_RED;

		OutPutMemory[y + h][x + i].Char.AsciiChar = '-';
		OutPutMemory[y + h][x + i].Attributes = FOREGROUND_RED;
	}

	for (int a = 0; a <= h; a++)
	{
		OutPutMemory[y + a][x].Char.AsciiChar = '|';
		OutPutMemory[y + a][x].Attributes = FOREGROUND_RED;

		OutPutMemory[y + a][x + w].Char.AsciiChar = '|';
		OutPutMemory[y + a][x + w].Attributes = FOREGROUND_RED;
	}

	for (int i = 0; i < arr.length(); i++)
	{
		OutPutMemory[y + 1][x + i + 1].Char.AsciiChar = arr[i];
		OutPutMemory[y + 1][x + i + 1].Attributes = FOREGROUND_RED;
	}

	// 刷新显存
	if (Mode == 1)
	{
		RefreshScreen();
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

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			OutPutMemory[y + i][x + j].Char.AsciiChar = ' ';
			OutPutMemory[y + i][x + j].Attributes = FOREGROUND_RED;
		}
	}
	// 刷新显存
	if (Mode == 1)
	{
		RefreshScreen();
	}
	/*return OldOutPutMemory;*/
}

/// <summary>
/// 界面全填充#
/// </summary>
void GUI_PaddingAll(char c,int Mode)
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
			OutPutMemory[i][j].Char.AsciiChar = c;
			OutPutMemory[i][j].Attributes = FOREGROUND_RED;
		}
	}

	// 刷新显存
	if (Mode == 1)
	{
		RefreshScreen();
	}
}

/// <summary>
/// 部分填充字符
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <param name="FlashMode">是否刷新显存</param>
/// <param name="DisPalyMode">是否覆盖显示</param>
void GUI_PaddingPart(int x,int y,int w,int h,char c,int FlashMode,int DisPalyMode)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (DisPalyMode)
			{
				OutPutMemory[y + i][x + j].Char.AsciiChar = c;
				OutPutMemory[y + i][x + j].Attributes = FOREGROUND_RED;
			}
			else
			{
				char OldChar = OutPutMemory[y + i][x + j].Char.AsciiChar;
				if (OldChar == ' ')
				{
					OutPutMemory[y + i][x + j].Char.AsciiChar = c;
					OutPutMemory[y + i][x + j].Attributes = FOREGROUND_RED;
				}
				else
				{
					OutPutMemory[y + i][x + j].Char.AsciiChar = OldChar;
					OutPutMemory[y + i][x + j].Attributes = FOREGROUND_RED;
				}
			}
		}
	}
	// 刷新显存
	if (FlashMode == 1)
	{
		RefreshScreen();
	}
}
