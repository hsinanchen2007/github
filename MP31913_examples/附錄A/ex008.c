#include<stdio.h>
int main(void)
{
  int number;
  int sum=0;
  /*do while迴圈開始*/ 
  do
  {
    printf("數字0為結束程式,請輸入數字: ");
    scanf("%d",&number);
    sum+=number;
    printf("目前累加的結果為: %d\n",sum);
  }while(number!=0);/*do while迴圈結束*/
  system("pause");
  return 0;
} 
