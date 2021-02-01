#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define INFINITE  99999 
#define NUMBER 6

int Graph_Matrix[SIZE][SIZE];/* 圖形陣列 */
int distance[SIZE][SIZE];/* 路徑長度陣列 */

/* 建立圖形 */
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* 邊線的起點 */
   int End_Point; /* 邊線的終點 */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
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
/* 印出圖形 */
 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   /* 圖形長度陣列初始化  */
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
     /* 利用Floyd演算法找出所有頂點兩兩之間的最短距離 */       
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
/* 主程式 */
int main() 
{
   int Path_Cost[7][3] = { {1, 2,20}, 
                      {2, 3, 30},
                      {2, 4, 25},
                      {3, 5, 28},
                      {4, 5, 32},
                      {4, 6, 95},
                      {5, 6, 67} }; 
   int i,j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   printf("===========================================\n");
   printf("      所有頂點兩兩之間的最短距離: \n");
   printf("===========================================\n");
   shortestPath(NUMBER); /* 計算所有頂點間的最短路徑 */
   /*求得兩兩頂點間的最短路徑長度陣列後，將其印出*/
   printf("       頂點1 頂點2 頂點3 頂點4 頂點5 頂點6\n");
      for ( i = 1; i <= NUMBER; i++ )
      {
         printf("頂點%d",i);
         for ( j = 1; j <= NUMBER; j++ )
         {
            printf("%5d ",distance[i][j]);
         }
         printf("\n");
      }
   printf("===========================================\n");
   printf("\n");
   system("PAUSE");
   return 0; 
}
