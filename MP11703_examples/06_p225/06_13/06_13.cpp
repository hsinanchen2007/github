// 06_13.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

#include "grid.h"

using namespace std;

#define ROWS 6
#define COLS 6
#define TOTAL 13 // 被感染點的總數

//標記被感染點的坐標陣列
int theCity[TOTAL][2] = {
	{ 0,0 },
	{ 1,1 },
	{ 2,2 },
	{ 2,3 },
	{ 2,5 },
	{ 3,2 },
	{ 3,3 },
	{ 3,5 },
	{ 4,0 },
	{ 4,2 },
	{ 4,3 },
	{ 4,5 },
	{ 5,0 }
};

int main() {
	grid *g;
	int col;
	int row;

	g = new grid((int*)theCity, ROWS, COLS, TOTAL);

	cout << "請輸入要檢測點的座標格式：x,y" << endl;
	scanf("%d,%d", &row, &col);

	cout << "The colony including the cell at "
		<< "(" << row << "," << col << ")"
		<< " has an area of " << g->count(row, col) << " units." << endl;

	cout << *g << endl;

	delete g;
	
	system("PAUSE");
	return EXIT_SUCCESS;

}
