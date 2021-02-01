/* File name: Hanoi.cpp */
/* August, 2017 */
/* Description: 利用遞迴方式玩河內塔遊戲 */

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class Hanoi {
public:
    void HanoiTower(int ,char,char,char);
};

//利用遞迴方式玩河內塔遊戲
void Hanoi::HanoiTower(int n,char a,char b,char c)
{
    if ( n == 1 )
        cout << "Move disk 1 from " << a << " -> " << c << "\n";
    else {
        // 將A上n-1個盤子借助C移至B
        HanoiTower(n-1,a,c,b);
        cout << "Move disk " << n << " from " << a << " -> " << c << "\n";
        // 將B上n-1個盤子借助A移至C
        HanoiTower(n-1,b,a,c);
    }
}


int main()
{
    Hanoi obj;
    int n;
    
    char A = 'A' , B = 'B' , C = 'C';
    cout << "-----Hanoi Tower Implementaion----\n";
    // 輸入共有幾個盤子在A柱子中
    cout << "How many disks in A ? ";
    cin >> n;
    if ( n == 0 )
        cout << "no disk to move\n";
    else
        obj.HanoiTower(n,A,B,C);
    system("PAUSE");
    return 0;
}