
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <map>
#include <windows.h>
using namespace std;

string shuru;
int zhuangjia = 0;
map<string, string> Color;
int player = 0;
class pokerface
{
	public:
		string id;
		string color;
		int zhi;
		pokerface(){}
		pokerface(char a, char c, int z)
		{
			this->id = a;
			this->color = c;
			this->zhi = z;
		}
}poker[52];
void Mygame()
{
	int lun = 0;
	int a, b;
	int num1 = 0;
	int num2 = 0;
	bool flag1 = false;//flag1是表示庄家拒绝接牌。
	bool flag2 = false;//flag2是表示玩家拒绝接牌。
	srand((int)time(0));
	while (true)
	{
		lun++;
		flag1 = false;
		flag2 = false;

		if (lun == 1)
		{
			cout << "游戏开始！" << endl;
			Sleep(1000);
			cout << "庄家开始第一次摸牌" << endl;
			Sleep(1000);
			b = rand() % 52;
			a = rand() % 52;
			cout << "庄家摸牌是" << Color[poker[a].color] << poker[a].id << endl;
			Sleep(1000);
			if (poker[a].id == "A")
			{
				zhuangjia += 11;
				num1++;
			}
			else zhuangjia += poker[a].zhi;
			cout << "庄家现在手牌为" << zhuangjia << endl;
			Sleep(1000);
			cout << "玩家开始第一次摸牌" << endl;
			Sleep(1000);
			cout << "玩家摸到手牌是" << Color[poker[b].color] << poker[b].id << endl;
			Sleep(1000);
			if (poker[b].id == "A")
			{
				player += 11;
				num2++;
			}
			else player += poker[b].zhi;
			cout << "玩家现在手牌为" << player << endl;
			Sleep(1000);
		}//
		else
		{
			cout << "现在继续游戏" << endl;
			a = rand() % 52;
			b = rand() % 52;
			cout << "请庄家确定是否接受这张牌(y表示是，n表示否)" << endl;
			cin >> shuru;
			while (shuru.size() > 1)
			{
				cout << "请正确输入命令"<<endl;
				cin >> shuru;
			}
			if (shuru == "y")
			{
				cout << "庄家收到的牌是" <<Color[poker[a].color]<< poker[a].id << endl;
				if (poker[a].id == "A")
				{
					if ((zhuangjia + 11 < 21))
					{
						zhuangjia += 11;
						num1++;
					}
					else 
						zhuangjia += 1;
				}
				else zhuangjia += poker[a].zhi;
				if (zhuangjia > 21 && num1 == 1)
					zhuangjia -= 10;
				cout << "庄家的手牌值" << zhuangjia << endl;
				if (zhuangjia > 21)
				{
					cout << "庄家输掉了比赛，游戏结束" << endl;
					Sleep(1000);
					cout << "请输入任意字母退出" << endl;
					if (cin >> shuru)
						exit(1);
				}
			}
			else if (shuru == "n")
			{
				flag1 = true;

			}
			else if (shuru == "q")
			{
				cout << "Bye" << endl;
				Sleep(2000);
				exit(1);
			}
			cout << "请玩家确定是否接受这张牌(y表示是，n表示不是)" << endl;
			cin >> shuru;
			while (shuru.size() > 1)
			{
				cout << "请正确输入命令"<<endl;
				cin >> shuru;
			}
			if (shuru == "y")
			{
				cout << "玩家收到的牌是" << Color[poker[b].color] << poker[b].id << endl;
				if (poker[b].id == "A")
				{
					if (player + 11 < 21)
					{
						player += 11;
						num2++;
					}
					else
						player += 1;				
				}
				else player += poker[b].zhi;
				if (player > 21 && num2 == 1)player -= 10;
				cout << "玩家的手牌值为" << player << endl;
				if (player > 21)
				{
					cout << "玩家输掉了比赛，游戏结束" << endl;
					Sleep(1000);
					cout << "请输入任意字母退出" << endl;
					if (cin >> shuru)
						exit(1);
				}
			}
			else if (shuru == "n")
			{
				flag2 = true;

			}
			else if (shuru == "q")
			{
				cout << "Bye" << endl;
				exit(1);
			}
			
			if (flag1 == true && flag2 == true)
			{
				cout << "现在不再接牌，开始比较大小" << endl;
				if (zhuangjia >= player)cout << "庄家胜利" << endl;
				else cout << "玩家胜利" << endl;
				cout << "10秒后退出游戏";
				Sleep(10000);
				exit(1);
			}

		}
	}
}
int i;
void assignment()
 {
	for (i = 0; i < 52; i++)
	{
		if (i < 13)
		{
			if (i % 13 == 0)
			{
				poker[i].id = 'A';
				poker[i].color = "R1";
				poker[i].zhi = 0;
			}
			else if (i % 13 == 9)
			{
				poker[i].id = "10";
				poker[i].color = "R1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 10 )
			{
				poker[i].id = 'J';
				poker[i].color = "R1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 11)
			{
				poker[i].id = 'Q';
				poker[i].color = "R1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 12)
			{
				poker[i].id = 'K';
				poker[i].color = "R1";
				poker[i].zhi = 10;
			}
			else
			{
				int a = i % 13 + 1;
				poker[i].id = (char)(a+'0');
				poker[i].color = "R1";
				poker[i].zhi = a;
			}
		}
		else if (i < 26)
		{
			if (i % 13 == 0)
			{
				poker[i].id = 'A';
				poker[i].color = "R2";
				poker[i].zhi = 0;
			}
			else if (i % 13 == 9)
			{
				poker[i].id = "10";
				poker[i].color = "R2";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 10)
			{
				poker[i].id = 'J';
				poker[i].color = "R2";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 11)
			{
				poker[i].id = 'Q';
				poker[i].color = "R2";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 12)
			{
				poker[i].id = 'K';
				poker[i].color = "R2";
				poker[i].zhi = 10;
			}
			else
			{
				int a = i % 13 + 1;
				poker[i].id = (char)(a + '0');
				poker[i].color = "R2";
				poker[i].zhi = a;
			}
		}
		else if (i < 39)
		{
			if (i % 13 == 0)
			{
				poker[i].id = 'A';
				poker[i].color = "B1";
				poker[i].zhi = 0;
			}
			else if (i % 13 == 9)
			{
				poker[i].id = "10";
				poker[i].color = "B1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 10)
			{
				poker[i].id = 'J';
				poker[i].color = "B1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 11)
			{
				poker[i].id = 'Q';
				poker[i].color = "B1";
				poker[i].zhi = 10;
			}
			else if (i % 13 == 12)
			{
				poker[i].id = 'K';
				poker[i].color = "B1";
				poker[i].zhi = 10;
			}
			else
			{
				int a = i % 13 + 1;
				poker[i].id = (char)(a + '0');
				poker[i].color = "B1";
				poker[i].zhi = a;
			}
		}
		else
		{
		if (i % 13 == 0)
		{
			poker[i].id = 'A';
			poker[i].color = "B2";
			poker[i].zhi = 0;
		}
		else if (i % 13 == 9)
		{
			poker[i].id = "10";
			poker[i].color = "B2";
			poker[i].zhi = 10;
		}
		else if (i % 13 == 10)
		{
			poker[i].id = 'J';
			poker[i].color = "B2";
			poker[i].zhi = 10;
		}
		else if (i % 13 == 11)
		{
			poker[i].id = 'Q';
			poker[i].color = "B2";
			poker[i].zhi = 10;
		}
		else if (i % 13 == 12)
		{
			poker[i].id = 'K';
			poker[i].color = "B2";
			poker[i].zhi = 10;
		}
		else
		{
			int a = i % 13 + 1;
			poker[i].id = (char)(a + '0');
			poker[i].color = "R1";
			poker[i].zhi = a;
		}
 }
	}
}
int main()
{
	
	Color["R1"] = "红桃";
	Color["R2"] = "方块";
	Color["B1"] = "黑桃";
	Color["B2"] = "梅花";
	assignment();
	Mygame();
	return 0;
}

