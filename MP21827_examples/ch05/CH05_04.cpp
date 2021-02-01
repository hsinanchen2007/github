#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 20
using namespace std;
int fib(int n)
{
    if(n==1 || n==0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
int fib_search(int data[MAX],int SearchKey)
{
    int index=2; 
    //費氏數列的搜尋
    while(fib(index)<=MAX)
        index++;
    index--;
    //index >=2
    //起始的費氏數
    int RootNode=fib(index);
    //上一個費氏數
    int diff1=fib(index-1); 
    //上二個費氏數即diff2=fib(index-2)
    int diff2=RootNode-diff1;
    RootNode--;//這列運算式是配合陣列的索引是從0開始儲存資料
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
            return RootNode;
       }
       else
       {
            if(index==2) return MAX; //沒有找到
            if(SearchKey<data[RootNode])
            {
                RootNode=RootNode-diff2;//左子樹的新費氏數
                int temp=diff1;
                diff1=diff2;//上一個費氏數
                diff2=temp-diff2;//上二個費氏數
                index=index-1;
            }
           else
           {
                if(index==3) return MAX;
                RootNode=RootNode+diff2;//右子樹的新費氏數 
                diff1=diff1-diff2;//上一個費氏數
                diff2=diff2-diff1;//上二個費氏數
                index=index-2;
           }         
       }
    }
}
int main(void)
{  
	int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;
	while(1)
	{  
		cout<<"請輸入搜尋鍵值(1-150)，輸入-1結束：";
		cin>>val;//輸入搜尋的數值
		if(val==-1)//輸入值為-1就跳離迴圈
			break;
		int RootNode=fib_search(data,val);//利用費氏搜尋法找尋資料
		if(RootNode==MAX)
			cout<<"##### 沒有找到["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"在第 "<<setw(2)<<RootNode+1
            <<"個位置找到 ["<<setw(3)<<data[RootNode]<<"]"<<endl;
	}
	cout<<"資料內容："<<endl;
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	return 0;
}
