#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX=7;  //雜湊表元素個數
const int MAXNUM=13;   //資料個數
void creat_table(int); //宣告建立雜湊表副程式
void print_data(int);  //宣告列印雜湊表副程式
int findnum(int);      //宣告雜湊搜尋副程式
class list	//宣告串列類別 
{
	public:
	int val;
	list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];//宣告動態陣列
int main(void)
{  
	int i,num,data[MAXNUM];
	srand(time(NULL));
	for(i=0;i<INDEXBOX;i++)//清除雜湊表
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	cout<<"原始資料：\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;//亂數建立原始資料
		cout<<"["<<setw(2)<<data[i]<<"] ";//並列印出來
		
		if (i%8==7)
			cout<<"\n\t";
	}
	cout<<endl;
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);//建立雜湊表
	while(1)
	{  
		cout<<"請輸入搜尋資料(1-30)，結束請輸入-1：";
		cin>>num;
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			cout<<"#####沒有找到 "<<num<<" #####"<<endl;
		else
			cout<<"找到 "<<num<<"，共找了 "<<i<<" 次!"<<endl;
	}
	cout<<"\n雜湊表："<<endl;
	for(i=0;i<INDEXBOX;i++)
		print_data(i);//列印雜湊表
	cout<<endl;
	return 0;
}
void creat_table(int val)//建立雜湊表副程式
{  
	link newnode;
	int hash;
	hash=val%7; //雜湊函數除以7取餘數
	newnode=(link)malloc(sizeof(node));
	if(!newnode)
	{  
		cout<<"ERROR!! 記憶體配置失敗!!"<<endl;
		exit(1);
	}
	newnode->val=val;
	newnode->next=NULL;
	newnode->next=indextable[hash].next;//加入節點
	indextable[hash].next=newnode;
}
void print_data(int val)//列印雜湊表副程式
{  
	link head;
	int i=0;
	head=indextable[val].next;//起始指標
	cout<<setw(2)<<val<<"：\t";//索引位址
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)//控制長度
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b "<<endl;//清除最後一個"-"符號
}
int findnum(int num)  //雜湊搜尋副程式
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
