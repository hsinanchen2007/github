// 02_p29.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "iostream"  
#pragma runtime_checks( "", off )  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int a = 5;
	unsigned int *pint = NULL;

	cout << "&a = " << &a << endl << " a = " << a << endl;
	cout << " &pint = " << &pint << endl << " pint = " << pint << endl;
	cout << " &(*pint) = " << &(*pint) << endl << endl;

	pint = &a;
	cout << "&a = " << &a << endl << " a = " << a << endl;
	cout << " &pint = " << &pint << endl << " pint = " << pint << endl;
	cout << " &(*pint) = " << &(*pint) << endl << endl;

	*pint = 10;
	cout << "&a = " << &a << endl << " a = " << a << endl;
	cout << " &pint = " << &pint << endl << " pint = " << pint << endl;
	cout << " &(*pint) = " << &(*pint) << endl << endl;

	system("PAUSE");
	return 0;
}
