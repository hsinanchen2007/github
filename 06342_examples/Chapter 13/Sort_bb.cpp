// Name : Sort_bb.cpp
// 泡沫排序

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class Type>
class Bubble {
	private:
		Type temp;
	public:
		void bubble_sort(Type data[]);
		void access(Type data[], int size);
};

template <class Type>
void Bubble<Type>::bubble_sort(Type data[])
{
	int size = 0, i;

	cout << "\nPlease enter number to sort ( enter 0 when end ):\n";
	cout << "Number : ";
	do {   // 要求輸入數字直到輸入數字為零
		cin >> data[size];
	}  while(data[size++] != 0);
	for(i = 0; i < 60; i++) cout << "-";
	cout << "\n";
	access(data, --size);  // --size用於將資料為零者排除
	for(i = 0; i < 60; i++) cout << "-";
	cout << "\nSorted : ";
	for(i = 0; i < size; i++)
		cout << data[i] << "  ";
}

template <class Type>
void Bubble<Type>::access(Type data[], int size)
{
	int i, j, k, temp, flag;

	for(i = 0; i < size-1; i++) {
		flag = 0;
		/*印出第幾次的 Pass */ 
		cout << "#" << i+1 << " pass : " << endl;
		
		for(j = 0; j < size-i-1; j++) {
			// 當某一筆資料大於其下一筆資料時，將兩資料對調
			if(data[j] > data[j+1]) {
				flag = 1;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			/* 印出每一次的 compare */ 
			cout << "   #" << j+1 << " compare : ";
			/* 每一次的 compare 資料量會減 1，故以在迴圈中以size-i為結束點 */ 
			for (k=0; k < size-i; k++)
			  cout << data[k] << " ";
	        cout << endl;
		}
		/*印出每一次的 Pass 的最後的資料 */ 
		cout << "#" << i+1 << " pass finished : ";
		for(k = 0; k < size; k++)
			cout << data[k] << "  ";
		cout << endl << endl;
		if(flag != 1)
			break;
	}
}

int main()
{
	Bubble<int> obj;
	int data[20];

	obj.bubble_sort(data);
      printf("\n");
	system("PAUSE");
	return 0;
}
