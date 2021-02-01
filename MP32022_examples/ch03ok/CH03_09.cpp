/*
[示範]:環狀鏈結串列節點的建立與插入 
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
using namespace std;
class list
{   
    public:
	int num,score;
	char name[10];
	class list *next;
};
typedef struct list node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     return ptr;
}

link insertnode(link head,link after,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=new node;
    link CurNode=NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(InsertNode==NULL)
    {
       cout<<"記憶體配置失敗"<<endl;
       return NULL;
    }
    else
    {
        if(head==NULL)//串列是空的
        {
           head=InsertNode;
           InsertNode->next=head;
           return head;
        }              
        else
        {
            if(after==NULL) //新增節點於串列首的位置
            {
               //1)將新增節點的指標指向串列首
               InsertNode->next=head;
               CurNode=head;
               while(CurNode->next!=head)
                  CurNode=CurNode->next;
               //(2)找到串列尾後將它的指標指向新增節點
               CurNode->next=InsertNode;
               //(3)將串列首指向新增節點
               head=InsertNode;
               return head;
            }
            else //新增節點於串列首以外的地方
            {
               //(1)將新增節點的指標指向after的下一個節點
               InsertNode->next=after->next;
               //(2)將節點after的指標指向新增節點
               after->next=InsertNode;
               return head; 
            }                             
        }                    
    }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"}
    ,{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));
	cout<<"座號  成績  座號  成績  座號  成績  座號  成績"<<endl;
	cout<<"=============================================="<<endl;
	for(i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"] ["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;  //建立串列首
	if(!head)
	{  
		cout<<"Error!! 記憶體配置失敗!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)  //建立串列
	{  
		newnode=new node;
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;//將前一個節點指向新建立的節點
		ptr=newnode; //新節點成為前一個節點
	}
	newnode->next=head;//將最後一個節點指向頭節點就成了環狀鏈結
	while(1)
	{  
		cout<<"請輸入要插入其後的學生編號，結束輸入-1：";
		cin>>position;
		if(position==-1)    /*迴圈中斷條件*/
			break;
		else
		{  
			ptr=findnode(head,position);
		  	cout<<"請輸入新插入的學生編號：";
			cin>>new_num;
			cout<<"請輸入新插入的學生成績：";
			cin>>new_score;
			cout<<"請輸入新插入的學生姓名：";
			cin>>new_name;
			head=insertnode(head,ptr,new_num,new_score,new_name);
		}
	}
	ptr=head;//指向串列的開頭
	cout<<"\n\t座號\t    姓名\t成績\n";      
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]\n";
		ptr=ptr->next;//指向下一個節點
    } while(head!=ptr && head!=head->next);
    delete newnode;
	return 0;
}
