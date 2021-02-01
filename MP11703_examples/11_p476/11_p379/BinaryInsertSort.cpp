#include "stdafx.h"
#include "BinaryInsertSort.h"  
#include <iostream>  

using namespace std;

BinaryInsertSort::BinaryInsertSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//2 二元插入排序
void BinaryInsertSort::binary_insert_sort()
{
	int middle;
	for (int i = 0; i<len; i++)
	{
		int insertNum = list[i];
		int left = 0;
		int right = i - 1;

		while (left <= right)                //二分法尋找插入位置
		{
			middle = (left + right) / 2;
			if (insertNum > list[middle]) left = middle + 1;
			else right = middle - 1;
		}
		for (int j = i; j>left; j--) list[j] = list[j - 1];
		list[left] = insertNum;
	}
}

void BinaryInsertSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
