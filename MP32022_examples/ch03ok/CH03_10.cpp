/*
[示範]:環狀鏈結串列的節點刪除 
*/
#include <iostream>
#include <cstdlib>
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
typedef class list node;
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

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        cout<<"[環狀串列已經空了]";
        return NULL;
     }
     else
     {
         if(del==head) //刪除的節點是串列首
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               //找到最後一個節點並記錄下來
               TailNode=CurNode;
               //(1)將串列首移到下一個節點
               head=head->next;
               //(2)將串列最後一個節點的指標指向新的串列首
               TailNode->next=head;
               return head;
         } 
         else //要刪除的節點不是串列首
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              //(1)找到要刪除節點的前一個節點並記錄下來
              PreNode=CurNode;
              //要刪除的節點
              CurNode=CurNode->next;
              //(2)將要刪除節點的前一個指標指向要刪除節點的下一個節點
              PreNode->next=CurNode->next;
              delete CurNode;
              return head;
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
			cout<<"["<<data[j*3+i][0]<<"]"<<setw(4)<<"["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;   //建立串列首
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
	for(i=1;i<12;i++) //建立串列
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
		cout<<"請輸入要刪除的學生編號，結束輸入-1：";
		cin>>position;
		if(position==-1) //迴圈中斷條件
			break;
		else
		{  
			ptr=findnode(head,position);
			head=deletenode(head,ptr);
		}
	}
	ptr=head;//指向串列的開頭
	cout<<"\n\t座號\t    姓名\t成績\n";         
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;//指向下一個節點
    } while(head!=ptr && head!=head->next);
    delete head;
	return 0;
}
