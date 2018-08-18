#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class calendar
{
	public:
		calendar(int x):year(x)//构造函数，根据提供的年份,通过一定计算为数据成员赋值 
		{
			int y[12]={31,28,31,30,31,30,31,31,30,31,30,31};//二月默认28天 
			memcpy(month,y,sizeof(int)*12);
			if( (year%4==0&&year%100!=0)||year%400==0 )//判断是否为闰年 
			month[1]=29;//若为闰年，二月改为29天 
			day=(year-1+(year-1)/4+(year-1)/400-(year-1)/100+1)%7;//求出当年1月1日星期 
		} 
		void show(void)//输出函数 
		{
			int i,j,n,begin=day;//i用来循环输出月，j用来循环输出每月的日，begin存储每月1号星期,初始存储1月星期 
			cout<<'\t'<<'\t'<<"  "<<year<<"年"<<endl;
			cout<<"------------------------------------------------"<<endl;
			for(i=0;i<=11;i++)//输出12个月 
			{
				cout<<'\t'<<'\t'<<"    "<<i+1<<"月"<<endl;
				cout<<"星期日 星期一 星期二 星期三 星期四 星期五 星期六"<<endl;
				j=1,n=begin;
				while(n--)
				cout<<"       ";
				while(j<=month[i])
				{
					cout<<setw(4)<<j<<"   " ;
					if( (j+begin-1)%7==6  )
					cout<<endl;//当天若为星期6，换行 
					j++;	
				}
				cout<<endl;
				begin=(begin+month[i])%7;//设置下一个月1号星期 
				cout<<"------------------------------------------------"<<endl;
				cout<<"------------------------------------------------"<<endl;
			}
		} 
	private:
		int year,day,month[12];//year存储年份，day存储当年1月1日星期，数组month存储当年12个月每月天数
};
int main()
{
	int year;
	cout<<"输入年份：\n"; 
	cin>>year;
	calendar A(year); 
	A.show();//输出	
	return 0; 
}

