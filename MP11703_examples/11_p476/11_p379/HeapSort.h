#pragma once
#ifndef HEAPSORT_H  
#define HEAPSORT_H  

#include <vector>  
using namespace std;

class HeapSort
{
private:
	int len;
	vector<int> list;
public:
	HeapSort(vector<int> _list, int _len);

	void heap_sort();
	void filterDown(int current, int last);
	void swap(int, int);
	void out();
};

#endif  
