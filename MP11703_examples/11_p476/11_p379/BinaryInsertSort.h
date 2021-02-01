#pragma once
#ifndef BINARYINSERTSORT_H  
#define BINARYINSERTSORT_H  

#include <vector>  
using namespace std;

class BinaryInsertSort
{
private:
	int len;
	vector<int> list;
public:
	BinaryInsertSort(vector<int> _list, int _len);
	void binary_insert_sort();
	void out();
};

#endif  
