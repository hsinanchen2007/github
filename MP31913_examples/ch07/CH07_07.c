#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999/* 無窮大 */ 

int Graph_Matrix[SIZE][SIZE];/* 圖形陣列 */
int distance[SIZE];/* 路徑長度陣列 */
/* 建立圖形 */ 
void BuildGraph_Matrix(int *Path_Cost);
void shortestPath(int vertex1, int vertex_total);

/* 主程式 */
int main() 
{
   int Path_Cost[8][3] = { {1, 2, 29}, 
                      {2, 3, 30},
                      {2, 4, 35},
                      {3, 5, 28},
                      {3, 6, 87},
                      {4, 5, 42},
                      {4, 6, 75},
                      {5, 6, 97} }; 
   int j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   shortestPath(1,NUMBER); /* 找尋最短路徑 */
   printf("-----------------------------------\n");
   printf("頂點1到各頂點最短距離的最終結果\n");
   printf("-----------------------------------\n");
   for (j=1;j<SIZE;j++) 
      printf("頂點 1到頂點%2d的最短距離=%3d\n",j,distance[j]);
   printf("-----------------------------------\n");
   printf("\n");
  
   system("PAUSE");
   return 0; 
}
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* 邊線的起點 */
   int End_Point; /* 邊線的終點 */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if ( i == j )
            Graph_Matrix[i][j] = 0; /* 對角線設為0 */ 
         else
            Graph_Matrix[i][j] = INFINITE;  
   /* 存入圖形的邊線 */  
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}

/* 單點對全部頂點最短距離 */ 
void shortestPath(int vertex1, int vertex_total)
{       
   int shortest_vertex = 1; /*紀錄最短距離的頂點*/
   int shortest_distance;   /*紀錄最短距離*/
   int goal[SIZE]; /*用來紀錄該頂點是否被選取*/ 
   int i,j;
   for ( i = 1; i <= vertex_total; i++ )
   { 
      goal[i] = 0;    
      distance[i] = Graph_Matrix[vertex1][i]; 
   }
   goal[vertex1] = 1;  
   distance[vertex1] = 0;  
   printf("\n");
   
   for (i=1; i<=vertex_total-1; i++ ) 
   {      
      shortest_distance = INFINITE;      
      /* 找最短距離頂 */
      for (j=1;j<=vertex_total;j++ )
         if (goal[j]==0&&shortest_distance>distance[j])
         {
            shortest_distance=distance[j];                                              
            shortest_vertex=j;              
         }
      goal[shortest_vertex] = 1;   
      /* 計算開始頂點到各頂點最短距離 */
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
