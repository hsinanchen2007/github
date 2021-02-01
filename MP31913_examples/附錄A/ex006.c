#include<stdio.h>
int main(void)
{
  int sum=0;
  int number;
  int i; /*宣告迴圈控制變數i*/
  printf("請輸入整數: ");
  scanf("%d",&number);
  /*遞增for迴圈,由小到大印出數字 */
  printf("\n由小到大排列輸出數字:\n");  
  for(i=1;i<=number; i++)
  {
    sum+=i; //設定sum為i的和 
    printf("%d",i);
    /*設定輸出連加的算式 */
    if(i<number)printf("+");
    else printf("=");
  }
  printf("%d\n",sum);
  sum=0;
  /*遞減for迴圈,由大到小印出數字 */
  printf("\n由大到小排列輸出數字:\n");
  for(i=number;i>=1; i--)
  {
    sum+=i; 
    printf("%d",i);
    if(i<=1)printf("=");
    else printf("+");
  }
  printf("%d\n",sum);
  system("pause");
  return 0;
} 
