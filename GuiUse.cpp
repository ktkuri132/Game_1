#include "lib.h"
#include <windows.h>
#include <thread>
using namespace std;

Cube* CubeHome[50];

int CubeCollide(int px, int py, int w, int h)
{
	// 边界碰撞检查
	if (px + w >= ConsoleLength - 1)
	{
		return 1;		// 右边界
	}
	else if (px <= 0)
	{
		return 2;		// 左边界
	}
	else if (py + h >= ConsoleWidth -1 -6)
	{
		return 3;		// 下边界
	}
	else if (py <= 0)
	{
		return 4;		// 上边界
	}
	else if (px + w >= ConsoleLength - 1 && py + h >= ConsoleWidth - 1 - 6)
	{
		return 5;		// 右下角
	}
	else if (px <= 0 && py + h >= ConsoleWidth - 1 - 6)
	{
		return 6;		// 左下角
	}
	else if (px + w >= ConsoleLength - 1 && py <= 0)
	{
		return 7;		// 右上角
	}
	else if (px <= 0 && py <= 0)
	{
		return 8;		// 左上角
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


void StopCube(int px, int py, int w, int h)
{
	
}

/// <summary>
/// 方块移动
/// </summary>
/// <param name="px">起始x坐标</param>
/// <param name="py">起始y坐标</param>
/// <param name="w">x轴方向长度</param>
/// <param name="h">y轴方向长度</param>
/// <param name="len">移动距离</param>
/// <param name="dir">移动方向</param>
/// <param name="c">字符</param>
/// <param name="FlashMode">刷新显存</param>
/// <param name="speed">移动速度</param>
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
		if (cube->dir == 1)
		{
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h) == 1)
			{
				cube->len = 0;
				CollideCallBack(CubeCollide(cube->px + i, cube->py, cube->w, cube->h));
				//GUI_PaddingPart(cube->px - 1, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				goto end;	
			}
			GUI_Clear(cube->px - 1, cube->py, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(++cube->px, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 2)
		{
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h) == 3)
			{
				if (cube->dir == 2)
				{
					cube->len = 0;
					CollideCallBack(CubeCollide(cube->px, cube->py + i, cube->w, cube->h));
					//GUI_PaddingPart(cube->px, cube->py - 1, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
					goto end;
				}
			}
			GUI_Clear(cube->px, cube->py - 1, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(cube->px, ++cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
				
		}
		else if (cube->dir == 3)
		{
			
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h) == 2)
			{
				if (cube->dir == 1)
				{
					cube->len = 0;
					CollideCallBack(CubeCollide(cube->px - i, cube->py, cube->w, cube->h));
					//GUI_PaddingPart(cube->px + 1, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
					goto end;
				}
			}
			GUI_Clear(cube->px + 1, cube->py, cube->w, cube->h, 0);		// 清除上一帧
			GUI_PaddingPart(--cube->px, cube->py, cube->w, cube->h, cube->c, FlashMode, 0);	// 刷新重叠部分
		}
		else if (cube->dir == 4)
		{
			
			if (CubeCollide(cube->px, cube->py, cube->w, cube->h) == 4)
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
		GUI_printf(1,7, 0, 1, FOREGROUND_INTENSITY, "len:%d", cube->len);
		
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



