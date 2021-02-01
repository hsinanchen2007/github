/*  ch3_15.c   */
#include <stdio.h>
#include <stdlib.h>

#define COLS 4

void Add(int A[][COLS], int B[][COLS], int C[][COLS], int rows, int cols)
{
     int i,j;
     for(i=0;i<rows;i++)
         for(j=0;j<cols;j++)
            C[i][j] = A[i][j] + B[i][j];
}
int main()
{
     int i,j;
     
     int A[2][4]={{1,2,2,3},{4,5,1,2}};
     int B[2][4]={{3,2,3,0},{3,2,1,4}};
     int C[2][4]={0};
     
         
     Add(A,B,C,2,4);
     
     for(i=0;i<2;i++)
     {
       for(j=0;j<4;j++)
         printf("%d\t",A[i][j]);
       printf("\n");    
     }
     
     for(i=0;i<2;i++)
     {
       for(j=0;j<4;j++)
         printf("%d\t",B[i][j]);
       printf("\n");    
     }
     
     for(i=0;i<2;i++)
     {
       for(j=0;j<4;j++)
         printf("%d\t",C[i][j]);
       printf("\n");    
     }
     system("pause");
     return 0;
}




     
