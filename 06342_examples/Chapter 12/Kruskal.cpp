// Name : Kruskal.cpp
// 利用Kruskal's演算法求出最小成本擴展樹

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define  MAX_V  100 /*最大節點數*/
#define  TRUE  1
#define  FALSE  0

using namespace std;

typedef  struct {
	int vertex1;
	int vertex2;
	int weight;
	int edge_deleted;
}  Edge;

typedef struct {
	int vertex[MAX_V];
	int edges;
} Graph;

class G_kruskal {
	private:
		Edge  E[MAX_V];
		Graph T;
		int total_vertex;
		int total_edge;
		int adjmatrix[MAX_V][MAX_V];  // store matrix weight
	public:
		void kruskal();
		void addEdge(Edge);
		void build_adjmatrix();
		void adjust();
		Edge mincostEdge();
		int  cyclicT(Edge e);
		void showEdge();
};



void G_kruskal::build_adjmatrix()
{
	ifstream fin;
	int vi,vj;
	fin.open("kruskal.dat", ios::in);
	if ( !fin.good() ) {
		perror("kruskal.dat");
		exit(0);
	}
// 讀取節點總數
	fin >> total_vertex; 
	for (vi = 1; vi <= total_vertex; vi++)
		for ( vj = 1; vj <= total_vertex; vj++ )
			fin >> adjmatrix[vi][vj];
	fin.close();
}

void G_kruskal:: adjust()
{
	Edge e;
	int i, j, weight;
	total_edge = 0;
	for (i = 1; i <= total_vertex; i++)
		for ( j = i+1; j <= total_vertex; j++ ) {
			weight = adjmatrix[i][j];
			if ( weight != 0 ) {
				e.vertex1 = i;
				e.vertex2 = j;
				e.weight = weight;
				e.edge_deleted = FALSE;
				addEdge(e);
			}
		}
}

void G_kruskal::addEdge(Edge e)
{
	E[++total_edge] = e;
}

void G_kruskal::showEdge()
{
	int  i = 1;
	cout << "total vertex = " << total_vertex << "  ";
	cout << "total_edge = " << total_edge << "\n";
	while ( i <= total_edge ) {
		cout << "V" << E[i].vertex1 << "  <----->  V" << E[i].vertex2
			 << "   weight= " << E[i].weight << "\n";
		i++;
	}
}
Edge G_kruskal::mincostEdge()
{
	int i , min;
	long minweight = 10000000;

	for ( i = 1; i <= total_edge; i++ ) {
		if (!E[i].edge_deleted && E[i].weight < minweight) {
			minweight = E[i].weight;
			min = i;
		}
	}
	E[min].edge_deleted = TRUE;
	return E[min];
}

void G_kruskal::kruskal()
{
	Edge e;
	int i,loop = 1;

	// init T
	for ( i = 1; i <= total_vertex; i++ )
		T.vertex[i] = 0;
	T.edges = 0;
	cout << "\nMinimum cost spanning tree using Kruskal\n";
	cout << "-------------------------------------------\n";
	while ( T.edges != total_vertex - 1  ) {
		e = mincostEdge();
		if ( !cyclicT(e) ) {
			cout << loop++ << "th min edge : ";
			cout << "V" << e.vertex1 << "  <---->  V" << e.vertex2
				 << "  weight= " << e.weight << "\n";
		}
	}
}

int G_kruskal::cyclicT(Edge e)
{
	int v1 = e.vertex1;
	int v2 = e.vertex2;

	T.vertex[v1]++;
	T.vertex[v2]++;
	T.edges++;
	if ( T.vertex[v1] >=2 && T.vertex[v2] >= 2 ) {
		if(v2 == 2)
			return FALSE;
		T.vertex[v1]--;
		T.vertex[v2]--;
		T.edges--;
		return TRUE;
	}
	else
		return FALSE;
}

int main()
{
	G_kruskal obj;

	obj.build_adjmatrix();
	obj.adjust();
	obj.showEdge();
	obj.kruskal();

system("PAUSE");
	return 0;
}

