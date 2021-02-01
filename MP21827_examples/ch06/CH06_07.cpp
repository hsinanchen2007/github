#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip> //操縱子的標頭檔 
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

link insertnode(link head,link ptr,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=new node;
    if(!InsertNode)
        return NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(ptr==NULL) //插入第一個節點
    {
        InsertNode->next=head;
        return InsertNode;
    }    
    else
    {
        if(ptr->next==NULL)//插入最後一個節點
        {
            ptr->next=InsertNode;
        }
        else //插入中間節點
        {
            InsertNode->next=ptr->next;
            ptr->next=InsertNode;     
        }
    }
    return head;
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
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
			cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]   ";
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
	for(i=1;i<12;i++) //建立串列
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		cout<<"請輸入要插入其後的學生編號，結束輸入-1：";
		cin>>position;
		if(position==-1)//迴圈中斷條件
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
	ptr=head;
	cout<<"\n\t座號\t    姓名\t成績\n";         
	cout<<"\t==============================\n";
	while(ptr!=NULL)
	{  
		cout<<"\t["<<ptr->num<<"]\t[ "<<ptr->name<<"]"<<setw(6)<<"\t["<<ptr->score<<"]\n";
		ptr=ptr->next;
	}
	delete head;
	return 0;
}
