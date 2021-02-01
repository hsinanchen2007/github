// 08_p277.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdio.h"  
#include "stdlib.h"  
#include "iostream"  

using namespace std;

#define N 110  

typedef struct {
	int prior; int next;
	int dis;
}Node;

Node node[N*N];
int father[N];
int find(int);
int union_(int, int);
int MST_Kruskal();
int n, ans = 0;
int cmp(const void *a, const void *b) {
	Node *x = (Node*)(a); Node *y = (Node*)(b);
	return (x->dis - y->dis);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m = 0;
	int i, j, a, b, t = 0;
	scanf("%d", &n);
	for (i = 1; i<n + 1; i++)
		for (j = 1; j<n + 1; j++) {
			node[t].prior = i;
			node[t].next = j;
			scanf("%d", &node[t++].dis);
		}

	scanf("%d", &m);
	for (i = 1; i<N; i++)
		father[i] = -1;
	for (i = 0; i<m; i++) {
		scanf("%d%d", &a, &b);
		union_(a, b);
	}
	qsort(node, n*n, sizeof(Node), cmp);
	MST_Kruskal();

	cout << ans << endl;

	system("PAUSE");
	return 0;
}

int MST_Kruskal() {
	int i = 0, u, v;
	for (i = 0; i<n*n; i++) {
		u = node[i].prior;
		v = node[i].next;
		if (find(u) != find(v)) {
			union_(u, v);
			ans += node[i].dis;
		}
	}
	return 0;
}

int find(int a) {
	int i, temp;
	for (i = a; father[i]>0; i = father[i]);
	while (a != i) {
		temp = father[a];
		father[a] = i;
		a = temp;
	}
	return i;
}

int union_(int a, int b) {
	int temp, temp1 = find(a), temp2 = find(b);
	if (temp1 == temp2) return 0;
	temp = father[temp1] + father[temp2];
	father[temp2] = temp1;
	father[temp1] = temp;
	return 1;
}
