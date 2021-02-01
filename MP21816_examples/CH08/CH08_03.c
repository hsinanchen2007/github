#include <stdio.h>
#include <stdlib.h>
#define VERTS	6                /*圖形頂點數*/

struct edge                      /*邊的結構宣告*/
{  
	int from,to;
	int find,val;
	struct edge* next;
};
typedef struct edge node;
typedef node* mst;
int v[VERTS+1];
mst findmincost(mst head)                 /*搜尋成本最小的邊*/
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval&&ptr->find==0)
		{                                  /*假如ptr->val的值小於minval*/
			minval=ptr->val;			   /*就把ptr->val設為最小值*/
			retptr=ptr;                    /*並且把ptr紀錄下來*/
		}
		ptr=ptr->next;
	}
	retptr->find=1;                        /*將retptr設為已找到的邊*/
	return retptr;                         /*傳回retptr*/
}
void mintree(mst head)                     /*最小成本擴張樹函數*/
{
	mst ptr,mceptr;
	int i,result=0;
	ptr=head;

	for(i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1&&v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			printf("起始頂點 [%d] -> 終止頂點 [%d] -> 路徑長度 [%d]\n",mceptr->from,mceptr->to,mceptr->val);
		ptr=ptr->next;
	}
}

int main()
{  
	int data[10][3]={{1,2,6},{1,6,12},{1,5,10},{2,3,3},    /*成本表陣列*/
                    {2,4,5},{2,6,8},{3,4,7},{4,6,11},
					{4,5,9},{5,6,16}};
	int i,j;
	mst head,ptr,newnode;
	head=NULL;
	
	for(i=0;i<10;i++)                    /*建立圖形串列*/
	{  
		for(j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
				newnode=(mst)malloc(sizeof(node));
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	
	printf("-------------------------------------------------\n");
	printf("建立最小成本擴張樹：\n");
	printf("-------------------------------------------------\n");
	mintree(head);                        /*建立最小成本擴張樹*/
	system("pause");
	return 0;
}
