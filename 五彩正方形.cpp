#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	short x[500][500],i,j,n,m,k;
	cout<<"ÇëÊäÈë±ß³¤\n"; 
	cin>>n;
	k=n;
	if(n%2==0)
	n=n/2;
	else
	n=(n+1)/2;
	for(m=0;m<=n-1;m++)
	{
		for(j=m;j<=k-m-1;j++)
		{
			x[m][j]=(m%15)+1;
			x[k-m-1][j]=(m%15)+1;
		}
		for(i=m;i<=k-m-1;i++)
		{
			x[i][m]=(m%15)+1;
			x[i][k-m-1]=(m%15)+1;
		}
	}
	for(i=0;i<=k-1;i++)
	{
		for(j=0;j<=k-1;j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x[i][j]);
			cout<<"¡ï";	
		}
		cout<<'\n';
	}
	return 0;
 } 
