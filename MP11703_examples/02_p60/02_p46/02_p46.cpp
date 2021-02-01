// 02_p46.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include <iomanip>  
#include "Array.h"  

using namespace std;

int main(int argc, char** argv) {

	Array<int>  A(10);

	int n;
	int primecount = 0, i, j;

	cout << "Enter a value >= 2 as upper limit for prime numbers: ";
	cin >> n;
	A[primecount++] = 2;    // 2是一個質數，[]下標運算  

	for (i = 3; i < n; i++) {
		if (primecount == A.Length()) A.ReSize(primecount + 10);
		if (i % 2 == 0) continue;
		j = 3;
		while (j <= i / 2 && i % j != 0) j += 2;
		if (j > i / 2) A[primecount++] = i;
	}

	for (i = 0; i < primecount; i++) {
		cout << setw(5) << A[i];
		if ((i + 1) % 10 == 0)  cout << endl;
	}

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
