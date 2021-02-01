/*  ch2_07.c   */
#include <stdio.h>
#include <stdlib.h>

int counter;

int FAC(int n)
{
     counter++;
     if(n<0)
     {
         counter++;  /* 代表return敘述 */
         return -1;
     }
     counter++; 
     if(n==0)
     {
        counter++;  /* 代表return敘述 */
        return 1;
     }
     counter++;       /* 代表return敘述 */
     return n * FAC(n-1);
}


int main()
{
   int r=FAC(10);
   printf("%d",counter);
   system("pause");
   return 0;    
}
