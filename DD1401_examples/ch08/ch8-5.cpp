#include <cstdlib>
#include <iostream>
#define n 10
int A[n]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //�ŧi����10�ӶüƭȪ��Ƶ{��
    void QuickSort(int A[], int start, int Max);       //�ŧi�ֳt�ƧǪk���Ƶ{��
    void PrintQuickSort();          //�ŧi�ֳt�Ƨǫ᪺���G���Ƶ{��
};
int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();           //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n"; 
    obj.QuickSort(A,0, n);    //�I�s�ֳt�ƧǪk���Ƶ{��
    obj.PrintQuickSort();     //�I�s�ֳt�Ƨǫ᪺���G���Ƶ{��
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

void fun::QuickSort(int A[], int left, int right) 
{ 
    int i, j, s , Temp;

    if(left < right) { 
        s = A[(left+right)/2]; 
        i = left - 1; 
        j = right + 1; 

        while(1) { 
            while(A[++i] < s) ;  // �V�k�� 
            while(A[--j] > s) ;  // �V���� 
            if(i >= j) 
                break; 
               Temp = A[i];
               A[i] = A[j];
               A[j] = Temp;
        } 
        QuickSort(A, left, i-1);   // �索��i�滼�j 
        QuickSort(A, j+1, right);  // ��k��i�滼�j 
    } 
} 

void fun:: PrintQuickSort()  //�ֳt�ƧǪk���Ƶ{�� 
 {
    int i;
    cout<<"�Ƨ�10�ӶüƭȡG";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

