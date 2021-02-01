// 05_p151.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <stack>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	stack<int> myStack;

	//置入與彈出堆疊
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.pop();

	cout << myStack.top() << endl;
	cout << myStack.size() << endl;
	cout << myStack.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
