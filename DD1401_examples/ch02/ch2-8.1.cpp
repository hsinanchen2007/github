#include <cstdlib>
#include <iostream>
#include <iomanip>
#define N 5
#define M 5
using namespace std;
    int Array_Data1[M][N] = 
    { 
      {1, 2, 3,  4,   5},
      {0, 6, 7,  8,   9},
      {0, 0, 10, 11, 12},
      {0, 0, 0,  13, 14},
      {0, 0, 0,  0,  15}};
    int Array_Data2[N*(1+N)/2] = {0};  //�����Ӽ�(�D0����)
    int i, j, Location = 0; 

int main(int argc, char *argv[])
{
  cout<<"�W�T���x�}����l��ơG\n"; 
  for(i = 0; i < M; i++) 
  { 
    for(j = 0; j < N; j++)
     {       
       cout<<setw(4)<<Array_Data1[i][j]; 
     }       
     cout<<"\n"; 
   }   
   cout<<"\n�H�C���D�G";
   for(i = 0; i < M; i++) 
   {    
     for(j = 0; j < N; j++)
      {      
        if(Array_Data1[i][j] != 0)   //�D0����
         Array_Data2[Location++] = Array_Data1[i][j]; 
      } 
    }   
   for(i = 0; i < N*(1+N)/2; i++)   
      cout<<Array_Data2[i]<<" ";  
   cout<<"\n";    
   system("PAUSE");
   return(0);        
}
