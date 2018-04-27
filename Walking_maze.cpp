#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
void go(int , int );
using namespace std;
char file[20];
char file_out[40] = {};
string line;
char map[12][12] = {};
int starC, starR, endC, endR;

int main()
{
	for (int l = 0; l < 12; l++)
	{
		for (int m = 0; m < 12; m++)
			map[l][m] = 10;//10:地圖外的地方
	}
	cout << "輸入邀開啟檔案的名稱,CASE1.txt 或 CASE2.txt" << endl;
	cin >> file;

	ifstream fin;

	if (fin.fail())
	{
		cout << "Can't open file!\n";
		exit(1);
	}
	fin.open(file, ios::in);

	int i = 0;

	while (getline(fin, line))
	{

		for (int k = 0; k < line.length(); k++)
		{
			if (line[k] == ' ')
				break;
			if (line[k] == 'T')
				map[i][k] = 2;//2:T
			else if (line[k] == 'E')
				map[i][k] = 3;//3:E
			else if (line[k] == 'S')
				map[i][k] = 4;//4:S
			else if (line[k] == '0')
				map[i][k] = 0;//路徑			
		}
		i++;
	}

	fin.close();

	for (int m = 0; m < 12; m++)
	{
		for (int n = 0; n < 12; n++)
		{
			if (map[m][n] == 0)
				cout << " 0";
			else if (map[m][n] == 4)
				cout << " S";
			else if (map[m][n] == 2)
				cout << " T";
			else if (map[m][n] == 3)
				cout << " E";
			else if (map[m][n] == 10)
				cout << " ";
		}
		cout << endl;
	}

	for (int h = 0; h < 12; h++)
	{
		for (int g = 0; g < 12; g++)
		{
			if (map[h][g] == 4)
			{
				starC = h;//起點的行
				starR = g;//起點的列
			}
		}
	}

	for (int h = 0; h < 12; h++)
	{
		for (int g = 0; g < 12; g++)
		{
			if (map[h][g] == 3)
			{
				endC = h;//終點的行
				endR = g;//終點的列
			}
		}
	}


	while (!(starC == endC && starR == endR))//當起點不等於終點時，走迷宮
	{
		if (map[starC][starR + 1] == 3 || map[starC + 1][starR] == 3 || map[starC - 1][starR] == 3 || map[starC][starR - 1] == 3)
		{
			map[starC][starR] = 9;//9:走過1次
			if (map[starC][starR + 1] == 3)//往右
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 3)//往下
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 3)//往上
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 3)//往左
			{
				starR--;
			}
		}

		else if (map[starC][starR + 1] == 0 || map[starC + 1][starR] == 0 || map[starC - 1][starR] == 0 || map[starC][starR - 1] == 0)
		{
			map[starC][starR] = 9;//9:走過1次

			if (map[starC][starR + 1] == 0)//往右
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 0)//往下
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 0)//往上
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 0)//往左
			{
				starR--;
			}
		}
		else if (map[starC][starR + 1] == 9 || map[starC + 1][starR] == 9 || map[starC - 1][starR] == 9 || map[starC][starR - 1] == 9)
		{
			map[starC][starR] = 7;//7:走過2次

			if (map[starC][starR + 1] == 9)//往右
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 9)//往下
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 9)//往上
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 9)//往左
			{
				starR--;
			}
		}
	}
	if (starC == endC && starR == endR)//當起點等於終點時
	{
		cout << "走迷宮結果為:" << endl;
		for (int m = 0; m < 11; m++)//印出結果
		{
			for (int n = 0; n < 11; n++)
			{
				if (map[m][n] == 0)
					cout << " 0";
				else if (map[m][n] == 4)
					cout << " S";
				else if (map[m][n] == 2)
					cout << " T";
				else if (map[m][n] == 3)
					cout << " E";
				else if (map[m][n] == 10)
					cout << " ";
				else if (map[m][n] == 9)
					cout << " 1";
				else if (map[m][n] == 7)
					cout << " 0";
			}
			cout << endl;
		}
	}
	for (int m = 0; m < 12; m++)
	{
		for (int n = 0; n < 12; n++)
		{
			if (map[m][n] == 0)
				map[m][n] = ' 0';
			else if (map[m][n] == 4)
				map[m][n] = ' S';
			else if (map[m][n] == 2)
				map[m][n] = ' T';
			else if (map[m][n] == 3)
				map[m][n] = ' E';
			else if (map[m][n] == 10)
				map[m][n] = '  ';
			else if (map[m][n] == 9)
				map[m][n] = ' 1';
			else if (map[m][n] == 7)
				map[m][n] = ' 0';
		}
	}

	cout << "請輸入你想輸出之檔案的名稱:" << endl;
	cin >> file_out;
	ofstream fout;
	fout.open(file_out);
	if (fout.fail())
	{
		cout << "Can't open file!\n";
		exit(1);
	}
	for (int x = 0; x < 12; x++)
	{
		fout << endl;
		for (int y = 0; y < 12; y++)
		{
			fout << map[x][y];
		}
	}
	cout << "檔案輸出成功";
		
	system ("PAUSE");
		return 0;
}
