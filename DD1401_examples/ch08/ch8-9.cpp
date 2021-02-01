#include <cstdlib>
#include <iostream>
#define Num 10
int data[10] = {79, 8, 6, 93, 59, 84, 55, 9, 71, 33}; 
int temp[10][10] = {0}; 
int order[10] = {0}; 
int i, j, k, n, lsd; 
using namespace std;
class fun
{
  public:
    void ShowData ();                    //宣告產生10個亂數值的副程式
    void Radix(int data[],int n);        //宣告基數排序法的副程式
};
int main(int argc, char *argv[])
{ //主程式
    k = 0; 
    n = 1; 
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch8-9.cpp                 =\n";
    cout<<"= 程式目的：追蹤「基數排序法」的過程  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";     
    fun obj;
  obj.ShowData();                    //呼叫顯示原始資料
  cout<<"\n=================輸出==================\n";  
  obj.Radix(data,n);                 //呼叫基數排序法的副程式
  cout<<"\n";
  system("PAUSE");
  return(0);
}

void fun::ShowData ()  //顯示原始資料
{
    int i;
    cout<<"排序前: "; 
    for(i = 0; i < 10; i++) 
        cout<<data[i]<<" "; 
}
//基數排序法的副程式
void fun::Radix(int data[],int n)  
{   int t=1;
    while(n <= 10)
     { 
        for(i = 0; i < 10; i++) 
        { 
            lsd = ((data[i] / n) % 10); 
            temp[lsd][order[lsd]] = data[i]; 
            order[lsd]++; 
        } 
        if (t==1) 
           cout<<"\n「個位數」為主排序："; 
        else 
           cout<<"\n「十位數」為主排序："; 
        for(i = 0; i < 10; i++)
         { 
            if(order[i] != 0) 
                for(j = 0; j < order[i]; j++) 
                { 
                    data[k] = temp[i][j]; 
                    cout<<data[k]<<" ";
                    k++; 
                } 
            order[i] = 0; 
        } 
        n *= 10; 
        k = 0; 
        t+=1;
    } 
  }
