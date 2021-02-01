/*  ch2_06.c   */
#include <stdio.h>
#include <stdlib.h>

int FAC(int n)
{
    if(n<0)
         return -1;
    if(n==0)
         return 1;
    return n * FAC(n-1);
}


void main()
{
   int r=FAC(10);
}
