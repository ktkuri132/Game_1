#include <iostream>
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
	
	//GUI_WriterPixel(10, 10, "Hello,world");
	//GUI_PaddingAll(1);
	//GUI_PaddingPart(10, 10, 5, 3, 1);
	//GUI_Clear(10,10,10,10);
	//GUI_DrawRect(10, 10, 12, 5,"", 1);
	while (1)
	{
		MoveCube(10, 10, 1, 1,"#" ,1);
		
	}
}