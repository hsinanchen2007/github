#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{  int i,j;
   int Sum[4];  
   int Score[4][5] = {{ 65, 85, 78, 75, 69 }, { 66, 55, 52, 92, 47 }, { 75, 99, 63, 73, 86 }, { 77, 88, 99, 91, 100 } };
   for (i = 0; i <=3; i++)                 //����C��
    Sum[i] = 0;   //���NSum�}�C�k0 
   for (i = 0; i <=3; i++)                 //����C��
   {     
     for (j = 0; j <=4; j++)               //������
      {
        Sum[i] = Sum[i] + Score[i][j];     //�p��X�C�@��P�Ǫ��`���Z
      }
   }
   for (i = 0; i <= 3; i++)   
   {        
    cout<<"��"<<i+1<<"��P�Ǫ��������Z="<<Sum[i]/5;  //�p��X�C�@��P�Ǫ��������Z
    cout<<"\n";
    }
   system("PAUSE");
   return(0);
}
