#include "stdafx.h"
#include "InsertSort.h"
#include <iostream>

using namespace std;

InsertSort::InsertSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//1 直接插入排序
void InsertSort::insert_sort()
{
	int insertNum;
	for (int i = 0; i<len; i++)
	{
		insertNum = list[i];	//待插入元素
		int j = i;
		while (j>0 && insertNum<list[j - 1])	//尋找插入位置
		{
			list[j] = list[j - 1];
			j--;
		}
		list[j] = insertNum;
	}
}

void InsertSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
