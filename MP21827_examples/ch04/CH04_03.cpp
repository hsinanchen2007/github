#include <iostream>
#include <iomanip>
using namespace std;

void select (int *); //宣告選擇排序法副程序
void showdata (int *);//宣告列印陣列副程序
int main(void)
{
	int data[6]={9,7,5,3,4,6};
	cout<<"原始資料為：";
	showdata(data);
	select(data);
	return 0;
}
void showdata (int data[])
{
	for (int i=0;i<6;i++)
	    cout<<setw(3)<<data[i];
	cout<<endl;
}

void select (int data[])
{
	for(int i=0;i<5;i++) //掃描5次
	{   
		for(int j=i+1;j<6;j++)  //由i+1比較起，比較5次
		{	
			if(data[i]>data[j]) //比較第i及第j個元素
			{	
				int tmp;
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
		cout<<"第 "<<i+1<<" 次排序結果：";
	    for (int k=0;k<6;k++)
			cout<<setw(3)<<data[k]; //列印排序結果
	    cout<<endl;
	}
    cout<<endl;
}
