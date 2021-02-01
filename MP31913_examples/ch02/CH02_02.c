#include <stdio.h>
#include <stdlib.h>

int main()
{
 int arr[2][2];
 int sum;
  printf("|a1 b1|\n");
  printf("|a2 b2|\n");
  printf("請輸入a1:");
  scanf("%d",&arr[0][0]);
  printf("請輸入b1:");
  scanf("%d",&arr[0][1]);
  printf("請輸入a2:");
  scanf("%d",&arr[1][0]);
  printf("請輸入b2:");
  scanf("%d",&arr[1][1]);
  sum = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];/* 求二階行列式的值 */
  printf("|%d %d|\n",arr[0][0],arr[0][1]);
  printf("|%d %d|\n",arr[1][0],arr[1][1]);
  printf("sum=%d\n",sum);
  
  system("pause");
  return 0;
 }
