#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h> 
#include<time.h> 
#include<windows.h>
using namespace std;

struct Node
{
	int x,y,p;
	void setV(int _x,int _y,int _p)
	{
		x=_x,y=_y,p=_p;
	}
};

int shift[4][2]={{0,1},{-1,0},{0,-1},{1,0}};//�������� 
int H,W;//�ɶ���Χ�߳�
int Len;//�ߵĵ�ǰ����
int vis[101][101];//ĳ�������Ƿ�����ռ�� 
Node snake[1000];//�ߵ���󳤶�
vector<int> pos;

#define InR(X,Y) (X>=1&&X<=H&&Y>=1&&Y<=W)//�˴����϶�vis���жϿ�ʹ�߲��ܴ��Լ� 

void SetP(int x,int y)//����ƶ���ĳλ�� 
{
    COORD pos;
    pos.Y=x;
    pos.X=2*y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void init()//��ʼ��һ��n*n��Χǽ
{
	int i;
    for(i=0;i<=W+1;i++)
	{
	    printf("��");
	}
	SetP(H+1,0);
	for(i=0;i<=W+1;i++)
	{
	    printf("��");
	}
	for(i=1;i<=H;i++)
	{
		SetP(i,0);
	    printf("��");
	    SetP(i,W+1);
	    printf("��");
	}
	Len=1;
	snake[1].setV(1,1,3);//�����(1,1)�����˶�
	vis[1][1]=1;
	SetP(1,1);//��ͷ 
	printf("��");
} 

void Move(int p,bool flag)//�߳�pλ���˶�һ��flag����Ƿ�Ҫ����һ�� 
{
	int i,Nx,Ny;
	Nx=snake[Len].x+shift[p][0];
	Ny=snake[Len].y+shift[p][1];
	vis[Nx][Ny]++;
	SetP(Nx,Ny);//��ͷ 
	printf("��");
	if(flag)//Ҫ���� 
	{
		snake[++Len].setV(Nx,Ny,p);
	}
	else
	{
		if(vis[snake[1].x][snake[1].y]==1)
		{
			SetP(snake[1].x,snake[1].y);
	     	printf("  ");//��β
		}
		vis[snake[1].x][snake[1].y]--;
		for(i=1;i<Len;i++)
		{
			snake[i]=snake[i+1];//����Ľڵ�ֵ���ǰ��Ľڵ�ֵ 
		}
		snake[Len].setV(Nx,Ny,p);
	}
} 

bool Turn(bool flag)//�����ת��ת�������Ƿ���� 
{
	random_shuffle(pos.begin(),pos.end());//�������
	int p,Nx,Ny,i;
	for(i=0;i<2;i++)
	{
		p=(snake[Len].p+pos[i]+4)%4;
		Nx=snake[Len].x+shift[p][0];
		Ny=snake[Len].y+shift[p][1];
		if(InR(Nx,Ny))
		{
			Move(p,flag);
			return 1;
		}
	}
	return 0;
} 

void Next(bool flag)//���������һ��״̬ 
{
	int Nx,Ny;
	int r=rand()%2;
	if(rand()%100>=80)//ת����� 
	{
		if(!Turn(flag))
		{
			Nx=snake[Len].x+shift[snake[Len].p][0];
			Ny=snake[Len].y+shift[snake[Len].p][1];
			if(InR(Nx,Ny))
			{
				Move(snake[Len].p,flag);
			}
			else
			{
				SetP(H+1,0);
				exit(0);
			}
		}
	}
	else//��������ײ��ֱ�� 
	{
		Nx=snake[Len].x+shift[snake[Len].p][0];
		Ny=snake[Len].y+shift[snake[Len].p][1];
		if(InR(Nx,Ny))
		{
			Move(snake[Len].p,flag);
		}
		else if(!Turn(flag))
		{
			SetP(H+1,0);
			exit(0);
		}
	}
} 

int main()
{
	srand((unsigned)time(NULL));
	pos.push_back(-1);
	pos.push_back(1);
	H=30,W=30;//�ɶ���Χ�ĸ���� 
	memset(vis,0,sizeof(vis)); 
	init();
	
	while(1)
	{
		if(Len<20)//��󳤶� 
		{
			Next(1);
		}
		else
		{
			Next(0);
		}
		
		Sleep(10);//ˢ��ʱ�� 
	}
	return 0; 
}


