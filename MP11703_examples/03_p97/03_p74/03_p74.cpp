// 03_p74.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <iomanip>
#include <string>

using namespace std;
void preKmp(const char *x, int m, int kmpNext[]) {
	int i, j;

	i = 0;
	j = kmpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
		i++;
		j++;
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}
}

void KMP(string p, string t) {

	int m = p.length();
	int n = t.length();
	if (m > n)
		return;

	const char * x = p.c_str();
	const char * y = t.c_str();

	int i = 0, j = 0, kmpNext[1000];	//m + 1
	preKmp(x, m, kmpNext);
	for (int k = 0; k <= m; k++)
		cout << setw(3) << kmpNext[k] << " ";
	cout << endl;

	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = kmpNext[i];
		i++;
		j++;
		if (i >= m) {
			cout << "Matching index found at: " << j - i << endl;
			i = kmpNext[i];
		}
	}

}

int  main(int argc, char** argv) {

	string p1 = "abcabcad";
	string p2 = "adcadcad";
	string p3 = "ababcaabc";
	string t = "ctcabcabcadtcaabcabcadat";

	cout << "KMP: " << endl;
	KMP(p1, t);

	//  cout<<"KMP: "<<endl;  
	//  KMP(p2, t);  

	//  cout<<"KMP: ";  
	//  KMP(p3, t);  

	cout << endl;
	system("PAUSE");
	return 0;
}
