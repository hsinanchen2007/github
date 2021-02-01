/*
[示範]:多項式相加
*/
#include <iostream>
using namespace std;
class list //宣告串列結構
{  
	public :
	int coef,exp;
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);
int main()
{  
	link a,b,c;
	int data1[4]={3,0,4,2}; //多項式A的係數
	int data2[4]={6,8,6,9}; //多項式B的係數
	cout<<"原始多項式："<<endl<<"A=";
	a=creat_link(data1);  //建立多項式A
	b=creat_link(data2);  //建立多項式B
	print_link(a);   //列印多項式A
	cout<<"B=";
	print_link(b);   //列印多項式B
	cout<<"多項式相加結果：\nC=";
	c=sum_link(a,b); //C為A、B多項式相加結果
	print_link(c);   //列印多項式C
}
link creat_link(int data[4])//建立多項式副程式
{
	link head,newnode,ptr;
	for(int i=0;i<4;i++)
	{  
		newnode = new node;
		if(!newnode)
		{  
			cout<<"Error!! 記憶體配置失敗!!"<<endl;
			exit(1);
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
void print_link(link head) //列印多項式副程式
{  
	while(head!=NULL) 
	{  
		if(head->exp==1 && head->coef!=0)//X^1時不顯示指數
			cout<<head->coef<<"X + ";
		else if(head->exp!=0 && head->coef!=0)
			cout<<head->coef<<"X^"<<head->exp<<" + ";
		else if(head->coef!=0)           //X^0時不顯示變數
			cout<<head->coef;
		head=head->next;
	}
	cout<<endl;
}
link sum_link(link a,link b) //多項式相加副程式
{  
	int sum[4],i=0;
	link ptr;
	ptr=b;
	while(a!=NULL) //判斷多項式1
	{  
		b=ptr; //重複比較A及B的指數
		while(b!=NULL)
		{  
			if(a->exp==b->exp)//指數相等，係數相加
			{  
				sum[i]=a->coef+b->coef;
				a=a->next;
				b=b->next;
				i++;
			}
			else if(b->exp > a->exp)//B指數較大，指定係數給C
			{  
				sum[i]=b->coef;
				b=b->next;
				i++;
			}
			else if(a->exp > b->exp)//A指數較大，指定係數給C
			{  
				sum[i]=a->coef;
				a=a->next;
				i++;
			}
		}
	}
	return creat_link(sum);//建立相加結果串列C
}
