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
      //��ӯx�}�ۥ[ 
     cout<<"===��ӯx�}�ۥ[===";
     cout<<"\n";
     obj.matrix_Aprint(2,3);         //��XA�x�}
     obj.matrix_Bprint(2,3);         //��XB�x�}  
     obj.matrix_Add(2, 3);           //C=A+B
     obj.matrix_Cprint(2, 3);        //��Xc�x�} 
     system("PAUSE");
     return(0);
}

//��XA�x�}
void fun::matrix_Aprint(int m, int n)
{
     cout<<"��XA�x�}�G";
     cout<<"\n";                    
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<A[i][j];
       cout<<"\n";
     }  
       cout<<"\n";
}

//��XB�x�}
void fun::matrix_Bprint(int m, int n)
{
     cout<<"��XB�x�}�G";
     cout<<"\n";                     
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<B[i][j];
       cout<<"\n";
     }
       cout<<"\n";    
}

/*���]A,B,C����mxn�}�C�A�o�Ө�ƭn�D�XC=A+B*/
void fun::matrix_Add(int m, int n)
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];  
}

//��X�ۥ[���G
void fun::matrix_Cprint(int m, int n)
{
     cout<<"��XA+B=C�����G�G";
     cout<<"\n";           
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<C[i][j];
       cout<<"\n";
     }
}
