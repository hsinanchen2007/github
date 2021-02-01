// Name : Dfs.cpp
// 圖形的追蹤: 相鄰串列與蹤向優先搜尋法(DFS)

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define  MAX_V  100 /*最大節點數*/
#define  TRUE  1
#define  FALSE  0

using namespace std;

// 定義資料結構
typedef struct node_tag {
	int vertex;
	struct node_tag *link;
} Node;

class G_dfs {
	private:
		Node *adjlist[MAX_V+1]; // 宣告相鄰串列
		int  visited[MAX_V+1];  // 記錄頂點是否已拜訪
		int  total_vertex;
	public:
		void build_adjlist();
		void show_adjlist();
		void dfs(int);
		Node *searchlast(Node *);
};

void G_dfs::build_adjlist()
{
	ifstream fin;
	Node *node,*lastnode;
	int vi,vj ,weight;
	fin.open("dfs.dat", ios::in);
	if ( !fin.good() ) {
		perror("dfs.dat");
		exit(0);
	}
	// 讀取節點總數
	fin >> total_vertex;
	for ( vi = 1; vi <= total_vertex; vi++) {
		// 設定陣列及各串列啟始值
		visited[vi] = FALSE;
		adjlist[vi] = new Node;
		adjlist[vi]->vertex = vi;
		adjlist[vi]->link = NULL;
	}
	// 讀取節點資料
	for ( vi = 1; vi <= total_vertex; vi++ )
		for ( vj = 1; vj <= total_vertex; vj++ ) {
			fin >> weight;
			// 資料檔以相鄰矩陣格式儲存,以1代表相鄰
			// 0 代表不相鄰，將相鄰頂點鏈結在各串列後
			if ( weight != 0 ) {
				node = new Node;
				node->vertex = vj;
				node->link = NULL;
				lastnode = searchlast(adjlist[vi]);
				lastnode->link = node;
			}
		}
	fin.close();
}

// 顯示各相鄰串列之資料
void G_dfs::show_adjlist()
{
	int index;
	Node *ptr;

	cout << "Head    adjacency nodes\n";
	cout << "------------------------------\n";
	for (index = 1; index <= total_vertex; index++) {
		cout << "V" << adjlist[index]->vertex << " ";
		ptr = adjlist[index]->link;
		while ( ptr != NULL ) {
			cout << "--> V" << ptr->vertex << " ";
			ptr = ptr->link;
		}
		cout << "\n";
	}
}

// 圖形之蹤向優先搜尋
void G_dfs::dfs(int v)
{
	Node *ptr;
	int w;

	cout << "V" << adjlist[v]->vertex << " ";
	visited[v] = TRUE;          // 設定v頂點為已拜訪過
	ptr = adjlist[v]->link;     // 拜訪相鄰頂點
	do {
		// 若頂點尚未走訪，則以此頂點為新啟始點繼續
		// 做蹤向優先搜尋法走訪，否則找與其相鄰的頂點
		// 直到所有相連接的節點都已走訪
		w = ptr->vertex;
		if ( !visited[w] )
			dfs(w);
		else
			ptr = ptr->link;
	} while ( ptr != NULL);
}

// 搜尋串列最後節點函數
Node *G_dfs::searchlast( Node *linklist )
{
	Node *ptr;

	ptr = linklist;
	while ( ptr->link != NULL ) 
		ptr = ptr->link;
	return ptr;
}

int main()
{
	G_dfs obj;

	obj.build_adjlist(); // 以相鄰串列表示圖形
	obj.show_adjlist();  // 顯示串列之資料
	cout << "\n------Depth First Search------\n";
	obj.dfs(1);     // 圖形之蹤向優先搜尋，以頂點1為啟始頂點

system("PAUSE");
	return 0;
}
