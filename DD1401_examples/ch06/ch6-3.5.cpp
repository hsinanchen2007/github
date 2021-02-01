#include <cstdlib>
#include <iostream>
#define NUM 10   //定義陣列的大小
using namespace std;
class fun
{
  public:
  void BinaryTree_Array(int data[], int n);  
};
int main(int argc, char *argv[])
{   
    fun obj;
    int data[10],n;
    int i;  
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch6-3.5.cpp               =\n";
    cout<<"= 程式目的：利用一維陣列來建立二元樹  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";
    cout<<"請輸入節點個數：";
    cin>>n;
    cout<<"請再分別輸入這"<<n<<"個節點的內容：\n";
    for (i=0;i<n;i++)
       cin>>data[i]; 
    cout<<"=================輸出==================\n";   
    obj.BinaryTree_Array(data,n);  //呼叫二元樹利用一個一維陣列來儲存
   system("PAUSE");
   return(0);
}
 
//二元樹利用一個一維陣列來儲存之副程式 
void fun:: BinaryTree_Array(int data[], int n)
    {
    int tree[10],t;                        
    int node=0,i,temp;
    for (i=0;i<10;i++)
	   tree[i]=0;
    tree[1]=data[0];//設定樹根的值 
    temp=n;
    for (i=1;i<n;i++)
     {
      node=1;
      while(tree[node]!=0)
	  {
	   if (data[i]>tree[node])  //大於樹根的鍵值 
	     node=2*node+1;         //放到右子樹 
	   else                    //小於樹根的鍵值
	     node=2*node;          //放到左子樹 
	   if (temp<node)
		 {
		  temp=node;
		  t=temp;
		 }
	   }
	tree[node]=data[i];
       }
    cout<<"二元樹儲存在一維陣列的結果：\n";
    for (i=1;i<=t;i++)
	  cout<<"  "<<tree[i];
    cout<<"\n";
    }
