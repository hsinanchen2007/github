#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int fact(int N);    
};

int main(int argc, char *argv[])
{ //主程式
   int Sum, Max = 10;
   fun obj;
   Sum = obj.fact(Max);         //呼叫自定函式
   cout<<"1*2*...*10=\n"<<Sum;  
   system("PAUSE");
   return(0);
}

int fun::fact(int n)     //遞迴函式名稱
 {
   if (n ==1)
     return 1;
   else
     return n * fact(n - 1); //函式自己又可以呼叫自己
 }
    
    
