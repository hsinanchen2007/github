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
  void PrintSelSort();   //宣告排序後的結果之副程式
};

int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();        //呼叫產生10個亂數值的副程式
    cout<<"\n"; 
    obj.SelSort();          //呼叫選擇排序法的副程式
    obj.PrintSelSort();     //呼叫選擇排序後的結果之副程式
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
   int i, j, Temp, NP = 0;
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
    }
 }
 
void fun::PrintSelSort()  //選擇排序法之副程式 
 {
    int i;
    cout<<"排序10個亂數值：";  
    for (i = 1; i <= n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

