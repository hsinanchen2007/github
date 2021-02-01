#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int GCD(int a,int b);    
};

int main(int argc, char *argv[])
{ //主程式
   int a=18,b=15;
   fun obj;
   cout<<"最大公因數為="<<obj.GCD(a, b);  
   cout<<"\n";
   system("PAUSE");
   return(0);
}

int fun::GCD(int a,int b)  //函式名稱
  {
    int c;
    c = a % b;
    if (c == 0)
        return b;
    else
        return GCD(b, c);  //函式自己又可以呼叫自己
  }

