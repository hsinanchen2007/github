#pragma once
#ifndef BUBBLESORT_H  
#define BUBBLESORT_H  

#include <vector>  
using namespace std;

class BubbleSort
{
private:
	int len;
	vector<int> list;
public:
	BubbleSort(vector<int> _list, int _len);
	void bubble_sort();
	void swap(int, int);
	void out();
};

#endif  
