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
     obj.matrix_pretrans(4, 4);       //�ഫ�e 
     obj.matrix_transpose(4, 4);      //�ഫ�Ƶ{�� 
     obj.matrix_posttrans(4, 4);      //�ഫ�� 
     system("PAUSE");
     return(0);
}

//�ഫ�e 
void fun::matrix_pretrans(int m, int n)
{              
     cout<<"�ഫ�e�G";
     cout<<"\n";             
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<A[i][j];
       cout<<"\n";
     }
}

//�ഫ�Ƶ{��(A�x�}��m��n�নB�x�}��n��m
void fun::matrix_transpose(int m, int n)
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      B[j][i] = A[i][j]; 
}

//�ഫ�� 
void fun::matrix_posttrans(int m, int n)
{
     cout<<"�ഫ��G";
     cout<<"\n";                   
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<setw(4)<<B[i][j];
       cout<<"\n";
     }
}
