#include <cstdlib>
#include <iostream>
#include <iomanip>
#define N 3
#define M 5
using namespace std;
  int Array_Data1[N][M] = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11,12,13,14,15}};
  int Array_Data2[N*M] = {0}; 
  int row, column, i;

int main(int argc, char *argv[])
{
  cout<<"二維資料之原始資料：\n"; 
  for(row = 0; row < N; row++)
   {
     for(column = 0; column < M; column++)
         cout<<setw(4)<<Array_Data1[row][column]; 
     cout<<"\n"; 
   }
   cout<<"\n以列為主：\n";
   for(row = 0; row < N; row++)
    { 
      for(column = 0; column < M; column++)
       {   
          i = column + row * M; 
          Array_Data2[i] = Array_Data1[row][column];
       }  
    } 
    for(i = 0; i < N*M; i++)    
     cout<<Array_Data2[i]<<" ";  
   cout<<"\n";    
   system("PAUSE");
   return(0);        
}
