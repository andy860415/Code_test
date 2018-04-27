#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
int temp[2][20];
string line;

int X[11]={};
int Y[11]={};
int constX[11]={};
int constY[11]={};

void ADD(int[],int[] ,int);
void SUB(int[],int [],int);
void MUL(int [],int[],int);
void DIV(int [],int[],int);

ifstream fin;
ofstream fout;
	
int main()
{	int W;
	char name[20];
	char Name[20]="HW1_E24046276.txt";
	fout.open(Name);
	if (fout.fail())
	{
		cout << "�}�ɥ���\n";
		exit(1);
	}
	do
	{
	cout<<"�п�J�Q�n�}�Ҫ� testbench+�Ʀr+.txt"<<endl; 
	cin>>name;
	fout<<name<<endl;
	fin.open(name);
	if(!fin){cout << "Ū�ɥ���" << endl; exit(1);  }    // �ˬdŪ�ɦ��\�P�_
	
	getline(fin,line);			//Ū�Ĥ@�� 
	for(int i=0;i<line.size();i++)
	X[i]=line[i];
	getline(fin,line);			//Ū�ĤG�� 
	for(int i=0;i<line.size();i++)
	Y[i]=line[i];
	fin.close();
	
	int L=line.size();

	for(int i=0;i<L;i++)
		{
			X[i]-=48;
			Y[i]-=48; 	//char->int
		}
	for(int i=0;i<L;i++)
	{
		constX[i]=X[i];
		constY[i]=Y[i]; 	
	}
		
	ADD(X,Y,L);
	SUB(X,Y,L);
	MUL(X,Y,L); 	
	for(int i=0;i<L;i++)			//��SUB��쪺X Y�٭� 
	{
		X[i]=constX[i];
		Y[i]=constY[i];
	}
   	DIV(X,Y,L);

	cout<<"/////////////////////////"<<endl; 
	cout<<"�٭n�}�Ҩ�L���ɮ׶�? Yes:1 No:Otherwise"<<endl;
	cin>>W;
	} while(W==1);
	
	system("pause");
	return 0;
}

void ADD(int X[],int Y[],int L)
{
	int S[L+1]={};
	int C[L]={};	
									//C=carry ,	S=sum
	for(int i=L-1;i>=0;i--)
	{	
		if(X[i]+Y[i]+C[i]>=10)			//���Ͷi�� 
		{
			S[i+1]=X[i]+Y[i]+C[i]-10;
			C[i-1]=1;	
		}
		else{
			S[i+1]=X[i]+Y[i]+C[i];
			}
		if(X[0]+Y[0]>=10)
		S[0]=1;
	}
	if(S[0]==0)
	{
		for(int i=1;i<=L;i++)
		{
			cout<<S[i];
			fout<<S[i];
		}
	}
	
	else
	{
		for(int i=0;i<=L;i++)
		{
			cout<<S[i];
			fout<<S[i];
		}
	}
	cout<<endl;
	fout<<endl;
}


void SUB(int X[],int Y[],int L)
{
	int S1[L]={};
	int mark=0,i=0;
	
	while(mark>=0)
		{
			if(X[i]<Y[i])
			{
			 mark--;									
			}
			if(X[i]>Y[i])
			break;
		
			i++;
			if(i>=L)
			break;
		} 

	if(mark>=0)						//X>=Y 
		{	
		for(int i=L-1;i>=0;i--)
			{
				if(X[i]<Y[i])								//������
					{
						S1[i]=10+X[i]-Y[i];					//�ɦ� 
				 		X[i-1]--;
					}	
				else
					{
						S1[i]=X[i]-Y[i];
					}						 
			}
			for(int i=0;i<L;i++)
			{
			cout<<S1[i];
			fout<<S1[i];
			}
		}
	 else									//X<Y
	 	{	
		 	for(int i=L-1;i>=0;i--)
			{
				if(Y[i]<X[i])								//������
				{
					S1[i]=10+Y[i]-X[i];					//�ɦ� 
					 Y[i-1]--;
				}	
				else
				{
					S1[i]=Y[i]-X[i];
				}						 
			}
	 		cout<<"-";
	 		fout<<"-";
		 	for(int i=0;i<L;i++)
			{
			cout<<S1[i];
			fout<<S1[i];
			}
		 }
	cout<<endl;	 
	fout<<endl;
}



void MUL(int X[],int Y[],int L)
{
	int S2[L*2]={}; 
	for(int i=L-1;i>=0;i--)			//line.size=10
	{ 
		for(int j=L-1;j>=0;j--)
		{
			S2[i+j+1]+=X[j]*Y[i];
			if(S2[i+j+1]>=10)
			{
				S2[i+j]+=S2[i+j+1]/10;		//�i�� 
				S2[i+j+1]=S2[i+j+1]%10;			//���Ӧ��
			}
		}
	 } 
	for (int i=0;i<L*2;i++)
		{
			cout<<S2[i];
			fout<<S2[i];
		}
		cout<<endl;
			fout<<endl;
}

void DIV(int X[],int Y[],int L)
{	
	int j=0;                     //j����X�����X�� 
	int S3[L]={};
	int mark1=0;				//����mark�bX=Y 
	
	while(j<L)
	{
		int i=0;
		int mark=0;
		while(mark==0)						//���X Y�j�p 
		{								
			if(X[i]>Y[i])			//X>Y
			mark=2;
		 	if(X[i]<Y[i])			//X<Y
			mark=-1;	
			if(i==L-1) 			 //X=Y        
			mark=1;
					
			i++;
		}
	
	if(mark>1)						//X>Y 
		{	
		for(int i=L-1;i>=0;i--)				//X-Y�@�� 
			{
				if(X[i]<Y[i])								//������
					{
						X[i]=10+X[i]-Y[i];					//�ɦ� 
				 		X[i-1]--;
					}	
				else
					{
						X[i]=X[i]-Y[i];
					}						 
			}
			S3[j]+=1;							//S�b��������j����m�W�[1 
		}
	 else	if(mark==1) 
	 {	mark1=1;
	 	break;		//X=Y�ɸ��X 
		}
	else						//X<Y
		{
			for( i=0;i<L;i++)		//X���������@�� 
			X[i]=X[i]*10;
			for(i=L-1;i>0;i--)
			{	
				X[i-1]+=X[i]/10;
				X[i]=X[i]%10;
			}
			j+=1;					//�������Ʈa1 
		} 
	
	}
	if(mark1==1)					//�p�GX=Y �A��@�� 
	{
			for(int i=L-1;i>=0;i--)				//X-Y�@�� 
			{
				if(X[i]<Y[i])								//������
					{
						X[i]=10+X[i]-Y[i];					//�ɦ� 
				 		X[i-1]--;
					}	
				else
					{
						X[i]=X[i]-Y[i];
					}						 
			}
			S3[j]+=1;
	}
	if(j==0)
	{
	cout<<S3[0];
	fout<<S3[0];
	}
	else
	{
		cout<<S3[0]<<".";				//�����@��  ���p���I 
		fout<<S3[0]<<".";
		for(int i=1;i<j;i++)
		{
			cout<<S3[i];
			fout<<S3[i];
		}
	}
	cout<<endl;
	fout<<endl;
}
