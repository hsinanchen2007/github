#include "stdafx.h"
#include "ShellSort.h"  
#include <iostream>  

using namespace std;

ShellSort::ShellSort(vector<int> _list, int _len)
{
	for (int i = 0; i<_len; i++) list.push_back(_list[i]);
	this->len = _len;
}

//3 希爾排序------------------------------------------------------------
void ShellSort::shell_sort()
{
	int insertNum;
	int gap = len / 2;						//初始增量
	while (gap)                             //當gap>=1
	{
		for (int i = gap; i<len; i++)       //對gap間隔子序列進行插入排序
		{
			insertNum = list[i];            //待插入元素
			int j = i;
			while (j >= gap && insertNum<list[j - gap])
			{                               //尋找插入位置
				list[j] = list[j - gap];
				j -= gap;
			}
			list[j] = insertNum;            //插入
		}

		gap = gap / 2;                      //縮小增量
	}

}

void ShellSort::out()
{
	for (int i = 0; i<len; i++)
	{
		cout << list[i] << " ";
		if ((i + 1) % 18 == 0) cout << endl;
	}
	cout << endl;
}
