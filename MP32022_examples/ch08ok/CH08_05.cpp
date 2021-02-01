/*
[示範]:謝耳排序法
*/
#include <iostream>
#include <iomanip>
#define SIZE 8 //定義矩陣大小
using namespace std;

void shell (int *,int);  //宣告排序法副程式
void showdata (int *);   //宣告列印陣列副程式
void inputarr (int *,int);//宣告輸入陣列副程式
int main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);
	cout<<"您輸入的原始陣列是：";
	showdata(data);
	shell(data,SIZE);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
	{ 
		cout<<"請輸入第 "<<i+1<<" 個元素：";
		cin>>data[i];
	}
}
void showdata(int data[])
{  	
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void shell(int data[],int size)
{  
	int i;        //i為掃描次數
	int j;        //以j來定位比較的元素
	int k=1;      //k列印計數
	int tmp;      //tmp用來暫存資料
	int jmp;      //設定間距位移量
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  //插入排序法
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		cout<<"第 "<<k++<<" 次排序：";
		showdata (data);
		jmp=jmp/2;    //控制迴圈數
	}
}
