#include<stdio.h>
/*函式原型宣告*/
void fun(int, int);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    /*輸出主程式中的a,b值與位址*/
    printf("函式外:\na=%d,\tb=%d\n",a,b);
    printf("a的位址:%d, b的位址:%d\n",&a,&b);	
	/*呼叫函式*/
    fun(a,b);
    /*分隔用*/
	printf("==========================\n");
 	/*輸出呼叫函式後的a,b值*/
  	printf("呼叫函式後: \na=%d,\tb=%d\n",a,b);
  	system("pause");
 	return 0;	
}
void fun(int a, int b)
{
	printf("==========================\n");
 	printf("函式內:\n");
 	printf("接收引數:a=%d, b=%d\n",a,b);
 	printf("a的位址:%d, b的位址:%d\n",&a,&b);
 	/*重設函式內的a,b值*/
	a=20;
	b=30;
	printf("變更數值後:a=%d, b=%d\n",a,b);
}
