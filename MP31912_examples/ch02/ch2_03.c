/*  ch2_03.c   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func1()
{
}

void compute()
{
   double Run_Time;
   long S,E;
   S = clock();
   func1();
   E = clock();
   Run_Time = ((double)(S-E)) / CLK_TCK;
}

void main()
{
   compute();
}

