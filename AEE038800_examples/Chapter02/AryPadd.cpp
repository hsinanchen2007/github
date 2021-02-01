/*	
File name: AryPadd.cpp
August, 2017
Description: 多項式相加實作
利用陣列表示法做多項式相加
 */
#include <iostream>
#include <iomanip>
#define DUMMY -1
using namespace std;
void outputP(int [], int );
void Padd(int [] , int [] , int [] );
char compare(int , int );

int main()
{
    /* 多項式的表示方式利用只儲存非零項法
     分別儲存每一個非零項的指數及係數，
     陣列第一元素放多項式非零項個數。
     ex: 下列A多項式有3個非零項，其多項式為 :
     5x四次方 + 3x二次方 + 2  */
    
    int A[] = { DUMMY, 3, 4, 5, 2, 3, 0, 2 };
    int B[] = { DUMMY, 3, 3, 6, 2, 2, 0, 1 };
    int C[13] = { DUMMY};
    
    Padd( A , B , C );  /*將A加B放至C */
    /*顯示各多項式結果*/
    cout << "A = ";
    outputP(A, A[1]*2 +1);  /*A[1]*2 + 1為陣列A的大小*/
    cout << "\nB = ";
    outputP(B, B[1]*2 +1);
    cout << "\nC = ";
    outputP(C, C[1]*2 +1);
    cout << "\n";
    return 0;
}

/*此為之前所解說第二種方法的多項式相加函數*/
void Padd(int a[] , int b[], int c[])
{
    int p, q, r, m, n;
    char result;
    
    m = a[1]; n = b[1];
    p = q = r = 2;
    while ( (p <= 2*m) && (q <= 2*n) ){
        /*比較a與b的指數*/
        result = compare ( a[p], b[q] );
        switch ( result ){
            case '=' :           /* a的指數等於b的指數 */
                c[r+1] = a[p+1] + b[q+1];  /*係數相加*/
                if ( c[r+1] != 0 ){
                    c[r] = a[p];  /*指數assign給c */
                    r+=2;
                }
                p+=2; q+=2;  /*移至下一個指數位置*/
                break;
            case '>' :      /* a的指數大於b的指數 */
                c[r+1] = a[p+1];
                c[r] = a[p];
                p+=2; r+= 2;
                break;
            case '<' :      /* a的指數小於b的指數 */
                c[r+1] = b[q+1];
                c[r] = b[q];
                q+=2; r+= 2;
                break;
        }
    }
    while ( p <= 2*m ){  /*將多項式a的餘項全部移至c */
        c[r+1] = a[p+1];
        c[r] = a[p];
        p+=2;  r+=2;
    }
    while ( q <= 2*n ){  /*將多項式b的餘項全部移至c */
        c[r+1] = b[q+1];
        c[r] = b[q];
        q+=2; r+=2;
    }
    c[1] = r/2 - 1;  /*計算c總共有多少非零項*/
}

char compare( int x, int y)
{
    if ( x == y )
        return '=';
    else if ( x > y )
        return '>';
    else
        return '<';
}

void outputP(int p[], int n)
{
    int i;
    
    cout << "(";
    for ( i = 1; i <= n; i++ )
        cout << setw(3) << p[i];
    cout << "  )";
}
