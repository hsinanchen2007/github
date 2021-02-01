#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  //使用亂數的表頭檔 
using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
};
list del_ptr(list *head,list *ptr);
int main()
{  
	list *ptr;
	int findword=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Moko"},
    {"Lean"},{"Melissa"},{"Angel"},{"Sabrina"},
    {"Joyce"},{"Jasica"},{"Hanson"},{"Amy"},
    {"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));//以時間為亂數的種子
	cout<<"座號 成績  座號 成績  座號 成績  座號  成績"<<endl;
	cout<<"=============================================="<<endl;
	for(int i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(int i=0;i<3;i++)
	{  
		for (int j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	list *head=new list;//建立串列首
 	if(!head)
	{  
		cout<<"Error!! 記憶體配置失敗!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (int j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(int i=1;i<12;i++)                   
	{  
		list *newnode=new list;//建立串列
  		newnode->num=data[i][0];
		for (int j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		cout<<"請輸入要刪除的成績，結束輸入-1：";
		cin>>findword;
		if(findword==-1)//迴圈中斷條件
			break;
		else
		{  
			ptr=head;
			find=0;
			while (ptr!=NULL)
			{  
				if(ptr->score==findword)     
				{  
					*ptr=del_ptr(head,ptr);//刪除資料
     				find++;
				}
				ptr=ptr->next;
			}
			if(find==0)
			cout<<"######沒有找到######"<<endl;
		}
	}
	ptr=head;
	cout<<"\n\t座號\t    姓名\t成績"<<endl; //列印剩餘串列資料
	cout<<"\t=============================="<<endl;
	while(ptr!=NULL)
	{  
		cout<<"\t["<<ptr->num<<"]\t["<<setw(10)<<ptr->name
            <<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;
	}
}
list del_ptr(list *head,list *ptr)//刪除節點副程式
{  
	list *top;
 	top=head;
	if(ptr==head)//[情形1]:刪除點在串列首
	{  
		head=head->next;
		cout<<"已刪除第 "<<ptr->num<<" 號學生!!姓名： "
            <<ptr->name<<endl;
	}
	else
	{  
		while(top->next!=ptr)//找到刪除點的前一個位置
			top=top->next;
		if(ptr->next==NULL)  //[情形2]:刪除點在串列尾
		{  
			top->next=NULL;
	 		cout<<"已刪除第 "<<ptr->num<<" 號學生!!姓名： "
                <<ptr->name<<endl;
		}
		else  //[情形3]:刪除點在串列中任一節點
		{  
			top->next=ptr->next;
			cout<<"已刪除第 "<<ptr->num<<" 號學生!!姓名： "
                <<ptr->name<<endl;
		}
	}
    delete []ptr;  //釋放記憶體空間
    return *head;  //回傳串列
}
