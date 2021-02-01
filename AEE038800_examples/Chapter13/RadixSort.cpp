/* File name: RadixSort.cpp */
/* August, 2017 */
/* 基數排序 */

#include <iostream>
using namespace std;

int main()
{
    int data[10] = {83, 57, 32, 22, 77, 12, 10, 64, 3, 92};
    int i, j, k = 0, n = 1, lsd, temp[10][10];
    int order[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    cout << "\n<< Radix sort >>\n";
    cout << "\nNumber : ";
    for(i = 0; i < 10; i++)
        cout << data[i] << "  ";
    puts("");
    for(i = 0; i < 60; i++) cout << "-";
    while(n <= 10){
        for(i = 0; i < 10; i++){
            lsd = ((data[i]/n) % 10);
            temp[lsd][order[lsd]] = data[i];  /* 依餘數將資料分類 */
            order[lsd]++;
        }
        cout << "\nAccess : ";
        for(i = 0; i < 10; i++){
            if(order[i] != 0)
            /* 依分類後的順序將資料重新排列 */
                for(j = 0; j < order[i]; j++){
                    data[k] = temp[i][j];
                    cout << data[k] << "  ";
                    k++;
                }
            order[i] = 0;
        }
        n *= 10;
        k = 0;
    }
    puts("");
    for(i = 0; i < 60; i++) printf("-");
    cout << "\nSorting: ";
    for(i = 0; i < 10; i++)
        cout << data[i] << "  ";
    cout << "\n";
    return 0;
}