#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int GCD(int a,int b);    
};

int main(int argc, char *argv[])
{ //�D�{��
   int a=18,b=15;
   fun obj;
   cout<<"�̤j���]�Ƭ�="<<obj.GCD(a, b);  
   cout<<"\n";
   system("PAUSE");
   return(0);
}

int fun::GCD(int a,int b)  //�禡�W��
  {
    int c;
    c = a % b;
    if (c == 0)
        return b;
    else
        return GCD(b, c);  //�禡�ۤv�S�i�H�I�s�ۤv
  }

