/*  ch1_02.c   */
#include <stdio.h>
#include <stdlib.h>

#define num 5
 
int main(void)
{
   int Scores[num]={75,53,80,60,87};
   int Sum,i,Avg;

   for(Sum=0,i=0;i<num;i++)
       Sum = Sum + Scores[i];
   Avg = Sum / num;
   printf("¥­§¡¦¨ÁZ=%d\n",Avg);
   system("pause"); 
   return 0;     
}
