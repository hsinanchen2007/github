/*  ch1_01.c   */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int Sum,n,i;
   n = 100;
   for(Sum=0,i=1;i<=n;i++)
       Sum = Sum + i;
   printf("1+2+...+100=%d\n",Sum);
   system("pause"); 
   return 0;       
}
