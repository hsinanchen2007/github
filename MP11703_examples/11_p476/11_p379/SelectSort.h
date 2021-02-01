#pragma once
#ifndef SELECTSORT_H  
#define SELCETSORT_H  

#include <vector>  
using namespace std;

class SelectSort
{
private:
	int len;
	vector<int> list;
public:
	SelectSort(vector<int> _list, int _len);
	void select_sort();
	void swap(int, int);
	void out();
};

#endif  
