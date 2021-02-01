#pragma once
#ifndef GRID_H  
#define GRID_H  

#include <string>  
#include <vector>  

using namespace std;

const bool INFECTED = true;
const bool NOT_INFECTED = false;

class grid;

class grid {

	int rows;
	int cols;
	int number;
	vector<bool> *area;
	vector<bool> *marked_area;

	int indexof(int row, int col) const;
	bool infected(int row, int col) const;
	void caculate(int row, int col);

public:
	grid(int* theCity, int, int, int);
	~grid();

	int count(int row, int col);

	friend ostream &operator<<(ostream &stream, const grid& ob);

};

#endif
