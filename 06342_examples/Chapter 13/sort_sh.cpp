/* file name: sort_sh.cpp*/
/* 謝耳排序 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class ShellSort {
private:
    int data[11] = {0, 75, 23, 98, 44, 57, 12, 29, 64, 38, 82};
public:
    void shell_sort();
};

void ShellSort::shell_sort()
{
    int i, j, k, incr, temp;
    cout << "\n<< Shell sort >>\n";
    cout << "\nUnsorted data : ";
    for(i = 1; i <= 10; i++)
        cout << data[i] << " ";
    puts("");
    for(i = 0; i < 60; i++) cout << "-";
    incr = 10/2;
    while(incr > 0)
    {
        for(i = incr+1; i <= 10; i++)
        {
            j = i - incr;
            while(j > 0)
                if(data[j] > data[j+incr])  /* 比較每部分的資料 */
                {	/* 大小順序不對則交換 */
                    temp = data[j];
                    data[j] = data[j+incr];
                    data[j+incr] = temp;
                    j = j - incr;
                }
                else
                    j = 0;
        }
        cout << "\nProcessing : ";
        for(k = 1; k <= 10; k++)
            cout << data[k] << " ";
        incr = incr/2;
    }
    puts("");
    for(i = 0; i < 60; i++) cout << "-";
    cout << "\nIncreasing data : ";
    for(i = 1; i <= 10; i++)
        cout << data[i] << " ";
    cout << "\n";
}

int main()
{
    ShellSort obj;
    obj.shell_sort();
    system("PAUSE");
    return 0;
}


