#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{  int i,j;
   int Sum[5];  
   int Score[4][5] = {{ 65, 85, 78, 75, 69 }, { 66, 55, 52, 92, 47 }, { 75, 99, 63, 73, 86 }, { 77, 88, 99, 91, 100 } };
   for (j = 0; j <=4; j++)                //������
    Sum[j] = 0;                           //���NSum�}�C�k0 
   for (j = 0; j <=4; j++)                //������
   {     
     for (i = 0; i <=3; i++)              //����C��
      {
        Sum[j] = Sum[j] + Score[i][j];    //�p��X�C�@��ت��`����
      }
   }
   for (j = 0; j <= 4; j++)      
   {  //�p��X�C�@��ت���������
    cout<<"��"<< j+1 << "��ت���������="<<Sum[j]/4;   
    cout<<"\n"; 
   }
   system("PAUSE");
   return(0);
}
