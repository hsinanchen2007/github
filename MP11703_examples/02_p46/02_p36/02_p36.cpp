// 02_p36.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

void first_bigger(int*& p, int threshold) {

	while (*p <= threshold) {
		p++;
	}
}

int main(int argc, char** argv) {

	int numbers[] = { 0, 12, 32, 44, 33, 5, 85, 45, 100, 75 };
	int* result = &numbers[0];

	cout << "Begin at: " << *result << endl;
	first_bigger(result, 60);
	cout << "Result is: " << *result << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
