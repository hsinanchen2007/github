#include "stdafx.h"
#include "car.h"  

using namespace std;

//建構函數
car::car(string license, int) :movedTimes(0), license(license) {}
//解構函數
car::~car() {}
//返回車輛被移動的次數
int car::getMovedTimes()const
{
	return movedTimes;
}
//返回車輛的代號
string car::getLicense()const
{
	return license;
}
//當車被移動時，屬性movedTimes自動加1
void car::move()
{
	movedTimes++;
}
