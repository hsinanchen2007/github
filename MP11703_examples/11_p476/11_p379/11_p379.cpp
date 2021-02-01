// 11_p379.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include "InsertSort.h"  
#include "BinaryInsertSort.h"  
#include "ShellSort.h"  
#include "SelectSort.h"  
#include "BubbleSort.h"  
#include "HeapSort.h"  
#include "ShakerSort.h"  
#include "QuickSort.h"  
#include "MergeSort.h"  
#include "CountingSort.h"  

#define MAX 1000  

using namespace std;

int main()
{
	//讀取無序表-----------------------------
	vector<int> list;
	int len, inp;
	cout << "請輸入序列個數(0退出)：";
	cin >> len;
	if (len == 0) exit(0);
	cout << "請輸入待排序列：";
	for (int i = 0; i<len; i++)
	{
		cin >> inp;
		list.push_back(inp);
	}

	//以下是十種常用快速排序----------------
	//1. 直接插入排序
	//2. 二元插入排序
	//3. 希爾排序
	//4. 直接選擇排序
	//5. 堆排序
	//6. 氣泡排序
	//7. Shaker排序
	//8. 快速排序
	//9. 合併排序
	//10.計數排序
	InsertSort sort1(list, len);
	sort1.insert_sort();
	sort1.out();

	BinaryInsertSort sort2(list, len);
	sort2.binary_insert_sort();
	sort2.out();

	ShellSort sort3(list, len);
	sort3.shell_sort();
	sort3.out();

	SelectSort sort4(list, len);
	sort4.select_sort();
	sort4.out();

	HeapSort sort5(list, len);
	sort5.heap_sort();
	sort5.out();

	BubbleSort sort6(list, len);
	sort6.bubble_sort();
	sort6.out();

	ShakerSort sort7(list, len);
	sort7.shaker_sort();
	sort7.out();

	QuickSort sort8(list, len);
	sort8.quick_sort(0, len - 1);
	sort8.out();

	MergeSort sort9(list, len);
	sort9.merge_sort(1, len);
	sort9.out();

	CountingSort sort10(list, len, MAX); //MAX為使用者提供的無序表最大範圍
	sort10.counting_sort();
	sort10.out();

	cout << endl << endl;
	system("PAUSE");
}
