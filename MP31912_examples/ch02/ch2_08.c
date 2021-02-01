/*  ch2_08.c   */

#include <stdio.h>
#include <stdlib.h>

int hanoi(int n,char T1,char T2,char T3)
{
   if(n<1)
       return 1;
   if(n==1)
       printf("%c��γ̤W�h�L�l���ʨ�%c���\n",T1,T3);
   else
   {
       hanoi(n-1,T1,T3,T2);
       printf("%c��γ̤W�h�L�l���ʨ�%c���\n",T1,T3);
       hanoi(n-1,T2,T1,T3);
   }
   return 0;
}

int main()
{
   hanoi(4,'A','B','C');

   system("pause");
   return 0;    
}
