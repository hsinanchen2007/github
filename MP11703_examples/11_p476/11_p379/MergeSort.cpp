#include "stdafx.h"
#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(vector<int> _list, int _len)
{
	list.push_back(0);
	link.push_back(0);
	for (int i = 0; i<_len; i++) {
		list.push_back(_list[i]);
		link.push_back(0);
	}
	this->len = _len;
}

//9 合併排序：遞迴-----------------------------------------------------------
//具體方法：以merger_link[]提供串列功能。merger_link[i]對應到有序子序列中
//merger_list[i]後一個節點在原merger_list[]中的標標；
//merger_link[0]總是表示有序子序列開始的節點在merge_list[]中的下標；
//st1,st2為兩個有序序列的第一個節點；
//將其合併後，並返回第一個節點的下標，亦即merger_link[0]

int MergeSort::list_merge(int st1, int st2)
{
	int k = 0, i = st1, j = st2;
	while (i && j)                  //未檢測完兩序列時
		if (list[i] <= list[j])		//將merge_list[i]和merge_list[j]中
		{                           //小的連接到merger_link[k]後
			link[k] = i;
			k = i;
			i = link[i];
		}
		else
		{
			link[k] = j;
			k = j;
			j = link[j];
		}
	if (!i) link[k] = j;            //將剩餘未檢測完的merge_list[]
	else link[k] = i;               //連接到merger_link[k]後
	return link[0];
}

int MergeSort::merge_sort(int left, int right)
{
	if (left >= right) return left;
	int middle = (left + right) / 2;
	//對左右兩子序列進行合併
	return list_merge(merge_sort(left, middle), merge_sort(middle + 1, right));
}

void MergeSort::out()
{
	int i = link[0];
	int j = 0;
	while (i)
	{
		j++;
		cout << list[i] << " ";
		i = link[i];
		if (j % 18 == 0) cout << endl;
	}
	cout << endl;
}
