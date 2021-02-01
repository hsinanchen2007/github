#include <stdio.h>
#include <stdlib.h>

struct list
{  int val;
   struct list *next;
};
typedef struct list node;
typedef node *link;
struct list head[6];       /*宣告一個節點型態陣列*/
int main()
{  
	link ptr,newnode;
	char data[14][2]={{1,2},{2,1},{2,5},{5,2},     /*圖形陣列宣告*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	int i,j;
	printf("圖形的鄰接串列內容：\n");
	printf("----------------------------------\n");
	for (i=1;i<6;i++)
	{  
		head[i].val=i;         /*串列首head*/
		head[i].next=NULL;
		printf("頂點 %d =>",i);  /*把頂點值列印出來*/
		ptr=&(head[i]);          /*暫存節點ptr*/
		for (j=0;j<14;j++)       /*走訪圖形陣列*/
		{  
			if (data[j][0]==i)    /*如果節點值=i，加入節點到串列首*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];        /*宣告新節點，值為終點值*/
				newnode->next=NULL;
				while(ptr!=NULL)                /*判斷是否為串列的尾端*/
					ptr=ptr->next;
				ptr=newnode;                   /*加入新節點*/
				printf("[%c] ",64+newnode->val);  /*列印相鄰頂點*/
			}
		}   
		printf("\n");
	}
	system("pause");
	return 0;
}
