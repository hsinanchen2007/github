#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //�ŧi����10�ӶüƭȪ��Ƶ{��
  void SelSort();        //�ŧi��ܱƧǪk���Ƶ{��
};

int main(int argc, char *argv[])
{ //�D�{��
  cout<<"===============�{���y�z================\n";
  cout<<"= �{���W�١Gch8-3a.cpp                =\n";
  cout<<"= �{���ت��G�l�ܡu��ܱƧǪk�v���L�{  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================��J==================\n";
  fun obj; 
  obj.RandomNum();          //�I�s����10�ӶüƭȪ��Ƶ{��
  cout<<"\n"; 
  cout<<"=================��X================================\n"; 
  obj.SelSort();            //�I�s��ܱƧǪk���Ƶ{��
  cout<<"\n"; 
  system("PAUSE");
  return(0);
}

void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL)); //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG";
  for (i = 1; i <= n; i++)
    {
       A[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<A[i]<<"  ";
    }
}

void fun::SelSort()  //��ܱƧǪk���Ƶ{��
{
 int i, j, k,Temp, NP = 0;
       for (i = 1; i <= n - 1; i++)
        {
          NP = i;
          for (j = i + 1; j <= n; j++)
             if (A[j] > A[NP])
                NP = j;
            {//�۾F��Ӫ���ƥ洫��m
               Temp = A[i];
               A[i] = A[NP];
               A[NP] = Temp;
             }
        printf("�� %d ���ƧǡG", i); 
        for(k = 1; k <= n; k++) 
         {
           if(k == 1)
             if(i==1)
                printf("[%d]", A[k]); 
             else
                printf("[%d ", A[k]); 
           else if(k == i)
              printf("%d] ", A[k]); 
           else
              printf("%d  ", A[k]);    
         }         
        printf("\n");             
       }
}
