#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{  int i,j;
   int Sum[5];  
   int Score[4][5] = {{ 65, 85, 78, 75, 69 }, { 66, 55, 52, 92, 47 }, { 75, 99, 63, 73, 86 }, { 77, 88, 99, 91, 100 } };
   for (j = 0; j <=4; j++)                //北︽计
    Sum[j] = 0;                           //盢Sum皚耴0 
   for (j = 0; j <=4; j++)                //北︽计
   {     
     for (i = 0; i <=3; i++)              //北计
      {
        Sum[j] = Sum[j] + Score[i][j];    //璸衡–ヘ羆だ计
      }
   }
   for (j = 0; j <= 4; j++)      
   {  //璸衡–ヘキАだ计
    cout<<"材"<< j+1 << "ヘキАだ计="<<Sum[j]/4;   
    cout<<"\n"; 
   }
   system("PAUSE");
   return(0);
}
