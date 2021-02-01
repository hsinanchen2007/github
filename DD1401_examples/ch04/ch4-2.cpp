#include <cstdlib>
#include <iostream>
#define NUM 10          //定義佇列大小
using namespace std;
class fun
{
  public:
  int number;
  void get_input();
  void Enqueue(int);      //宣告Enqueue副程式
  int Dequeue(void);      //宣告Dequeue副程式
  void PrintQueue(void);  //宣告列印目前佇列的內容之副程式 
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
  cout<<"==========程式描述============================\n";
  cout<<"= 程式名稱：ch4-2.cpp                        =\n";
  cout<<"= 程式目的：使用佇列進行Enqueue以及Dequeue   =\n"; 
  cout<<"==============================================\n";
  while(1)
  {
   obj.get_input();
   op=obj.number;

    switch(op)
    {
      case 1: cout<<"請輸入你要加入的資料:";
              cin>>item;
              obj.Enqueue(item);      //呼叫Enqueue副程式 
              break;
      case 2: item = obj.Dequeue( );  //呼叫Dequeue副程式
              if(item != -1)
                cout<<item<<"是從佇列刪除的資料\n";
              break;
      case 3: obj.PrintQueue( );      //呼叫PrintQueue副程式
              break;
    }
  }
  system("pause");     //使程式暫停在執行畫面讓我們看到結果
  return 0;
}

void fun::get_input()
{
    cout<<"========================================\n";
    cout<<"=   1.Enqueue(加入)                    =\n";
    cout<<"=   2.Dequeue(刪除)                    =\n";
    cout<<"=   3.顯示目前佇列的內容               =\n";
    cout<<"=   4.結束                             =\n";    
    cout<<"========================================\n";
    cout<<"請輸入你的操作：";
    cin>>number;    
}

void fun:: Enqueue(int item)    //Enqueue副程式 
{
  if(qu.Rear == NUM -1) {
    cout<<"佇列是滿的!\n";
    return;
  } else
    qu.Q[++qu.Rear] = item;
}
int fun:: Dequeue(void)        //Dequeue副程式
{
  if(qu.Front == qu.Rear) {
    cout<<"佇列是空的!\n";
    return -1;
  } else
    return qu.Q[++qu.Front];
}
void fun:: PrintQueue(void)     //列印目前佇列的內容之副程式
{
  int i;
  cout<<"目前佇列的內容：";
  for(i=qu.Rear;i>=qu.Front+1;i--)
    cout<<"  "<<qu.Q[i];
  cout<<"\n";  
}
