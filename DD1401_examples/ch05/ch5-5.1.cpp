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
   cout<<"===============�{���y�z====================\n";
   cout<<"= �{���W�١Gch5-5.1.cpp                   =\n";
   cout<<"= �{���ت��G�ʺA�t�m��V�쵲��C�@�Ӹ`�I  =\n"; 
   cout<<"===========================================\n"; 
   int Node_data;
   NODE *list;
   list=NewNode();
   cout<<"=================��J======================\n";    
   cout<<"�п�J��@�`�I���e�G";
   cin>>Node_data;
   list->data=Node_data;
   list->link=NULL;
   cout<<"=================��X======================\n";  
   cout<<"�`�I���e���G"<<list->data;        //�L�X��C������椧���e
   cout<<"\n"; 
   system("PAUSE");
   return(0);                        //�ΨӪ�ܼȰ�
 }
 
NODE *NewNode(void)  //�إߤ@�ӷs�`�I
{
  NODE *pt;
  pt=new NODE;  //�ʺA�O����t�m
  if(pt== NULL ) {
    cout<<"�O����Ŷ�����!";
    exit(1);
  }
  return pt;
}
