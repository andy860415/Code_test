
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printMAP(char MAP[12][12]);
void initMAP(char MAP[12][12]);
void go(int count,int block1,int block2);

char MAP[12][12];
int count=0;

struct player{
	int x;
	int y;
	int block;
};

struct player Player1;
struct player Player2;


int main(void)
{
	
	
	initMAP(MAP);
	Player1.block = Player2.block=2;
	printMAP(MAP);
	
	while((Player1.x<10)&&(Player2.x>2))
	{
			go(count,Player1.block,Player2.block);
			count++;
			printMAP(MAP);
		}

	if(Player1.x==10) 
	{
		printf("Player1 win!!\n");
		
	}
	else if(Player2.x==2)
	{
		printf("Player2 win!!\n");
	}
	
//	system("pause");
	return 0;
}

void initMAP(char MAP[12][12])
{	
	int i,j;
	char A='1';
	for(i=2;i<12;i+=2)
	{
		MAP[0][i]=A;
		A++;
	}
	 A='A';
	for(i=2;i<12;i+=2)
	{
		MAP[i][0]=A;
		A++;
	}
	A='*';
	for(i=1;i<12;i+=2)
	{
		for(j=1;j<12;j+=1)
		MAP[i][j]=A;
	}
	for(i=1;i<12;i+=1)
	{
		for(j=1;j<12;j+=2)
		MAP[i][j]=A;
	}
	MAP[8][2]='1';
	MAP[4][10]='2';
	Player1.y=8,Player1.x=1;
	Player2.y=4,Player2.x=10;
}

void printMAP(char MAP[12][12])
{
    int i,j;
	for( i=0;i<12;i++)
	{
		for( j=0;j<12;j++)
		{
			printf("%c",MAP[i][j]);
		}
			printf("\n");
		
	}
}

void go(int count,int block1,int block2)
{	
	int error=1;
  if (count%2==0)
	{	
		printf("Player1's tern\n");
		char type[1],locate1[3],locate2[3];
		while(error==1)
		{
		error=0;
		scanf("%s",&type);
		scanf("%s",&locate1);
		scanf("%s",&locate2);
		
	//	int i=0;
	//	printf("%c",type[0]);
		
		printf("\n");
		
	//	for(i=0;i<3;i++)
		printf("%c",locate1[1]);
		
		printf("\n");
		
	//	for(i=0;i<3;i++)
		printf("%c",locate2[1]);
		
		if(block1>0)						//設圍牆 
		{
			if((type[0]=='p') && (locate1[2]-locate1[0]==1) && (locate2[2]-locate2[0]==1) )
			{		printf("XXX\n");
				MAP[locate1[2]-'0'][locate2[2]-locate2[0]]='X';
				MAP[locate1[0]-'0'][locate2[2]-locate2[0]]='X';
				block1--;
			}
		}
		
		/*if(block1<2)								//已經有圍牆 
		{
			if(type[0]=='m')
			{
		
		
		}*/
	
	/*	else if(block1==2)							//沒有圍牆 
		{
			if(type[0]=='m')
			{
			if
			{
			if(((type[2]-'A'+1)*2-Player1.y==2)&&((type[4]-'0')*2==Player1.x)&&(Player1.y!=2))				//上移一格 
				Player1.y+=2;
			else	if(((type[2]-'A'+1)*2-Player1.y==-2)&&((type[4]-'0')*2==Player1.x)&&(Player1.y!=10))				//下移一格 
				Player1.y-=2;
			else	if(((type[2]-'A'+1)*2==Player1.y)&&((type[4]-'0')*2-Player1.x==2)&&(Player1.x!=2))				//左移一格 
				Player1.x-=2;
			else	if(((type[2]-'A'+1)*2==Player1.y)&&((type[4]-'0')*2-Player1.x==-2)&&(Player1.x!=10))				//右移一格 
				Player1.x+=2;
			}
			}
		}
	
		else
			{
				printf("Input Error, please input again!!\n");
				error=1;
			}
		}
	}
/*	else{
			printf("Player2's tern\n");
		
	}
*/
}
}
}
