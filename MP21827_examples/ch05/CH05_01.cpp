#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main(void)
{  
	int i,j,val=0,data[80]={0};
	for (i=0;i<80;i++)
		data[i]=(rand()%150+1);
	while (val!=-1)
	{  
		int find=0;
		cout<<"請輸入搜尋鍵值(1-150)，輸入-1離開：";
		cin>>val;
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
			    cout<<"在第 "<<setw(3)<<i+1<<"個位置找到鍵值 ["<<data[i]<<"]"<<endl;
				find++;
			}
		}
		if(find==0 && val !=-1)
			cout<<"######沒有找到 ["<<val<<"]######"<<endl;
	}
	cout<<"資料內容："<<endl;
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			cout<<setw(2)<<i*8+j+1<<"["<<setw(3)<<data[i*8+j]<<"]  ";
		cout<<endl;
	}
	return 0;
}
