#include <stdio.h>
#include <stdlib.h>

int main(void)
{  
	int front,rear,val,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
		printf("請輸入一個值以存入佇列，欲取出值請輸入0。(結束輸入-1)：");
		scanf("%d",&val);
		if(val==0)
		{  
			if(front==rear)
			{  
				printf("[佇列已經空了]\n");
				break;
			}
			front++;
			if (front==5)
				front=0;
			printf("取出佇列值 [%d]\n",queue[front]);
			queue[front]=0;
		}
		else if(val!=-1&&rear<5)
		{  
			if(rear+1==front||rear==4&&front<=0)
			{  
				printf("[佇列已經滿了]\n");
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	printf("\n佇列剩餘資料：\n");
	if (front==rear)
		printf("佇列已空!!\n");
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			printf("[%d]",queue[front]);
			queue[front]=0;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
