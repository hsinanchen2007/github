// 05_p157.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <queue>  

using namespace std;

class myCompare {
public:
	bool operator () (const int& a, const int& b)
	{
		return a > b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	priority_queue<int, vector<int>, myCompare> Q;
	Q.push(1);
	Q.push(5);
	Q.push(2);
	Q.push(4);
	Q.push(6);
	Q.push(3);

	int size = Q.size();

	for (int i = 0; i < size; i++)
	{
		cout << Q.top() << endl;
		Q.pop();
	}

	cout << endl << Q.empty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
