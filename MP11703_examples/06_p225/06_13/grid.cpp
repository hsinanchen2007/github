#include "stdafx.h"

#include <iostream>  
#include <fstream>  

using namespace std;

#include "grid.h"  

int grid::indexof(int row, int col) const {
	return row*cols + col;
}

bool grid::infected(int row, int col) const {
	return (area->operator[](indexof(row, col)) == INFECTED);
}

//篶ㄧ计  
grid::grid(int* theCity, int row, int col, int total) {

	number = 0;

	rows = row;
	cols = col;

	area = new vector<bool>(rows*cols, NOT_INFECTED);
	marked_area = new vector<bool>(rows*cols, NOT_INFECTED);

	for (int i = 0; i<total; i++) {

		int blob_row;
		int blob_col;

		blob_row = theCity[i * 2];
		blob_col = theCity[i * 2 + 1];

		area->operator[](indexof(blob_row, blob_col)) = INFECTED;
	}
}

//篶ㄧ计  
grid::~grid() {
	delete area;
	delete marked_area;
}

//砆稰琕灿璏矪(+)笲衡才腹更 
ostream &operator<<(ostream &stream, const grid& ob) {

	for (int row = 0; row < ob.rows; row++) {

		for (int col = 0; col < ob.cols; col++) {
			stream << ob.area->operator[](ob.indexof(row, col));
			if (ob.marked_area->operator[](ob.indexof(row, col)))
				stream << "+  ";
			else
				stream << "   ";
		}

		stream << endl;
	}

	stream << endl;
	return stream;
}

int grid::count(int row, int col)
{
	caculate(row, col);
	return number;
}

//患癹み场だ秈︽よ浪琩  
void grid::caculate(int row, int col)
{
	if (row<0 || col<0 || row >= rows || col >= cols || marked_area->operator [](indexof(row, col)))
		return;
	if (infected(row, col))
	{
		marked_area->operator[](indexof(row, col)) = INFECTED;
		number++;
		caculate(row, col + 1);
		caculate(row, col - 1);
		caculate(row + 1, col);
		caculate(row - 1, col);
		caculate(row + 1, col + 1);
		caculate(row - 1, col - 1);
		caculate(row + 1, col - 1);
		caculate(row - 1, col + 1);
	}
}
