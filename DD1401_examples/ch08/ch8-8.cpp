#include <cstdlib>
#include <iostream>
#define MAX1 10 
#define MAX2 10 
int A[10]={0};
int B[10]={0};
int C[20]={0};
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 
using namespace std;
class fun
{
  public:
    void RandomNum();                //宣告產生10個亂數值的副程式
    void Quicksort(int A[],int a,int b);        //宣告快速排序法的副程式
    void PrintQuicksort(int A[],int B[]);        //列印出第一與二組資料排序結果
    void Mergesort(int A[],int MAX_1,int B[],int MAX_2,int C[]); //進行合併排序 
    void PrintMergesort(int C[]);          //顯示合併排序之結果
};
int main(int argc, char *argv[]) 
{ 
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch8-8.cpp                 =\n";
    cout<<"= 程式目的：追蹤「合併排序法」的過程  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";     
    fun obj;
    obj.RandomNum();                //呼叫產生10個亂數值的副程式
    cout<<"\n";  
    obj.Quicksort(A, 0, MAX1-1);    //第一組資料排序 
    obj.Quicksort(B, 0, MAX2-1);    //第二組資料排序
    cout<<"\n=================輸出==================\n";  
    obj.PrintQuicksort(A,B);        //列印出第一與二組資料排序結果 
    cout<<"\n"; 
    obj.Mergesort(A,MAX1,B,MAX2,C); //進行合併排序 
    cout<<"\n";  
    obj.PrintMergesort(C);          //顯示合併排序之結果 
    cout<<"\n"; 
    system("PAUSE");
    return(0);
} 
void fun::RandomNum()  //產生10個亂數值之副程式
{
  int i;
  srand((unsigned)time(NULL));   //亂數值初始化
  cout<<"產生10個亂數值：\n"; 
  cout<<"第一組資料：";
  for (i = 0; i < MAX1; i++)
    {
       A[i] = rand() % 40+10;    //產生10~50的整數亂數值
       cout<<A[i]<<"  ";
    }
  printf("\n"); 
   printf("第二組資料：");
  for (i = 0; i < MAX2; i++)
    {
       B[i] = rand() % 50+51;    //產生51~100的整數亂數值
       cout<<B[i]<<"  ";
    }   
}

void fun::Quicksort(int A[], int left, int right)
 { 
    int q; 
    if(left < right) 
    { 
    int i, j, s; 
    s = A[right]; 
    i = left - 1; 
    for(j = left; j < right; j++) { 
        if(A[j] <= s) { 
            i++; 
            SWAP(A[i], A[j]); 
        } 
    } 
    SWAP(A[i+1], A[right]); 
    q = i+1; 
    
        Quicksort(A, left, q-1); 
        Quicksort(A, q+1, right); 
    } 
} 


//快速排序法之副程式 
void fun::PrintQuicksort(int A[], int B[])  
 {
    int i;
    cout<<"\n排序後："; 
    cout<<"\n第一組資料："; 
    for(i = 0; i < MAX1; i++) 
        cout<<A[i]<<"  ";
    cout<<"\n第二組資料："; 
    for(i = 0; i < MAX2; i++) 
        cout<<B[i]<<"  ";
}
//進行合併排序
void fun::Mergesort(int A[], int M, int B[],int N, int C[])
 { 
    int i = 0, j = 0, k = 0; 
    while(i < M && j < N) 
    { 
        if(A[i] <= B[j]) 
            C[k++] = A[i++]; 
        else 
            C[k++] = B[j++]; 
    } 
    while(i < M) 
        C[k++] = A[i++]; 
    while(j < N) 
        C[k++] = B[j++]; 
}
//顯示合併排序之結果
void fun::PrintMergesort(int C[])  //合併後之副程式 
 {
    int i;
    cout<<"合併後：\n"; 
    for(i = 0; i < MAX1+MAX2; i++) 
        cout<<C[i]<<" "; 
}
