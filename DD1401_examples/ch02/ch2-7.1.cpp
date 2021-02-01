#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
     int A[4][4] ={ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
     int B[4][4];
class fun
{
  public:
    void matrix_pretrans(int m, int n);
    void matrix_transpose(int m, int n);
    void matrix_posttrans(int m, int n);
};

int main(int argc, char *argv[])
{
     fun obj; 
     obj.matrix_pretrans(4, 4);       //轉換前 
     obj.matrix_transpose(4, 4);      //轉換副程式 
     obj.matrix_posttrans(4, 4);      //轉換後 
     system("PAUSE");
     return(0);
}

//轉換前 
void fun::matrix_pretrans(int m, int n)
{              
     cout<<"轉換前：";
     cout<<"\n";             
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<A[i][j];
       cout<<"\n";
     }
}

//轉換副程式(A矩陣的m×n轉成B矩陣的n×m
void fun::matrix_transpose(int m, int n)
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      B[j][i] = A[i][j]; 
}

//轉換後 
void fun::matrix_posttrans(int m, int n)
{
     cout<<"轉換後：";
     cout<<"\n";                   
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<B[i][j];
       cout<<"\n";
     }
}
