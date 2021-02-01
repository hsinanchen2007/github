// 08_p261.cpp : 定義主控台應用程式的進入點。
//

#pragma warning (disable:4786)  
#pragma warning (disable:4503)  

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <string>  
#include <list>  
#include <map>  
#include <queue>  

#include "City.h"  
#include "Road.h"  
#include "RoadSystem.h"  

using namespace std;

int main() {

	try {

		RoadSystem rs("MapInformation.txt");

		while (true) {

			cerr << endl << "請輸入起點城市和終點城市：(退出請輸入'quit')" << endl;

			string from, to;
			cin >> from;
			if (from == "quit") break;
			cin >> to;

			if (rs.is_valid_city(from) && rs.is_valid_city(to)) {
				rs.output_cheapest_route(from, to, cout);
			}
			else {
				cout << "無此城市，請確認後重試！" << endl << endl;
			}

		}

		return EXIT_SUCCESS;

	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "程式出現異常，請退出程式後重試。" << endl;
	}

	return EXIT_FAILURE;
}
