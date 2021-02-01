/* File name: QuickSort.cpp */
/* August, 2017 */
/* 快速排序 */

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class Type>
class Quick {
private:
    Type temp;
public:
    void quick_sort(Type data[]);
    void access(Type data[], int left, int right, int size);
};

template <class Type>
void Quick<Type>::quick_sort(Type data[])
{
    int size = 0, i;
    
    // 要求輸入資料直到輸入資料為零
    cout << "\nPlease enter number to sort ( enter 0 when end ):\n";
    cout << "Number : ";
    do {
        cin >> data[size];
    }  while(data[size++] != 0);
    for(i = 0; i < 60; i++) cout << "-";
    cout << "\n";
    access(data, 0, --size-1, size-1);
    for(i = 0; i < 60; i++) cout << "-";
    cout << "\nSorted data: ";
    for(i = 0; i < size; i++)
        cout << data[i] << "  ";
}

template <class Type>
void Quick<Type>::access(Type data[], int left, int right, int size)
{
    // left與right分別表欲排序資料兩端
    int lbase, rbase, i;
    
    if(left < right) {
        lbase = left+1;
        while(data[lbase] < data[left]) lbase++;
        rbase = right;
        while(data[rbase] > data[left]) rbase--;
        while(lbase < rbase) { // 若lbase小於rbase，則兩資料對調
            temp = data[lbase];
            data[lbase] = data[rbase];
            data[rbase] = temp;
            lbase++;
            while(data[lbase] < data[left]) lbase++;
            rbase--;
            while(data[rbase] > data[left]) rbase--;
        }
        temp = data[left];  // 此時lbase大於rbase，則rbase的資料與第一筆對調
        data[left] = data[rbase];
        data[rbase] = temp;
        cout << "Access : ";
        for(i = 0; i < size; i++)
            cout << data[i] << "  ";
        cout << "\n";
        access(data, left, rbase-1, size);
        access(data, rbase+1, right, size);
    }
}

int main()
{
    Quick<int> obj;
    int data[20];
    
    obj.quick_sort(data);
    cout << endl;
    system("PAUSE");
    return 0;
}