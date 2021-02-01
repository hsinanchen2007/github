#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //宣告產生10個亂數值的副程式
  void SelSort();        //宣告選擇排序法的副程式
};

int main(int argc, char *argv[])
{ //主程式
  cout<<"===============程式描述================\n";
  cout<<"= 程式名稱：ch8-3a.cpp                =\n";
  cout<<"= 程式目的：追蹤「選擇排序法」的過程  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================輸入==================\n";
  fun obj; 
  obj.RandomNum();          //呼叫產生10個亂數值的副程式
  cout<<"\n"; 
  cout<<"=================輸出================================\n"; 
  obj.SelSort();            //呼叫選擇排序法的副程式
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

void fun::SelSort()  //選擇排序法之副程式
{
 int i, j, k,Temp, NP = 0;
       for (i = 1; i <= n - 1; i++)
        {
          NP = i;
          for (j = i + 1; j <= n; j++)
             if (A[j] > A[NP])
                NP = j;
            {//相鄰兩個的資料交換位置
               Temp = A[i];
               A[i] = A[NP];
               A[NP] = Temp;
             }
        printf("第 %d 次排序：", i); 
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
