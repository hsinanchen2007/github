#include <cstdlib>
#include <iostream>
#define MaxNum 5     //定義堆疊大小
int Stack[MaxNum];   //以陣列Stack當作堆疊
int Top = -1;   //Top紀錄目前堆疊頂端的索引值，初始值設為-1表示堆疊為空

using namespace std;
class fun
{
  public:
  int number;
  void get_input();
  void Push(int);  //宣告Push副程式 
  int Pop(void);   //宣告Pop副程式 
  void PrintStack(void);  //宣告列印目前堆疊的內容之副程式   
};

int main(int argc, char *argv[])
{
  int op=0,item;
  fun obj;
  cout<<"===============程式描述=======================\n";
  cout<<"= 程式名稱：ch3-2.cpp                        =\n";
  cout<<"= 程式目的：使用堆疊進行push以及pop          =\n"; 
  cout<<"==============================================\n"; 

  while(1)
  {
   obj.get_input();
   op=obj.number;
   switch(op)
    {
      case 1: cout<<"請輸入你要push的資料：";
              cin>>item;
              obj.Push(item); //呼叫Push副程式 
              break;
      case 2: cout<<obj.Pop( )<<"是從堆疊彈出的資料\n"; //呼叫Pop副程式 
              break;
      case 3: obj.PrintStack( );  //顯示目前Stack的內容 
              break;
    }
  }
  system("pause");     //使程式暫停在執行畫面讓我們看到結果
  return 0;
}

void fun::get_input()
{
    cout<<"=================================================\n";
    cout<<"=   1.push(加入)                                =\n";
    cout<<"=   2.pop(取出)                                 =\n";
    cout<<"=   3.顯示目前Stack的內容(從由上而下Top-Down)   =\n";
    cout<<"=   4.結束                                      =\n";    
    cout<<"=================================================\n";
    cout<<"請輸入你的操作：";
    cin>>number;    
}

void fun:: Push(int item)  //Push副程式 
{
  if(Top == MaxNum -1)
    cout<<"堆疊是滿的!";
  else
    Stack[++Top] = item;
}

int fun:: Pop(void)         //Pop副程式 
{
  if(Top == -1) 
    cout<<"堆疊是空的!";
  else
    return Stack[Top--];
}
void fun:: PrintStack(void)  //列印目前堆疊的內容
{
  int i;
  if(Top == -1) {
    cout<<"堆疊是空的!\n";
  } else {
    cout<<"目前堆疊的內容為: ";
    for(i=Top;i>=0;i--)
      cout<<"  "<<Stack[i];
    cout<<"\n";
  }
}
