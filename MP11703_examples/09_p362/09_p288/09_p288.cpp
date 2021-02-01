// 09_p288.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>  
#include "BinarySearchTree.h"  

using namespace std;

int main()
{
	BinarySearchTree t;
	t.insert(21);
	t.insert(12);
	t.insert(0);
	t.insert(35);
	t.insert(15);
	t.insert(36);
	t.insert(14);

	cout << (t.findMax())->getElement() << endl;
	cout << (t.findMin())->getElement() << endl;
	cout << (t.find(35))->getElement() << endl;

	t.remove(35);
	if (t.find(35) == NULL)
		cout << "This node does not exist!!" << endl;

	t.makeEmpty();
	cout << t.isEmpty() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
