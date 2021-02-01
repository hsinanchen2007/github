#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //宣告產生10個亂數值的副程式
  void BubSort();        //宣告氣泡排序法的副程式
};

int main(int argc, char *argv[])
{ //主程式
  cout<<"===============程式描述================\n";
  cout<<"= 程式名稱：ch8-2a.cpp                =\n";
  cout<<"= 程式目的：追蹤「氣泡排序法」的過程  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================輸入==================\n";
  fun obj; 
  obj.RandomNum();          //呼叫產生10個亂數值的副程式
  cout<<"\n"; 
  cout<<"=================輸出================================\n";  
  obj.BubSort();            //呼叫氣泡排序法的副程式
  cout<<"\n"; 
  system("PAUSE");
  return(0);
}

void fun::RandomNum()  //產生10個亂數值之副程式
{
  int i;
  srand((unsigned)time(NULL)); //亂數值初始化
  cout<<"產生10個亂數值：";
  for (i = 0; i <= n-1; i++)
    {
       A[i] = rand() % 90+10;  //產生10~100的整數亂數值
       cout<<A[i]<<"  ";
    }
}

void fun::BubSort()  //氣泡排序法之副程式
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
        printf("第 %d 次排序：", t); 
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
