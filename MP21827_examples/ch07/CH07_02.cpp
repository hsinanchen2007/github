#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define INDEXBOX 7     //雜湊表元素個數
#define MAXNUM 13      //資料個數
using namespace std;
void creat_table(int); //宣告建立雜湊表副程式
void print_data(int);  //宣告列印雜湊表副程式
class list             //宣告串列結構
{  
    public:
	int val;
	class list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];  //宣告動態陣列
int main(void)
{  
	int i,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++) //清除雜湊表
	{  
		indextable[i].val=-1;
		indextable[i].next=NULL;
	}
	cout<<"原始資料：\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1; //亂數建立原始資料
		cout<<"["<<setw(2)<<data[i]<<"] "; //並列印出來
		if(i%8==7)
			cout<<"\n\t";
	}
	cout<<"\n雜湊表：\n";
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]); //建立雜湊表
	for(i=0;i<INDEXBOX;i++)
		print_data(i);    //列印雜湊表
	cout<<endl;
	return 0;
}
void creat_table(int val) //建立雜湊表副程式
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;          //雜湊函數除以7取餘數
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; //將節點加在串列
}
void print_data(int val)   //列印雜湊表副程式
{  
	link head;
	int i=0;
	head=indextable[val].next;  //起始指標
	cout<<"   "<<setw(2)<<val<<"：\t";//索引位址
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)  //控制長度
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b \n";//清除最後一個"-"符號
}
