// 02_p41.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

int main(int argc, char** argv) {

	int a[4][4] = { { 0, 1, 2, 3 },{ 4, 5, 6, 7 },{ 8, 9, 10, 11 },{ 12, 13, 14, 15 } };
	int i = 0;
	int j = 0;
	int tmp = 0;

	for (i = 0; i < 4; i++)
	{
		for (; j < 4; j++)
		{
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
		j = i + 1;
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
