// 10_p368.cpp : 定義主控台應用程式的進入點。
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
			PARENT[array[i]] = -1;
	}

	int Find(int item) {
		if (PARENT[item] < 0)
			return item;
		else
			return Find(PARENT[item]);
	}

	void Union(int node1, int node2) {
		int set1 = Find(node1);
		int set2 = Find(node2);
		if (set1 == set2)
			return;

		if (PARENT[set1] < PARENT[set2])
			PARENT[set2] = set1;
		else
		{
			if (PARENT[set1] == PARENT[set2])
				PARENT[set2] -= 1;
			PARENT[set1] = set2;
		}
	}

	//////////////////////  
	unordered_map<int, int> getP()
	{
		return PARENT;
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

	unordered_map<int, int> p = dj_set.getP();

	for (int i = 0; i < len; i++)
	{
		cout << p[i] << " ";
	}

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
