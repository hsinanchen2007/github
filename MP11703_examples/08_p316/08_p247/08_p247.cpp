// 08_p247.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <stdio.h>  
#include <string.h>  
#include "iostream"  

using namespace std;

#define N 27  

char str[1001];
int v[N];
int is[N][N];

int viii[N];
int dfs(int);
int counter;

int main() {
	int x[N], f[N], j, len, y[N], i, test, flag, lengths, p, q = 0;
	int count = 0;

	scanf("%d", &test);
	for (i = 0; i<test; i++) {
		memset(x, 0, sizeof(x)); memset(y, 0, sizeof(y));
		memset(f, 0, sizeof(f)); memset(v, 0, sizeof(v));
		memset(is, 0, sizeof(is));
		for (j = 0; j<N; j++)is[j][j] = 1;
		scanf("%d", &len); counter = 0;
		memset(viii, 0, sizeof(viii));
		count = 0;

		for (j = 0; j<len; j++) {
			scanf("%s", str);
			lengths = strlen(str);
			if (str[lengths - 1] != str[0]) {
				x[str[0] - 'a']++;
				y[str[lengths - 1] - 'a']++;
				v[str[0] - 'a'] = v[str[lengths - 1] - 'a'] = 1;
				count++;
				is[str[0] - 'a'][str[lengths - 1] - 'a'] = 1;
				is[str[lengths - 1] - 'a'][str[0] - 'a'] = 1;
			}
			else f[str[0] - 'a'] = 1;
		}

		for (j = 0, p = 0, q = 0, flag = 0; j<N; j++) {
			if (x[j] != y[j]) {
				if (x[j] == y[j] + 1) p++; else if (x[j] + 1 == y[j])q++; else
					flag++;

			}
		}

		if (count == 0) {
			for (j = 0; j<N; j++) if (f[j]) count++;
			if (count == 1)
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
			continue;
		}
		for (j = 0; j<N; j++) if (v[j]) break;

		dfs(j);
		for (j = 0; j<N; j++)
			if (v[j] && !viii[j]) { j = N + 10; break; }
		if (j == N + 10) {
			cout << "The door cannot be opened." << endl; continue;
		}
		if (!flag && (p + q == 0 || p*q == 1)) {
			for (j = 0; j<N; j++)
				if (f[j] == 1 && v[j] != 1) { j = N + 10; break; }
			if (j<N + 2) printf("Ordering is possible.\n");
			else printf("The door cannot be opened.\n");
		}
		else printf("The door cannot be opened.\n");
	}

	cout << endl;
	system("PAUSE");
	return 0;
}

int dfs(int index) {
	int i = 0;
	counter; viii[index] = 1;
	for (i = 0; i<N; i++)
		if (!viii[i] && is[i][index]) {
			dfs(i);
		}
	return 0;
}
