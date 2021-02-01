#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
     int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
     int B[2][3] = {{11, 12, 13}, {14, 15, 16}};
     int C[2][3];
class fun
{
  public:
    void matrix_Aprint(int m, int n);
    void matrix_Bprint(int m, int n);
    void matrix_Add(int m, int n);
    void matrix_Cprint(int m, int n);
};

int main(int argc, char *argv[])
{
     fun obj; 
      //兩個矩陣相加 
     cout<<"===兩個矩陣相加===";
     cout<<"\n";
     obj.matrix_Aprint(2,3);         //輸出A矩陣
     obj.matrix_Bprint(2,3);         //輸出B矩陣  
     obj.matrix_Add(2, 3);           //C=A+B
     obj.matrix_Cprint(2, 3);        //輸出c矩陣 
     system("PAUSE");
     return(0);
}

//輸出A矩陣
void fun::matrix_Aprint(int m, int n)
{
     cout<<"輸出A矩陣：";
     cout<<"\n";                    
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<A[i][j];
       cout<<"\n";
     }  
       cout<<"\n";
}

//輸出B矩陣
void fun::matrix_Bprint(int m, int n)
{
     cout<<"輸出B矩陣：";
     cout<<"\n";                     
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<B[i][j];
       cout<<"\n";
     }
       cout<<"\n";    
}

/*假設A,B,C均為mxn陣列，這個函數要求出C=A+B*/
void fun::matrix_Add(int m, int n)
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];  
}

//輸出相加結果
void fun::matrix_Cprint(int m, int n)
{
     cout<<"輸出A+B=C的結果：";
     cout<<"\n";           
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<C[i][j];
       cout<<"\n";
     }
}
