#include <stdio.h>
#include <stdlib.h>

int fib(int);			/* fib()函數的原型宣告 */

int main()
{
   int i,n;
   printf("請輸入所要計算第幾個費式數列:");
   scanf("%d",&n); 
   for(i=0;i<=n;i++)			/* 計算前1n個費氏數列 */
      printf("fib(%d)=%d\n",i,fib(i));		

   system("pause");
   return 0;
}

int fib(int n) 		/* 定義函數fib()*/
{
    	
   if (n==0)
      return 0; /* 如果n=0 則傳回 0*/ 
   else if(n==1 || n==2)	/* 如果n=1或n=2，則傳回1 */
      return 1;
   else				/* 否則傳回 fib(n-1)+fib(n-2) */
      return (fib(n-1)+fib(n-2));
}

