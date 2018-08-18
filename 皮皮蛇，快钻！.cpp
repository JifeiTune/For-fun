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

int shift[4][2]={{0,1},{-1,0},{0,-1},{1,0}};//右上左下 
int H,W;//可动范围边长
int Len;//蛇的当前长度
int vis[101][101];//某个格子是否被蛇身占据 
Node snake[1000];//蛇的最大长度
vector<int> pos;

#define InR(X,Y) (X>=1&&X<=H&&Y>=1&&Y<=W)//此处加上对vis的判断可使蛇不能穿自己 

void SetP(int x,int y)//光标移动到某位置 
{
    COORD pos;
    pos.Y=x;
    pos.X=2*y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void init()//初始化一个n*n的围墙
{
	int i;
    for(i=0;i<=W+1;i++)
	{
	    printf("□");
	}
	SetP(H+1,0);
	for(i=0;i<=W+1;i++)
	{
	    printf("□");
	}
	for(i=1;i<=H;i++)
	{
		SetP(i,0);
	    printf("□");
	    SetP(i,W+1);
	    printf("□");
	}
	Len=1;
	snake[1].setV(1,1,3);//起初从(1,1)像右运动
	vis[1][1]=1;
	SetP(1,1);//蛇头 
	printf("■");
} 

void Move(int p,bool flag)//蛇朝p位置运动一格，flag标记是否要增长一段 
{
	int i,Nx,Ny;
	Nx=snake[Len].x+shift[p][0];
	Ny=snake[Len].y+shift[p][1];
	vis[Nx][Ny]++;
	SetP(Nx,Ny);//蛇头 
	printf("■");
	if(flag)//要增长 
	{
		snake[++Len].setV(Nx,Ny,p);
	}
	else
	{
		if(vis[snake[1].x][snake[1].y]==1)
		{
			SetP(snake[1].x,snake[1].y);
	     	printf("  ");//蛇尾
		}
		vis[snake[1].x][snake[1].y]--;
		for(i=1;i<Len;i++)
		{
			snake[i]=snake[i+1];//后面的节点值变成前面的节点值 
		}
		snake[Len].setV(Nx,Ny,p);
	}
} 

bool Turn(bool flag)//随机左转右转，返回是否可行 
{
	random_shuffle(pos.begin(),pos.end());//随机方向
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

void Next(bool flag)//随机生成下一个状态 
{
	int Nx,Ny;
	int r=rand()%2;
	if(rand()%100>=80)//转向概率 
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
	else//若不会碰撞则直走 
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
	H=30,W=30;//可动范围的高与宽 
	memset(vis,0,sizeof(vis)); 
	init();
	
	while(1)
	{
		if(Len<20)//最大长度 
		{
			Next(1);
		}
		else
		{
			Next(0);
		}
		
		Sleep(10);//刷新时间 
	}
	return 0; 
}


