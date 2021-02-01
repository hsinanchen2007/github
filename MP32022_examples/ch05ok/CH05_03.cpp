/*
[示範]:實作環狀佇列資料的存入和取出
*/
#include <iostream>
using namespace std;
int main(void)
{  
	int front,rear,val=0,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
	    cout<<"請輸入一個值以存入佇列，欲取出值請輸入-2。(結束輸入-1)：";
		cin>>val;
		if(val==-2)
		{  
			if(front==rear)
			{  
				cout<<"[佇列已經空了]"<<endl;
				break;
			}
			front++;
			if (front==5)
				front=0;
			cout<<"取出佇列值 ["<<queue[front]<<"]"<<endl;
			queue[front]=0;
		}
		else if(val!=-1 && rear<5)
		{  
			if(rear+1==front || rear==4 && front<=0)
			{  
				cout<<"[佇列已經滿了]"<<endl;
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	cout<<"\n佇列剩餘資料："<<endl;
	if (front==rear)
		cout<<"佇列已空!!"<<endl;
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			cout<<"["<<queue[front]<<"]";
			queue[front]=0;
		}
	}
	cout<<endl;
	return 0;
}
