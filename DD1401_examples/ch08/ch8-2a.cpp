#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //�ŧi����10�ӶüƭȪ��Ƶ{��
  void BubSort();        //�ŧi��w�ƧǪk���Ƶ{��
};

int main(int argc, char *argv[])
{ //�D�{��
  cout<<"===============�{���y�z================\n";
  cout<<"= �{���W�١Gch8-2a.cpp                =\n";
  cout<<"= �{���ت��G�l�ܡu��w�ƧǪk�v���L�{  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================��J==================\n";
  fun obj; 
  obj.RandomNum();          //�I�s����10�ӶüƭȪ��Ƶ{��
  cout<<"\n"; 
  cout<<"=================��X================================\n";  
  obj.BubSort();            //�I�s��w�ƧǪk���Ƶ{��
  cout<<"\n"; 
  system("PAUSE");
  return(0);
}

void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL)); //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG";
  for (i = 0; i <= n-1; i++)
    {
       A[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<A[i]<<"  ";
    }
}

void fun::BubSort()  //��w�ƧǪk���Ƶ{��
  {
 int i, j , k,t, Temp;
    t = 0;
    for (i =n-1; i>=1; i--)
       {
       for (j =0; j <=i-1; j++)
          if (A[j] > A[j+1])
             {
               Temp = A[j];
               A[j] = A[j+1];
               A[j+1] = Temp;
             }
        t = t + 1;     
        printf("�� %d ���ƧǡG", t); 
        for(k = 0; k <= n-1; k++) 
         {
           if(k == (n - t - 1))
              printf("%d [", A[k]); 
           else if(k == n - 1)
              printf("%d]", A[k]); 
           else
              printf("%d  ", A[k]);    
         }
        cout<<"\n";             
       }
  }
