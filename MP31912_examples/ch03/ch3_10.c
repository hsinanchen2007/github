/*  ch3_10.c   */
#include <stdio.h>
#include <stdlib.h>

int strlen(const char *Str)       /* ���o�r����׹B�� */
{
     int len=0;
     while(Str[len]!='\0')
         len++;
     return len;
}
int main(){
     char s1[]="Welcome";
     int length = strlen(s1);

     printf("%s\n",s1);
     printf("%d\n",length);
     
     system("pause");
     return 0;
}
