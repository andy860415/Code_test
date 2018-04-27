#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;
string line;
struct link
{
    link *next;
	int data[50]={};
	int exp[50]={};
};
void print(link *first);
void mul(link *Acurrent,link *Bcurrent);
void sort(link *a);
void operation(string);
void align(int A[]);


ifstream fin;
ofstream fout;
int main(){ 
	
	fout.open("HW2_E24046276.txt") ;
	
	operation("1");
	operation("2");
	operation("3");
	operation("4");

	//system("pause");

	fout.close();
		return 0;
}
	
	
	
void operation(string NUMBER){
		
	fin.open(("testbench"+NUMBER+".txt").c_str());
	if(!fin){cout << "讀檔失敗" << endl; exit(1);  }    // 檢查讀檔成功與否
	getline(fin,line);	
	getline(fin,line);	
		int i;
	int A[line.size()]={};
	for(i=0;i<line.size()-1;i++)
	{
		A[i]=line[i+2] ;
	}
	fout<<("Test"+NUMBER)<<":"<<endl;
	fout<<"    ";
	for(i=0;i<line.size();i++)
	{
		fout<<line[i] ;
	}
	fout<<endl;
	for(i=0;i<line.size()-2;i++)
	A[i]-=48;							//char轉int 

	
    link Ahead;							//空的head 
    link* Achild=new link;    			//配置新記憶體空間 
    link *Acurrent=new link;
    Ahead.next=Achild;	
	Acurrent=Achild;							//current從開始往下指 

	int k=0;

while(k<line.size()-2)
	{
		if(A[k]==-5)						
		{	
			link *sub=new link; 
			Acurrent->next=sub;
			Acurrent=Acurrent->next; 
		}
		
		
		if(A[k]==-16) 					//跳過" " 
		{
			k++;
		}
		else if(A[k]==72&&A[k+2]!=46)
		{
		Acurrent->exp[0]=1;
		Acurrent->exp[1]=-1;
		k++;
		}
		else if(A[k-2]==46)    				//如果i的前2個是"^" 
		{	
		int j=0;
		while(A[k]!=-16){				//不等於" " 
		Acurrent->exp[j]=A[k];	
		k++;j++;
		if(A[k]==0)break;
			}
		Acurrent->exp[j]=-1;
		}
		
		else if(A[k-2]==13||A[k-2]==-5)     //i-2 是"=" or"+" 
		{	
			int j=0;
		while(A[k]!=-16){				//不等於" " 
		Acurrent->data[j]=A[k];
		k++;j++;
		if(A[k]==0)break;
			}
		Acurrent->data[j]=-1;
		}

		else k++; 
	
	}
	Acurrent->next=0;
	getline(fin,line);	
	int B[line.size()]={};
	fout<<"    ";
	for(i=0;i<line.size()-1;i++)
	{
		B[i]=line[i+2] ;
	}
		for(i=0;i<line.size();i++)
	{
		fout<<line[i] ;
	}
	fout<<endl;
	for(i=0;i<line.size()-2;i++)
	B[i]-=48;							//char轉int 
	
	 link Bhead;							//空的head 
    link* Bchild=new link;    			//配置新記憶體空間 
    link *Bcurrent=new link;
    Bhead.next=Bchild;	
	Bcurrent=Bchild;	
	k=0;
	while(k<line.size()-2)
	{
		if(B[k]==-5)						
		{	
			link *sub=new link; 
			Bcurrent->next=sub;
			Bcurrent=Bcurrent->next; 
		}
		
		if(B[k]==-16) 					//跳過" " 
		{
			k++;
		}
		else if(B[k]==72&&B[k+2]!=46)
		{Bcurrent->exp[0]=1;
		Bcurrent->exp[1]=-1;
		k++;}
		else if(B[k-2]==46)    				//如果i的前2個是"^" 
		{	
		int j=0;
		while(B[k]!=-16){				//不等於" " 
		Bcurrent->exp[j]=B[k];	
		k++;j++;
		if(B[k]==0)break;
			}
		Bcurrent->exp[j]=-1;
		}
			
		else if(B[k-2]==13||B[k-2]==-5)     //i-2 是"=" or"+" 
		{	
			int j=0;
		while(B[k]!=-16){				//不等於" " 
		Bcurrent->data[j]=B[k];
		k++;j++;
		if(B[k]==0)break;
			}
			Bcurrent->data[j]=-1;
		}

		else k++; 
	
	}
	fin.close();
	
		Bcurrent->next=0;

	
		Acurrent=Ahead.next;
	
		mul(Achild,Bchild);

}
	
	
	
	
	void mul(link *Acurrent,link *Bcurrent)
	{
		link sum;
		link *sumchild=new link;
		sum.next=sumchild;
		link *Scurrent=new link;
		Scurrent=sumchild;
		link *Bfirst=new link;
		Bfirst=Bcurrent;
		
		while(Acurrent){
				Bcurrent=Bfirst;	
				align(Acurrent->data);
				align(Acurrent->exp);
			while(Bcurrent){
						
				align(Bcurrent->data);
				align(Bcurrent->exp);
			
		for(int i=49;i>=25;i--)			//line.size=10						//data乘法 
	{	
		for(int j=49;j>=25;j--)
		{	int k=i+j-49;
			Scurrent->data[k]+=Acurrent->data[j]*Bcurrent->data[i];
			if(Scurrent->data[k]>=10)
			{
				Scurrent->data[k-1]+=Scurrent->data[k]/10;		//進位
				Scurrent->data[k]=Scurrent->data[k]%10;			//取個位數
			}
		}
	 }
				int C[50]={};
				
		for(int i=49;i>=0;i--)
	{
		if(Acurrent->exp[i]+Bcurrent->exp[i]+C[i]>=10)			//產生進位
		{
			Scurrent->exp[i]=(Acurrent->exp[i]+Bcurrent->exp[i]+C[i]-10);
			C[i-1]=1;
		}
		else{
			Scurrent->exp[i]=(Acurrent->exp[i]+Bcurrent->exp[i]+C[i]);
	}

			}
				
			Bcurrent=Bcurrent->next;	
			link *schild=new link;
			Scurrent->next=schild;
			Scurrent=Scurrent->next;
		
			}
			Acurrent=Acurrent->next;
		
		}
		Scurrent->next=0;
		sort(sumchild);
		print(sumchild);
		
	
	}

	


