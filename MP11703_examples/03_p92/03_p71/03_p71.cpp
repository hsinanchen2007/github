// 03_p71.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>

using namespace std;

void preMp(const char *x, int m, int mpNext[]) {
	int i, j;

	i = 0;
	j = mpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = mpNext[j];
		mpNext[++i] = ++j;
	}
}

void MP(string p, string t) {

	int m = p.length();
	int n = t.length();
	if (m > n) {
		cerr << "Unsuccessful match!" << endl;
		return;
	}

	const char * x = p.c_str();
	const char * y = t.c_str();

	//const int mm = m + 1;
	int i = 0, j = 0, result = -1, mpNext[1000];

	preMp(x, m, mpNext);

	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = mpNext[i];

		i++;
		j++;
		if (i >= m) {
			cout << "Matching index found at: " << j - i << endl;
			i = mpNext[i];
		}
	}
}

int main(int argc, char** argv) {

	string p1 = "abcabcad";
	string p2 = "adcadcad";
	string p3 = "ababcaabc";
	string t = "ctcabcabcadtcaabcabcadat";

	cout << "MP : " << endl;
	MP(p1, t);
	cout << endl;

	//  cout<<"MP : "<<endl;  
	//  MP(p2, t);  
	//  cout<<endl;  

	//  cout<<"MP : "<<endl;  
	//  MP(p3, t);  

	cout << endl;
	system("PAUSE");
	return 0;
}