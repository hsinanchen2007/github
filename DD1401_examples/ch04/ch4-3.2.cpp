#include <cstdlib>
#include <iostream>
#define NUM 5           //�w�q���Φ�C�j�p
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
  int CQueue[NUM];
  int Rear;
  int Front;
} Queue;
Queue qu;
int main(int argc, char *argv[])
{
  int op=0,item;
      fun obj;
  qu.Rear = 0;
  qu.Front = 0;
  cout<<"===============�{���y�z=======================\n";
  cout<<"= �{���W�١Gch4-3.2.cpp                      =\n";
  cout<<"= �{���ت��G���Φ�C�i��Enqueue�H��Dequeue   =\n"; 
  cout<<"==============================================\n";

  while(1)
  {
   obj.get_input();
   op=obj.number;
    switch(op)
    {
      case 1: cout<<"�п�J�A�n�[�J�����:";
              cin>>item;
              obj.Enqueue(item);
              break;
      case 2: item = obj.Dequeue( );
              if(item != -1)
               cout<<item<<"�O�q���Φ�C�R�������\n";
              break;
      case 3: obj.PrintQueue( );
              break;
    }
  }
  system("pause");     //�ϵ{���Ȱ��b����e�����ڭ̬ݨ쵲�G
  return 0;
}

void fun::get_input()
{
    cout<<"=======================================\n";
    cout<<"=   1.enqueue(�[�J)                   =\n";
    cout<<"=   2.dequeue(�R��)                   =\n";
    cout<<"=   3.��ܥثe���Φ�C�����e          =\n";
    cout<<"=   4.����                            =\n";    
    cout<<"=======================================\n";
    cout<<"�п�J�A���ާ@�G";
    cin>>number;    
}

void fun:: Enqueue(int item)  //�[�Jitem�����Φ�C�����Ƶ{��
{
  qu.Rear = (qu.Rear+1)%NUM;
  if((qu.Rear)%NUM == qu.Front) {
    cout<<"��C�O����!\n";
    system("pause");
    exit(1);
  } else
    qu.CQueue[qu.Rear] = item;
}
int fun:: Dequeue(void)  //�q���Φ�C���R��item
{
  if(qu.Front == qu.Rear) {
    cout<<"��C�O�Ū�!\n";
    system("pause");
    exit(1);
  } else {
    qu.Front = (qu.Front+1)%NUM;
    return qu.CQueue[qu.Front];
  }  
}
void fun:: PrintQueue(void)   //��ܥثe���Φ�C�����e���Ƶ{��
{
  int i;
  cout<<"�ثe���Φ�C�����e�G";
  for(i=qu.Rear;i!=qu.Front;i=(i+NUM-1)%NUM)
    cout<<"  "<<qu.CQueue[i];
  cout<<"\n";  
}
