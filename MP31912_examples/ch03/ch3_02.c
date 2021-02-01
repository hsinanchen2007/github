/*  ch3_02.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i;
   int Months[12] = {0};   /*  將陣列的所有元素初始為0	*/
   int *ptr1 = Months;     /*  ptr1指標存放陣列的起始位址	*/
   int a = 10;
   int *ptr2 = &a;         /*  ptr2指標存放a的記憶體位址	*/

   Months[6] = 100;        /*  修改Months[6]的資料值	*/
   *(Months+3) = 200;      /*  修改Months[3]的資料值	*/

   /* Months = ptr2;   */
   ptr2 = Months;

   *(ptr2+4) = 300;        /*  修改Months[4]的資料值	*/
   ptr2[7] = 400;          /*  修改Months[7]的資料值	*/
       
       
       
       
    for(i=0;i<12;i++)
      printf("%d\t",Months[i]);
    system("pause");
    return 0; 

}
