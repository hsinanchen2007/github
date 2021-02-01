/*  ch3_05.c   */
#include <stdio.h>
#include <stdlib.h>

#define n 3
void func3(int p[][n],int rows,int cols);  /*  ¨ç¦¡«Å§i  */
int main()
{
     int i,j;
     int Ary[2][3]={{2,5,8},{3,6,9}};
     for(i=0;i<2;i++)
     {
       for(j=0;j<3;j++)
          printf("%d\t",Ary[i][j]);
       printf("\n");
     }
   

     func3(Ary,2,3);
     
     for(i=0;i<2;i++)
     {
       for(j=0;j<3;j++)
          printf("%d\t",Ary[i][j]);
       printf("\n");
     }     
     system("pause");
     return 0;
}
void func3(int p[][n],int rows,int cols)
{
     int i,j;

     for(i=0;i<rows;i++)
         for(j=0;j<cols;j++)
            p[i][j] = p[i][j] - 1;

}

