// Name : Sort_is.cpp
// 插入排序

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class Type>
class Insertion {
	private:
		Type temp;
	public:
		void insertion_sort(Type data[]);
		void access(Type data[], int size);
};

template <class Type>
void Insertion<Type>::insertion_sort(Type data[])
{
	int size = 0, i;

	cout << "\nPlease enter number to sort ( enter 0 when end ):\n";
	cout << "Unsorted data is : ";
	do {   // 要求輸入資料直到輸入為零
		cin >> data[size];
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) cout << "-";
	cout << endl;
	access(data, --size);
	for(i = 0; i < 60; i++) cout << "-";
	cout << "\nSorted : ";
	for(i = 0; i < size; i++)
		cout << data[i] << "  ";
}

template <class Type>
void Insertion<Type>::access(Type data[], int size)
{
	int base, compare, i;
	cout << "First data is " << data[0] << endl << endl; 
	for(base = 1; base < size; base++){
	// 當資料小於第一筆，則插於前方，否則與後面資料比對找出插入位置
		temp = data[base];
		compare = base;
		cout << "Insert data is " << data[base] << endl; 
		while(compare > 0 && data[compare-1] > temp) {
 			data[compare]=data[compare-1];
 			data[compare-1]=temp;
 			compare--;
		}
		cout << "Ater #" << base << " insertion : ";
		for(i = 0; i <= base; i++)
			cout << data[i] << "  ";
		cout << endl << endl;
	}
}

int main()
{
	Insertion<int> obj;
	int data[20];

	obj.insertion_sort(data);
	cout << endl;
	system("PAUSE");
	return 0;
} 
