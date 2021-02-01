/*  ch3_17.c   */
#include <stdio.h>
#include <stdlib.h>

#define MAX_Item 100

struct item
{
    int row;
    int column;
    double value;
};
struct item A[MAX_Item+1];   /*  MAX_Item為一個常數  */

void Transpose(struct item  A[], struct item  B[])
{
     int i,j,Workb=1;
     B[0].row = A[0].column;   B[0].column = A[0].row;   B[0].value = A[0].value;
     for(i=1;i<=A[0].column;i++)
         for(j=1;j<=A[0].value;j++)
            if(A[j].column==i)
            {
               B[Workb].row = A[j].column;
               B[Workb].column = A[j].row;
               B[Workb].value = A[j].value;
               Workb++;
            }
}
int main(){
     int i;
     struct item A[MAX_Item+1];
     struct item B[MAX_Item+1];
     A[0].row = 4;    A[0].column = 3;     A[0].value = 3;
     A[1].row = 1;    A[1].column = 1;     A[1].value = 2;
     A[2].row = 2;    A[2].column = 3;     A[2].value = 1;
     A[3].row = 3;    A[3].column = 1;     A[3].value = 7;
     
     for(i=0;i<4;i++)
     {
         printf("%d\t%d\t%f\t",A[i].row,A[i].column,A[i].value);
         printf("\n");    
     }
     
     Transpose(A,B);
     printf("===================\n");  
     for(i=0;i<4;i++)
     {
         printf("%d\t%d\t%f\t",B[i].row,B[i].column,B[i].value);
         printf("\n");    
     }
    
     system("pause");
     return 0;
}
