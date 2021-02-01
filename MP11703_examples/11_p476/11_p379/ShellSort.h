#pragma once
#ifndef SHELLSORT_H  
#define SHELLSORT_H  

#include <vector>  
using namespace std;

class ShellSort
{
private:
	int len;
	vector<int> list;
public:
	ShellSort(vector<int> _list, int _len);
	void shell_sort();
	void out();
};

#endif  
