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
     //��ӯx�}�ۭ� 
     cout<<"===��ӯx�}�ۭ�===";
     cout<<"\n";
     obj.matrix_Aprint(2,3);         //��XA�x�}
     obj.matrix_Bprint(3,3);         //��XB�x�}  
     obj.matrix_Mul(2, 3, 3);        //C=A*B
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
         cout<<"   "<<A[i][j];
       cout<<"\n";
     }  
       cout<<"\n";
}

//��XB�x�}
void fun::matrix_Bprint(int m, int n)
{
     printf("��XB�x�}�G");
     printf("\n");                     
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
        cout<<"   "<<B[i][j];
       cout<<"\n";
     }
       cout<<"\n";    
}

/*���]A,B,C����mxn�}�C�A�o�Ө�ƭn�D�XC=A*B*/
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

//��X�ۭ����G
void fun::matrix_Cprint(int m, int n)
{
     printf("��XA*B=C�����G�G");
     printf("\n");             
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<C[i][j];
       cout<<"\n";
     }
}
