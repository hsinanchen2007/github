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
  void PrintInSort();   //�ŧi�Ƨǫ᪺���G���Ƶ{��
};

int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();       //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n";
    obj.InSort();          //�I�s���J�ƧǪk���Ƶ{��
    obj.PrintInSort();     //�I�s���J�Ƨǫ᪺���G���Ƶ{��
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

void fun::InSort()  //���J�ƧǪk���Ƶ{��
 {
   int i, j, Temp;
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
    }
 }
 
void fun::PrintInSort()  //���J�ƧǪk���Ƶ{�� 
 {
    int i;
    cout<<"�Ƨ�10�ӶüƭȡG";    
    for (i = 1; i <=n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

