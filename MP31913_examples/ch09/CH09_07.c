#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 7         /*雜湊表元素個數*/
#define MAXNUM 13          /*資料個數*/
void creat_table(int);     /*宣告建立雜湊表副程式*/
void print_data(int);      /*宣告列印雜湊表副程式*/
int findnum(int);          /*宣告雜湊搜尋副程式*/
struct list
{  
	int val;
	struct list *next;
};
typedef struct list node;
typedef node *link;
node indextable[INDEXBOX];   /*宣告動態陣列*/

int main(void)
{  
	int i,num,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++)     /*清除雜湊表*/
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	printf("原始資料：\n\t");
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;          /*亂數建立原始資料*/
		printf("[%2d] ",data[i]);     /*並列印出來*/
		if (i%8==7)
			printf("\n\t");
	}
	printf("\n");
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);    /*建立雜湊表*/
	while(1)
	{  
		printf("請輸入搜尋資料(1-30)，結束請輸入-1：");
		scanf("%d",&num);
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			printf("#####沒有找到 %d #####\n",num);
		else
			printf("找到 %d，共找了 %d 次!\n",num,i);
	}
	printf("\n雜湊表：\n");
	for(i=0;i<INDEXBOX;i++)
		print_data(i);         /*列印雜湊表*/
	printf("\n");
	system("pause");
	return 0;
}
void creat_table(int val)    /*建立雜湊表副程式*/
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;              /*雜湊函數除以7取餘數*/
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; /*將節點加在串列*/
}
void print_data(int val)    /*列印雜湊表副程式*/
{  
	link head;
	int i=0;
	head=indextable[val].next;   /*起始指標*/
	printf("   %2d：\t",val);    /*索引位址*/
	while(head!=NULL)
	{  
		printf("[%2d]-",head->val);
		i++;
		if(i%8==7)              /*控制長度*/
			printf("\n\t");
		head=head->next;
	}
	printf("\b \n");            /*清除最後一個"-"符號*/
}
int findnum(int num)     /*雜湊搜尋副程式*/
{  
	link ptr;
	int i=0,hash;
	hash=num%7;
	ptr=indextable[hash].next;
	while(ptr!=NULL)
	{  
		i++;
		if(ptr->val==num)
			return i;
		else
			ptr=ptr->next;
	}
	return 0;
}
