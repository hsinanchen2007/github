// 08_p256.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <cstdlib>  
#include <set>  
#include <vector>  
#include <list>  
#include <stack>  
#include <queue>  

using namespace std;

//BFS  
void bfs(vector< list<int> >& adj_lists, int start_node) {

	queue<int> not_yet_explored;
	set<int> discovered;

	// 標記起始節點為已被發現，並將其置於佇列中開始探索
	not_yet_explored.push(start_node);
	discovered.insert(start_node);

	while (!not_yet_explored.empty()) {

		// 取得一個新節點並依此作為基點進行探索
		int node_to_explore = not_yet_explored.front();
		not_yet_explored.pop();
		// 檢測該節點的所有邊
		list<int>::iterator edges = adj_lists[node_to_explore].begin();
		for (; edges != adj_lists[node_to_explore].end(); edges++) {

			if (discovered.count(*edges) == 0) {

				// 發現新節點，將其加入佇列
				discovered.insert(*edges);
				not_yet_explored.push(*edges);

				cout << "Found " << *edges << " from " << node_to_explore << endl;

			}
		}
	}
}

//DFS  
void dfs_helper(vector< list<int> >& adj_lists, set<int>& discovered, int node) {

	// 檢測該節點的所有邊
	list<int>::iterator edges = adj_lists[node].begin();
	for (; edges != adj_lists[node].end(); edges++) {
		// 檢測某邊是否含有未發現的頂點
		if (discovered.count(*edges) == 0) {
			discovered.insert(*edges);
			cout << "Found " << *edges << " from " << node << endl;
			dfs_helper(adj_lists, discovered, *edges);
		}
	}
}

void dfs(vector< list<int> >& adj_lists, int start_node) {

	//標記起始頂點為已被發現
	set<int> discovered;
	discovered.insert(start_node);
	dfs_helper(adj_lists, discovered, start_node);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//初始化圖資訊
	vector< list<int> > g(7, list<int>());

	g[0].push_back(2);
	g[0].push_back(1);

	g[1].push_back(0);
	g[1].push_back(2);

	g[2].push_back(4);
	g[2].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);

	g[3].push_back(2);
	g[3].push_back(4);
	g[3].push_back(5);

	g[4].push_back(6);
	g[4].push_back(5);
	g[4].push_back(3);
	g[4].push_back(2);

	g[5].push_back(4);
	g[5].push_back(3);

	g[6].push_back(4);

	cout << "BFS" << endl;
	bfs(g, 0);

	cout << endl << "DFS" << endl;
	dfs(g, 0);

	cout << endl;
	system("PAUSE");
	return 0;
}
