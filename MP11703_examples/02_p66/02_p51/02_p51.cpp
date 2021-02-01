// 02_p51.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include <memory.h>  

#define SIZE 14  

using namespace std;

// 返回位數為size1+size2  
int* multi(int* num1, int size1, int* num2, int size2)
{
	int size = size1 + size2;
	int* ret = new int[size];
	int i = 0;

	memset(ret, 0, sizeof(int) * size);

	for (i = 0; i < size2; ++i)
	{
		int k = i;
		for (int j = 0; j < size1; ++j)
			ret[k++] += num2[i] * num1[j];
	}

	for (i = 0; i < size; ++i)
	{
		if (ret[i] >= 10)
		{
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}
	}
	return ret;
}

int main(int argc, char** argv) {

	int num1[SIZE] = { 1,2,3,4,5,6,7,8,9,1,1,1,1,1 };//第一個大整數 11111987654321
	int num2[SIZE] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,5 };//第二個大整數 55444333222111

	int* ret = multi(num1, SIZE, num2, SIZE);

	for (int i = SIZE * 2 - 1; i >= 0; i--)
		cout << ret[i];

	delete[] ret; //釋放記憶體

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
