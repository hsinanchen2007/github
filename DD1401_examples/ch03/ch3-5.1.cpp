#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int fact(int N);    
};

int main(int argc, char *argv[])
{ //�D�{��
   int Sum, Max = 10;
   fun obj;
   Sum = obj.fact(Max);         //�I�s�۩w�禡
   cout<<"1*2*...*10=\n"<<Sum;  
   system("PAUSE");
   return(0);
}

int fun::fact(int n)     //���j�禡�W��
 {
   if (n ==1)
     return 1;
   else
     return n * fact(n - 1); //�禡�ۤv�S�i�H�I�s�ۤv
 }
    
    
