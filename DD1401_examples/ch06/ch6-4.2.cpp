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
  void Preorder(int node);
};
int main(int argc, char *argv[])
{
    fun obj;
    int n,i;
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch6-4.2.cpp               =\n";
    cout<<"= �{���ت��G�إߤ@�ӤG����e�ǰl��    =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n"; 
    cout<<"�п�J�`�I�ӥءG";
    cin>>n;
    cout<<"�ЦA���O��J�o"<<n<<"�Ӹ`�I�����e�G\n";
    for (i=0;i<n;i++)
       cin>>data[i];
    obj.CreateBinaryTree(data,n); //�I�s�إߤG���𤧰Ƶ{�� 
    cout<<"=================��X==================\n"; 
    cout<<"�G����e�ǰl�ܪ����G�G\n";
    obj.Preorder(1);   //�I�s�e�Ǥ��Ƶ{�� 
    cout<<"\n";
       system("PAUSE");
   return(0);
}

//�إߤG���𤧰Ƶ{�� 
void fun::CreateBinaryTree(int data[],int n)
 {           
    int node=1,i,j,temp;
    for (i=0;i<Num;i++)
	   tree[i]=0;  //��ȳ]�w 
    for (i=0;i<n;i++)
     {
	   tree[node]=data[i];
	   node=node+1;
       }
 }

//�i��e�Ǥ��Ƶ{�� 
void fun::Preorder(int node)
 {
  if (tree[node]!=0)
     {
	   if (tree[node]!=0)
	   cout<<"  "<<tree[node];  //�C�L���
	   Preorder(2*node);    //���j���l��
	   Preorder(2*node+1);  //���j�k�l��
      }
 }

