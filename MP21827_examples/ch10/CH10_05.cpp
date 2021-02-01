/*
[示範]:Floyd演算法(所有頂點兩兩之間的最短距離)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 //無窮大
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];//圖形陣列
int distance[SIZE][SIZE];//路徑長度陣列
//建立圖形 
void BuildGraph_Matrix(int *Path_Cost)
{
    int Start_Point;//邊線的起點
    int End_Point;  //邊線的終點 
    int i, j;
    for ( i = 1; i < SIZE; i++ )
        for ( j = 1; j < SIZE; j++ )
            if (i==j)
                Graph_Matrix[i][j] = 0; //對角線設為0
            else
                Graph_Matrix[i][j] = INFINITE;  
    //存入圖形的邊線
    i=0;
    while(i<SIZE)
    {
        Start_Point = Path_Cost[i*3]; 
        End_Point = Path_Cost[i*3+1]; 
        Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
        i++;
    }
}
//印出圖形
void printGraph_Matrix()
{
   int i, j;
   for ( i = 1; i < SIZE; i++ )
   {
        cout<<"vex%d"<<i;
        for ( j = 1; j < SIZE; j++ )
            if ( Graph_Matrix[i][j] == INFINITE )
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
   }
}
//單點對全部頂點最短距離 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   extern int distance[SIZE][SIZE];//宣告為外部變數 
   //圖形長度陣列初始化
   for (i=1;i<=vertex_total;i++ )
        for (j=i;j<=vertex_total;j++ )
        {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
        }
   //利用Floyd演算法找出所有頂點兩兩之間的最短距離
   for (k=1;k<=vertex_total;k++ ) 
        for (i=1;i<=vertex_total;i++ )
            for (j=1;j<=vertex_total;j++ )
                if (distance[i][k]+distance[k][j]<distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];   
}
//主程式
int main(void) 
{
    extern int distance[SIZE][SIZE];//宣告為外部變數
    int Path_Cost[7][3] = { {1, 2, 10}, 
                        {2, 3, 20},
                        {2, 4, 25},
                        {3, 5, 18},
                        {4, 5, 22},
                        {4, 6, 95},
                        {5, 6, 77} }; 
    int i,j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"=================================="<<endl;
    cout<<"此範例圖形的相鄰矩陣如下: "<<endl;
    cout<<"=================================="<<endl;
    cout<<"頂點 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix();  //顯示圖形的相鄰矩陣
    cout<<"=================================="<<endl;
    cout<<"所有頂點兩兩之間的最短距離: "<<endl;
    cout<<"=================================="<<endl;
    shortestPath(NUMBER); //計算所有頂點間的最短路徑
    //求得兩兩頂點間的最短路徑長度陣列後，將其印出
    cout<<"頂點 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    for ( i = 1; i <= NUMBER; i++ )
    {
        cout<<"vex"<<i;
        for ( j = 1; j <= NUMBER; j++ )
        {
            cout<<setw(5)<<distance[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return 0; 
}
