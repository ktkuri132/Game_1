#include <limits>
#include "lib.h"
#include "readme.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	
		/*if (CheckConsoleEncoding())
		{
			cout << utf8_to_gbk("#####俄罗斯方块####") << endl;
			cout << utf8_to_gbk("点击Enter开始游戏......") << endl;
		}
		else
		{
			cout << "#####俄罗斯方块####" << endl;
			cout << "点击Enter开始游戏......" << endl;
		}*/
char c;
	strat:
		system("cls");
		Guicout("####俄罗斯方块####", 24,1);
		Guicout("####1.开始游戏####", 23,1);
		Guicout("####2.游戏选项####", 23,1);
		Guicout("####3.游戏帮助####", 23,1);
		Guicout("####4.作者####", 17,1);
		Guicout("####5.更多信息####", 23,1);
		Guicout("请键入数字，再按下回车以选择:", 49,0);
		
		cin >> c;
		switch (c)
		{
			case '1':
			{
				full_screen();
				system("cls");
				SetSize(ConsoleLength, ConsoleWidth);
				GameStart();
			}break;
			case '2':
			{
				system("cls");
				Guicout("没有什么选项",20,1);
				Sleep(1000);
				Guicout("按下任意键，再按Enter以返回......", 45, 0);
				cin >> c;
				goto strat;
			}
			case '3':
			{
				system("cls");
				GameHelp();
				Guicout("按下任意键，再按Enter以返回......", 45, 0);
				cin >> c;
				goto strat;
			}
			case '4':
			{
				system("cls");
				GameAuthor();
				Guicout("按下任意键，再按Enter以返回......", 45, 0);
				cin >> c;
				goto strat;
			}
			default:
				break;
		}
	system("pause");
	return 0;
}