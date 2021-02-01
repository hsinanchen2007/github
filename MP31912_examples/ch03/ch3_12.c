/*  ch3_12.c   */
#include <stdio.h>
#include <stdlib.h>

int strlen(const char *Str)       /* 取得字串長度運算 */
{
     int len=0;
     while(Str[len]!='\0')
         len++;
     return len;
}

char *strcat(char *dest,const char *src)  /* 連結字串運算 */
{
     int i=0,j=0;
     char *result = (char *)malloc(strlen(src)+strlen(dest)+1);
     while(dest[i]!='\0')
     {
         result[i] = dest[i];
         i++;
     }
     while(src[j]!='\0')
     {
         result[i] = src[j];
         i++;
         j++;
     }
     result[i] = '\0';
     dest = result;
     return dest;
}
int main(){
     char *s1 = "Wel";
     char *s2 = "come";
     
     
     printf("%s\n",s1);          
     printf("%s\n",s2);
     
     s1 = strcat(s1,s2);
     
     printf("%s\n",s1);
     system("pause");
     return 0;
}