void sort(link *a)
{
		link *cur = new	link;
		link *next = new link;
		link *temp = new link;
	
		cur=a;
	
		while(cur)									//從exp大排到小 
		{	
			next=cur->next;
		while(next){
		int mark=0,i=0;
			while(mark>=0)								//mark<0 當cur的exp < next的exp 
			{
			if(cur->exp[i]<next->exp[i])
			{
			 mark--;
			}
			 if(cur->exp[i]>next->exp[i])
			break;

			i++;
			if(i>=50)
			break;
			}
		
		if(mark){
			for(i=0;i<50;i++)						//swap
			{
				temp->exp[i] = cur->exp[i];
				cur->exp[i] = next->exp[i];
				next->exp[i] = temp->exp[i];
				temp->data[i] = cur->data[i];
				cur->data[i] = next->data[i];
				next->data[i] = temp->data[i];
			}
		}
			next=next->next;
	}
		cur=cur->next;
	}
	
		cur=a;
		next=cur->next;	
		while(next){
		int	k=0,i=0;
		for(i;i<50;i++)
		{
			if(cur->exp[i]!=next->exp[i])k++;
		}														//k!=0當cur!=next 
		
		if(!k)
		{	int C[50]={};
			for(i=49;i>=0;i--)
			{
				if(cur->data[i]+next->data[i]+C[i]>=10)			//產生進位
			{
			cur->data[i]=(cur->data[i]+next->data[i]+C[i]-10);
			C[i-1]=1;
			}
				else{
			cur->data[i]=(cur->data[i]+next->data[i]+C[i]);
				}
			}
			cur->next=next->next;
			next=cur->next;	
		}
		else{
			cur=cur->next;
			next=cur->next;
			}		
		}	
}


		void print(link *first)
	{
		link *current=new link;
		current=first;
		fout<<"    C = A * B = ";		
		while(current)
		{	
			int i=0,k=0,tempdata=0,tempexp=0;
			
			for(k;k<50;k++)
			{
				if(current->data[k])tempdata++;
				if(current->exp[k])tempexp++;
			}
			if(tempdata)	fout<<" + ";
			while(!current->data[i])i++;
			for(i;i<50;i++)
			fout<<current->data[i];
			
			if(tempexp)
			fout<<" x ^ ";
			i=0;
			while(!current->exp[i])i++;
			for(i;i<50;i++)
			fout<<current->exp[i];
			
			
			current=current->next;
		
		}
		fout<<endl;
			
	}
	
	//array 對齊
	void align(int A[])
	{	if(A[0])
		{
		int i=0,j=0;
		while(A[i]!=-1)	i++; A[i]=0;
		for(int k=50-i;k<50;k++){A[k]=A[j];A[j]=0;j++;}
		}
		}

