#include <cstdlib>
#include <iostream>
using namespace std;
int i, j,k;
 char Temp[]= "";
 int Stu_Sum[3][4];          //�ǥ��`���Z
 int Stu_Average[3][4];      //�ǥͥ������Z
 int Subject_Sum[3][5];      //����`���Z
 int Subjcet_Average[3][5];   //��إ������Z
 char Stu_Name[4] = { 'A','B','C','D'};
 int Score[3][4][5] ={ { { 65, 85, 78, 75, 69 }, { 66, 55, 52, 92, 47 }, { 75, 99, 63, 73, 86 }, { 77, 88, 99, 91, 99 } }, { { 77, 88, 66, 77, 66 }, { 65, 66, 88, 55, 77 }, { 70, 88, 56, 88, 88 }, { 80, 90, 95, 99, 99 } }, { {55, 67, 56,  98, 67 }, {66, 69, 76, 66, 78}, {77, 89, 88, 77, 77}, {88, 89, 99, 97, 88} } };
 int main(int argc, char *argv[])
{ 
   // ======= Ū����ƨíp��U���`��======
    for (k = 0; k <= 2; k++)            //3�����
       for (i = 0; i <= 3; i++)          //����C��
          for (j = 0; j <= 4; j++)       //������
          {  //�p��X�C�@��u�P�ǡv���`���Z�P�C�@�u��ءv���`���Z
                Stu_Sum[k][i] = Stu_Sum[k][i] + Score[k][i][j];           
                Subject_Sum[k][j] = Subject_Sum[k][j] + Score[k][i][j];   
           }
            //========= �L�X�}�Y========
     for (k = 0; k <= 2; k++)
       {
         cout<<"==========��"<<k+1<<"����Ҧ��Z�p�U�G==========";
         cout<<"\n"; 
         cout<<"�m�W�@���@ �^�� �@�ƾ� �@�p�� �@�{�]";
         cout<<"\n"; 
         cout<<"=======================================";
         cout<<"\n"; 
         // ======== �L�X���Z��=======
         for (i = 0; i <= 3; i++)       //����C��
           {
              cout<< Stu_Name[i];
              for (j = 0; j <= 4; j++)   //������
               {
                 cout<<"     "<<Score[k][i][j];
               }
                cout<<"\n"; 
                }
                cout<<"\n"; 
            }
     system("PAUSE");
     return(0);
}
