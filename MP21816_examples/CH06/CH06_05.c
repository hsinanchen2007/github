#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10			/*定義佇列的大小*/

int main()
{
	int front,rear,val,queue[MAX]={0};
	char choice;
	front=rear=-1;
	while(rear<MAX-1 && choice!='e')
	{  
		printf("[a]表示存入一個數值[d]表示取出一個數值[e]表示跳出此程式: ");
		choice=getche();
		switch(choice)
		{
			case 'a':
				printf("\n[請輸入數值]: ");
				scanf("%d",&val);
				rear++;
				queue[rear]=val;
				break;
			case 'd':
				if(rear>front)
				{  
					front++;
					printf("\n[取出數值為]: [%d]\n",queue[front]);
					queue[front]=0;
				}
				else
				{  
					printf("\n[佇列已經空了]\n");
					exit(0);
				}
				break;
			default:
				printf("\n");
				break;
		}
	}
	printf("\n------------------------------------------\n");
	printf("[輸出佇列中的所有元素]:");
	
    if(rear==MAX-1) 
     printf("[佇列已滿]\n");
	else if (front>=rear)
	{
		printf("沒有\n");
		printf("[佇列已空]\n");
	}
	else
	{
        while (rear>front)
		{  
			front++;
			printf("[%d] ",queue[front]);
		}
		printf("\n");
		printf("------------------------------------------\n");
	}
	printf("\n");
	system("pause");
	return 0;
}
