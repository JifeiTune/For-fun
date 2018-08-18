#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h> 
#include<time.h>
#include<vector> 
#include<windows.h>
using namespace std;

int H,W,sp;
bool vis[101][101];
int shift[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<int> pos;

#define InR(X,Y) (X>=1&&X<=H&&Y>=1&&Y<=W&&(!vis[X][Y]))//是否可行 

void SetP(int x,int y)//光标移动到某位置 
{
    COORD pos;
    pos.Y=x;
    pos.X=2*y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void DFS(int x,int y)
{
	if(InR(x,y))
	{
		random_shuffle(pos.begin(),pos.end());//随机方向 
		Sleep(sp);
		SetP(x,y);
		printf("■");
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			DFS(x+shift[pos[i]][0],y+shift[pos[i]][1]);
		}
	}
	/* 
	SetP(x,y);
	printf(" ");//恢复
	*/ 
}

int main()
{
	pos.push_back(0);
	pos.push_back(1);
	pos.push_back(2);
	pos.push_back(3);
	srand((unsigned)time(NULL));
	H=30,W=30;//高与宽 
	sp=10;//毫秒间隔 
	memset(vis,0,sizeof(vis)); 
	DFS(1,1);//DFS起点，不同起点不同效果 
	SetP(W+1,0);
	return 0; 
}


