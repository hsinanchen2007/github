#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX = 10;   //雜湊表最大元素
const int MAXNUM = 7;       //最大資料個數
int print_data(int *,int);
int creat_table(int ,int *);

int main(void)
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand(time(NULL));     //依時間初始亂數
	cout<<"原始陣列值：\n";
	for(i=0;i<MAXNUM;i++)       //起始資料值
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     //清除雜湊表
		index[i]=-1;
	print_data(data,MAXNUM);    //列印起始資料
	cout<<"雜湊表內容："<<endl;
	for(i=0;i<MAXNUM;i++)       //建立雜湊表
	{  
		creat_table(data[i],index);
		cout<<data[i]<<" =>";  //列印單一元素的雜湊表位置
		print_data(index,INDEXBOX);
	}
	cout<<"完成雜湊表："<<endl;     
	print_data(index,INDEXBOX);  //列印最後完成結果
	return 0;
}
int print_data(int *data,int max)  //列印陣列副程式
{  
	cout<<"\t";
	for(int i=0;i<max;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
}
int creat_table(int num,int *index)  //建立雜湊表副程式
{  
	int tmp;
	tmp=num%INDEXBOX;  //雜湊函數=資料%INDEXBOX
	while(1)
	{  
		if(index[tmp]==-1) //如果資料對應的位置是空的
		{  
			index[tmp]=num; //則直接存入資料
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX; //否則往後找位置存放
	}
}
