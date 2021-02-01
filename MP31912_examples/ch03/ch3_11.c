/*  ch3_11.c   */
#include <stdio.h>
#include <stdlib.h>

int strlen(const char *Str)       /* 取得字串長度運算 */
{
     int len=0;
     while(Str[len]!='\0')
         len++;
     return len;
}

char *strcpy(char *dest,const char *src)  /* 複製字串運算 */
{
     int i=0;
     dest = (char *)malloc(sizeof(char)*(strlen(src)+1));
     while(src[i]!='\0')
     {
         dest[i] = src[i];
         i++;
     }
     dest[i] = '\0';
     return dest;
}


int main(){
     char *s1="Welcome";
     char *s2=NULL;
     s2 = strcpy(s2,s1);
     
     printf("%s\n",s1);          
     printf("%s\n",s2);
     
     system("pause");
     return 0;
}
