/*  ch1_03.c   */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   struct StuData
   {
      char id[9];
      int score;
   };
   struct StuData p1;
   strcpy(p1.id,"S9903501");  /*  �Np1�ǥͪ��Ǹ����w���r��S9903501 */
   p1.score = 75;
   system("pause"); 
   return 0;     
}
