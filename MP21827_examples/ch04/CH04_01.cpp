#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
    int data[6]={6,5,9,7,2,8};	// 原始資料 
    cout<<"氣泡排序法：\n原始資料為：";
	for (int i=0;i<6;i++)
	    cout<<setw(3)<<data[i];
	cout<<endl;

	for (int i=5;i>0;i--)// 掃瞄次數 
	{
		for (int j=0;j<i;j++)//比較、交換次數
		{
			if (data[j]>data[j+1])// 比較相鄰兩數，如第一數較大則交換 
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		cout<<"第 "<<6-i<<" 次排序後的結果是："; //把各次掃描後的結果印出
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;
	}
	cout<<"排序後結果為：";
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
	return 0;
}
