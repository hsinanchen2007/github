#include <cstdlib>
#include <iostream>
#define n 10
int A[10]={0};
using namespace std;
class fun
{
  public:
  void RandomNum();      //宣告產生10個亂數值的副程式
  void InSort();        //宣告插入排序法的副程式
  void PrintInSort();   //宣告排序後的結果之副程式
};

int main(int argc, char *argv[])
{ 
    fun obj;
    obj.RandomNum();       //呼叫產生10個亂數值的副程式
    cout<<"\n";
    obj.InSort();          //呼叫插入排序法的副程式
    obj.PrintInSort();     //呼叫插入排序後的結果之副程式
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

void fun::InSort()  //插入排序法之副程式
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
 
void fun::PrintInSort()  //插入排序法之副程式 
 {
    int i;
    cout<<"排序10個亂數值：";    
    for (i = 1; i <=n; i++)
    {
      cout<<A[i]<<"  ";
    }   
}

