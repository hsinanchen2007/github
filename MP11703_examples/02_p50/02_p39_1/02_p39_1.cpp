// 02_p39_1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

int main(int argc, char* argv[]) {

	int a[10] = { 1, 32, 65, 2, 100, 34, 33, 21, 10, 1 };
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = sum + a[i];
	}
	cout << "陣列中元素的和為：" << sum << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
