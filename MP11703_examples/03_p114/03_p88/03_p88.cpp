// 03_p88.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>  

using namespace std;
int N_gram(string x, string y, int n) {

	int lp = x.length();
	int lt = y.length();

	int num_x = lp - n + 1;
	int num_y = lt - n + 1;
	int num_s = 0;

	for (int i = 0; i < num_x; i++) {
		string sub_str = x.substr(i, n);
		if (y.find(sub_str) != -1)
			num_s++;
	}

	return num_x + num_y - 2 * num_s;
}

int main(int argc, char** argv) {

	int N = 2;

	string p = "Gorbachev";
	string t = "Gorbechyov";

	cout << N_gram(p, t, N) << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
