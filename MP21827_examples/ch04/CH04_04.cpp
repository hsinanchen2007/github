/*
[示範]:插入排序法
*/
#include <iostream>
#include <iomanip>
#define SIZE 6  //定義陣列大小
using namespace std;

void inser (int *);//宣告插入排序法副程式
void showdata (int *);//宣告列印陣列副程式
void inputarr (int *,int);//宣告輸入陣列副程式
int  main(void)
{ 
    int data[SIZE];
	inputarr(data,SIZE);//把陣列名稱及陣列大小傳給副程式
	cout<<"您輸入的原始陣列是：";
	showdata (data);
	inser(data);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)//利用迴圈輸入陣列資料
	{ 
		cout<<"請輸入第 "<<i+1<<" 個元素：";
		cin>>data[i];
	}
}
void showdata(int data[])
{  
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];//列印陣列資料
	cout<<endl;
}
void inser(int data[])
{  
	int i; //i為掃描次數
	int j; //以j來定位比較的元素
	for (i=1;i<SIZE;i++)  //掃描迴圈次數為SIZE-1
	{  
 		int tmp;  //tmp用來暫存資料
		tmp=data[i];
        j=i-1;
	    while (j>=0 && tmp<data[j]) //如果第二元素小於第一元素
		{							 
			data[j+1]=data[j];		//就把所有元素往後推一個位置		
			j--;
		}
		data[j+1]=tmp;              //最小的元素放到第一個元素	
		cout<<"第 "<<i<<" 次掃瞄：";
		showdata(data);
	}
}
