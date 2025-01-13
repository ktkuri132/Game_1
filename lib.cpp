#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include "lib.h"
using namespace std;


extern struct Cube;

extern CHAR_INFO OutPutMemory[ConsoleWidth][ConsoleLength];

int Decodeformat = 0;

void Guicout(const char* arr,int m,int n)
{
	for (int i = 0; i < m; i++)
	{
		cout << arr[i];
		Sleep(10);
	}
	if (n)
	{
		cout << endl;
	}
}

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


void CubeColl(int dir_1, int dir_2,Cube* cube_A)
{
	
	while (1)
	{	
		if ((dir_1 == 1 && dir_2 == 3)||(dir_1 == 2 && dir_2 == 4))
		{
			cube_A->dir = dir_1;
			MoveCube( 1, cube_A);
			cube_A->dir = dir_2;
			MoveCube( 1, cube_A);
		}
		else if ((dir_1 == 5 && dir_2 == 7) || (dir_1 == 7 && dir_2 == 5) || (dir_1 == 6 && dir_2 == 8))
		{
			if (((cube_A->px + cube_A->w) < 120)&&((cube_A->px + cube_A->w) > 0))
			{
				cube_A->dir = dir_1;
				MoveCube(1, cube_A);
				cube_A->dir = dir_2;
				MoveCube(1, cube_A);
			}
			else
			{
				cube_A->dir = dir_1;
				MoveCube(1, cube_A);
				cube_A->dir = dir_2;
				MoveCube(1, cube_A);
				if (((cube_A->py + cube_A->h) <= 29) && ((cube_A->py + cube_A->h) >= 0))
				{
					cube_A->dir = dir_1;
					MoveCube(1, cube_A);
					cube_A->dir = dir_2;
					MoveCube(1, cube_A);
				}
			}
		}
	}
}

char UserInfoKeyEvent;
short UserInfoMouseEvent[4];

void CharPut(Cube* cube)
{
	while (1)
	{
		GUI_printf(1,5,0, 0,  FOREGROUND_INTENSITY ,"key:%c", UserInfoKeyEvent);
		
	}
}

void GetUserInput(Cube* cube)
{
	while (1)
	{
		if (UserInfoKeyEvent == 'w')
		{
			cube->dir = 4;
			cube->len++;
			UserInfoKeyEvent = ' ';
		}
		else if (UserInfoKeyEvent == 's')
		{
			cube->dir = 2;
			cube->len++;
			UserInfoKeyEvent = ' ';
		}
		else if (UserInfoKeyEvent == 'a')
		{
			cube->dir = 3;
			cube->len+=3;
			UserInfoKeyEvent = ' ';
		}
		else if (UserInfoKeyEvent == 'd')
		{
			cube->dir = 1;
			cube->len+=3;
			UserInfoKeyEvent = ' ';
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
	
	
	Cube* cube_A = new Cube;
	Cube* cube_B = new Cube;
	Cube* cube_C = new Cube;
	Cube* cube_D = new Cube;
	Cube* cube_E = new Cube;
	Cube* cube_F = new Cube;
	Cube* cube_G = new Cube;
	Cube* cube_H = new Cube;
	
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
	cube_A->px = 10;
	cube_A->py = 10;
	cube_A->w = 5;
	cube_A->h = 3;
	cube_A->len = 10;
	cube_A->dir = 1;
	cube_A->c = '#';
	cube_A->speed = 1;
	//thread t1(MoveCube, 1,cube_A);
	thread t2(MoveCube, 1, cube_A);
	/*thread t3(CubeColl, 30, 15, 5, 3, -1, 5, 7, '#', 1, cube_C);
	thread t4(CubeColl, 40, 20, 5, 3, -1, 2, 4, '#', 1, cube_D);
	thread t5(CubeColl, 50, 15, 5, 3, -1, 1, 3, '#', 1, cube_E);
	thread t6(CubeColl, 60, 6, 5, 3, -1, 5, 7, '#', 1, cube_F);
	thread t7(CubeColl, 70, 15, 5, 3, -1, 5, 7, '#', 1, cube_G);
	thread t8(CubeColl, 80, 30, 5, 3, -1, 2, 4, '#', 1, cube_H);
	thread t9(CubeColl, 90, 25, 5, 3, -1, 1, 3, '#', 1, cube_A);
	thread t10(CubeColl,100, 6, 5, 3, -1, 5, 7, '#', 1, cube_B);
	thread t11(CubeColl, 110, 15, 5, 3, -1, 5, 7, '#', 1, cube_C);
	thread t12(CubeColl, 120, 40, 5, 3, -1, 2, 4, '#', 1, cube_D);
	thread t13(CubeColl, 130, 35, 5, 3, -1, 1, 3, '#', 1, cube_E);
	thread t14(CubeColl, 140, 6, 5, 3, -1, 5, 7, '#', 1, cube_F);
	thread t15(CubeColl, 150, 15, 5, 3, -1, 5, 7, '#', 1, cube_G);
	thread t16(CubeColl, 160, 15, 5, 3, -1, 2, 4, '#', 1, cube_H);
	thread t17(CubeColl, 170, 45, 5, 3, -1, 1, 3, '#', 1, cube_A);
	thread t18(CubeColl, 180, 6, 5, 3, -1, 5, 7, '#', 1, cube_B);
	thread t19(CubeColl, 190, 15, 5, 3, -1, 5, 7, '#', 1, cube_C);
	thread t20(CubeColl, 200, 15, 5, 3, -1, 2, 4, '#', 1, cube_D);*/
	thread t21(CharPut,cube_A);
	
	thread t23(GetUserInput, cube_A);
	thread t24(ReadConsoleInputExample);

	//t1.join();
	t2.join();
	/*t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();*/
	t21.join();
	
	t23.join();
	t24.join();
	/*thread t1(MoveCube, 10, 10, 5, 3, -1,5, 'A', 1, 10, cube);
	t1.join();*/
	
	
	for (;;);
	
}