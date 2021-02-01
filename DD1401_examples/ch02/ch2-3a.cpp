#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{  int i,j;
   int Sum[4];  
   int Score[4][5] = {{ 65, 85, 78, 75, 69 }, { 66, 55, 52, 92, 47 }, { 75, 99, 63, 73, 86 }, { 77, 88, 99, 91, 100 } };
   for (i = 0; i <=3; i++)                 //北计
    Sum[i] = 0;   //盢Sum皚耴0 
   for (i = 0; i <=3; i++)                 //北计
   {     
     for (j = 0; j <=4; j++)               //北︽计
      {
        Sum[i] = Sum[i] + Score[i][j];     //璸衡–厩羆Θ罿
      }
   }
   for (i = 0; i <= 3; i++)   
   {        
    cout<<"材"<<i+1<<"厩キАΘ罿="<<Sum[i]/5;  //璸衡–厩キАΘ罿
    cout<<"\n";
    }
   system("PAUSE");
   return(0);
}
