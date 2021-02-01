/*
[示範]:基數排序法
*/
// 基數排序法 由小到大排序 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void radix (int *,int);	// 基數排序法副程式 
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	cout<<"請輸入陣列大小(100以下)：";
	cin>>size;
	cout<<"您輸入的原始資料是："<<endl;
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	return 0;
}
void inputarr(int data[],int size)
{
	srand(time(NULL));
	for (int i=0;i<size;i++)
		data[i]=(rand()%999)+1;	
			// 設定data 值最大為 3 位數 
}
void showdata(int data[],int size)
{  
	for (int i=0;i<size;i++)
		cout<<setw(5)<<data[i];
	cout<<endl;
}
void radix(int data[],int size)
{  
	for (int n=1;n<=100;n=n*10)		
	// n為基數，由個位數開始排序 
	{  
		int tmp[10][100]={0};		
		// 設定暫存陣列，[0~9位數][資料個數]，所有內容均為0 
		for (int i=0;i<size;i++) // 比對所有資料 
		{  
			int m=(data[i]/n)%10;	
			// m為n位數的值，如 36取十位數 (36/10)%10=3 
			tmp[m][i]=data[i];		
			// 把data[i]的值暫存於tmp 裡 
		}
		int k=0;
		for (int i=0;i<10;i++)
		{  
			for(int j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)		
				// 因一開始設定 tmp ={0}，故不為0者即為 
				{  
					data[k]=tmp[i][j];	
					// data暫存在 tmp 裡的值，把tmp 裡的值放 
					k++;		        // 回data[ ]裡 
				}
			}
		}
		cout<<"經過"<<setw(3)<<n<<"位數排序後：";
		showdata(data,size);
	} 
}
