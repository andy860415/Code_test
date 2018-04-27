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
		cout << "開檔失敗\n";
		exit(1);
	}
	do
	{
	cout<<"請輸入想要開啟的 testbench+數字+.txt"<<endl; 
	cin>>name;
	fout<<name<<endl;
	fin.open(name);
	if(!fin){cout << "讀檔失敗" << endl; exit(1);  }    // 檢查讀檔成功與否
	
	getline(fin,line);			//讀第一行 
	for(int i=0;i<line.size();i++)
	X[i]=line[i];
	getline(fin,line);			//讀第二行 
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
	for(int i=0;i<L;i++)			//把SUB改到的X Y還原 
	{
		X[i]=constX[i];
		Y[i]=constY[i];
	}
   	DIV(X,Y,L);

	cout<<"/////////////////////////"<<endl; 
	cout<<"還要開啟其他的檔案嗎? Yes:1 No:Otherwise"<<endl;
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
		if(X[i]+Y[i]+C[i]>=10)			//產生進位 
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
				if(X[i]<Y[i])								//不夠減
					{
						S1[i]=10+X[i]-Y[i];					//借位 
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
				if(Y[i]<X[i])								//不夠減
				{
					S1[i]=10+Y[i]-X[i];					//借位 
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
				S2[i+j]+=S2[i+j+1]/10;		//進位 
				S2[i+j+1]=S2[i+j+1]%10;			//取個位數
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
	int j=0;                     //j紀錄X左移幾次 
	int S3[L]={};
	int mark1=0;				//紀錄mark在X=Y 
	
	while(j<L)
	{
		int i=0;
		int mark=0;
		while(mark==0)						//比較X Y大小 
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
		for(int i=L-1;i>=0;i--)				//X-Y一次 
			{
				if(X[i]<Y[i])								//不夠減
					{
						X[i]=10+X[i]-Y[i];					//借位 
				 		X[i-1]--;
					}	
				else
					{
						X[i]=X[i]-Y[i];
					}						 
			}
			S3[j]+=1;							//S在左移次數j的位置上加1 
		}
	 else	if(mark==1) 
	 {	mark1=1;
	 	break;		//X=Y時跳出 
		}
	else						//X<Y
		{
			for( i=0;i<L;i++)		//X全部左移一位 
			X[i]=X[i]*10;
			for(i=L-1;i>0;i--)
			{	
				X[i-1]+=X[i]/10;
				X[i]=X[i]%10;
			}
			j+=1;					//左移次數家1 
		} 
	
	}
	if(mark1==1)					//如果X=Y 再減一次 
	{
			for(int i=L-1;i>=0;i--)				//X-Y一次 
			{
				if(X[i]<Y[i])								//不夠減
					{
						X[i]=10+X[i]-Y[i];					//借位 
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
		cout<<S3[0]<<".";				//左移一次  有小數點 
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
