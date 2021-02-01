/*  ch2_05.c   */
#include <stdio.h>
#include <stdlib.h>

void compute()
{
  int i,counter,Sum=0;
  
  for(i=0,counter=0;i<100;i++)
  {
       Sum = Sum + i;       /*   這是準備被量測的步驟    */
       counter++;
  }     
  printf("%d",counter);
}


int main()
{
   compute();

   system("pause");
   return 0;  
}

