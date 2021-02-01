// 06_03.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "stdio.h"
#include <vector>
#include <iostream>

using namespace std;

int binarySearch(const vector<int> & a, const int & x, int low, int high)
{
	if (low>high)
		return -1;

	int mid = (low + high) / 2;
	//二元搜尋演算法的遞迴核心部分
	if (a[mid]<x)
		return binarySearch(a, x, mid + 1, high);
	else if (x<a[mid])
		return binarySearch(a, x, low, mid - 1);
	else
		return mid;
}

int Search(const vector<int> & a, const int & x)
{
	return binarySearch(a, x, 0, a.size() - 1);
}

void main()
{
	vector<int> box;

	box.push_back(1);
	box.push_back(4);
	box.push_back(6);
	box.push_back(7);
	box.push_back(8);
	box.push_back(10);
	box.push_back(13);
	box.push_back(21);
	box.push_back(22);
	box.push_back(30);

	const int searchValue = 22;

	int result = Search(box, searchValue);

	if (result == -1)
		cout << "要查的數字不在陣列內！" << endl;
	else
		cout << searchValue << "的位置在第" << ++result << "位" << endl;

	cout << endl;
	system("PAUSE");

}

