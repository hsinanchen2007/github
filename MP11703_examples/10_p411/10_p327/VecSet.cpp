#include "stdafx.h"
#include "VecSet.h"  

VecSet::~VecSet()
{
	if (contain != NULL)
		delete[] contain;
}

VecSet::VecSet(int MaxSize) :size(MaxSize) {
	assert(MaxSize>0);
	contain = new int[size];
	assert(contain != NULL);
	MakeEmpty();
}

void VecSet::Add(int add) {
	assert(add >= 0 && add<size);
	contain[add] = 1;
}

void VecSet::Del(int del) {
	assert(del >= 0 && del<size);
	contain[del] = 0;
}

void VecSet::MakeEmpty() {
	for (int i = 0; i<size; i++) {
		contain[i] = 0;
	}
}

bool VecSet::IsMember(const int x)
{
	assert(x >= 0 && x < size);
	return contain[x] != 0;
}

VecSet& VecSet::operator+(VecSet& another) {
	assert(this->GetSize() == another.GetSize());
	VecSet* temp = new VecSet(this->GetSize());
	for (int i = 0; i<size; i++) {
		(*temp).contain[i] = contain[i] || another.contain[i];
	}
	return *temp;
}

VecSet& VecSet::operator-(VecSet& another) {
	assert(this->GetSize() == another.GetSize());
	VecSet* temp = new VecSet(this->GetSize());
	for (int i = 0; i<size; i++) {
		(*temp).contain[i] = contain[i] && (!another.contain[i]);
	}
	return *temp;
}

VecSet& VecSet::operator*(VecSet& another) {
	assert(this->GetSize() == another.GetSize());
	VecSet* temp = new VecSet(this->GetSize());
	for (int i = 0; i<size; i++) {
		(*temp).contain[i] = contain[i] && another.contain[i];
	}
	return *temp;
}

VecSet& VecSet::operator=(VecSet& another) {
	assert(this->GetSize() == another.GetSize());
	for (int i = 0; i<size; i++) {
		contain[i] = another.contain[i];
	}
	return
		*this;
}

bool VecSet::operator == (VecSet& another) {
	assert(this->GetSize() == another.GetSize());
	for (int i = 0; i<size; i++) {
		if (contain[i] != another.contain[i]) {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& stream, VecSet& set) {
	for (int i = 0; i<set.GetSize(); i++) {
		if (set.IsMember(i)) cout << i << " ";
	}
	cout << endl;
	return
		stream;
}
