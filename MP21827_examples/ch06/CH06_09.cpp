/*
[示範]:將生成績依座號反轉列印出來
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
int main()
{  
    link ptr,last,before;
    int i,j,findword=0,data[12][2];
    char namedata[12][10]={{"Allen"},{"Mako"},{"Lean"},
                           {"Melissa"},{"Angel"},{"Sabrina"},{"Joyce"},
                           {"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    for (i=0;i<12;i++)
    {  
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    link head=new node;//建立串列首
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
    for(i=1;i<12;i++) //建立鏈結串列
    {  
        link newnode=new node;
        newnode->num=data[i][0];
        for (j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }
    ptr=head;
    i=0;
    cout<<"原始串列資料："<<endl;               
    while (ptr!=NULL)                       
    {   //列印串列資料
        cout<<"["<<setw(2)<<ptr->num<<setw(8)
        <<ptr->name<<setw(3)<<ptr->score<<"] -> ";
        i++;
        if(i>=3) //三個元素為一列
        {  
            cout<<endl;
            i=0;
        }
        ptr=ptr->next;
    }
    ptr=head;
    before=NULL;
    cout<<"\n反轉後串列資料："<<endl;          
    while(ptr!=NULL) //串列反轉
    {  
        last=before;
        before=ptr;
        ptr=ptr->next;
        before->next=last;
    }
    ptr=before;
    while(ptr!=NULL)
    {  
        cout<<"["<<setw(2)<<ptr->num<<setw(8)
        <<ptr->name<<setw(3)<<ptr->score<<"] -> ";
        i++;
        if(i>=3)
        {  
            cout<<endl;
            i=0;
        }
        ptr=ptr->next;
    }
}
