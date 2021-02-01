// 10_p366.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <unordered_map>    

using namespace std;

class Disjoint_set {
	unordered_map<int, int> PARENT;
public:
	Disjoint_set(int * array, int len) {
		for (int i = 0; i < len; i++)
			PARENT[array[i]] = array[i];
	}

	int Find(int item) {
		if (PARENT[item] == item)
			return item;
		else
			return Find(PARENT[item]);
	}

	void Union(int node1, int node2) {
		int set1 = Find(node1);
		int set2 = Find(node2);
		PARENT[set1] = set2;
	}
};

int main(int argc, char** argv) {

	int array[] = { 0, 1, 2, 3, 4, 5, 6 };
	int len = sizeof(array) / sizeof(array[0]);
	Disjoint_set dj_set(array, len);

	dj_set.Union(4, 3);
	dj_set.Union(6, 5);
	dj_set.Union(6, 4);
	dj_set.Union(2, 3);

	cout << dj_set.Find(6) << endl;
	cout << dj_set.Find(5) << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
