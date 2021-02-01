#pragma once
#ifndef _ROAD_H_  
#define _ROAD_H_  

#include <string>  

using namespace std;

class Road {

public:

	int fee;
	int distance;
	string destination;

	Road(string city, int f, int d) : fee(f),
		distance(d), destination(city) {}
}
;

#endif  
