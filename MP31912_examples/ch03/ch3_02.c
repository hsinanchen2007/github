/*  ch3_02.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i;
   int Months[12] = {0};   /*  �N�}�C���Ҧ�������l��0	*/
   int *ptr1 = Months;     /*  ptr1���Цs��}�C���_�l��}	*/
   int a = 10;
   int *ptr2 = &a;         /*  ptr2���Цs��a���O�����}	*/

   Months[6] = 100;        /*  �ק�Months[6]����ƭ�	*/
   *(Months+3) = 200;      /*  �ק�Months[3]����ƭ�	*/

   /* Months = ptr2;   */
   ptr2 = Months;

   *(ptr2+4) = 300;        /*  �ק�Months[4]����ƭ�	*/
   ptr2[7] = 400;          /*  �ק�Months[7]����ƭ�	*/
       
       
       
       
    for(i=0;i<12;i++)
      printf("%d\t",Months[i]);
    system("pause");
    return 0; 

}
