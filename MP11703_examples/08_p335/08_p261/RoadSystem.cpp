#pragma warning (disable:4786)  
#pragma warning (disable:4503)  

#include "stdafx.h"
#include "RoadSystem.h"  

void RoadSystem::reset(void) {

	map<string, City*>::iterator it;
	for (it = cities.begin(); it != cities.end(); ++it) {
		it->second->visited = false;
		it->second->total_fee = INT_MAX;
		it->second->total_distance = INT_MAX;
		it->second->from_city = "";
	}
}

string RoadSystem::recover_route(const string& city) {

	string route;
	string current = city;

	while (current != "") {

		route = current + route;
		string prev = cities[current]->from_city;

		if (prev != "") {
			route = " -> " + route;
		}
		current = prev;
	}

	return route;
}


RoadSystem::RoadSystem(string const &filename) {

	load_roads(filename);
}

RoadSystem::~RoadSystem(void) {

	// 釋放城市資訊
	map<string, City*>::iterator city_it = cities.begin();
	for (; city_it != cities.end(); city_it++) {
		delete city_it->second;
	}

	// 釋放道路資訊
	map<string, list<Road*> >::iterator roads_it =
		outgoing_roads.begin();
	for (; roads_it != outgoing_roads.end(); roads_it++) {

		list<Road*>::iterator road_it = roads_it->second.begin();
		for (; road_it != roads_it->second.end(); road_it++) {
			delete *road_it;
		}
	}
}

void RoadSystem::load_roads(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while (inf.good()) {

		// 讀取出發城市、目的城市、費用和路程資訊等
		inf >> from >> to >> fee >> distance;

		if (inf.good()) {

			Road* s = new Road(to, fee, distance);

			// 在cities容器中加入實體
			if (cities.count(from) == 0) {
				cities[from] = new City(from);
				outgoing_roads[from] = list<Road*>();
			}

			if (cities.count(to) == 0) {
				cities[to] = new City(to);
				outgoing_roads[to] = list<Road*>();
			}

			// 為城市加上道路
			outgoing_roads[from].push_back(s);

		}
	}

	inf.close();
}

//輸出結果
void RoadSystem::output_cheapest_route(const string& from,
	const string& to, ostream& out) {

	reset();
	pair<int, int> totals = calc_route(from, to);

	if (totals.first == INT_MAX) {
		out << "從" << from << "到" << to << "之間不存在可達的路徑！" << endl;
	}
	else {
		out << "從" << from << "到" << to << "之間最便宜的路徑需要花費" << totals.first << "澳元。" << endl;
		out << "該路線全長" << totals.second << "公里。" << endl;
		cout << recover_route(to) << endl << endl;
	}
}

bool RoadSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

//戴克斯特拉演算法計算最短路徑
pair<int, int> RoadSystem::calc_route(string from, string to) {

	// 用優先佇列取得下一個費用最低的城市
	priority_queue<City*, vector<City*>, Cheapest> candidates;
	City* start_city = cities[from];

	// 將起始城市加入佇列中
	start_city->total_fee = 0;
	start_city->total_distance = 0;
	candidates.push(start_city);

	// 如果優先佇列不為空則循環
	while (!candidates.empty()) {

		City* visiting_city;
		visiting_city = candidates.top();
		candidates.pop();

		if (!visiting_city->visited) {
			visiting_city->visited = true;

			// 反複檢查與該城市相連的各條公路
			list<Road*>::iterator it;
			for (it = outgoing_roads[visiting_city->name].begin();
				it != outgoing_roads[visiting_city->name].end(); ++it) {

				City* next_city = cities[(*it)->destination];
				int next_fee = (*it)->fee + visiting_city->total_fee;

				// 載克斯特拉演算法修改標記處
				if ((next_fee < next_city->total_fee)
					&& next_city->name != from) {
					next_city->total_fee = next_fee;
					next_city->total_distance =
						(*it)->distance + visiting_city->total_distance;
					next_city->from_city = visiting_city->name;
					candidates.push(next_city);
				}
			}
		}
	}

	// 返回總體費用和全長路徑
	if (cities[to]->visited) {
		return pair<int, int>(cities[to]->total_fee, cities[to]->total_distance);
	}
	else {
		return pair<int, int>(INT_MAX, INT_MAX);
	}
}

