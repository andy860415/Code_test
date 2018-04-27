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
			map[l][m] = 10;//10:�a�ϥ~���a��
	}
	cout << "��J�ܶ}���ɮת��W��,CASE1.txt �� CASE2.txt" << endl;
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
				map[i][k] = 0;//���|			
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
				starC = h;//�_�I����
				starR = g;//�_�I���C
			}
		}
	}

	for (int h = 0; h < 12; h++)
	{
		for (int g = 0; g < 12; g++)
		{
			if (map[h][g] == 3)
			{
				endC = h;//���I����
				endR = g;//���I���C
			}
		}
	}


	while (!(starC == endC && starR == endR))//��_�I��������I�ɡA���g�c
	{
		if (map[starC][starR + 1] == 3 || map[starC + 1][starR] == 3 || map[starC - 1][starR] == 3 || map[starC][starR - 1] == 3)
		{
			map[starC][starR] = 9;//9:���L1��
			if (map[starC][starR + 1] == 3)//���k
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 3)//���U
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 3)//���W
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 3)//����
			{
				starR--;
			}
		}

		else if (map[starC][starR + 1] == 0 || map[starC + 1][starR] == 0 || map[starC - 1][starR] == 0 || map[starC][starR - 1] == 0)
		{
			map[starC][starR] = 9;//9:���L1��

			if (map[starC][starR + 1] == 0)//���k
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 0)//���U
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 0)//���W
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 0)//����
			{
				starR--;
			}
		}
		else if (map[starC][starR + 1] == 9 || map[starC + 1][starR] == 9 || map[starC - 1][starR] == 9 || map[starC][starR - 1] == 9)
		{
			map[starC][starR] = 7;//7:���L2��

			if (map[starC][starR + 1] == 9)//���k
			{
				starR++;
			}
			else if (map[starC + 1][starR] == 9)//���U
			{
				starC++;
			}
			else if (map[starC - 1][starR] == 9)//���W
			{
				starC--;
			}
			else if (map[starC][starR - 1] == 9)//����
			{
				starR--;
			}
		}
	}
	if (starC == endC && starR == endR)//��_�I������I��
	{
		cout << "���g�c���G��:" << endl;
		for (int m = 0; m < 11; m++)//�L�X���G
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

	cout << "�п�J�A�Q��X���ɮת��W��:" << endl;
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
	cout << "�ɮ׿�X���\";
		
	system ("PAUSE");
		return 0;
}
