#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //�ŧi����10�ӶüƭȪ��Ƶ{��
  void InSort();        //�ŧi���J�ƧǪk���Ƶ{��
};

int main(int argc, char *argv[])
{ //�D�{��
  cout<<"===============�{���y�z================\n";
  cout<<"= �{���W�١Gch8-4a.cpp                =\n";
  cout<<"= �{���ت��G�l�ܡu���J�ƧǪk�v���L�{  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================��J==================\n";
  fun obj; 
  obj.RandomNum();         //�I�s����10�ӶüƭȪ��Ƶ{��
  printf("\n"); 
  cout<<"=================��X================================\n";  
  obj.InSort();            //�I�s���J�ƧǪk���Ƶ{��
  printf("\n"); 
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

void fun::InSort()  //���J�ƧǪk���Ƶ{��
  {
     int i, j, k, Temp;
     for (i = 1; i <= n; i++)
      {
        Temp=A[i];
        j=i-1;
        while (Temp<A[j])
         {
           A[j+1]=A[j];
           j--;
           if(j==-1)
             break;
         }
        A[j+1]=Temp;            
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
      cout<<"\n"; 
     }
  }
