/*
[示範]:實作佇列資料的存入和取出
*/
#include <iostream>
using namespace std;
const int MAX=20;//定義佇列的大小
int main(void)
{
	int front,rear,val,queue[MAX]={0};
	char ch;
	front=rear=-1;
	while(rear<MAX-1&&ch!='E')
	{  
		cout<<"[I]存入一個數值[G]取出一個數值[E]結束: ";
		cin>>ch;
		switch(ch)
		{
			case 'I':
				cout<<"[請輸入數值]: ";
				cin>>val;
				rear++;
				queue[rear]=val;
				break;
			case 'G':
				if(rear>front)
				{  
					front++;
					cout<<"[取出數值為]: ["<<queue[front]<<"]";
					cout<<endl;
					queue[front]=0;
				}
				else
				{  
					cout<<"[佇列已經空了]"<<endl;
					exit(0);
				}
				break;
			default:
				cout<<endl;
				break;
		}
	}
	if(rear==MAX-1) cout<<"[佇列已經滿了]"<<endl;
	cout<<"[目前佇列中的資料]:";
	if (front>=rear)
	{
		cout<<"沒有"<<endl;
		cout<<"[佇列已經空了]"<<endl;
	}
	else
	{
		while (rear>front)
		{  
			front++;
			cout<<"["<<queue[front]<<"]\t";
		}
		cout<<endl;
	}
	return 0;
}
