// 10_p372.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include<set>  
#include<iostream>  
#include<iterator>  
#include<algorithm>  

using namespace std;

int main(int argc, char** argv) {

	set<int> mySet2;
	set<int> mySet3;

	set<int>::iterator i;

	int a[] = { 1, 2, 3, 4, 5 };

	set<int> mySet1(a, a + 5);

	cout << mySet1.size() << endl;

	i = mySet1.begin();
	cout << "mySet1 : ";
	//遍覽輸出
	while (i != mySet1.end())
	{
		cout << *i << " ";
		++i;
	}

	mySet2.insert(2);
	mySet2.insert(3);
	mySet2.insert(5);
	mySet2.insert(7);

	cout << endl;

	i = mySet2.begin();
	cout << "mySet2 : ";
	//遍覽輸出
	while (i != mySet2.end())
	{
		cout << *i << " ";
		++i;
	}

	cout << endl;

	if (mySet2.find(5) != mySet2.end()) {
		cout << "mySet2 contains 5" << endl;
	}

	ostream_iterator<int> out(cout, " ");
	//求集合mySet1與mySet2的交集
	cout << "\nmySet1與mySet2的交集：";
	set_intersection(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//求集合mySet1與mySet2的聯集
	cout << "\nmySet1與mySet2的聯集：";
	set_union(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//求集合mySet1與mySet2的差集
	cout << "\nmySet1與mySet2的差集：";
	set_difference(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(), out);
	//求集合mySet1與mySet2的對稱差
	set_symmetric_difference(mySet1.begin(), mySet1.end(),
		mySet2.begin(), mySet2.end(),
		inserter(mySet3, mySet3.begin()));

	cout << "\nmySet1與mySet2的對稱差：";
	i = mySet3.begin();
	while (i != mySet3.end())
	{
		cout << *i << " ";
		++i;
	}

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
