#pragma once
#ifndef VECSET_H  
#define VECSET_H  

#include <iostream>  
#include <assert.h>  
using namespace std;

const int DefaultSize = 100;

class VecSet
{
	int* contain;
	int size;
public:

	VecSet(int MaxSize = DefaultSize);
	~VecSet();

	void Add(int add);
	void Del(int del);
	void MakeEmpty();
	int GetSize() { return size; }
	bool IsMember(const int x);
	VecSet& operator+(VecSet& another);
	VecSet& operator-(VecSet& another);
	VecSet& operator*(VecSet& another);
	VecSet& operator=(VecSet& another);
	bool operator==(VecSet& another);
	friend ostream& operator<<(ostream& stream, VecSet& set);
};

#endif  
