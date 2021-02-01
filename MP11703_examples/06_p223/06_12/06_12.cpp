// 06_12.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

//盤子的數目
#define numOfDisks 10

//在文字檔out.txt中輸出結果
ofstream fout("out.txt");

void Move(int n, char x, char y)
{
	fout << "move " << n << " from " << x << " to " << y << endl;
}

//遞迴求解
void Hannoi(int n, char a, char b, char c)
{
	if (n == 1)
		Move(1, a, c);
	else
	{
		Hannoi(n - 1, a, c, b);
		Move(n, a, c);
		Hannoi(n - 1, b, a, c);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	fout << "The solution for Hanoi, when the number of disks is " <<
		numOfDisks << endl;
	Hannoi(numOfDisks, 'a', 'b', 'c');
	fout.close();
	cout << "The End! Please Check out.txt." << endl << endl;
	system("pause");
	return 0;
}
