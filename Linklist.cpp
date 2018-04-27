#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
ofstream fout;
struct ListNode
{
	ListNode* Next;
	int Data;
};
char name[100];

void printBuckets(ListNode *list[]);
//將Bucket裡的串列印出
void printBucketstoFile(ListNode *list[]);
//將Bucket裡的串列印到一個你想要的檔案中
void sort(ListNode *a);
//將Bucket內的值由小到大排列
void sort(ListNode *a)
{
	ListNode *cur = new ListNode;
	ListNode *next = new ListNode;
	cur = a;
	int temp;                                 //暫存值的空間
	while (cur != 0)
	{
		next = cur->Next;
		while (next != 0)
		{
			if (cur->Data > next->Data)
			{
				temp = cur->Data;				//互換值
				cur->Data = next->Data;
				next->Data = temp;
			}
			next = next->Next;
		}
		cur = cur->Next;
	}
}

void printBuckets(ListNode *list[])
{
	ListNode *curr = new  ListNode;
	for (int i = 0; i < 10; i++)
	{
		curr = list[i];
		cout << i << ":   ";
		while (curr != 0)
		{
			cout << " " <<curr->Data ;
			curr = curr->Next;
		}
		cout << endl;
	}
}
void printBucketstoFile(ListNode *list[])
{

	ListNode *curr = new  ListNode;

	for (int i = 0; i < 10; i++)
	{
		curr = list[i];
		fout << i << ":   ";
		while (curr != 0)
		{
			fout <<" "<< curr->Data ;
			curr = curr->Next;
		}
		fout << endl;
	}
}

int main()
{
	ifstream fin;				//讀檔

	if (fin.fail())
	{
		cout << "無法開啟檔案!";
		exit(1);
	}

	cout << "輸入要開啟檔案的名稱\n" << endl;
	cin >> name;
	fin.open(name);					
	if (fin.fail())
	{
		cout << "Can't open file!\n";
		exit(1);
	}
	vector<int> store;
	int line;
	while (fin >> line)
	{  
		store.push_back(line);					//將值讀入陣列中
	}
	fin.close();


	ListNode **bucket = new ListNode*[10];		//宣告一個一維的指標陣列並配給它10個ListNode大小的空間
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = 0;							//先將裡面設為沒有東西
	}

	ListNode *first;
	first = new ListNode;
	first->Next = 0;
	first->Data = -1;

	for (int i = 0; i < store.size(); i++)
	{
		ListNode *current;
		int tens = store[i] / 10;			//tens為資料的十位數
		current = new ListNode;
		current->Next = 0;
		current->Data = store[i];

		if (bucket[tens] == 0)				//將資料分類，若第一排Bucket還未放值，就將現在的值放進去
		{
			bucket[tens] = current;
		}

		else                                //若已有值，則將資料一個一個串在後面
		{
			ListNode *connet = new ListNode;
			connet = bucket[tens];
			while (connet->Next != 0)
			{
				connet = connet->Next;
			}
			connet->Next = current;
		}
	}
	cout << "輸入要輸出的檔案名稱：";			
	cin >> name;
	fout.open(name);
	if (fout.fail())
	{
		cout << "Can't open file!\n";
		exit(1);
	}
	cout << "key\n";							//輸出結果
	fout << "key\n";
	printBuckets(bucket);
	printBucketstoFile(bucket);
	for (int i = 0; i < 10; i++)
	{
			sort(bucket[i]);
		cout << "key=" << i << endl;
		fout << "key=" << i << endl;
			printBuckets(bucket);
			printBucketstoFile(bucket);
			cout << endl;
			fout << endl;
	}

	system("pause");
	return 0;
}

