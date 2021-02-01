#include <iostream>
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
int main()
{  
	link newnode,ptr,delptr; //宣告三個串列結構指標
	cout<<"請輸入 5 筆學生資料："<<endl;
	delptr=new node;  //delptr暫當串列首
	if (!delptr)
	{  
		cout<<"[Error!!記憶體配置失敗!]"<<endl;
		exit(1);
	}
	cout<<"請輸入座號：";
	cin>>delptr->num;
	cout<<"請輸入姓名：";
	cin>>delptr->name;
	cout<<"請輸入成績：";
	cin>>delptr->score;
	ptr=delptr;   //保留串列首，以ptr為目前節點指標
	for (int i=1;i<5;i++)
	{  
		newnode=new node;  //建立新節點
		if(!newnode)
		{  
			cout<<"[Error!!記憶體配置失敗!"<<endl;
			exit(1);
		}
		cout<<"請輸入座號：";
		cin>>newnode->num;
		cout<<"請輸入姓名：";
		cin>>newnode->name;
		cout<<"請輸入成績：";
		cin>>newnode->score;
		newnode->next=NULL;
		ptr->next=newnode; //把新節點加在串列後面
		ptr=ptr->next;     //讓ptr保持在串列的最後面
	}
    cout<<"\n  學  生  成  績"<<endl;
    cout<<" 座號\t姓名\t成績\n====================="<<endl;
	ptr=delptr;            //讓ptr回到串列首
	while(ptr!=NULL)
	{  
		cout<<ptr->num<<"\t"<<ptr->name<<"\t"<<ptr->score<<endl;
	    delptr=ptr;
		ptr=ptr->next;     //ptr依序往後走訪串列
        delete delptr;     //釋回記憶體空間
	}
}
