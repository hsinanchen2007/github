// 04_p122_2.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include <string>  
#include <cstdlib>  
#include <list>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str[] = { "Today ","is ","not ","Friday." };
	list<string> eraseThird;
	for (int i = 0; i < 4; i++)
		eraseThird.push_back(str[i]);

	// 刪除串列中的第3個元素  
	list<string>::iterator third = eraseThird.begin();
	++third;
	++third;
	eraseThird.erase(third);

	list<string>::iterator third2 = eraseThird.begin();
	third2++;
	third2++;
	eraseThird.insert(third2, "not ");


	list<string>::iterator it = eraseThird.begin();
	while (it != eraseThird.end()) {
		cout << *it;
		++it;
	}
	cout << endl;


	list<int> list1(15, 3);
	list<int> list2(16, 2);

	list<int>::iterator insertMass = list1.begin();
	insertMass++;

	list1.insert(insertMass, list2.begin(), list2.end());
	cout << list1.size() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
