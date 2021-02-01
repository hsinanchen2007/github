/*
[示範]:用遞迴函數求 0-4 階層的值
*/
#include <iostream>
using namespace std;
int recursive(int);  //函數原型
int main(void)
{  
	for (int i=0;i<5;i++)
		cout<<i<<" 階層值為 "<<recursive(i)<<endl;   
    return 0;
}
int recursive(int i)
{  
	int sum;
	if(i == 0) //遞迴終止的條件
		return(1);
	else
		sum = i * recursive(i-1); //sum=n*(n-1)!所以直接呼叫本身
	return sum;
}
