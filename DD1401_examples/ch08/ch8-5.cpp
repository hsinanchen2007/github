#include <cstdlib>
#include <iostream>
#define n 10
int A[n]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //宣告產生10個亂數值的副程式
    void QuickSort(int A[], int start, int Max);       //宣告快速排序法的副程式
    void PrintQuickSort();          //宣告快速排序後的結果之副程式
};
int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();           //呼叫產生10個亂數值的副程式
    cout<<"\n"; 
    obj.QuickSort(A,0, n);    //呼叫快速排序法的副程式
    obj.PrintQuickSort();     //呼叫快速排序後的結果之副程式
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}

void fun::RandomNum()  //產生10個亂數值之副程式
{
  int i;
  srand((unsigned)time(NULL)); //亂數值初始化
  cout<<"產生10個亂數值：";
  for (i = 1; i <= n; i++)
    {
       A[i] = rand() % 90+10;  //產生10~100的整數亂數值
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
            while(A[++i] < s) ;  // 向右找 
            while(A[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
               Temp = A[i];
               A[i] = A[j];
               A[j] = Temp;
        } 
        QuickSort(A, left, i-1);   // 對左邊進行遞迴 
        QuickSort(A, j+1, right);  // 對右邊進行遞迴 
    } 
} 

void fun:: PrintQuickSort()  //快速排序法之副程式 
 {
    int i;
    cout<<"排序10個亂數值：";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

