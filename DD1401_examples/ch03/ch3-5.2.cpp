#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int Fib(int N);    
};

int main(int argc, char *argv[])
{ //主程式
   int N = 6,Sum;
   fun obj;
   Sum = obj.Fib(N);                //呼叫自定函式
   cout<<"Sum="<<Sum;  
   cout<<"\n";  
   system("PAUSE");
   return(0);
}
int fun::Fib(int N)  //函式名稱
  {
   if (N <= 2)
     return 1;
   else
     return Fib(N-1) + Fib(N - 2); //函式自己又可以呼叫自己
}
