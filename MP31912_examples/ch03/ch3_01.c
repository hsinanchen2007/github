/*  ch3_01.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int Months[12]={0};             /*  將所有元素初始為0	*/
    int Days[31];                   /*  未設定陣列元素的初值	*/
    int Weeks[7]={3,6,2,5,8,2,1};   /*  設定陣列元素的初值	*/
    int Seasons[4][3];              /*  二維陣列，有四列三行 */
    int Incomes[2][3]={{20,15,16},
                       {10,17,12}}; /*  宣告二維陣列，並設定初值 */
    Months[3] = 5;                  /*  將第四個元素設定為5，因為索引從0開始  */
    Incomes[1][0] = 14;             /*  將元素值10改為14，因為索引從0開始，並以列為優先 */
    Days[10] = Weeks[6];            /*  將Days[10]元素值設為1  */
    for(i=0;i<31;i++)
       Days[i] = 10 * i;            /*  逐一設定陣列元素值為0,10,20,…,300  */

       
       
       
       
    for(i=0;i<12;i++)
      printf("%d\t",Months[i]);
    printf("\n--------\n");
    for(i=0;i<31;i++)
      printf("%d\t",Days[i]);
    printf("\n--------\n");
    for(i=0;i<7;i++)
      printf("%d\t",Weeks[i]);
    printf("\n--------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
           printf("%d\t",Seasons[i][j]);
        printf("\n");
    }
    printf("--------\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
           printf("%d\t",Incomes[i][j]);
        printf("\n");
    }  
    system("pause");
    return 0; 

}
