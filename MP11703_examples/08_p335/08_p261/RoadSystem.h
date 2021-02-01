#pragma once
#ifndef _ROADSYSTEM_H_  
#define _ROADSYSTEM_H_  

#include <iostream>  
#include <fstream>  
#include <map>  
#include <list>  
#include <queue>  
#include <vector>  

#include "Road.h"  
#include "City.h"  

using namespace std;

class Cheapest {

public:
	Cheapest() {}

	bool operator()(City* city1, City* city2) {
		return city1->total_fee > city2->total_fee;
	}
};


class RoadSystem {

private:
	map<string, list<Road*> > outgoing_roads;
	map<string, City*> cities;

	void load_roads(const string& filename);
	void reset(void);
	string recover_route(const string& city);
	pair<int, int> calc_route(string from, string to);

public:

	RoadSystem(const string& filename);//盿把计篶ㄧ计眖ゅンい弄瓜戈癟
	~RoadSystem(void);//秆篶ㄧ计

	void output_cheapest_route(const string& from, const string& to, ostream& out);
	bool is_valid_city(const string& name);
};

#endif  
