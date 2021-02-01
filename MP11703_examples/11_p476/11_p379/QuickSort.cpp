#include "stdafx.h"
#include "QuickSort.h"
#include <iostream>

using namespace std;

QuickSort::QuickSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//8 快速排序------------------------------------------------------------
void QuickSort::quick_sort(int left, int right)
{
	int i = left;
	int j = right;
	int pivot = list[left];

	while (i<j)
	{
		while (i<j && list[j] >= pivot) j--; //找到比基數小的元素
		if (i < j) swap(i, j);
		while (i<j && list[i] <= pivot) i++; //找到比基數大的元素
		if (i < j) swap(i, j);
	}

	if (i != left) quick_sort(left, i - 1);    //對list[left...i-1]排序
	if (j != right) quick_sort(j + 1, right);  //對list[j+1...right]排序
}

void QuickSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void QuickSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
