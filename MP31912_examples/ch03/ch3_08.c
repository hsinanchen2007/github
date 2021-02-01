/*  ch3_08.c   */
#include <stdio.h>
#include <stdlib.h>


int deleteElement(int location,int ary[],int len)/* 刪除運算 */
{
     int i;
     if(location >= len) return 0;  /* 如果刪除的索引位置超過陣列範圍，回傳0 */
     for(i=location ; i<len ; i++)
         ary[i] = ary[i+1];
     ary[len-1] = 0;
     return 1;
}
int main(){
     int i;
     int array[7]={2,4,6,8,10,12,14};
      
     for(i=0;i<7;i++)
         printf("%d\t",array[i]);
     printf("\n");
     
     int e = deleteElement(2,array,7);
    
     for(i=0;i<7;i++)
         printf("%d\t",array[i]);
     printf("\n");
     
     
     system("pause");
     return 0;
}
