/*
[示範]:將兩個學生成績串列連結起來，
       然後列印出連結後的串列內容
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
class list
{
	public:
 	int num,score;
	char name[10];
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);
int main()
{  
	link ptr1,ptr2,ptr;
	int i,data1[6][2],data2[6][2];
	srand(time(NULL));
	for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
	ptr1=creat_link(data1,6);//建立串列1
	ptr2=creat_link(data2,6);//建立串列2
	i=0;
	cout<<"\t\t    原 始 串 列 資 料："<<endl;
	cout<<"\t    座號 成績   座號 成績   座號 成績"<<endl;
	cout<<"\t    =================================="<<endl;
	cout<<"   串列 1 ：";
	print_link(ptr1);
	cout<<"   串列 2 ：";
	print_link(ptr2);
	cout<<"\t    =================================="<<endl;
	cout<<"連結後串列：";
	ptr=concat(ptr1,ptr2);//連結串列
	print_link(ptr);
}
link creat_link(int data[10][2],int num)//建立串列副程式
{  
	link head,ptr,newnode;
	for(int i=0;i<num;i++)
	{  
		newnode=new node;
		if(!newnode)
		{  
			cout<<"Error!! 記憶體配置失敗!!"<<endl;
			exit(i);
		}
		if(i==0)//建立串列首
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else //建立串列其他節點
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;//回傳串列
}
void print_link(link head)//列印串列副程式
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		cout<<"["<<setw(2)<<ptr->num<<"-"<<setw(3)
            <<ptr->score<<"] -> ";
		i++;
		if(i>=3)//每行列印三個元素
		{  
			cout<<"\n\t    ";
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	cout<<endl;
}
link concat(link ptr1,link ptr2)//連結串列副程式
{  
	link head;
	head=ptr1->next;//在ptr1及ptr2中，各找任意一個節點
	ptr1->next=ptr2->next;//把兩個節點的next對調即可
	ptr2->next=head;
	return ptr2;
}
