// Name : Factor_i.cpp
// Description : Factorial numbers count unsing iterative
// 利用非遞迴方式(迴圈)計算 N 階乘

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class Factor_i {
	public:
		long Factorial(long);
};

long Factor_i::Factorial(long n)
{
	long sum = 1;
	int  i;

	if ( n == 0 || n ==1)     // 當n=0或n=1時,0!=1,1!=1
		return (1);		// 故直接傳回1
	else {
		for ( i = 2; i<= n; i++ ) // sum記錄目前階乘之和
			sum *= i;	     // sum 與i相乘之和放回sum中
	}
	return (sum);
}

int main()
{
	Factor_i obj;
	char ch;
	long n;

	cout << "-----Factorial counting using Iterative-----";
	do {
		cout << "\nEnter a number(0 <= n <= 12) to count n! : ";
		cin >> n;
		if ( n < 0 || n > 12)
			cout << "Input out of range!\n";
		else
			cout << n << "! = " << obj.Factorial(n) << "\n";
		cout << "Continue (y/n)? ";
		while(cin.get(ch) && ch == '\n');
		cin.get();
		ch = toupper(ch);
	} while ( ch == 'Y');

system("PAUSE");
	return 0;
}

