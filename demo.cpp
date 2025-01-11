#include <iostream>
#include "lib.h"
using namespace std;


int main()
{
	while (1)
	{
		if (CheckConsoleEncoding())
		{
			cout << utf8_to_gbk("#####俄罗斯方块####") << endl;
			cout << utf8_to_gbk("点击Enter开始游戏......") << endl;
		}
		else
		{
			cout << "#####俄罗斯方块####" << endl;
			cout << "点击Enter开始游戏......" << endl;
		}
		
		switch (cin.get())
		{
			case '\n':
			{
				full_screen();
				system("cls");
				SetSize(ConsoleLength, ConsoleWidth);
				GameStart();
				break;
			}
			default:
				break;
		}

	}
	system("pause");
	return 0;
}