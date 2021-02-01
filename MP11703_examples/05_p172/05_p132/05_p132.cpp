// 05_p132.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include "LinkStack.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "請輸入括號序列(以0結束)：";
	LinkStack<char> small;
	char a;
	do {
		cin >> a;
		switch (a) {
		case '(':small.Push(a); break;
		case ')':
			if (!small.IsEmpty()) {
				small.Pop();
				break;
			}
			if (small.IsEmpty()) {
				cout << "Wrong!" << endl;
				system("PAUSE");
				return 0;
			}
		}
	} while (a != '0');

	if (small.IsEmpty())
		cout << "OK!" << endl;
	else
		cout << "Wrong!" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
