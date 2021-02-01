#include <cstdlib>
#include <iostream>
#define N 8                       //�w�q���I�`�� 
#define Edge 10                   //�w�q�䪺�`��
int G[N][N];                   
int Gnode[10][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 8}, {7, 8}};
int Visited[N];        //�O���w�Q���X�L���`�I 
int row, column, i;

using namespace std;
class fun
{
  public:
  void Create_Graph();   //�ŧi�إ߹ϧ�
  void DFS(int);         //�ŧi�`���u���j�M�k
};
int main(int argc, char *argv[])
{   
    fun obj;
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch7-5.1.cpp               =\n";
    cout<<"= �{���ت��G�`���u���j�M�k(DFS)       =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";
 //�N�G���}�C�����e�ഫ���۾F�}�C
 int R_node;
 //�۾F�}�C�w�]��0
 for(row = 0;row<=N - 1;row++)
  {
    for(column = 0;column<=N - 1;column++)
      G[row][column]=0;
  }
  
//�]�w���I���_�I
 for(row = 0;row<=Edge - 1;row++)
  {
    R_node = Gnode[row][0] - 1;     
    for(column = 0;column<=1;column++)
      G[R_node][Gnode[row][column] - 1] = 1;
  }

//�]�w���I�����I
 for(row = 0;row<=Edge - 1;row++)
  {
    R_node = Gnode[row][1] - 1;
    for(column = 0;column<=1;column++)
      G[R_node][Gnode[row][column] - 1] = 1;
  }

//�﨤�u�]�w��0
 for(row = 0;row<=N - 1;row++)
  {    
    for(column = 0;column<=N - 1;column++)
     {
       if(row == column)
          G[row][column]=0;
     }
  }

//�]�w�`�I���|���Q���X
  for(i = 0;i<=N - 1;i++)
    Visited[i] = 0;
  obj.Create_Graph();//�إ߹ϧ� 
  cout<<"=================��X==================\n";        
  cout<<"�ϧΪ��`���u���j�M(DFS)����:\n";     //�L�X���X�L�{ 
  obj.DFS(0);                                       //�I�s�`���j�M�k
  cout<<"\n";
  system("PAUSE");	
  return 0;

 
}
 
 //�إ߹ϧ�
void fun:: Create_Graph()           
{
 cout<<"�ϧΪ��۾F��C���e�p�U:\n";
  for(row = 0;row<=N - 1;row++)
  {
    for(column = 0;column<=N - 1;column++)
       cout<<"  "<<G[row][column];
    cout<<"\n";
  }
}

 //�`���j�M�k
void fun::DFS(int i)       
{
  int j;
  Visited[i] = 1;
  cout<<"  v"<<i + 1;
  for(j = 0;j<=N - 1;j++)
   {
    if(G[i][j] == 1)
      if (Visited[j]!=1)  //�P�_�O�_�w�g�Q���X�L
           DFS(j);
   }
}                    
