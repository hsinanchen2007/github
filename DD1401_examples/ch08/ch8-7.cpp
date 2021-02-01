#include <cstdlib>
#include <iostream>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 
int A[10]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //宣告產生10個亂數值的副程式
    void Shellsort(int A[]);        //宣告謝耳排序法的副程式
};
int main(int argc, char *argv[])
{ 
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch8-7.cpp                 =\n";
    cout<<"= 程式目的：追蹤「謝耳排序法」的過程  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";    
    fun obj;
    obj.RandomNum();                //呼叫產生10個亂數值的副程式
    cout<<"\n"; 
    obj.Shellsort(A);               //呼叫謝耳排序法的副程式
    cout<<"\n";
    system("PAUSE");
    return(0);
} 
void fun::RandomNum()  //產生10個亂數值之副程式
{
  int i;
  srand((unsigned)time(NULL));   //亂數值初始化
  cout<<"產生10個亂數值：\n";
  for (i = 0; i < MAX; i++)
    {
       A[i] = rand() % 90+10;    //產生10~100的整數亂數值
       cout<<A[i]<<"  ";
    }
}
 //謝耳排序法的副程式
void fun::Shellsort(int A[]) 
{ 
    int i, j, k, Gap, t; 
    Gap = MAX / 2; 
    while(Gap > 0)
     { 
        for(k = 0; k < Gap; k++) 
        { 
            for(i = k+Gap; i < MAX; i+=Gap) 
            { 
                for(j = i - Gap; j >= k; j-=Gap) 
                { 
                    if(A[j] > A[j+Gap]) 
                    { 
                        SWAP(A[j], A[j+Gap]); 
                    } 
                    else 
                        break; 
                } 
            } 
        } 
        cout<<"\nGap ="<<Gap<<"："; 
        for(i = 0; i < MAX; i++) 
            cout<<A[i]<<"  ";
        Gap /= 2; 
    } 
}
