#include <stdio.h>
#include <stdlib.h>

void shortestpath(int,int [][],int [],int,short int []);
int chooseMin(int [],int,short int []);

#define FALSE 0
#define TRUE 1
#define INFINITE 99        /* 用以代表無限大 */
#define MaxVertexSize 10   /* 最多頂點+1 */

void shortestpath(int F,int edgeCost[][MaxVertexSize],
                  int D[],int n,short int selected[])
{
    int x,t,I;
    for(x=1;x<n;x++)    
    {
      selected[x] = FALSE;
      D[x] = edgeCost[F][x];
    }

    selected[F] = TRUE;
    D[F] = 0;

    for(x=2;x<n;x++)     /* 對應範例 Step2~Step9 */
    {
      t = chooseMin(D,n,selected);
      selected[t] = TRUE;
      for(I=1;I<=n;I++)
      { 
        if(selected[I]!=TRUE)         
          if(D[I] > D[t] + edgeCost[t][I])
             D[I] = D[t] + edgeCost[t][I];
      }
    }
}
int chooseMin(int D[],int n,short int selected[])
{
    int x,min,minPosition;
    min = INFINITE;
    minPosition = 0;
    for(x=1;x<n;x++)
    {
       if(D[x] < min && selected[x]!=TRUE)
       {
           minPosition = x;
           min = D[x];
       }
    }
   
    return minPosition;
}

int main()
{
  int edgeCost[][MaxVertexSize] = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1, 0,15,12,30,99,99,99,99,99},
                                   {-1,99, 0,99,11,99,26,99,99,99},
                                   {-1,99,99, 0,99,20,99,99,99,99},
                                   {-1,99,99,99, 0,10,99,99,99,99},
                                   {-1,99,99,99,99, 0,99,99,99,24},
                                   {-1,99,99,99,99,14, 0,99,18,99},
                                   {-1,99,99,99,99,13,99, 0,99,99},
                                   {-1,99,99,99,99,99,99,99, 0,15},
                                   {-1,99,99,99,99,99,99,99,99, 0}};
  int D[MaxVertexSize];
  short int selected[MaxVertexSize];
  int n=MaxVertexSize;
  int F,x;
  printf("輸入起始頂點:");
  scanf("%d",&F);

  shortestpath(F,edgeCost,D,n,selected);  /* 計算最短路徑 */

  for(x=1;x<n;x++)
  {
     if(D[x]<INFINITE)
       printf("shortest path from %d to %d is %2d\n",F,x,D[x]);
     else
       printf("%d -> %d not connected\n",F,x);
  }
  system("pause");
  return 0;
}
