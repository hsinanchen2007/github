/*  ch3_04.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i;
     int *stu; 
     int n = 50;        /*  n�ΨӰO���ǥͤH�ơA�i�H�אּ�ѨϥΪ̩�{������ɿ�J  */
     stu = (int *)malloc(sizeof(int)*n);
     stu[6] = 76;                        /*  �]�w�ĤC��ǥͪ����Z��76��  */

     
          
     for(i=0;i<n;i++)
        printf("%d\t",stu[i]);
     printf("\n");
   
     free(stu);    
     
     system("pause");
     return 0;
}



    
    
