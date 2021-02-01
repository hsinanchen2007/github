#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct node
 {
    int data;
    struct node *link;
 }NODE;
NODE *NewNode(void);
void PrintLists(NODE*);    //�ŧi�C�L��өΨ�ӥH�W��C�����e 
int main(void)
{   
    cout<<"===============�{���y�z====================\n";
    cout<<"= �{���W�١Gch5-5.2.cpp                   =\n";
    cout<<"= �{���ت��G��өΨ�ӥH�W�`�I���쵲��C  =\n"; 
    cout<<"===========================================\n";  
    int i;
    char choice;
    NODE *head,*temp;      //�ŧihead,temp�����V���cNODE������ 
    head = NewNode( );     //���t�s�`�I�Ŷ� 
    temp = head;           //��ӫ��Ы��V�P�@�Ӹ`�I 
    cout<<"=================��J======================\n";  
    cout<<"�п�J��C��1�Ӹ�����ȡG";
    cin>>head->data;
    for(i=1;i<=4;i++) 
    {
      cout<<"�п�J��C��"<<i+1<<"�Ӹ�����ȡG";
      temp->link = NewNode( );  //�I�s�إ߷s�`�I 
      cin>>temp->link->data;
      temp = temp->link;
    }
    temp->link = NULL;
    cout<<"=================��X======================\n"; 
    PrintLists(head);   //�I�s�C�L��өΨ�ӥH�W��C�����e
    while(head != NULL) {
      NODE *temp;
      temp = head;
      head = head->link;
      free(temp);
    }
  system("pause");     //�ϵ{���Ȱ��b����e��
  return 0;
}
NODE *NewNode(void)  //�إ߷s�`�I���Ƶ{�� 
{
  NODE *pt;
  pt=new NODE;  //�ʺA�O����t�m
  if(pt== NULL ) {
    cout<<"�O����Ŷ�����!";
    exit(1);
  }
  return pt;
}

void PrintLists(NODE* head)  //�C�L��өΨ�ӥH�W��C�����e���Ƶ{�� 
{
  NODE *temp=head;
  cout<<"�쵲��C���G";        //�L�X��C������椧���e
  while(temp != NULL)
  {
    cout<<" "<<temp->data;
    temp = temp->link;
  }
  cout<<"\n";
}
