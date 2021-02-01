/* File name: Fib.cpp */
/* August, 2017 */
/* 利用遞迴方式求費氏數列 */
/*
 費氏數列為0,1,1,2,3,5,8,12,21,…
 其中某一項為前二項之和,且第0項為0,第1項為1
*/

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class Fib {
public:
    long Fibonacci(long);
};

//利用遞迴方式求費氏數列
long Fib::Fibonacci(long n)
{
    if ( n == 0)       // 第0項為 0
        return (0);
    else if ( n == 1 ) // 第1項為 1
        return (1);
    else   // 遞迴呼叫函數 第N項為第n-1 與第n-2項之和
        return( Fibonacci(n-1) + Fibonacci(n-2) );
}

int main()
{
    Fib obj;
    char ch;
    long n;
    
    cout << "-----Fibonacii numbers Using Recursive-----";
    do {
        cout << "\nEnter a number(n>=0) : ";
        cin >> n;
        // n值大於0
        if ( n < 0 )
            cout << "Number must be > 0\n";
        else
            cout << "Fibonacci(" << n << ") = " << obj.Fibonacci(n) << "\n";
        cout << "Contiune (y/n) ? ";
        while(cin.get(ch) && ch == '\n')
            ;
        cin.get();
        ch = toupper(ch);
    } while ( ch == 'Y' );
    
    system("PAUSE");
    return 0;
}