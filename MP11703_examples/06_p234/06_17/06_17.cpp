// 06_17.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <conio.h>
#include <iostream>

using namespace std;
//首先要求皇后不衝突，那麼每列只能有一個皇后
//以queens[]陣列儲存每個皇后的位置
//例如：queens[m] = n，表示第m列的皇后放在第n行上

#define MAX 8

int sum = 0;
class QueenPuzzle
{
	int queens[MAX]; //儲存每列皇后的行編號

public:
	void printOut(); //印出結果
	int IsValid(int n); //判斷放上第n個皇后之後是否合法
	void placeQueen(int i); //遞迴運算，擺放皇后
};

void QueenPuzzle::printOut()
{
	for (int i = 0; i<MAX; i++)
	{
		for (int j = 0; j<MAX; j++)
		{
			if (j == queens[i])
				cout << "Q ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	cout << endl << "按q鍵退出，按其他鍵繼續" << endl << endl;

	if (getch() == 'q')
		exit(0);
}

//在第i列擺放皇后
void QueenPuzzle::placeQueen(int i)
{
	for (int j = 0; j<MAX; j++)
	{
		//如果全部放完，則輸出結果
		if (i == MAX)
		{
			sum++;
			cout << "第" << sum << "組解：" << endl;
			printOut();

			return;
		}

		//擺放皇后
		queens[i] = j;

		//此位置不能擺放皇后，繼續嘗試下一位置
		if (IsValid(i))
			placeQueen(i + 1);
	}
}

//判斷放上第n個皇后之後是否合法，亦即是否無衝突
int QueenPuzzle::IsValid(int n)
{
	//將第n個皇后的位置依序與前面n-1個皇后的位置比較
	for (int i = 0; i < n; i++)
	{
		//兩個皇后在同一行，返回0
		if (queens[i] == queens[n])
			return 0;

		//兩個皇后在同一對角線上，返回0
		if (abs(queens[i] - queens[n]) == (n - i))
			return 0;
	}

	//沒有衝突，返回1
	return 1;
}

void main()
{
	QueenPuzzle queen;
	queen.placeQueen(0);
	cout << "共" << sum << "組解" << endl;
}
