#include<stdio.h>
/*加上取值運算子的函式原型宣告*/
void fun(int*, int*);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    printf("函式外:\na=%d,\tb=%d\n",a,b);
    printf("a的位址:%d, b的位址:%d\n",&a,&b);
    /*引數需加上&取址運算子*/	
	fun(&a,&b);
	printf("==========================\n");
	printf("呼叫函式後: \na=%d,\tb=%d\n",a,b);
	system("pause");
	return 0;	
}
void fun(int *a, int *b)
{
	printf("==========================\n");
 	printf("函式內:\n");
 	/*此時的*a與*b代表的是位址上的數值*/
	printf("接收引數:a=%d,\tb=%d\n",*a,*b);
	/*輸出函式內a與b的位址*/
	printf("a的位址:%d, b的位址:%d\n",a,b);
	*a=20;
	*b=30;	
	printf("變更數值後:a=%d, b=%d\n",*a,*b);
}
