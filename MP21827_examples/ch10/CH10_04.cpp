/*
[示範]:Dijkstra演算法(單點對全部頂點的最短路徑)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999 //無窮大
using namespace std;
int Graph_Matrix[SIZE][SIZE];//圖形陣列
int distance[SIZE];//路徑長度列
//建立圖形 
void BuildGraph_Matrix(int *Path_Cost)
{
    int Start_Point;//邊線的起點 
    int End_Point; //邊線的終點
    int i, j;
    for ( i = 1; i < SIZE; i++ )
        for ( j = 1; j < SIZE; j++ )
            if ( i == j )
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
        cout<<"vex"<<i;
        for ( j = 1; j < SIZE; j++ )
            if ( Graph_Matrix[i][j] == INFINITE )
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
    }
}
//單點對全部頂點最短距離 
void shortestPath(int vertex1, int vertex_total)
{       
    extern int distance[SIZE];//宣告為外部變數 
    int shortest_vertex = 1; //紀錄最短距離的頂點
    int shortest_distance;   //紀錄最短距離
    int goal[SIZE]; //用來紀錄該頂點是否被選取
    int i,j;
    for ( i = 1; i <= vertex_total; i++ )
    { 
        goal[i] = 0;    
        distance[i] = Graph_Matrix[vertex1][i]; 
    }
    goal[vertex1] = 1;  
    distance[vertex1] = 0;  
    cout<<endl;   
    for (i=1; i<=vertex_total-1; i++ ) 
    {      
        shortest_distance = INFINITE;      
        //找最短距離頂 
        for (j=1;j<=vertex_total;j++ )
            if (goal[j]==0&&shortest_distance>distance[j])
            {
                shortest_distance=distance[j];                                              
                shortest_vertex=j;              
            }
        goal[shortest_vertex] = 1;   
        //計算開始頂點到各頂點最短距離
        for (j=1;j<=vertex_total;j++ )
        {
            if ( goal[j] == 0 && 
                distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
                <distance[j])
            {
                distance[j]=distance[shortest_vertex]
                +Graph_Matrix[shortest_vertex][j];
            }       
        }
   }
}
//主程式
int main(void) 
{
    extern int distance[SIZE];//宣告為外部變數
    int Path_Cost[7][3] = { {1, 2, 10}, 
                            {2, 3, 20},
                            {2, 4, 25},
                            {3, 5, 18},
                            {4, 5, 22},
                            {4, 6, 95},
                            {5, 6, 77} }; 
    int j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"=================================="<<endl;
    cout<<"此範例圖形的相鄰矩陣如下: "<<endl;
    cout<<"=================================="<<endl;
    cout<<"頂點 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix();  //顯示圖形
    shortestPath(1,NUMBER); //找尋最短路徑
    cout<<"=================================="<<endl;
    cout<<"頂點1到各頂點最短距離的最終結果"<<endl;
    cout<<"=================================="<<endl;
    for (j=1;j<SIZE;j++) 
        cout<<"頂點 1到頂點"<<setw(2)<<j<<"的最短距離="
        <<setw(3)<<distance[j]<<endl;
    cout<<endl;
    return 0; 
}
