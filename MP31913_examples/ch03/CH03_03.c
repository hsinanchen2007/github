#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{  
	int num,score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     return ptr;
}

link insertnode(link head,link ptr,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=(link)malloc(sizeof(node));
    if(!InsertNode)
       return NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(ptr==NULL) /*插入第一個節點*/ 
    {
       InsertNode->next=head;
       return InsertNode;
    }    
    else
    {
        if(ptr->next==NULL)/*插入最後一個節點*/
        {
           ptr->next=InsertNode;
        }
        else /*插入中間節點*/
        {
            InsertNode->next=ptr->next;
            ptr->next=InsertNode;     
        }
    }
    return head;
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},
    {"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	printf("員工編號 薪水 員工編號 薪水 員工編號 薪水 員工編號 薪水\n");
	printf("-------------------------------------------------------\n");
	
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%4d] $%5d ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	printf("------------------------------------------------------\n");
	head=(link)malloc(sizeof(node));     /*建立串列首*/
	if(!head)
	{  
		printf("Error!! 記憶體配置失敗!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*建立串列*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		printf("\n");
        printf("請輸入要插入其後的員工編號,如輸入的編號不在此串列中,\n");
        printf("新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1：");
		scanf("%d",&position);
		if(position==-1)    /*迴圈中斷條件*/
			break;
		else
		{  
			ptr=findnode(head,position);
		  	printf("請輸入新插入的員工編號：");
			scanf("%d",&new_num);
			printf("請輸入新插入的員工薪水：");
			scanf("%d",&new_score);
			printf("請輸入新插入的員工姓名：");
			scanf("%s",new_name);
			head=insertnode(head,ptr,new_num,new_score,new_name);
		}
	}
	ptr=head;
	printf("\n\t員工編號    姓名\t薪水\n");         
	printf("\t==============================\n");
	while(ptr!=NULL)
	{  
		printf("\t[%2d]\t[ %-7s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}
