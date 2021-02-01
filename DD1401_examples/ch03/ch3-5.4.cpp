#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int number;
  void get_input();
  void Towers(int n, char from, char through, char to);
};

int main(int argc, char *argv[])
{  
   fun obj; 
   int value;
   obj.get_input();
   value=obj.number;
   obj.Towers (value,'A','B','C');
   printf("\n");  
   system("PAUSE");
   return(0);
}

void fun::get_input()
{
   cout<<"請輸入盤子個數n：";  
   cin>>number;    
}

void fun::Towers(int n, char from, char through, char to)
{
  if (n > 0){
    Towers (n - 1, from, to, through);
    cout<<"將盤子"<<n<<"從柱子"<<from<<"移到柱子"<<to<<"\n";
    Towers (n - 1, through, from, to);
  }
}
