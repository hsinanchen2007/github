/*  ch3_09.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "Welcome";                   /* s1���}�C�r��  */
    char *s2 = "Welcome";                    /* s2�����Цr��  */
    char *s3 = (char *)malloc(sizeof(char)); /* s3�����Цr��  */
    char *s4 = "Good morning";               /* s4�����Цr��  */
 /* s1 = s4;  */
    s2 = s4;
    s3 = s1;
    
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",s3);
    printf("%s\n",s4);
     
     system("pause");
     return 0;
}
