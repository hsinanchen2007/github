/*  ch3_03.c   */
#include <stdio.h>
#include <stdlib.h>

void func1(int *p,int len);           /*  �禡�ŧi  */
int main()
{
     int i;
     int Ary[3]={2,5,8};
     
     for(i=0;i<3;i++)
        printf("%d\t",Ary[i]);
     printf("\n");
     
     func1(Ary,3);
     
     for(i=0;i<3;i++)
        printf("%d\t",Ary[i]);
     printf("\n");
     
     system("pause");
     return 0;
}
void func1(int *p,int len)   /*  �i��g�� void func1(int p[],int len)  */
{
     int i;


     for(i=0;i<len;i++)
        p[i] = p[i] - 1;        /*   �i��g�� *(p+i) = *(p+i) - 1;  */

}

    
    
