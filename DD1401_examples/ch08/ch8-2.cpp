#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();       //宣告產生10個亂數值的副程式
  void BubSort();        //宣告氣泡排序法的副程式
  void PrintBubSort();   //宣告排序後的結果之副程式
};

int main(int argc, char *argv[])
{ //主程式
    fun obj; 
    obj.RandomNum();        //呼叫產生10個亂數值的副程式
    cout<<"\n"; 
    obj.BubSort();          //呼叫氣泡排序法的副程式
    obj.PrintBubSort();     //呼叫排序後的結果之副程式
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}

void fun::RandomNum()  //氣泡排序法之副程式
{
  int i;
  srand((unsigned)time(NULL));
  cout<<"產生10個亂數值：";
  for (i = 1; i <= n; i++)
    {
       A[i] = rand() % 90+10;  //產生10~100的整數亂數值
       cout<<A[i]<<" ";
    }
}


void fun::BubSort()  //氣泡排序法之副程式
  {
    int i, j , k,t=1, Temp;
    for (i=n-1; i>0; i--)
       {
       for (j =0; j <=i; j++)
          if (A[j] > A[j+1])
             {  //兩數交換位置
               Temp = A[j];
               A[j] = A[j+1];
               A[j+1] = Temp;
             }        
       }
  }
  
void fun::PrintBubSort()  //氣泡排序法之副程式 
 {
    int i;
    cout<<"排序10個亂數值：";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<" ";
    }   
}
