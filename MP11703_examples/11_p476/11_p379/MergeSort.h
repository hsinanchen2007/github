#pragma once
#ifndef MERGESORT_H  
#define MERGESORT_H  

#include <vector>  
using namespace std;

class MergeSort
{
private:
	int len;
	vector<int> list;
	vector<int> link;
public:
	MergeSort(vector<int> _list, int _len);
	int merge_sort(int, int);
	int list_merge(int, int);
	void out();
};

#endif  
