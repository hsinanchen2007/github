#include <stdio.h>
#include <stdlib.h>

struct list
{  
	int val;
    struct list *next;
};
typedef struct list node;
typedef node *link;
struct list* head[9];
int run[9];

void dfs(int current)                  /*深度優先函數*/
{  
	link ptr;
	run[current]=1;
	printf("[%d] ",current);
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0)        /*如果頂點尚未走訪，*/
			dfs(ptr->val);           /*就進行dfs的遞迴呼叫*/
		ptr=ptr->next;
	}
}
int main()
{  
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},   /*圖形邊線陣列宣告*/
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{8,7},{7,8}};
	int i,j;

	for (i=1;i<=8;i++)                        /*共有八個頂點*/
	{  
		run[i]=0;                             /*設定所有頂點成尚未走訪過*/
		head[i]=(link)malloc(sizeof(node));   
		head[i]->val=i;                       /*設定各個串列首的初值*/
		head[i]->next=NULL;
		ptr=head[i];                          /*設定指標為串列首*/
		for(j=0;j<20;j++)                     /*二十條邊線*/
		{  
			if(data[j][0]==i)                 /*如果起點和串列首相等，則把頂點加入串列*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;        /*加入新節點*/
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	printf("圖形的鄰接串列內容：\n");      /*列印圖形的鄰接串列內容*/
	for(i=1;i<=8;i++)
	{
		ptr=head[i];
		printf("頂點 %d=> ",i);
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			printf("[%d] ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}

	printf("深度優先走訪頂點：\n");      /*列印深度優先走訪的頂點*/
	dfs(1);
	printf("\n");
	system("pause");
	return 0;
}

