#include <iostream>
#include <thread>
#include "lib.h"
using namespace std;

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
	/*thread t1(MoveCube, 60, 15, 5, 3, 10, 1, 'A', 1, 1000);
	thread t2(MoveCube, 60, 15, 5, 3, 10 ,2, 'B', 1, 1000);
	thread t3(MoveCube, 60, 15, 5, 3, 10, 3, 'C', 1, 1000);
	thread t4(MoveCube, 60, 15, 5, 3, 10, 4, 'D', 1, 1000);
	thread t5(MoveCube, 60, 15, 5, 3, 10, 5, 'E', 1, 1000);
	thread t6(MoveCube, 60, 15, 5, 3, 10, 6, 'F', 1, 1000);
	thread t7(MoveCube, 60, 15, 5, 3, 10, 7, 'G', 1, 1000);
	thread t8(MoveCube, 60, 15, 5, 3, 10, 8, 'H', 1, 1000);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();*/
	//MoveCube(10, 10, 5, 3, 10, '#',1,1000);
	while (1)
	{
		
		
	}
}