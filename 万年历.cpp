#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class calendar
{
	public:
		calendar(int x):year(x)//���캯���������ṩ�����,ͨ��һ������Ϊ���ݳ�Ա��ֵ 
		{
			int y[12]={31,28,31,30,31,30,31,31,30,31,30,31};//����Ĭ��28�� 
			memcpy(month,y,sizeof(int)*12);
			if( (year%4==0&&year%100!=0)||year%400==0 )//�ж��Ƿ�Ϊ���� 
			month[1]=29;//��Ϊ���꣬���¸�Ϊ29�� 
			day=(year-1+(year-1)/4+(year-1)/400-(year-1)/100+1)%7;//�������1��1������ 
		} 
		void show(void)//������� 
		{
			int i,j,n,begin=day;//i����ѭ������£�j����ѭ�����ÿ�µ��գ�begin�洢ÿ��1������,��ʼ�洢1������ 
			cout<<'\t'<<'\t'<<"  "<<year<<"��"<<endl;
			cout<<"------------------------------------------------"<<endl;
			for(i=0;i<=11;i++)//���12���� 
			{
				cout<<'\t'<<'\t'<<"    "<<i+1<<"��"<<endl;
				cout<<"������ ����һ ���ڶ� ������ ������ ������ ������"<<endl;
				j=1,n=begin;
				while(n--)
				cout<<"       ";
				while(j<=month[i])
				{
					cout<<setw(4)<<j<<"   " ;
					if( (j+begin-1)%7==6  )
					cout<<endl;//������Ϊ����6������ 
					j++;	
				}
				cout<<endl;
				begin=(begin+month[i])%7;//������һ����1������ 
				cout<<"------------------------------------------------"<<endl;
				cout<<"------------------------------------------------"<<endl;
			}
		} 
	private:
		int year,day,month[12];//year�洢��ݣ�day�洢����1��1�����ڣ�����month�洢����12����ÿ������
};
int main()
{
	int year;
	cout<<"������ݣ�\n"; 
	cin>>year;
	calendar A(year); 
	A.show();//���	
	return 0; 
}

