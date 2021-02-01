#include <cstdlib>
#include <iostream>
using namespace std;
     int Sparse[4][3] = {{5, 0, 0}, {0, 0, -1}, {3, 0, 0}, {0, 9, 10}};
     int Compress[6][3];
class fun
{
  public:
    void Sparse_print(int m, int n);
    void Compress_process(int m, int n);
    void Compress_print(int m, int n);
};

int main(int argc, char *argv[])
{
     fun obj;    
     //��ӯx�}�ۥ[ 
     cout<<"===�}���x�}�����Y����ܪk===";
     cout<<"\n";
     obj.Sparse_print(4,3);                      //��X�}���x�}
     obj.Compress_process(4, 3);                //���Y�B�z 
     obj.Compress_print(6, 3);                  //��X���Y���G 
     system("PAUSE");
     return(0);
}

//��X�}���x�}
void fun::Sparse_print(int m, int n)
{
     cout<<"��X�}���x�}�G";
     cout<<"\n";                    
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<Sparse[i][j];
       cout<<"\n";
     }
}

//���Y�B�z 
void fun::Compress_process(int m, int n)
{
   int i,j,k;
   k = 1;                              // �]�w�ܼƪ��     
   Compress[0][0] = m;                 // �}�Csparse��m�C  
   Compress[0][1] = n;                 // �}�Csparse��n�� 
   Compress[0][2] = 5;                 // �}�C�ϥ�5�Ӥ���  
   for ( i = 0; i < m; i++ )           // �G���}�C�����X   
      for ( j = 0; j < n; j++ )
         if ( Sparse[i][j] != 0 )      // �P�_�O�_���D0����   
         {
            Compress[k][0] = i;    // �x�s�C��         
            Compress[k][1] = j;    // �x�s���         
            //�x�s������
            Compress[k][2] = Sparse[i][j];
            k++;                   // �U�@�C           
         }
}

//��X���Y���G
void fun::Compress_print(int m, int n)
{
     cout<<"��X���Y���G�G";
     cout<<"\n";            
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<Compress[i][j];
       cout<<"\n";
     }
}
