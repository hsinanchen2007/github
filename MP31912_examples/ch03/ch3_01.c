/*  ch3_01.c   */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int Months[12]={0};             /*  �N�Ҧ�������l��0	*/
    int Days[31];                   /*  ���]�w�}�C���������	*/
    int Weeks[7]={3,6,2,5,8,2,1};   /*  �]�w�}�C���������	*/
    int Seasons[4][3];              /*  �G���}�C�A���|�C�T�� */
    int Incomes[2][3]={{20,15,16},
                       {10,17,12}}; /*  �ŧi�G���}�C�A�ó]�w��� */
    Months[3] = 5;                  /*  �N�ĥ|�Ӥ����]�w��5�A�]�����ޱq0�}�l  */
    Incomes[1][0] = 14;             /*  �N������10�אּ14�A�]�����ޱq0�}�l�A�åH�C���u�� */
    Days[10] = Weeks[6];            /*  �NDays[10]�����ȳ]��1  */
    for(i=0;i<31;i++)
       Days[i] = 10 * i;            /*  �v�@�]�w�}�C�����Ȭ�0,10,20,�K,300  */

       
       
       
       
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
