/* File name: FibIterative.cpp */
/* August, 2017 */
/* 利用非遞迴方式(迴圈)計算費氏數列 */
/*
 費氏數列為0,1,1,2,3,5,8,13,21,…；其中某一項為前二項之和,且第0項為0,第1項為1
*/

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class Fib_i {
public:
    long Fibonacci(long);
};

long Fib_i::Fibonacci(long n)
{
    long backitem1;    // 前一項的值
    long backitem2;    // 前二項的值
    long thisitem;     // 目前項數的值
    long i;
    
    if (n == 0)        // 費氏數列第0項為0
        return (0);
    else if (n == 1)   // 第二項為1
        return (1);
    else {
        backitem2 = 0;
        backitem1 = 1;
        // 利用迴圈將前二項相加後放入目前項
        // 之後改變前二項的值
        for ( i = 2; i <= n; i++ ) {
            // F(i) = F(i-1) + F(i-2)
            thisitem = backitem1 + backitem2;
            // 改變前二項之值
            backitem2 = backitem1;
            backitem1 = thisitem;
        }
        return (thisitem);
    }
}

int main()
{
    Fib_i obj;
    char ch;
    long n;
    
    cout << "-----Fibonacci numbers Using Iterative-----";
    do {
        cout << "\nEnter a number(n>=0) : ";
        cin >> n;
        // n 值大於 0
        if ( n < 0 )
            cout << "Input number must be > 0!\n";
        else
            cout << "Fibonacci(" << n << ") = "
            << obj.Fibonacci(n) << "\n";
        cout << "Continue (y/n) ? ";
        while(cin.get(ch) && ch == '\n');
        cin.get();
        ch = toupper(ch);
    }  while (  ch == 'Y');
    
    system("PAUSE");
    return 0;
}