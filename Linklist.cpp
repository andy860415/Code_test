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
//�NBucket�̪���C�L�X
void printBucketstoFile(ListNode *list[]);
//�NBucket�̪���C�L��@�ӧA�Q�n���ɮפ�
void sort(ListNode *a);
//�NBucket�����ȥѤp��j�ƦC
void sort(ListNode *a)
{
	ListNode *cur = new ListNode;
	ListNode *next = new ListNode;
	cur = a;
	int temp;                                 //�Ȧs�Ȫ��Ŷ�
	while (cur != 0)
	{
		next = cur->Next;
		while (next != 0)
		{
			if (cur->Data > next->Data)
			{
				temp = cur->Data;				//������
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
	ifstream fin;				//Ū��

	if (fin.fail())
	{
		cout << "�L�k�}���ɮ�!";
		exit(1);
	}

	cout << "��J�n�}���ɮת��W��\n" << endl;
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
		store.push_back(line);					//�N��Ū�J�}�C��
	}
	fin.close();


	ListNode **bucket = new ListNode*[10];		//�ŧi�@�Ӥ@�������а}�C�ðt����10��ListNode�j�p���Ŷ�
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = 0;							//���N�̭��]���S���F��
	}

	ListNode *first;
	first = new ListNode;
	first->Next = 0;
	first->Data = -1;

	for (int i = 0; i < store.size(); i++)
	{
		ListNode *current;
		int tens = store[i] / 10;			//tens����ƪ��Q���
		current = new ListNode;
		current->Next = 0;
		current->Data = store[i];

		if (bucket[tens] == 0)				//�N��Ƥ����A�Y�Ĥ@��Bucket�٥���ȡA�N�N�{�b���ȩ�i�h
		{
			bucket[tens] = current;
		}

		else                                //�Y�w���ȡA�h�N��Ƥ@�Ӥ@�Ӧ�b�᭱
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
	cout << "��J�n��X���ɮצW�١G";			
	cin >> name;
	fout.open(name);
	if (fout.fail())
	{
		cout << "Can't open file!\n";
		exit(1);
	}
	cout << "key\n";							//��X���G
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

