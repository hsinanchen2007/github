/*  ch3_13.c   */
#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1,const char *s2)  /* ����r��B�� */
{
     int i;
     for(i=0;s1[i]==s2[i];i++)
     {
         if(s1[i]=='\0')
             return 0;
     }
     if(s1[i]>s2[i])
        return 1;
     else
        return -1;
}
int main(){
     char *s1 = "Welcome";
     char *s2 = "Data";
     int r = strcmp(s1,s2);
     
     if(r>0) printf("s1��s2�j");
     else if(r<0) printf("s1��s2�p");
     else if(r==0) printf("s1=s2");
     
     system("pause");
     return 0;
}

