#include <cstdlib>
#include <iostream>
using namespace std;
     int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
     int B[3][3] = {{1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
     int C[2][3];
class fun
{
  public:
    void matrix_Aprint(int m, int n);
    void matrix_Bprint(int m, int n);
    void matrix_Mul(int m, int n, int p);
    void matrix_Cprint(int m, int n);
};

int main(int argc, char *argv[])
{
     fun obj; 
     //兩個矩陣相乘 
     cout<<"===兩個矩陣相乘===";
     cout<<"\n";
     obj.matrix_Aprint(2,3);         //輸出A矩陣
     obj.matrix_Bprint(3,3);         //輸出B矩陣  
     obj.matrix_Mul(2, 3, 3);        //C=A*B
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
         cout<<"   "<<A[i][j];
       cout<<"\n";
     }  
       cout<<"\n";
}

//輸出B矩陣
void fun::matrix_Bprint(int m, int n)
{
     printf("輸出B矩陣：");
     printf("\n");                     
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
        cout<<"   "<<B[i][j];
       cout<<"\n";
     }
       cout<<"\n";    
}

/*假設A,B,C均為mxn陣列，這個函數要求出C=A*B*/
void fun::matrix_Mul(int m, int n, int p)
{
  int i, j, k;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      {
        C[i][j]=0;
        for(k=0;k<n;k++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j]; 
      }
}

//輸出相乘結果
void fun::matrix_Cprint(int m, int n)
{
     printf("輸出A*B=C的結果：");
     printf("\n");             
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<C[i][j];
       cout<<"\n";
     }
}
