#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include "lib.h"
using namespace std;


extern struct Cube;

extern CHAR_INFO OutPutMemory[ConsoleWidth][ConsoleLength];

int Decodeformat = 0;



// 控制台全屏
void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);   /* 标准输出缓冲区句柄 */
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 */

	COORD size = GetConsoleSize();
	SetSize(size.X, size.Y);
	//SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy , 0);
	ShowWindow(hwnd, SW_MAXIMIZE); //最大化窗口
	keybd_event(VK_F11, 0, 0, 0);
}

// 设置控制台大小
void SetSize(unsigned uCol, unsigned uLine)
{
	char cmd[64];
	sprintf_s(cmd, "mode con cols=%d lines=%d", uCol, uLine);
	system(cmd);
}


std::string utf8_to_gbk(const std::string& utf8_str) {
	// 先将 UTF-8 转换为 UTF-16
	int utf16_len = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, NULL, 0);
	if (utf16_len == 0) {
		return "";
	}
	std::wstring utf16_str(utf16_len, 0);
	MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, &utf16_str[0], utf16_len);

	// 再将 UTF-16 转换为 GBK
	int gbk_len = WideCharToMultiByte(CP_ACP, 0, utf16_str.c_str(), -1, NULL, 0, NULL, NULL);
	if (gbk_len == 0) {
		return "";
	}
	std::string gbk_str(gbk_len, 0);
	WideCharToMultiByte(CP_ACP, 0, utf16_str.c_str(), -1, &gbk_str[0], gbk_len, NULL, NULL);

	return gbk_str;
}

int CheckConsoleEncoding() {
	UINT codePage = GetConsoleOutputCP();
	if (codePage == CP_UTF8) {
		//std::cout << "当前控制台编码是 UTF-8" << std::endl;
		return 1;
	}
	else if (codePage == 936) { // 936 是 GBK 的代码页
		//std::cout << "当前控制台编码是 GBK" << std::endl;
		return 0;
	}
	else {
		//std::cout << "当前控制台编码是其他编码: " << codePage << std::endl;
		return -1;
	}
}

/// <summary>
/// 初始界面选项
/// </summary>
void witerEdge()
{
	cout << "####俄罗斯方块####" << endl;
	cout << "####1.开始游戏####" << endl;
	cout << "####2.游戏选项####" << endl;
	cout << "####3.游戏帮助####" << endl;
	cout << "####4.重新开始####" << endl;
	cout << "####5.读取存档####" << endl;
	cout << "####6.作者####" << endl;
	cout << "####7.更多信息####" << endl;
}


void CubeColl(int px, int py, int w, int h, int len, int dir_1, int dir_2, char c, int speed)
{
	Cube* cube_A = new Cube;
	cube_A->px = px;
	cube_A->py = py;
	cube_A->w = w,
	cube_A->h = h;
	cube_A->len = -1;
	cube_A->c = c;
	cube_A->speed = speed;
	while (1)
	{	
		if ((dir_1 == 1 && dir_2 == 3)||(dir_1 == 2 && dir_2 == 4))
		{
			MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, dir_1, cube_A->c, 1, cube_A->speed, cube_A);
			MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, dir_2, cube_A->c, 1, cube_A->speed, cube_A);
		}
		else if ((dir_1 == 5 && dir_2 == 7) || (dir_1 == 7 && dir_2 == 5) || (dir_1 == 6 && dir_2 == 8))
		{
			if (((cube_A->px + cube_A->w) < 120)&&((cube_A->px + cube_A->w) > 0))
			{
				MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 5, cube_A->c, 1, cube_A->speed, cube_A);
				MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 7, cube_A->c, 1, cube_A->speed, cube_A);
			}
			else
			{
				MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 6, cube_A->c, 1, cube_A->speed, cube_A);
				MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 8, cube_A->c, 1, cube_A->speed, cube_A);
				if (((cube_A->py + cube_A->h) <= 29) && ((cube_A->py + cube_A->h) >= 0))
				{
					MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 8, cube_A->c, 1, cube_A->speed, cube_A);
					MoveCube(cube_A->px, cube_A->py, cube_A->w, cube_A->h, -1, 6, cube_A->c, 1, cube_A->speed, cube_A);
				}
			}
		}
	}
}

/// <summary>
/// 游戏开始
/// </summary>
void GameStart()
{
	GUI_Init(1);
	//MoveCube(10, 10, 1, 1,"#" ,1);
	//GUI_WriterPixel(10, 10, "Hello,world");
	//GUI_PaddingAll(1);
	//GUI_PaddingPart(10, 10, 5, 3,'A', 1);
	//GUI_PaddingPart(10, 20, 5, 3, "A", 1);
	//GUI_Clear(10,10,10,10);
	//GUI_DrawRect(10, 10, 12, 5,"", 1);
	
	
	Cube* cube = new Cube;
	
	/*thread t2(MoveCube, 60, 15, 5, 3, 10 ,2, 'B', 1, 1000);
	thread t3(MoveCube, 60, 15, 5, 3, 10, 3, 'C', 1, 1000);
	thread t4(MoveCube, 60, 15, 5, 3, 10, 4, 'D', 1, 1000);
	thread t5(MoveCube, 60, 15, 5, 3, 10, 5, 'E', 1, 1000);
	thread t6(MoveCube, 60, 15, 5, 3, 10, 6, 'F', 1, 1000);
	thread t7(MoveCube, 60, 15, 5, 3, 10, 7, 'G', 1, 1000);
	thread t8(MoveCube, 60, 15, 5, 3, 10, 8, 'H', 1, 1000);*/
	
	/*t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();*/
	//MoveCube(10, 10, 5, 3, 10, '#',1,1000);
	thread t1(CubeColl, 60, 15, 5, 3, -1, 1, 3, '#', 1);
	thread t2(CubeColl, 20, 6, 5, 3, -1, 5, 7, '#', 1);
	thread t3(CubeColl, 40, 15, 5, 3, -1, 5, 7, '#', 1);
	thread t4(CubeColl, 80, 15, 5, 3, -1, 2, 4, '#', 1);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	/*thread t1(MoveCube, 10, 10, 5, 3, -1,5, 'A', 1, 10, cube);
	t1.join();*/
	

	while (1)
	{
		
		//MoveCube(10, 10, 5, 3, -1, 7, 'A', 1, 10, cube);
	}
	
}