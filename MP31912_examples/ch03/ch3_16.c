/*  ch3_16.c   */
#include <stdio.h>
#include <stdlib.h>

#define ACOLS 4
#define BCOLS 3
#define CCOLS 3

void Mul(int A[][ACOLS], int B[][BCOLS], int C[][CCOLS], int m, int n, int p)
{
     int i,j,k;
     for(i=0;i<m;i++)
         for(j=0;j<p;j++)
         {
             C[i][j] = 0;
             for(k=0;k<n;k++)
                 C[i][j] += A[i][k] * B[k][j];
         }
}
int main()
{    int i,j;
     int A[2][4]={{1,2,2,3},{4,5,1,2}};
     int B[4][3]={{2,5,1},{3,2,1},{2,2,4},{3,5,2}};
     int C[2][3]={0};
     
     for(i=0;i<2;i++)
     {
       for(j=0;j<4;j++)
         printf("%d\t",A[i][j]);
       printf("\n");    
     }
     
     for(i=0;i<4;i++)
     {
       for(j=0;j<3;j++)
         printf("%d\t",B[i][j]);
       printf("\n");    
     }
     
     Mul(A,B,C,2,4,3);

     for(i=0;i<2;i++)
     {
       for(j=0;j<3;j++)
         printf("%d\t",C[i][j]);
       printf("\n");    
     }
     
     system("pause");
     return 0;
}
