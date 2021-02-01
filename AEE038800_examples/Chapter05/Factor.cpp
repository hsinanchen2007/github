/* File name: Factor.cpp */
/* August, 2017 */
/* Description : 以遞迴方式計算 N 階乘 */

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class Factor {
public:
    long Factorial(long);
};

// 遞迴方式計算N 階乘
long Factor::Factorial(long n)
{
    if ( n == 1 || n== 0)
        return (1);
    else
        return( n * Factorial(n-1));
}

int main()
{
    Factor obj;
    char ch;
    long n;
    
    cout << "-----Factorial counting Using Recursive----";
    do {
        cout << "\nEnter a number( 0 <= n <= 12 ) to count n!: ";
        cin >> n;
        // n 值在一般系統中超過13會產生overflow 得到不正確的值
        if ( n < 0 || n >12 )
            cout << "input out of range !\n";
        else
            cout << n << "! = " << obj.Factorial(n) << "\n";
        
        cout << "Continue (y/n) ? ";
        while(cin.get(ch) && ch == '\n');
        cin.get();
        ch = toupper(ch);
    } while (ch == 'Y' );
    system("PAUSE");
    return 0;
}