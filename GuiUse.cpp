#include "lib.h"
#include <windows.h>
#include <thread>
using namespace std;

Cube* CubeHome[50];

int CubeCollide(int px, int py, int w, int h)
{
	// 边界碰撞检查
	if ((px + w >= ConsoleLength - 1) && (py + h >= ConsoleWidth - 2 - 6))
	{
		return 5;		// 右下角
	}
	else if (px <= 1 && py + h >= ConsoleWidth - 1 - 6)
	{
		return 6;		// 左下角
	}
	else if (px + w >= ConsoleLength - 1 && py <= 1)
	{
		return 7;		// 右上角
	}
	else if (px <= 1 && py <= 1)
	{
		return 8;		// 左上角
	}
	else if (px + w >= ConsoleLength - 1)
	{
		return 1;		// 右边界
	}
	else if (px <= 1)
	{
		return 2;		// 左边界
	}
	else if (py + h >= ConsoleWidth -2 -6)
	{
		return 3;		// 下边界
	}
	else if (py <= 1)
	{
		return 4;		// 上边界
	}
	return 0;
}

void CollideCallBack(int colret)
{
	switch (colret)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	default:
		break;
	}
}

/// <summary>
/// 方块移动
/// </summary>
/// <param name="FlashMode">刷新显存</param>
/// <param name="cube">方块结构体</param>
void MoveCube(int FlashMode ,Cube* cube)
{
	int i = 0;
	if (cube->len == -1)
	{
		cube->len = 65535;
	}
	
	
	GUI_PaddingPart(cube->px, cube->py, cube->w, cube->h, cube->c, 0, 0);
back:
	while (cube->len)
	{
		int a = CubeCollide(cube->px, cube->py, cube->w, cube->h);
		GUI_printf(1, 7, 0, 1, FOREGROUND_INTENSITY, "len:%d", a);
		if (cube->dir == 1)							// 向右
		{
			if ((a == 1) || (a == 5) || (a == 7))				//  检测右边界，右下角，右上角
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px + i, cube->py, cube->w, cube->h));
				//GUI_PaddingPart(cube->px - 1, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;	
			}
			GUI_Clear(cube->px - 1, cube->py, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(++cube->px, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 2)						// 向下
		{
			if ((a == 3) || (a == 5) || (a == 6))							// 检测下边界，右下角，左下角
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px, cube->py + i, cube->w, cube->h));
				//GUI_PaddingPart(cube->px, cube->py - 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px, cube->py - 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(cube->px, ++cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 3)						// 向左
		{
			if ((a == 2)||(a == 6)||(a == 8))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px - i, cube->py, cube->w, cube->h));
				//GUI_PaddingPart(cube->px + 1, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px + 1, cube->py, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(--cube->px, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 4)						// 向上
		{
			if ((a == 4)||(a == 7)||(a == 8))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px, cube->py - i, cube->w, cube->h));
				//GUI_PaddingPart(cube->px, cube->py + 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px, cube->py + 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(cube->px, --cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 5)
		{
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px + i, cube->py + i, cube->w, cube->h));
				GUI_PaddingPart(cube->px - 1, cube->py - 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px - 1, cube->py - 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(++cube->px, ++cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 6)
		{
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px - i, cube->py + i, cube->w, cube->h));
				GUI_PaddingPart(cube->px + 1, cube->py - 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px + 1, cube->py - 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(--cube->px, ++cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 7)
		{
			if (CubeCollide(cube->px + i, cube->py - i, cube->w, cube->h))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px + i, cube->py - i, cube->w, cube->h));
				GUI_PaddingPart(cube->px - 1, cube->py + 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px - 1, cube->py + 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(++cube->px, --cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 8)
		{
			if (CubeCollide(cube->px - i, cube->py - i, cube->w, cube->h))
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px - i, cube->py - i, cube->w, cube->h));
				GUI_PaddingPart(cube->px + 1, cube->py + 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;
			}
			GUI_Clear(cube->px + 1, cube->py + 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(--cube->px, --cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}

		cube->len --;
		this_thread::sleep_for(chrono::milliseconds(cube->speed));
	}
end:
	while (1)
	{
		if (cube->len)
		{
			goto back;
		}
	}
}

