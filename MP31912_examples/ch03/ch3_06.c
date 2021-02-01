/*  ch3_06.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i,j;
     int Ary1[3]={5,3,2};
     int Ary2[2][3]={{2,5,8},{3,6,9}};
     int a,b;
     
     for(i=0;i<3;i++)
         printf("%d\t",Ary1[i]);
     printf("\n");

     for(i=0;i<2;i++)
     {
       for(j=0;j<3;j++)
          printf("%d\t",Ary2[i][j]);
       printf("\n");
     }


     a = Ary1[1];
     b = Ary2[0][2];
     Ary1[2] = 7;
     Ary2[1][1] = a;
     
     for(i=0;i<3;i++)
         printf("%d\t",Ary1[i]);
     printf("\n");

     for(i=0;i<2;i++)
     {
       for(j=0;j<3;j++)
          printf("%d\t",Ary2[i][j]);
       printf("\n");
     }
     system("pause");
     return 0;
}

