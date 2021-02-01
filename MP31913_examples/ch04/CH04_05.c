/*用遞迴函數求 n階乘的值*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int);  /*函數原型*/
int main()
{  
    int i,n;
    
    printf("請輸入階乘數:"); 
    scanf("%d",&n);
    
    for (i=0;i<=n;i++)
     printf("%d !值為 %3d\n", i,factorial(i));
    
    system("pause");
    return 0;
}

int factorial(int i)
{  
    int sum;
     if(i == 0)/* 遞迴終止的條件 */
      return(1);
     else
     sum = i * factorial(i-1); /* sum=n*(n-1)!所以直接呼叫本身 */
     return sum;
}
