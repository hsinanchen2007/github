#include <stdio.h>
#include <stdlib.h>

struct list              /*宣告串列結構*/
{  
	int coef,exp;
	struct list *next;
};
typedef struct list node;
typedef node *link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);
int main()
{  
	link a,b,c;
	int data1[4]={3,0,4,2};         /*多項式A的係數*/
	int data2[4]={6,8,6,9};         /*多項式B的係數*/
	printf("原始多項式：\nA=");
	a=creat_link(data1);            /*建立多項式A*/
	b=creat_link(data2);            /*建立多項式B*/
	print_link(a);                  /*列印多項式A*/
	printf("B=");
	print_link(b);                  /*列印多項式B*/
	printf("多項式相加結果：\nC=");
	c=sum_link(a,b);                /*C為A、B多項式相加結果*/
	print_link(c);                  /*列印多項式C*/
	system("pause");
	return 0;
}
link creat_link(int data[4]) /*建立多項式副程式*/
{  
	int i;
	link head,newnode,ptr;
	for(i=0;i<4;i++)
	{  
		newnode=(link)malloc(sizeof(node));
		if(!newnode)
		{  
			printf("Error!! 記憶體配置失敗!!\n");
			exit(i);
		}
		if(i==0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else if(data[i]!=0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
	}
	return head;
}
void print_link(link head)     /*列印多項式副程式*/
{  
	while(head!=NULL) 
	{  
		if(head->exp==1 && head->coef!=0)  /*X^1時不顯示指數*/
			printf("%dX + ",head->coef);
		else if(head->exp!=0 && head->coef!=0)
			printf("%dX^%d + ",head->coef,head->exp);
		else if(head->coef!=0) /*X^0時不顯示變數*/
			printf("%d",head->coef);
		head=head->next;
	}
	printf("\n");
}
link sum_link(link a,link b)  /*多項式相加副程式*/
{  
	int sum[4],i=0;
	link ptr;
	ptr=b;
	while(a!=NULL)   /*判斷多項式1*/
	{  
		b=ptr;       /*重複比較A及B的指數*/
		while(b!=NULL)
		{  
			if(a->exp==b->exp)  /*指數相等，係數相加*/
			{  
				sum[i]=a->coef+b->coef;
				a=a->next;
				b=b->next;
				i++;
			}
			else if(b->exp > a->exp) /*B指數較大，指定係數給C*/
			{  
				sum[i]=b->coef;
				b=b->next;
				i++;
			}
			else if(a->exp > b->exp) /*A指數較大，指定係數給C*/
			{  
				sum[i]=a->coef;
				a=a->next;
				i++;
			}
		}
	}
	return creat_link(sum);     /*建立相加結果串列C*/
}
