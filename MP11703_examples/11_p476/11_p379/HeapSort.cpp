#include "stdafx.h"
#include "HeapSort.h"
#include <iostream>

using namespace std;

HeapSort::HeapSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}
// 堆排序
void HeapSort::heap_sort()
{
	for (int i = (len - 2) / 2; i >= 0; i--) filterDown(i, len - 1);//建立堆

	for (int i = len - 1; i>0; i--)
	{
		swap(0, i);
		filterDown(0, i - 1);			//不斷調整堆為最大堆
	}

}
// 堆的建立或調整
void HeapSort::filterDown(int current, int last)
{
	int child = 2 * current + 1;		//child為current的孩子位置
	int temp = list[current];           //暫存子樹根節點
	while (child <= last)               //判斷是否到最後結尾
	{
		if (child<last && list[child]<list[child + 1]) child++;
		//將child指向兩孩子中的大者
		if (temp >= list[child]) break; //temp的關鍵碼大則不做調整
		else                             //否則孩子中的大者上移
		{
			list[current] = list[child];
			current = child;
			child = 2 * child + 1;
		}
	}
	list[current] = temp;               //temp中暫存元素放到合適位置
}

void HeapSort::swap(int i, int j)
{
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}


void HeapSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
