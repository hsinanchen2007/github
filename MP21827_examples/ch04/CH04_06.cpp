/*
[示範]:快速排序法
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process = 0;
int main(void)
{
	int size,data[100]={0};
	cout<<"請輸入陣列大小(100以下)：";
	cin>>size;
	cout<<"您輸入的原始資料是："<<endl;
	inputarr (data,size);
	showdata (data,size);
	quick(data,size,0,size-1);
	cout<<"\n排序結果：";
	showdata(data,size);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
		cin>>data[i];
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void quick(int d[],int size,int lf,int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
 //1:第一筆鍵值為d[lf]
	if(lf<rg)
	{
		lf_idx=lf+1;
		rg_idx=rg;
    while(1) {
	    cout<<"[處理過程"<<process++<<"]=> ";
        for(int t=0;t<size;t++)
			cout<<"["<<setw(2)<<d[t]<<"] ";
		cout<<endl;
		for(int i=lf+1;i<=rg;i++)
		//2:由左向右找出一個鍵值大於d[lf]者
		{
			if(d[i]>=d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(int j=rg;j>=lf+1;j--)
		//3:由右向左找出一個鍵值小於d[lf]者
		{
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)       
		 //4-1:若lf_idx<rg_idx
		{					     
			tmp = d[lf_idx];       
			d[lf_idx] = d[rg_idx];
			//則d[lf_idx]和d[rg_idx]互換
			d[rg_idx] = tmp;      //然後繼續排序 
        } else {
			break;    //否則跳出排序過程 
		} 
    }
		if(lf_idx>=rg_idx)      
		 //5-1:若lf_idx大於等於rg_idx
		{       //則將d[lf]和d[rg_idx]互換
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
                                      
			//5-2:並以rg_idx為基準點分成左右兩半
			quick(d,size,lf,rg_idx-1);
			//以遞迴方式分別為左右兩半進行排序
			quick(d,size,rg_idx+1,rg);
			//直至完成排序
		}
	}
}
