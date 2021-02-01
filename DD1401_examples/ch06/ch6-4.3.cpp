#include <cstdlib>
#include <iostream>
#define Num 20
int data[Num]={0}; 
int tree[Num]={0}; 
using namespace std;
class fun
{
  public:
  void CreateBinaryTree(int data[],int n); 
  void Postorder(int node);
};
int main(int argc, char *argv[])
{
    fun obj;
    int n,i;
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch6-4.3.cpp               =\n";
    cout<<"= 程式目的：建立一個二元樹後序追蹤    =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n"; 
    cout<<"請輸入節點個目：";
    cin>>n;
    cout<<"請再分別輸入這"<<n<<"個節點的內容：\n";
    for (i=0;i<n;i++)
       cin>>data[i];
    obj.CreateBinaryTree(data,n); //呼叫建立二元樹之副程式 
    cout<<"=================輸出==================\n"; 
    cout<<"二元樹後序追蹤的結果：\n";
    obj.Postorder(1);   //呼叫後序之副程式 
    cout<<"\n";
       system("PAUSE");
   return(0);
}

//建立二元樹之副程式 
void fun::CreateBinaryTree(int data[],int n)
 {           
    int node=1,i,j,temp;
    for (i=0;i<Num;i++)
	   tree[i]=0;  //初值設定 
    for (i=0;i<n;i++)
     {
	   tree[node]=data[i];
	   node=node+1;
       }
 }

//進行後序之副程式 
void fun::Postorder(int node)
 {
  if (tree[node]!=0)
     {
	   Postorder(2*node);    //遞迴左子樹
	   Postorder(2*node+1);  //遞迴右子樹
	   if (tree[node]!=0)
	     cout<<"  "<<tree[node]; //列印樹根
	  }
 }

