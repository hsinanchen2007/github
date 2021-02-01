#include <stdio.h>
#include <stdlib.h>

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
     while(ptr->next!=head)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     ptr=NULL;   
     return ptr;
}

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        printf("[環狀串列已經空了]");
        return NULL;
     }
     else
     {
         if(del==head) /*要刪除的節點是串列首*/
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               /*找到最後一個節點並記錄下來*/
               TailNode=CurNode;
               /*(1)將串列首移到下一個節點*/
               head=head->next;
               /*(2)將串列最後一個節點的指標指向新的串列首*/
               TailNode->next=head;
               return head;
         } 
         else /*要刪除的節點不是串列首*/
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              /*(1)找到要刪除節點的前一個節點並記錄下來*/
              PreNode=CurNode;
              /*要刪除的節點*/
              CurNode=CurNode->next;
              /*(2)將要刪除節點的前一個指標指向要刪除節點的下一個節點*/
              PreNode->next=CurNode->next;
              return head;
         }
     }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	printf("員工編號 薪水 員工編號 薪水 員工編號 薪水 員工編號 薪水\n");
	printf("-------------------------------------------------------\n");
	
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
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
	head->num=data[0][0];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*建立串列*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->num=data[i][0];
		newnode->next=NULL;
		ptr->next=newnode;/*將前一個節點指向新建立的節點*/ 
		ptr=newnode; /*新節點成為前一個節點*/ 
	}
	newnode->next=head;/*將最後一個節點指向頭節點就成了環狀鏈結*/ 
	while(1)
	{  
		printf("\n請輸入要刪除的員工編號,要結束插入過程,請輸入-1：");
		scanf("%d",&position);
		if(position==-1)    /*迴圈中斷條件*/
			break;
		else
		{  
	
            ptr=findnode(head,position);
            if(ptr==NULL)
             {
              printf("-----------------------\n");
              printf("串列中沒這個節點....\n");
              break;
              } 
            else
			 {
             head=deletenode(head,ptr);
			 printf("已刪除第 %d 號員工 姓名：%s 薪資:%d\n",ptr->num,ptr->name,ptr->score);
             }
		}
	}
	 ptr=head;/*指向串列的開頭*/
     printf("\n\t員工編號    姓名\t薪水\n");         
     printf("\t==============================\n");

	do
	{
	    printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;/*指向下一個節點*/
    } while(head!=ptr && head!=head->next);
	system("pause");
	return 0;
}
