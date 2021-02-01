// 03_p82.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>  

using namespace std;
const int MAXCHAR = 256;

void PreProcess(const char * patt, int m, int bmBc[])
{
	int k = 0;
	for (k = 0; k < MAXCHAR; k++)
		bmBc[k] = m;

	for (k = 0; k < m - 1; k++)
	{
		bmBc[patt[k]] = m - k - 1;
	}
}

int BMS(string t, string p)
{
	int bmBc[MAXCHAR];
	int m = p.length();
	const char * patt = p.c_str();
	PreProcess(patt, m, bmBc);

	const char * text = t.c_str();

	int n = t.length();
	if (m > n)
		return -1;

	int k = m - 1;

	while (k < n) {
		int j = m - 1;
		int i = k;
		while (j >= 0 && text[i] == patt[j]) {
			j--;
			i--;
		}
		if (j == -1)
			return i + 1;
		k += bmBc[text[k]];
	}

	return -1;
}

int main(int argc, char** argv) {

	string p = "GTTAC";
	string t = "GCCTCATCCUACGTTAC";

	cout << BMS(t, p) << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
