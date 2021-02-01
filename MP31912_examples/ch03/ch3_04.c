/*  ch3_04.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i;
     int *stu; 
     int n = 50;        /*  n用來記錄學生人數，可以改為由使用者於程式執行時輸入  */
     stu = (int *)malloc(sizeof(int)*n);
     stu[6] = 76;                        /*  設定第七位學生的成績為76分  */

     
          
     for(i=0;i<n;i++)
        printf("%d\t",stu[i]);
     printf("\n");
   
     free(stu);    
     
     system("pause");
     return 0;
}



    
    
