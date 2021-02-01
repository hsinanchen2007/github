// 05_p144.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "LinkQueue.h"  
#include <iostream>  

using namespace std;

template<class T>
void evaluate(LinkQueue<T>& ori, LinkQueue<T>& target) {
	ori.MakeEmpty();
	while (!target.IsEmpty()) {
		int tmp_value = target.DelQueue();
		ori.EnQueue(tmp_value);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "請輸入楊輝三角的階數i (i>2)：";
	int num;
	cin >> num;
	LinkQueue<int> ori;

	int ini_value = 1;
	ori.EnQueue(ini_value);
	ori.EnQueue(ini_value);
	LinkQueue<int> next;
	for (int i = 0; i<num - 2; i++) {
		next.EnQueue(ini_value);
		while (!ori.IsEmpty()) {
			int i = ori.DelQueue();
			if (!ori.IsEmpty())
			{
				int tmp = i + ori.GetFront();
				next.EnQueue(tmp);
			}
			if (ori.IsEmpty())
				next.EnQueue(i);
		}
		evaluate(ori, next);
	}
	cout << "楊輝三角第" << num << "列的內容如下：" << endl;
	while (!ori.IsEmpty()) {
		cout << ori.DelQueue() << " ";
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
