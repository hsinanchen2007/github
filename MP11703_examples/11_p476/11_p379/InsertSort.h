#pragma once
#ifndef INSERTSORT_H  
#define INSERTSORT_H  

#include "stdafx.h"
#include <vector>  
using namespace std;

class InsertSort
{
private:
	int len;
	vector<int> list;
public:
	InsertSort(vector<int> _list, int _len);
	void insert_sort();
	void out();
};

#endif  
