/*  ch8_d.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MaxVertexSize 4    /* �̦h���I+1 */
#define INFINITE 99        /* �ΥH�N��L���j */

void Floyd_shortestpath(int edgeCost[][MaxVertexSize],
                        int A[][MaxVertexSize],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)                       
      for(j=1;j<n;j++)
        A[i][j] = edgeCost[i][j];

    for(k=1;k<n;k++)                     
      for(i=1;i<n;i++)
        for(j=1;j<n;j++)
          if (A[i][j]>A[i][k]+A[k][j])
            A[i][j] = A[i][k] + A[k][j];
}




int main(void)
{
   
      

      system("pause");
      return 0;
}
