#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();       //�ŧi����10�ӶüƭȪ��Ƶ{��
  void BubSort();        //�ŧi��w�ƧǪk���Ƶ{��
  void PrintBubSort();   //�ŧi�Ƨǫ᪺���G���Ƶ{��
};

int main(int argc, char *argv[])
{ //�D�{��
    fun obj; 
    obj.RandomNum();        //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n"; 
    obj.BubSort();          //�I�s��w�ƧǪk���Ƶ{��
    obj.PrintBubSort();     //�I�s�Ƨǫ᪺���G���Ƶ{��
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}

void fun::RandomNum()  //��w�ƧǪk���Ƶ{��
{
  int i;
  srand((unsigned)time(NULL));
  cout<<"����10�ӶüƭȡG";
  for (i = 1; i <= n; i++)
    {
       A[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<A[i]<<" ";
    }
}


void fun::BubSort()  //��w�ƧǪk���Ƶ{��
  {
    int i, j , k,t=1, Temp;
    for (i=n-1; i>0; i--)
       {
       for (j =0; j <=i; j++)
          if (A[j] > A[j+1])
             {  //��ƥ洫��m
               Temp = A[j];
               A[j] = A[j+1];
               A[j+1] = Temp;
             }        
       }
  }
  
void fun::PrintBubSort()  //��w�ƧǪk���Ƶ{�� 
 {
    int i;
    cout<<"�Ƨ�10�ӶüƭȡG";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<" ";
    }   
}
