#include <cstdlib>
#include <iostream>
#define MaxNum 10      //定義堆疊大小
int Stack[MaxNum];    //以陣列Stack當作堆疊
int Top = -1;        //Top紀錄目前堆疊頂端的索引值，初始值設為-1表示堆疊為空

using namespace std;
class fun
{
  public:
  void Push(int);         //宣告Push副程式
  int Pop(void);          //宣告Pop副程式
  int Transfer(char*);    //宣告後序運算式之副程式 
};

int main(int argc, char *argv[])
{
  fun obj;
  char itemset[20];
  cout<<"===============程式描述================\n";
  cout<<"= 程式名稱：ch3-3.6.cpp               =\n";
  cout<<"= 程式目的：後序運算                  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================輸入==================\n"; 

  while(1) {
    cout<<"請輸入一個後序式:";
    gets(itemset);
    cout<<itemset<<"="<<obj.Transfer(itemset);
    cout<<"\n";
  }
  system("pause");     //使程式暫停在執行畫面讓我們看到結果
  return 0;
}

int fun:: Transfer(char itemset[])  //後序運算式之副程式
{
  cout<<"=================輸出==================\n";    
  cout<<"運算結果：";   

    fun obj;
  char *pt=itemset;
  while(*pt) {
    if(*pt >= '0' && *pt <= '9')
      Push(*pt-'0');
    else {
      switch(*pt) {
        case '+': obj.Push(Pop( ) + obj.Pop( ));
                  break; 
        case '-': obj.Push(Pop( ) - obj.Pop( ));
                  break;
        case '*': obj.Push(Pop( ) * obj.Pop( ));
                  break;
        case '/': obj.Push(Pop( ) / obj.Pop( ));
                  break;
        default: return -1;
      }
    }
    pt++;  
  }  
  return obj.Pop( );
}

void fun:: Push(int n)    //Push副程式
{
  if(Top == MaxNum -1) {
    cout<<"堆疊已滿！";
    return;
  }
  Stack[++Top] = n;
}

int fun:: Pop(void)       //Pop副程式 
{
  if(Top == -1) {
    cout<<"堆疊是空！";
   }
  return Stack[Top--];
}
