// 02_p32.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  

using namespace std;

void fun(int x)
{
	cout << "x = " << x << endl;
	x++;
	cout << "x = " << x << endl;
}

int main(int argc, char** argv) {

	int x = 0;
	cout << "x = " << x << endl;
	fun(x);
	cout << "x = " << x << endl << endl;

	system("PAUSE");
	return 0;
}
