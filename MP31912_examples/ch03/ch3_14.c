/*  ch3_14.c   */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 3

void Transpose(int A[][COLS], int B[][ROWS], int rows, int cols)
{
     int i,j;
     for(i=0;i<rows;i++)
         for(j=0;j<cols;j++)
            B[j][i] = A[i][j];
}
int main()
{
     int i,j; 
     
     int A[2][3]={{2,5,8},{3,6,9}};
     int B[3][2]={0};

     for(i=0;i<ROWS;i++)
     {
       for(j=0;j<COLS;j++)
         printf("%d\t",A[i][j]);
       printf("\n");    
     }
     

     Transpose(A,B,2,3);

     for(i=0;i<COLS;i++)
     {
       for(j=0;j<ROWS;j++)
         printf("%d\t",B[i][j]);
       printf("\n");    
     }  
     
     system("pause");
     return 0;
}


