#include <cstdlib>
#include <iostream>
#define NUM 10   //�w�q�}�C���j�p
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
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch6-3.5.cpp               =\n";
    cout<<"= �{���ت��G�Q�Τ@���}�C�ӫإߤG����  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";
    cout<<"�п�J�`�I�ӼơG";
    cin>>n;
    cout<<"�ЦA���O��J�o"<<n<<"�Ӹ`�I�����e�G\n";
    for (i=0;i<n;i++)
       cin>>data[i]; 
    cout<<"=================��X==================\n";   
    obj.BinaryTree_Array(data,n);  //�I�s�G����Q�Τ@�Ӥ@���}�C���x�s
   system("PAUSE");
   return(0);
}
 
//�G����Q�Τ@�Ӥ@���}�C���x�s���Ƶ{�� 
void fun:: BinaryTree_Array(int data[], int n)
    {
    int tree[10],t;                        
    int node=0,i,temp;
    for (i=0;i<10;i++)
	   tree[i]=0;
    tree[1]=data[0];//�]�w��ڪ��� 
    temp=n;
    for (i=1;i<n;i++)
     {
      node=1;
      while(tree[node]!=0)
	  {
	   if (data[i]>tree[node])  //�j���ڪ���� 
	     node=2*node+1;         //���k�l�� 
	   else                    //�p���ڪ����
	     node=2*node;          //��쥪�l�� 
	   if (temp<node)
		 {
		  temp=node;
		  t=temp;
		 }
	   }
	tree[node]=data[i];
       }
    cout<<"�G�����x�s�b�@���}�C�����G�G\n";
    for (i=1;i<=t;i++)
	  cout<<"  "<<tree[i];
    cout<<"\n";
    }
