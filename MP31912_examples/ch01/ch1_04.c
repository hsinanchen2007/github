/*  ch1_04.c   */
#include <stdio.h>
#include <stdlib.h>

#define num 5

int main(void)
{
   struct StuData
   {
      char id[9];
      int score;
   };
   struct StuData p[num];   
   int Sum,i,Avg;

   strcpy(p[0].id,"S9903501");  /* �Np[0]�ǥͪ��Ǹ����w���r��S9903501 */
   p[0].score = 75;             /* �Np[0]�ǥͪ����Z���w��75 */
   strcpy(p[1].id,"S9903502");  /* �Np[1]�ǥͪ��Ǹ����w���r��S9903502 */
   p[1].score = 53;             /* �Np[1]�ǥͪ����Z���w��53 */
      :
   for(Sum=0,i=0;i<num;i++)
       Sum = Sum + p[i].score;      /*  �֥[�ǥͦ��Z */
   Avg = Sum / num;
   printf("�������Z=%d\n",Avg);
   return 0;     
}
