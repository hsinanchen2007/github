// 02_p35.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  

using namespace std;

void fun(int& r)
{
	cout << "r = " << r << endl;
	r++;
	cout << "r = " << r << endl;
}

int main(int argc, char** argv) {
	int x = 0;
	cout << "x = " << x << endl;
	fun(x);
	cout << "x = " << x << endl << endl;

	system("PAUSE");
	return 0;
}
