#include <iostream>
#include "lib.h"
using namespace std;


int main()
{
	while (1)
	{
		
		cout << "#####俄罗斯方块#####" << endl;

		switch (cin.get())
		{
			case '\n':
			{
				system("cls");
				system("mode con cols=120 lines=30");
				cout << "####游戏开始####" << endl;
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