// 09_p314.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include "RedBlackTree.h"  

using namespace std;

int main(int argc, char** argv) {

	int a[] = { 12, 15, 16, 17, 21, 22, 23, 30, 35 };
	int length = (sizeof(a)) / (sizeof(a[0]));

	RBTree<int>* tree = new RBTree<int>();
	for (int i = 0; i<length; i++)
		tree->RBTInsert(a[i]);

	cout << tree->GetMin() << endl;
	cout << tree->GetMax() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
