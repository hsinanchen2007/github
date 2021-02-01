#include "stdafx.h"
#include "CountingSort.h"
#include <iostream>

using namespace std;

CountingSort::CountingSort(vector<int> _list, int _len, int _max)
{
	this->max = _max;
	this->len = _len;

	for (int i = 0; i<_len; i++)
	{
		list.push_back(_list[i]);
		result.push_back(0);
		if (_list[i] > max)
		{
			cout << "資料超出範圍！" << endl;
			return;
		}
	}

}

//10 計數排序
void CountingSort::counting_sort()
{

	int* mark = new int[max];               //標記無序表中元素
	memset(mark, 0, max * sizeof(int));
	for (int i = 0; i < len; i++) mark[list[i]]++;
	//統計元素出現次數
	for (int i = 1; i < max; i++) mark[i] += mark[i - 1];
	//計算元素在有序表中位置
	for (int i = len - 1; i >= 0; i--)
	{
		//透過mark[]直接將list[i]有序地存入result[]
		result[mark[list[i]] - 1] = list[i];
		mark[list[i]]--;
	}
	delete[]mark;
}

void CountingSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << result[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
