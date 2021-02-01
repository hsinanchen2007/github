#include <cstdlib>
#include <iostream>
#define N 8                       //定義頂點總數 
#define Edge 10                   //定義邊的總數
int G[N][N];                   
int Gnode[10][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 8}, {7, 8}};
int Visited[N];        //記錄已被拜訪過的節點 
int Queue[N + 1];
int row, column, i;
int Front = -1;
int Rear = -1;


using namespace std;
class fun
{
  public:
   void Create_Graph();   //宣告建立圖形
   void Add(int);         //Enqueue副程式 
   int Delete(void);      //Dequeue副程式
   void BFS(int);         //宣告廣度優先搜尋法 
};
int main(int argc, char *argv[])
{   
    fun obj;
    cout<<"===============程式描述================\n";
    cout<<"= 程式名稱：ch7-5.2.cpp               =\n";
    cout<<"= 程式目的：廣度優先搜尋法(BFS)       =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================輸入==================\n";
 //將二維陣列的內容轉換成相鄰陣列
 int R_node;
 //相鄰陣列預設為0
 for(row = 0;row<=N - 1;row++)
  {
    for(column = 0;column<=N - 1;column++)
      G[row][column]=0;
  }
  
//設定頂點的起點
 for(row = 0;row<=Edge - 1;row++)
  {
    R_node = Gnode[row][0] - 1;     
    for(column = 0;column<=1;column++)
      G[R_node][Gnode[row][column] - 1] = 1;
  }

//設定頂點的終點
 for(row = 0;row<=Edge - 1;row++)
  {
    R_node = Gnode[row][1] - 1;
    for(column = 0;column<=1;column++)
      G[R_node][Gnode[row][column] - 1] = 1;
  }

//對角線設定為0
 for(row = 0;row<=N - 1;row++)
  {    
    for(column = 0;column<=N - 1;column++)
     {
       if(row == column)
          G[row][column]=0;
     }
  }

//設定節點都尚未被拜訪
  for(i = 0;i<=N - 1;i++)
    Visited[i] = 0;
  obj.Create_Graph();//建立圖形 
  cout<<"=================輸出==================\n";        
  cout<<"廣度優先搜尋法(BFS)拜訪頂點的順序為：\n";  //印出走訪過程 
  obj.BFS(0);                                       //呼叫深先搜尋法
  cout<<"\n";
  system("PAUSE");	
  return 0;

 
}
 
 //建立圖形
void fun:: Create_Graph()           
{
 cout<<"圖形的相鄰串列內容如下:\n";
  for(row = 0;row<=N - 1;row++)
  {
    for(column = 0;column<=N - 1;column++)
       cout<<"  "<<G[row][column];
    cout<<"\n";
  }
}

 //深先搜尋法
void fun::BFS(int i)       
{
 int j;
  Visited[i] = 1;
  cout<<"  v"<<i + 1;
  for(j = 0;j<=N - 1;j++)
   {
    if(G[i][j] == 1)
      if (Visited[j]!=1)  //判斷是否已經被拜訪過
         Add(j);
   }
   while (Front!= Rear)
   {
     i = Delete();
     if(Visited[i]!= 1)
       BFS(i);
   }

}  

//資料加入佇列
void fun::Add(int j)    //Enqueue副程式 
{
  if(Rear == N + 1) 
    cout<<"佇列是滿的!\n";
  else
  {
   Rear = Rear + 1;
   Queue[Rear] = j;  
  }
}

//資料從佇列刪除 
int fun::Delete(void)        //Dequeue副程式
{
  if(Front == Rear) 
    cout<<"佇列是空的!\n";
   else
   {
     Front = Front + 1;
     return Queue[Front];
   }
}
                  
