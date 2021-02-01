#pragma once
#ifndef QUICKSORT_H  
#define QUICKSORT_H  

#include <vector>  
using namespace std;

class QuickSort
{
private:
	int len;
	vector<int> list;
public:
	QuickSort(vector<int> _list, int _len);
	void quick_sort(int, int);
	void swap(int, int);
	void out();
};

#endif  
