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

   strcpy(p[0].id,"S9903501");  /* 將p[0]學生的學號指定為字串S9903501 */
   p[0].score = 75;             /* 將p[0]學生的成績指定為75 */
   strcpy(p[1].id,"S9903502");  /* 將p[1]學生的學號指定為字串S9903502 */
   p[1].score = 53;             /* 將p[1]學生的成績指定為53 */
      :
   for(Sum=0,i=0;i<num;i++)
       Sum = Sum + p[i].score;      /*  累加學生成績 */
   Avg = Sum / num;
   printf("平均成績=%d\n",Avg);
   return 0;     
}
