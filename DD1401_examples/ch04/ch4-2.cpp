#include <cstdlib>
#include <iostream>
#define NUM 10          //�w�q��C�j�p
using namespace std;
class fun
{
  public:
  int number;
  void get_input();
  void Enqueue(int);      //�ŧiEnqueue�Ƶ{��
  int Dequeue(void);      //�ŧiDequeue�Ƶ{��
  void PrintQueue(void);  //�ŧi�C�L�ثe��C�����e���Ƶ{�� 
};
typedef struct queue {
  int Q[NUM];
  int Rear;
  int Front;
} Queue;
Queue qu;
int main(int argc, char *argv[])
{
  int op=0,item;
    fun obj;
  qu.Rear = -1;
  qu.Front = -1;
  cout<<"==========�{���y�z============================\n";
  cout<<"= �{���W�١Gch4-2.cpp                        =\n";
  cout<<"= �{���ت��G�ϥΦ�C�i��Enqueue�H��Dequeue   =\n"; 
  cout<<"==============================================\n";
  while(1)
  {
   obj.get_input();
   op=obj.number;

    switch(op)
    {
      case 1: cout<<"�п�J�A�n�[�J�����:";
              cin>>item;
              obj.Enqueue(item);      //�I�sEnqueue�Ƶ{�� 
              break;
      case 2: item = obj.Dequeue( );  //�I�sDequeue�Ƶ{��
              if(item != -1)
                cout<<item<<"�O�q��C�R�������\n";
              break;
      case 3: obj.PrintQueue( );      //�I�sPrintQueue�Ƶ{��
              break;
    }
  }
  system("pause");     //�ϵ{���Ȱ��b����e�����ڭ̬ݨ쵲�G
  return 0;
}

void fun::get_input()
{
    cout<<"========================================\n";
    cout<<"=   1.Enqueue(�[�J)                    =\n";
    cout<<"=   2.Dequeue(�R��)                    =\n";
    cout<<"=   3.��ܥثe��C�����e               =\n";
    cout<<"=   4.����                             =\n";    
    cout<<"========================================\n";
    cout<<"�п�J�A���ާ@�G";
    cin>>number;    
}

void fun:: Enqueue(int item)    //Enqueue�Ƶ{�� 
{
  if(qu.Rear == NUM -1) {
    cout<<"��C�O����!\n";
    return;
  } else
    qu.Q[++qu.Rear] = item;
}
int fun:: Dequeue(void)        //Dequeue�Ƶ{��
{
  if(qu.Front == qu.Rear) {
    cout<<"��C�O�Ū�!\n";
    return -1;
  } else
    return qu.Q[++qu.Front];
}
void fun:: PrintQueue(void)     //�C�L�ثe��C�����e���Ƶ{��
{
  int i;
  cout<<"�ثe��C�����e�G";
  for(i=qu.Rear;i>=qu.Front+1;i--)
    cout<<"  "<<qu.Q[i];
  cout<<"\n";  
}
