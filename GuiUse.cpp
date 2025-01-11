#include "lib.h"
#include <windows.h>
#include <thread>
using namespace std;

Cube* CubeHome[50];

int CubeCollide(int px, int py, int w, int h)
{
	// 边界碰撞检查
	if (px + w >= ConsoleLength)
	{
		return 1;		// 右边界
	}
	else if (px <= 0)
	{
		return 2;		// 左边界
	}
	else if (py + h >= ConsoleWidth -1)
	{
		return 3;		// 下边界
	}
	else if (py <= 0)
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
void MoveCube(int px,int py,int w,int h,int len, int dir, char c , int FlashMode , int speed ,Cube* cube)
{
	cube->len = len;
	cube->dir = dir;
	cube->c = c;
	cube->speed = speed;
	int i = 0;
	if (len == -1)
	{
		len = 65535;
	}
	for (i = 0; i < len; i++)
	{
		if (dir == 1)
		{
			GUI_PaddingPart(px + i, py, w, h, c, 0, 0);		// 向右移动
		}
		else if (dir == 2)
		{
			GUI_PaddingPart(px, py + i, w, h, c, 0, 0);		// 向下移动
		}
		else if (dir == 3)
		{
			GUI_PaddingPart(px - i, py, w, h, c, 0, 0);		// 向左移动
		}
		else if (dir == 4)
		{
			GUI_PaddingPart(px, py - i, w, h, c, 0, 0);		// 向上移动
		}
		else if (dir == 5)
		{
			GUI_PaddingPart(px + i, py + i, w, h, c, 0, 0);		// 向右下移动
		}
		else if (dir == 6)
		{
			GUI_PaddingPart(px - i, py + i, w, h, c, 0, 0);		// 向左下移动
		}
		else if (dir == 7)
		{
			GUI_PaddingPart(px + i, py - i, w, h, c, 0, 0);		// 向右上移动
		}
		else if (dir == 8)
		{
			GUI_PaddingPart(px - i, py - i, w, h, c, 0, 0);		// 向左上移动
		}
		if (i)	// 第一帧是个例
		{
			if (dir == 1)
			{
				GUI_Clear(px + i - 1, py, w, h, 0);		// 清除上一帧
				if (CubeCollide(px + i, py, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px + i, py, w, h));
					// 保存方块信息
					cube->px = px + i;
					cube->py = py;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px + i, py, w, h, c, FlashMode, 0);	// 刷新重叠部分

			}
			else if (dir == 2)
			{
				GUI_Clear(px, py + i - 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px, py + i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px, py + i, w, h));
					// 保存方块信息
					cube->px = px ;
					cube->py = py +i;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
				
			}
			else if (dir == 3)
			{
				GUI_Clear(px - i + 1, py, w, h, 0);		// 清除上一帧
				if (CubeCollide(px - i, py, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px - i, py, w, h));
					// 保存方块信息
					cube->px = px - i;
					cube->py = py;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px - i, py, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 4)
			{
				GUI_Clear(px, py - i + 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px, py - i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px, py - i, w, h));
					// 保存方块信息
					cube->px = px ;
					cube->py = py - i;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
				
			}
			else if (dir == 5)
			{
				GUI_Clear(px + i -1, py + i - 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px + i, py + i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px + i, py + i, w, h));
					// 保存方块信息
					cube->px = px + i;
					cube->py = py + i;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px + i, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 6)
			{
				GUI_Clear(px - i + 1, py + i - 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px - i, py + i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px - i, py + i, w, h));
					// 保存方块信息
					cube->px = px - i;
					cube->py = py + i;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px - i, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 7)
			{
				GUI_Clear(px + i - 1, py - i + 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px + i, py - i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px + i, py - i, w, h));
					// 保存方块信息
					cube->px = px + i;
					cube->py = py - i;
					cube->w = w;
					cube->h = h;
					return;
					
				}
				GUI_PaddingPart(px + i, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 8)
			{
				GUI_Clear(px - i + 1, py - i + 1, w, h, 0);		// 清除上一帧
				if (CubeCollide(px - i, py - i, w, h))
				{
					len = i;
					CollideCallBack(CubeCollide(px - i, py - i, w, h));
					// 保存方块信息
					cube->px = px - i;
					cube->py = py - i;
					cube->w = w;
					cube->h = h;
					return;
				}
				GUI_PaddingPart(px - i, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
		}
		//this_thread::sleep_for(chrono::milliseconds(speed));
		Sleep(speed);
	}
}



