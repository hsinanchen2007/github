// 10_p327.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include "VecSet.h"  

using namespace std;

int main(int argc, char** argv) {

	VecSet a(8);
	VecSet b(8);
	VecSet c(8);

	for (int i = 1; i <= 5; i++) {
		a.Add(i);
	}

	b.Add(2);
	b.Add(3);
	b.Add(4);
	b.Add(5);
	b.Add(7);
	b.Del(4);

	cout << a * b;
	cout << a + b;
	cout << a - b;
	c = b;
	cout << c;
	cout << (c == b);

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
