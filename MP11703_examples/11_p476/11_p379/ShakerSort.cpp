#include "stdafx.h"
#include "ShakerSort.h"
#include <iostream>

using namespace std;

ShakerSort::ShakerSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//7 Shaker排序------------------------------------------------------------  
void ShakerSort::shaker_sort()
{

	int i, left = 0, right = len - 1, shift = 0;
	while (left < right)
	{
		for (i = left; i < right; i++)    //向右進行氣泡排序
		{
			if (list[i] > list[i + 1])
			{
				swap(i, i + 1);
				shift = i;
			}
		}
		right = shift;

		for (i = right; i > left; i--)    //向左進行氣泡排序
		{
			if (list[i] < list[i - 1])
			{
				swap(i, i - 1);
				shift = i;
			}
		}
		left = shift;
	}
}

void ShakerSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

void ShakerSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
