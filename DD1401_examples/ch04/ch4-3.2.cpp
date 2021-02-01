#include <cstdlib>
#include <iostream>
#define NUM 5           //定義環形佇列大小
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
  cout<<"===============程式描述=======================\n";
  cout<<"= 程式名稱：ch4-3.2.cpp                      =\n";
  cout<<"= 程式目的：環形佇列進行Enqueue以及Dequeue   =\n"; 
  cout<<"==============================================\n";

  while(1)
  {
   obj.get_input();
   op=obj.number;
    switch(op)
    {
      case 1: cout<<"請輸入你要加入的資料:";
              cin>>item;
              obj.Enqueue(item);
              break;
      case 2: item = obj.Dequeue( );
              if(item != -1)
               cout<<item<<"是從環形佇列刪除的資料\n";
              break;
      case 3: obj.PrintQueue( );
              break;
    }
  }
  system("pause");     //使程式暫停在執行畫面讓我們看到結果
  return 0;
}

void fun::get_input()
{
    cout<<"=======================================\n";
    cout<<"=   1.enqueue(加入)                   =\n";
    cout<<"=   2.dequeue(刪除)                   =\n";
    cout<<"=   3.顯示目前環形佇列的內容          =\n";
    cout<<"=   4.結束                            =\n";    
    cout<<"=======================================\n";
    cout<<"請輸入你的操作：";
    cin>>number;    
}

void fun:: Enqueue(int item)  //加入item到環形佇列中的副程式
{
  qu.Rear = (qu.Rear+1)%NUM;
  if((qu.Rear)%NUM == qu.Front) {
    cout<<"佇列是滿的!\n";
    system("pause");
    exit(1);
  } else
    qu.CQueue[qu.Rear] = item;
}
int fun:: Dequeue(void)  //從環形佇列中刪除item
{
  if(qu.Front == qu.Rear) {
    cout<<"佇列是空的!\n";
    system("pause");
    exit(1);
  } else {
    qu.Front = (qu.Front+1)%NUM;
    return qu.CQueue[qu.Front];
  }  
}
void fun:: PrintQueue(void)   //顯示目前環形佇列的內容之副程式
{
  int i;
  cout<<"目前環形佇列的內容：";
  for(i=qu.Rear;i!=qu.Front;i=(i+NUM-1)%NUM)
    cout<<"  "<<qu.CQueue[i];
  cout<<"\n";  
}
