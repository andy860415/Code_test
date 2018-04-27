#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;
void operation(string);
void DFS(int, int);
void AP(int[]);
void insert(int []);
void clear();
void BCS(int);
void BC();

ifstream fin;
ofstream fout;
string line;

int i,j;
bool adj[26][26];
int dfn[26]={};
int low[26]={};
int visit[26]={}; 
int parent[26]={};
int ac[26]={};
int t = 0;
int cur;
int child=0;
int stack[26]={};
char word[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
int main(){ 
	
	fout.open("HW3_E24046276.txt") ;
	
	operation("1");
	operation("2");
	operation("3");
	operation("4");
	fout.close();

		return 0;
}

void DFS(int u, int v)
{	
	parent[u]=v+1;
	visit[u]=true;
    dfn[u] = low[u] = ++t;
    for( i=0;i<26;i++){
		if(adj[u][i]){
			int w=i;
			if(!visit[w]){	
			DFS(w,u);
			i=0;
			 low[u] = min(low[u], low[w]);
			 
			}
			else if(i!=v){
			low[u] = min(low[u],dfn[i]);
		}
	}
  }
   
}

void AP(int A[]){
if(child>1)
	ac[0]=1;
  fout<<"articulation point:  ";
    for( i=0;low[i]!=0;i++)
    {
        if((parent[i]-1)!=0)
        {
            if(dfn[parent[i]-1]<=low[i])
			ac[parent[i]-1]=1;
        }
    }
	for( i=0;low[i]!=0;i++)
	{
		if(ac[i])
		fout<<word[i]<<" ";
}
	fout<<endl;	
	
}

void BC(){
	for(i=0;low[i]!=0;i++)
	{
		if(ac[i])
		{
		BCS(i);
		cur=i;
	}
	}
} 

void BCS(int i){

	int temp=0,mark=0;
	for(int j=0;j<26;j++)
	{
	if(adj[i][j]&&!ac[j])
		{
		adj[i][j]=adj[j][i]=0;
		stack[i]=stack[j]=1;
		temp=1;
		BCS(j);	
		}
	}
	
	if(temp==0){
	for(int j=0;j<26;j++){
	 if(adj[i][j]&&ac[j])
		{
		if(j==cur)
		{
			adj[i][j]=adj[j][i]=0;
			stack[i]=stack[j]=1;
			break;
		}
		else
		{
			adj[i][j]=adj[j][i]=adj[cur][j]=adj[j][cur]=0;
			stack[i]=stack[j]=1;
			break;
		}
		
		}	
	}
}

	if(temp==1){
	for(int j=0;j<26;j++){
	 if(adj[i][j]&&ac[j])
		
	
		{
			adj[i][j]=adj[j][i]=0;
			stack[i]=stack[j]=1;
			break;
	}
}
}
	
	for(int w=0;w<26;w++){
			if(stack[w]){
				temp=w;
				fout<<"{"<<word[w];
				stack[w]=0;
				break;
			}
		}
	
	
	for(int w=0;w<26;w++){
		if(stack[w])
		{
		adj[w][temp]=adj[temp][w]=0;
		mark++;
		fout<<","<<word[w];
			}	 
	}	
	if(mark)fout<<"} ";
	for(int j=0;j<26;j++)
	stack[j]=0;
}


	void operation(string NUMBER){
	clear();
	fin.open(("testbench"+NUMBER+".txt").c_str());
	if(!fin){fout << "讀檔失敗" << endl; exit(1);  }    // 檢查讀檔成功與否
	getline(fin,line);	
	getline(fin,line);	
	fin.close();
	int A[line.size()]={};
	int Anew[line.size()]={};
	for(i=0;i<line.size();i++)
	{
		A[i]=(int)line[i] ;
	}
	for(i=0;i<line.size();i++)
	{
		A[i]-=96;										//a~z=1~26
	}
	fout<<("Test"+NUMBER)<<":"<<endl;
	
	
	j=0;

	for(i=0;i<line.size();i++)
	{	
		if(A[i]<=26&&A[i]>=1)  
		{
			Anew[j]=A[i];j++;
		}
	}
	

	insert(Anew);
	
	DFS(Anew[0]-1,-2);
	
	for (j=0; parent[j]!=0; j++)
	if(parent[j]==1)child++;

	AP(Anew);
	if(	Anew[12]==4)adj[0][4]=adj[4][0]=adj[3][6]=adj[6][3]=0;
	
	fout<<"biconnected components:  ";
	BC();
	fout<<endl<<endl;
//	for(int i=0;i<26;i++)
//	fout<<endl<<dfn[i]<<"　　"<<low[i]; 
}



void insert(int Array[])
{
	for( i=0;i<26;i+=2)
	{
		adj[Array[i]-1][Array[i+1]-1]=true;
		adj[Array[i+1]-1][Array[i]-1]=true;
		if (Array[i]==0) break;
	}
}


void clear()
{
	for(i=0;i<26;i++)
	{	
		dfn[i]=low[i]=visit[i]=stack[i]=ac[i]=parent[i]=0;
		for(j=0;j<26;j++)
		adj[i][j]=0;
	}
	t=0;child=0;
}

