// 07_p224.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <string>  
#include <iostream>  
#include <vector>  

using namespace std;

int main() {
	int i = 0;

	vector<int> v1(10);
	vector<double> v2;
	vector<string> v3(10, "OK!");
	vector<string> v4(v3);

	v1[1] = 2;
	v1.at(2) = 45;

	for (int i = 0; i < 9; i++)
	{
		v2.push_back(1.0 + i);
	}

	v2.pop_back();

	cout << v2.back() << endl;
	cout << v2.front() << endl;
	cout << v2.at(5) << endl;
	cout << v1[2] << endl;

	for (i = 0; i < 10; i++)
		cout << v3[i] << " ";
	cout << endl;
	for (i = 0; i < 10; i++)
		cout << v4[i] << " ";
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
