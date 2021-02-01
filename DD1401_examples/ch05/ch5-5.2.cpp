#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct node
 {
    int data;
    struct node *link;
 }NODE;
NODE *NewNode(void);
void PrintLists(NODE*);    //宣告列印兩個或兩個以上串列的內容 
int main(void)
{   
    cout<<"===============程式描述====================\n";
    cout<<"= 程式名稱：ch5-5.2.cpp                   =\n";
    cout<<"= 程式目的：兩個或兩個以上節點的鏈結串列  =\n"; 
    cout<<"===========================================\n";  
    int i;
    char choice;
    NODE *head,*temp;      //宣告head,temp為指向結構NODE的指標 
    head = NewNode( );     //分配新節點空間 
    temp = head;           //兩個指標指向同一個節點 
    cout<<"=================輸入======================\n";  
    cout<<"請輸入串列第1個資料欄位值：";
    cin>>head->data;
    for(i=1;i<=4;i++) 
    {
      cout<<"請輸入串列第"<<i+1<<"個資料欄位值：";
      temp->link = NewNode( );  //呼叫建立新節點 
      cin>>temp->link->data;
      temp = temp->link;
    }
    temp->link = NULL;
    cout<<"=================輸出======================\n"; 
    PrintLists(head);   //呼叫列印兩個或兩個以上串列的內容
    while(head != NULL) {
      NODE *temp;
      temp = head;
      head = head->link;
      free(temp);
    }
  system("pause");     //使程式暫停在執行畫面
  return 0;
}
NODE *NewNode(void)  //建立新節點之副程式 
{
  NODE *pt;
  pt=new NODE;  //動態記憶體配置
  if(pt== NULL ) {
    cout<<"記憶體空間不足!";
    exit(1);
  }
  return pt;
}

void PrintLists(NODE* head)  //列印兩個或兩個以上串列的內容之副程式 
{
  NODE *temp=head;
  cout<<"鏈結串列為：";        //印出串列的資料欄之內容
  while(temp != NULL)
  {
    cout<<" "<<temp->data;
    temp = temp->link;
  }
  cout<<"\n";
}
