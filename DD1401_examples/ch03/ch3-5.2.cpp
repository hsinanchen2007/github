#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int Fib(int N);    
};

int main(int argc, char *argv[])
{ //�D�{��
   int N = 6,Sum;
   fun obj;
   Sum = obj.Fib(N);                //�I�s�۩w�禡
   cout<<"Sum="<<Sum;  
   cout<<"\n";  
   system("PAUSE");
   return(0);
}
int fun::Fib(int N)  //�禡�W��
  {
   if (N <= 2)
     return 1;
   else
     return Fib(N-1) + Fib(N - 2); //�禡�ۤv�S�i�H�I�s�ۤv
}
