#include "lib.h"

/// <summary>
/// 游戏帮助
/// </summary>
void GameHelp()
{
	Guicout("要是进入游戏后出现乱码，那不要慌，不是这个程序把你电脑搞坏了，不要慌张", 106, 1);
	Sleep(1000);
	Guicout("慢慢来", 10, 1);
	Sleep(1000);
	Guicout("假设你现在的屏幕是2k分辨率，那就把缩放设置成130%", 70, 1);
	Sleep(1000);
	Guicout("不知道在哪，不要紧，它就在：设置-->系统-->屏幕-->缩放-->自定义缩放-->改成130就OK了，别担心改不回来，不会有事的", 156, 1);
	Sleep(1000);
	Guicout("这个游戏到目前为止是一个简单的方块移动模拟器", 67, 1);
	Sleep(1000);
	Guicout("你可以通过键盘上的WASD键来控制方块的移动", 59, 1);
	Sleep(1000);
	Guicout("W:上 S:下 A:左 D:右", 24, 1);
	Sleep(1000);
}



void GameAuthor()
{
	Guicout("\033[33m作者：KT.kuri\033[0m ", 27, 1);
	Sleep(1000);
}