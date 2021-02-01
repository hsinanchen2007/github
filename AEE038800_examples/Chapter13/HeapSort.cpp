/* Name: HeapSort.cpp */
/* August, 2017 */
/* 堆積排序 */

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class Type>
class Heap {
private:
    Type temp;
public:
    void heap_sort(Type data[]);
    void adjust(Type data[], int i, int n);
};

template <class Type>
void Heap<Type>::heap_sort(Type data[])
{
    int i, k;
    
    cout << "\n<< Heap sort >>\n";
    cout << "\nNumber : ";
    for(k = 1; k <= 10; k++)
        cout << data[k] << "  ";
    cout << "\n";
    for(k = 0; k < 60; k++) cout << "-";
    for(i = 10/2; i > 0; i--)
        adjust(data, i, 10);
    cout << "\nHeap   : ";
    for(k = 1; k <= 10; k++)
        cout << data[k] << "  ";
    for(i = 9; i > 0; i--) {
        temp = data[i+1];
        data[i+1] = data[1];
        data[1] = temp;    // 將樹根和最後的節點交換
        adjust(data, 1, i);  // 再重新調整為堆積樹
        cout << "\nAccess : ";
        for(k = 1; k <= 10; k++)
            cout << data[k] << "  ";
    }
    cout << "\n";
    for(k = 0; k < 60; k++) cout << "-";
    cout << "\nSorted: ";
    for(k = 1; k <= 10; k++)
        cout << data[k] << "  ";
}

template <class Type>
void Heap<Type>::adjust(Type data[], int i, int n)  // 將資料調整為堆積樹
{
    int j, k, done = 0;
    
    k = data[i];
    j = 2*i;
    while((j <= n) && (done == 0)) {
        if((j < n) && (data[j] < data[j+1])) j++;
        if(k >= data[j])
            done = 1;
        else {
            data[j/2] = data[j];
            j *= 2;
        }
    }
    data[j/2] = k;
}

int main()
{
    Heap<int> obj;
    int data[11] = {0, 5, 67, 93, 33, 57, 52, 29, 64, 71, 12};
    
    obj.heap_sort(data);
    cout << endl;
    system("PAUSE");
    return 0;
}