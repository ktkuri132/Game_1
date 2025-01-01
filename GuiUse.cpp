#include "lib.h"
#include <windows.h>
#include <thread>
using namespace std;

//extern CHAR_INFO OutPutMemory[30][120];

void CubeCollide()
{

}

/// <summary>
/// 方块移动
/// </summary>
/// <param name="px"></param>
/// <param name="py"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <param name="len">移动距离</param>
/// <param name="dir">移动方向</param>
/// <param name="c">字符</param>
/// <param name="FlashMode">刷新显存</param>
/// <param name="speed">移动速度</param>
void MoveCube(int px,int py,int w,int h,int len, int dir, char c , int FlashMode , int speed )
{
	//static CHAR_INFO OldOutPutMemory[30][120];
	int i = 0;
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
				GUI_PaddingPart(px + i, py, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 2)
			{
				GUI_Clear(px, py + i - 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 3)
			{
				GUI_Clear(px - i + 1, py, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px - i, py, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 4)
			{
				GUI_Clear(px, py - i + 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 5)
			{
				GUI_Clear(px + i - 1, py + i - 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px + i, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 6)
			{
				GUI_Clear(px - i + 1, py + i - 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px - i, py + i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 7)
			{
				GUI_Clear(px + i - 1, py - i + 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px + i, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
			else if (dir == 8)
			{
				GUI_Clear(px - i + 1, py - i + 1, w, h, 0);		// 清除上一帧
				GUI_PaddingPart(px - i, py - i, w, h, c, FlashMode, 0);	// 刷新重叠部分
			}
		}
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	//memcpy(OldOutPutMemory, OutPutMemory, sizeof(OutPutMemory));
}



