// 04_p101.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "List.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//建立兩個連結串列listFirst, listSecond  
	List<int> listFirst;
	List<int> listSecond;

	//初始化連結串列listFirst  
	listFirst.AddTail(1);
	listFirst.AddTail(6);
	listFirst.AddTail(8);
	listFirst.AddTail(9);
	listFirst.AddTail(13);

	//初始化連結串列listSecond  
	listSecond.AddTail(0);
	listSecond.AddTail(3);
	listSecond.AddTail(4);
	listSecond.AddTail(6);
	listSecond.AddTail(11);
	listSecond.AddTail(17);

	while (listSecond.GetCount() != 0) { //當listSecond非空時持續循環  
		int indexFirst = 0;
		//每次把listSecond中的第一個數依序插入listFirst中
		//用while迴圈結構尋找插入位置
		while (listSecond.GetAt(0)>listFirst.GetAt(indexFirst)) {
			++indexFirst;
			//如果listFirst已到串列尾端，則結束本次迴圈
			if (indexFirst == listFirst.GetCount()) {
				break;
			}
		}
		if (indexFirst == listFirst.GetCount()) {//插入位置在listFirst串列尾端
			listFirst.AddTail(listSecond.GetAt(0));
			listSecond.RemoveAt(0);
		}
		else {//插入位置在listFirst串列中
			listFirst.InsertAt(indexFirst, listSecond.GetAt(0));
			listSecond.RemoveAt(0);
		}
	}

	ListNode<int> * curNode = listFirst.GetHead();
	while (curNode != listFirst.GetTail())
	{
		curNode = curNode->GetLink();
		cout << curNode->GetData() << endl;
	}

	cout << endl;
	system("PAUSE");

	return 0;
}
