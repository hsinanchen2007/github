// 10_p369.cpp : 定義主控台應用程式的進入點。
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
};

int main(int argc, char** argv) {

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(array) / sizeof(array[0]);
	Disjoint_set dj_set(array, len);

	dj_set.Union(0, 1);
	dj_set.Union(2, 3);
	dj_set.Union(4, 1);
	dj_set.Union(3, 5);
	dj_set.Union(1, 5);
	dj_set.Union(7, 6);
	dj_set.Union(8, 6);
	dj_set.Union(0, 5);
	dj_set.Union(1, 3);

	int nums[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < len; i++)
		nums[dj_set.Find(i)] += 1;

	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != 0)
			sum++;
	}
	cout << "犯罪團伙數量：" << sum << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
