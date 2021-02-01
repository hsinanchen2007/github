#include <cstdlib>
#include <iostream>
#define MAX 10
int A[10]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //宣告產生10個亂數值的副程式
    void Createheap(int A[],int root, int index);        //宣告建立堆積樹的副程式
    void Heapsort(int A[], int index);         //宣告堆積排序後的結果之副程式
};
int main(int argc, char *argv[])
 { 
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch8-6.cpp                 =\n";
    cout<<"= 程式目的：追蹤「堆積排序法」的過程  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";            
    fun obj;
    int number[MAX+1] = {-1}; 
    int i, num;  
    obj.RandomNum();                //呼叫產生10個亂數值的副程式
    cout<<"\n=================輸出==================\n";  
    cout<<"建立堆積樹：\n"; 
    obj.Heapsort(A,MAX);              //呼叫堆積排序法的副程式
    cout<<"\n";
    system("PAUSE");
    return(0);
} 

void fun::RandomNum()  //產生10個亂數值之副程式
{
  int i;
  srand((unsigned)time(NULL)); //亂數值初始化
  cout<<"產生10個亂數值：\n";
  for (i = 1; i <= MAX; i++)
    {
      A[i] = rand() % 90+10;  //產生10~100的整數亂數值
       cout<<A[i]<<"  ";
    }
}

//建立堆積樹的副程式
void fun::Createheap(int A[],int root, int index) { 
 int i, j , temp;
     int finish;              
     j=2*root;                
     temp=A[root];            
     finish=0;                
     while ( j<= index  &&  finish==0 )
     {
     //找最大值
	 if ( j < index )
	       if ( A[j] < A[j+1] )
              j++;
	 if ( temp >= A[j] )
	     finish=1;         
        else
        {
	     A[j/2]=A[j];      
         j=2*j;
        }
     }
     A[j/2]=temp;        
} 

//呼叫堆積排序法的副程式
void fun::Heapsort(int A[], int index) { 
    int i, j,t, temp;
    t=1;
    //將完整二元樹轉成堆積樹 
    for ( i= (index/2); i >= 1; i--)
       Createheap(A, i , index);
    for(i = 1; i <= 10; i++) 
       printf("%4d",A[i]);
    //累堆排序
    cout<<"\n\n堆積排序法："; 
    for  ( i = index-1; i >= 1; i--)
    {
	 temp=A[i+1];          
     A[i+1]=A[1];
     A[1]=temp;
	 Createheap(A,1,i);    
     printf("\n第 %d 次排序：", t++);
     for ( j=1; j <= index; j++)
	       printf("%d ", A[j] );
   }
}
