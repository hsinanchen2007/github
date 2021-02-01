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
   strcpy(p1.id,"S9903501");  /*  將p1學生的學號指定為字串S9903501 */
   p1.score = 75;
   system("pause"); 
   return 0;     
}
