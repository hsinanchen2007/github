#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct node
 {
    int data;
    struct node *link;
 }NODE;
NODE *NewNode(void);

int main(int argc, char *argv[])
 {
   cout<<"===============程式描述====================\n";
   cout<<"= 程式名稱：ch5-5.1.cpp                   =\n";
   cout<<"= 程式目的：動態配置單向鏈結串列一個節點  =\n"; 
   cout<<"===========================================\n"; 
   int Node_data;
   NODE *list;
   list=NewNode();
   cout<<"=================輸入======================\n";    
   cout<<"請輸入單一節點內容：";
   cin>>Node_data;
   list->data=Node_data;
   list->link=NULL;
   cout<<"=================輸出======================\n";  
   cout<<"節點內容為："<<list->data;        //印出串列的資料欄之內容
   cout<<"\n"; 
   system("PAUSE");
   return(0);                        //用來表示暫停
 }
 
NODE *NewNode(void)  //建立一個新節點
{
  NODE *pt;
  pt=new NODE;  //動態記憶體配置
  if(pt== NULL ) {
    cout<<"記憶體空間不足!";
    exit(1);
  }
  return pt;
}
