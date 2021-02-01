#pragma once
#ifndef _CITY_H_  
#define _CITY_H_  

#include <string>  

using namespace std;

class City {

public:

	// 城鎮的名稱
	string name;

	// 簿記資訊
	bool visited;
	int total_fee;
	int total_distance;
	string from_city;

	//預設建構函數  
	City() : name(""), visited(false), total_fee(0),

		total_distance(0), from_city("") {}

	City(string const &s) : name(s), visited(false),
		total_fee(0), total_distance(0), from_city("") {}
};

#endif  
