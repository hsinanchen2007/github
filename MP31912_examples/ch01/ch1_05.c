/*  ch1_05.c   */
#include <stdio.h>
#include <stdlib.h>

#define num 5

int ComputeAvg2(int scores[],int n)
{
  int Sum = 0, i, Avg;
  for(i=0;i<n;i++)
     Sum = Sum + scores[i];
  Avg = Sum / n;
  return Avg;
}


int main(void)
{
   int scores[]={10,20,30,40,50};              
   int Avg; 
   Avg = ComputeAvg2(scores,5);
   printf("¥­§¡¦¨ÁZ=%d\n",Avg);
   system("pause");
   return 0;     
}
