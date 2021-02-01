/*
[示範]:單向串列的連結功能 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list
{  
	int num,score;
	char name[10];
	struct list *next;
};
typedef struct list node;
typedef node *link;
link concatlist(link,link);

int main()
{  
	link head,ptr,newnode,last,before;
	link head1,head2;
	int i,j,findword=0,data[12][2];
	/*第一組串列的姓名 */ 
	char namedata1[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"Jon"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    /*第二組串列的姓名 */
    char namedata2[12][10]={{"May"},{"John"},{"Michael"},
    {"Andy"},{"Tom"},{"Jane"},{"Yoko"},{"Axel"},
    {"Alex"},{"Judy"},{"Kelly"},{"Lucy"}};
	srand((unsigned)time(NULL));
	for (i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	head1=(link)malloc(sizeof(node));    /*建立第一組串列首*/
	if(!head1)
	{  
		printf("Error!! 記憶體配置失敗!!\n");
		exit(1);
	}
	head1->num=data[0][0];
	for (j=0;j<10;j++)
		head1->name[j]=namedata1[0][j];
	head1->score=data[0][1];
	head1->next=NULL;
	ptr=head1;
	for(i=1;i<12;i++)    /*建立第一組鏈結串列*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata1[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	
	srand((unsigned)time(NULL));
	for (i=0;i<12;i++)
	{  
		data[i][0]=i+13;
		data[i][1]=rand()%40+41;
	}
	head2=(link)malloc(sizeof(node)); /*建立第二組串列首*/
	if(!head2)
	{  
		printf("Error!! 記憶體配置失敗!!\n");
		exit(1);
	}
	head2->num=data[0][0];
	for (j=0;j<10;j++)
		head2->name[j]=namedata2[0][j];
	head2->score=data[0][1];
	head2->next=NULL;
	ptr=head2;
	for(i=1;i<12;i++)   /*建立第二組鏈結串列*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata2[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	i=0;
	ptr=concatlist(head1,head2);/*將串列相連*/
	printf("兩個鏈結串列相連的結果：\n");               
	while (ptr!=NULL)                       
	{                    /*列印串列資料*/
		printf("[%2d %6s %3d] -> ",ptr->num,ptr->name,ptr->score);
		i++;
		if(i>=3)         /*三個元素為一列*/
		{  
			printf("\n");
			i=0;
		}
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}
link concatlist(link ptr1,link ptr2)
{
     link ptr;
     ptr=ptr1;
     while(ptr->next!=NULL)
        ptr=ptr->next;
     ptr->next=ptr2;
     return ptr1;
}
