/*  ch3_07.c   */
#include <stdio.h>
#include <stdlib.h>


int insertElement(int value,int location,int ary[],int len) 
{   /* 插入運算 */
     int i;
     if(location >= len) return 0;  /* 如果插入的索引位置超過陣列範圍，回傳0 */
     for(i=len-2 ; i>=location ; i--)
         ary[i+1] = ary[i];
     ary[location] = value;
     return 1;
}
int main()
{
     int i;    
     int array[7]={2,4,6,8,10,12,14};
     
     for(i=0;i<7;i++)
         printf("%d\t",array[i]);
     printf("\n");
     
     int e = insertElement(9,2,array,7);
     
     for(i=0;i<7;i++)
         printf("%d\t",array[i]);
     printf("\n");
     
     
     system("pause");
     return 0;
}

