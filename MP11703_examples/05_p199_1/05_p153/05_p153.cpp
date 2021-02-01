// 05_p153.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <queue>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	queue<int> myQueue;

	//加入與刪除元素
	myQueue.push(5);
	myQueue.push(6);
	myQueue.push(7);

	myQueue.pop();

	cout << myQueue.front() << endl;
	cout << myQueue.back() << endl;

	cout << myQueue.size() << endl;
	cout << myQueue.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
