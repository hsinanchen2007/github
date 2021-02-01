#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int bin_search(int data[80],int val);
int main(void)
{  
	int num,val=1,data[80]={0};
	for (int i=0;i<80;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while (1)
	{  
		num=0;
		cout<<"請輸入搜尋鍵值(1-150)，輸入-1結束：";
		cin>>val;
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			cout<<"##### 沒有找到["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"在第 "<<setw(2)<<num+1<<"個位置找到 ["<<setw(3)<<data[num]<<"]"<<endl;
	}
	cout<<"資料內容："<<endl;
	for(int i=0;i<8;i++)
	{ 
		for(int j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
int bin_search(int data[80],int val)
{  
	int low,mid,high;
	low=0;
	high=79;
	cout<<"搜尋處理中......"<<endl;
	while(low <= high && val !=-1)
	{  
		mid=(low+high)/2;
		if(val<data[mid])
		{  
			cout<<val<<" 介於位置 "<<low+1<<"["<<setw(3)<<data[low]<<"]及中間值 "<<mid+1<<"["<<setw(3)<<data[mid]<<"]，找左半邊"<<endl;
			high=mid-1;	     
		}
		else if(val>data[mid])
		{  
			cout<<val<<" 介於中間值位置 "<<mid+1<<"["<<setw(3)<<data[mid]<<"]及"<<high+1<<"["<<setw(3)<<data[high]<<"]，找右半邊"<<endl;			
   			low=mid+1;   	     
		}
		else
			return mid;
	}
	return -1;
}
