// Name : Sort_sl.cpp
// 選擇排序

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class Type>
class Selection {
	private:
		Type temp;
	public:
		void select_sort(Type data[]);
		void access(Type data[], int size);
};

template <class Type>
void Selection<Type>::select_sort(Type data[])
{
	int size = 0, i;

	// 要求輸入資料直到輸入為零
	cout << "\nPlease enter number to sort ( enter 0 when end ):\n";
	cout << "Number : ";
	do {
		cin >> data[size];
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) cout << "-";
	cout << "\n";
	access(data, --size);
	for(i = 0; i < 60; i++) cout << "-";
	cout << "\nSorted: ";
	for(i = 0; i < size; i++)
		cout << data[i] << "  ";
}

template <class Type>
void Selection<Type>::access(Type data[], int size)
{
	int base, compare, min, i;

	for(base = 0; base < size-1; base++) {	
		// 將目前資料與後面資料中最小的對調
		min = base;
		for(compare = base+1; compare < size; compare++)
			if(data[compare] < data[min])
				min = compare;
        cout << "#" << base+1 << " selected data is : " << data[min] << endl;
		temp = data[min];
		data[min] = data[base];
		data[base] = temp;
		
		for(i = 0; i < size; i++)
			cout << data[i] << "  ";
		cout << endl << endl;
	}
}

int main()
{
	Selection<int> obj;
	int data[20];

	obj.select_sort(data);
	cout << endl;
	system("PAUSE");
	return 0;
} 
