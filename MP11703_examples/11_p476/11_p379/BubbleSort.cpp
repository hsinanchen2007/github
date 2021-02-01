#include "stdafx.h"
#include "BubbleSort.h"
#include <iostream>

using namespace std;

BubbleSort::BubbleSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//6 ®ðªw±Æ§Ç
void BubbleSort::bubble_sort()
{
	for (int i = 0; i<len; i++)
		for (int j = i + 1; j<len; j++)
			if (list[i] > list[j]) swap(i, j);
}

void BubbleSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void BubbleSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
