#pragma once
#ifndef SHAKERSORT_H  
#define SHAKERSORT_H  

#include <vector>  
using namespace std;

class ShakerSort
{
private:
	int len;
	vector<int> list;
public:
	ShakerSort(vector<int> _list, int _len);
	void shaker_sort();
	void swap(int, int);
	void out();
};

#endif  
