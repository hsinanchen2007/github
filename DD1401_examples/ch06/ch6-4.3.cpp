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
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch6-4.3.cpp               =\n";
    cout<<"= �{���ت��G�إߤ@�ӤG�����ǰl��    =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n"; 
    cout<<"�п�J�`�I�ӥءG";
    cin>>n;
    cout<<"�ЦA���O��J�o"<<n<<"�Ӹ`�I�����e�G\n";
    for (i=0;i<n;i++)
       cin>>data[i];
    obj.CreateBinaryTree(data,n); //�I�s�إߤG���𤧰Ƶ{�� 
    cout<<"=================��X==================\n"; 
    cout<<"�G�����ǰl�ܪ����G�G\n";
    obj.Postorder(1);   //�I�s��Ǥ��Ƶ{�� 
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

//�i���Ǥ��Ƶ{�� 
void fun::Postorder(int node)
 {
  if (tree[node]!=0)
     {
	   Postorder(2*node);    //���j���l��
	   Postorder(2*node+1);  //���j�k�l��
	   if (tree[node]!=0)
	     cout<<"  "<<tree[node]; //�C�L���
	  }
 }

