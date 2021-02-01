/*  ch2_04.c   */
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
    S = time(NULL);
    func1();
    E = time(NULL);
    Run_Time = difftime(S,E);
}


void main()
{
   compute();
}

