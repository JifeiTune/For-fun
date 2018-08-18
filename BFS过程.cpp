#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h> 
#include<time.h>
#include<vector> 
#include<windows.h>
#include<queue>
using namespace std;

int H,W,sp;
bool vis[101][101];
int shift[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<int> pos;

#define InR(X,Y) (X>=1&&X<=H&&Y>=1&&Y<=W&&(!vis[X][Y]))//�Ƿ���� 

void SetP(int x,int y)//����ƶ���ĳλ�� 
{
    COORD pos;
    pos.Y=x;
    pos.X=2*y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void BFS(int x,int y)
{
	int Ox,Oy,Nx,Ny;
	vis[x][y]=1;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		random_shuffle(pos.begin(),pos.end());//������� 
		Ox=q.front().first,Oy=q.front().second;
		q.pop();
		SetP(Ox,Oy);
		printf("��");
		vis[Ox][Oy]=1;
		for(int i=0;i<4;i++)
		{
			Nx=Ox+shift[pos[i]][0];
			Ny=Oy+shift[pos[i]][1];
			if(InR(Nx,Ny))
			{
				Sleep(sp);
				vis[Nx][Ny]=1;
				q.push(make_pair(Nx,Ny));
			}
		}
	}
}

int main()
{
	pos.push_back(0);
	pos.push_back(1);
	pos.push_back(2);
	pos.push_back(3);
	srand((unsigned)time(NULL));
	H=30,W=30;//����� 
	sp=10;//������ 
	memset(vis,0,sizeof(vis)); 
	BFS(15,15);//BFS��㣬��ͬ��㲻ͬЧ�� 
	SetP(W+1,0);
	return 0; 
}


