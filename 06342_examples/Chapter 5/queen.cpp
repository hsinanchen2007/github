/*
	file name : queen.cpp
	Description : 利用遞迴法求出8個皇后問題之解
 */

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define TRUE 1
#define FALSE 0
#define MAXQUEEN 8
#define ABS(x) ((x>0) ?(x): -(x))  /*求x之絕對值*/

class Queen{
private:
    /*存放8個皇后之列位置,陣列註標為皇后的行位置*/
    int queen[MAXQUEEN];
    int total_solution = 0;  /*計算共有幾組解*/
public:
    /*函數原型宣告*/
    void place(int);
    int attack(int,int);
    void output_solution();
};



int main()
{
    Queen obj;
    obj.place(0);  /*從第0個皇后開始擺放至棋盤*/
    system("PAUSE");
    return 0;
}

void Queen::place(int q)
{
    int i;
    
    i = 0;
    while ( i < MAXQUEEN )
    {
        if ( !attack(i, q))  /*皇后未受攻擊*/
        {
            queen[q] = i;  /*儲存皇后所在的列位置*/
            /*判斷是否找到一組解 */
            if ( q == 7 )
                output_solution();  /*列出此組解*/
            else
                place(q+1);  /*否則繼續擺下一個皇后*/
        }
        i++;
    }
}

/* 測試在(row,col)上的皇后是否遭受攻擊
 若遭受攻擊則傳回值為1，否則傳回0 */
int Queen::attack(int row,int col)
{
    int i,atk = FALSE;
    int offset_row,offset_col;
    i = 0;
    while ( !atk && i < col )
    {
        offset_col = ABS(i - col);
        offset_row = ABS(queen[i] - row);
        /*判斷兩皇后是否在同一列,皇后是否在對角線上*/
        /*若皇后同列或在對角線上則產生攻擊,atk ==TRUE */
        atk = (queen[i] == row)||(offset_row == offset_col);
        i++;
    }
    return atk;
}

/*列出8個皇后之解*/
void Queen::output_solution()
{
    int x,y;
    total_solution+=1;
    cout << "Solution #" << setw(3) << total_solution << "\n\t";
    
    for ( x = 0; x < MAXQUEEN; x++ )
    {
        for ( y =0; y< MAXQUEEN;y++ )
            if ( x == queen[y] )
                cout << "Q";
            else
                cout << "-";
        cout << "\n\t";
    }
    cout << "\n";
}

