#include <cstdlib>
#include <iostream>
#define NUM 5
using namespace std;
class fun
{
  public:
  void BinaryTree_List(int data[], int n);  
};
int main(int argc, char *argv[])
{   
    fun obj;
    int data[20],n;
    int i;
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch6-3.5a.cpp              =\n";
    cout<<"= �{���ت��G�Q���쵲��C�ӫإߤG����  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";
    cout<<"�п�J�`�I�ӼơG";
    cin>>n;
    cout<<"�ЦA���O��J�o"<<n<<"�Ӹ`�I�����e�G\n";
    for (i=0;i<n;i++)
       cin>>data[i]; 
    cout<<"=================��X==================\n";    
    obj.BinaryTree_List(data,n);   //�I�s�G����Q���쵲��C���x�s
   system("PAUSE");
   return(0);
}
 //�G����Q���쵲��C���x�s���Ƶ{�� 
void fun::BinaryTree_List(int data[],int n)
 {
    int tree[20],t;
    int node=0,i,temp,left,right;
    for (i=0;i<20;i++)
	   tree[i]=0;    //��ȳ]�w��0 
    tree[1]=data[0];  //�]�w��ڪ��� 
    temp=n;   //�`�I�Ӽ�
    for (i=1;i<n;i++)
    {
	node=1;
	while(tree[node]!=0)
	     {
	      if (data[i]>tree[node])   //�j���ڪ���� 
	        node=2*node+1;          //���k�l�� 
	     else                      //�p���ڪ����
	        node=2*node;           //��쥪�l�� 
	      if (temp<node)
		 {
		  temp=node;
		  t=temp;
		 }
	     }
	  tree[node]=data[i];
    }
    cout<<"�G����Q���쵲��C���x�s�覡�G\n";
    cout<<"�`�I�@���`�I�@�`�I����ȡ@�k�`�I\n";
    for (i=1;i<=t;i++)
	{
	left=2*i;
	right=2*i+1;
	if (tree[left]==0)
	   left=0;
	if (tree[right]==0)
	   right=0;
	if (tree[i]!=0)
	   cout<<"["<<i<<"]"<<"        "<<left<<"         "<<tree[i]<<"        "<<right<<"\n";
   	}
 }

