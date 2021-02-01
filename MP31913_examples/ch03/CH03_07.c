#include <stdio.h>
#include <stdlib.h>

struct student
{ 
	int num;
	char name[10];
	int score;
	struct student *next;
};
typedef struct student node;
typedef node *link;

int main()
{  
	link newnode,ptr,delptr;             /*宣告三個串列結構指標*/
	int i;
	printf("請輸入 5 筆學生資料：\n");
	delptr=(link)malloc(sizeof(node));   /*delptr暫當串列首*/
	if (!delptr)
	{  
		printf("[Error!!記憶體配置失敗!]\n");
		exit(1);
	}
	printf("請輸入座號：");
	scanf("%d",&delptr->num);
	printf("請輸入姓名：");
	scanf("%s",delptr->name);
	printf("請輸入成績：");
	scanf("%d",&delptr->score);
	ptr=delptr;                          /*保留串列首，以ptr為目前節點指標*/
	for (i=1;i<5;i++)
	{  
		newnode=(link)malloc(sizeof(node));  /*建立新節點*/
		if(!newnode)
		{  
			printf("[Error!!記憶體配置失敗!\n");
			exit(1);
		}
		printf("請輸入座號：");
		scanf("%d",&newnode->num);
		printf("請輸入姓名：");
		scanf("%s",newnode->name);
		printf("請輸入成績：");
		scanf("%d",&newnode->score);
		newnode->next=NULL;
		ptr->next=newnode;          /*把新節點加在串列後面*/
		ptr=ptr->next;              /*讓ptr保持在串列的最後面*/
	}
    printf("\n  學  生  成  績\n");
    printf(" 座號\t姓名\t成績\n=====================\n");
	ptr=delptr;                     /*讓ptr回到串列首*/
	while(ptr!=NULL)
	{  
		printf("%3d\t%-s\t%3d\n",ptr->num,ptr->name,ptr->score);
	    delptr=ptr;
		ptr=ptr->next;              /*ptr依序往後走訪串列*/
        free(delptr);               /*釋回記憶體空間*/
	}
	system("pause");
	return 0;
}
