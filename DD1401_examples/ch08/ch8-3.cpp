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
  void PrintSelSort();   //�ŧi�Ƨǫ᪺���G���Ƶ{��
};

int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();        //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n"; 
    obj.SelSort();          //�I�s��ܱƧǪk���Ƶ{��
    obj.PrintSelSort();     //�I�s��ܱƧǫ᪺���G���Ƶ{��
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
   int i, j, Temp, NP = 0;
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
    }
 }
 
void fun::PrintSelSort()  //��ܱƧǪk���Ƶ{�� 
 {
    int i;
    cout<<"�Ƨ�10�ӶüƭȡG";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

