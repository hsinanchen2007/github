// 09_p300.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <conio.h>  
#include <iostream>  
#include "avltree.h"  

using namespace std;

int main(int argc, char** argv) {

	AvlTree<int> tree;

	tree.Insert(21);
	tree.Insert(12);
	tree.Insert(35);
	tree.Insert(0);
	tree.Insert(15);
	tree.Insert(36);
	tree.Insert(14);
	tree.Insert(7);
	tree.Insert(28);
	tree.Insert(9);

	tree.DisplayTree(tree.getRoot(), 0);

	while (true)
	{
		int number;
		cout << "請輸入要刪除的節點：" << endl;
		cin >> number;
		tree.Remove(number);
		cout << "刪除後的樹為：" << endl;
		tree.DisplayTree(tree.getRoot(), 0);

		cout << "按ESC退出，或按任意鍵繼續…" << endl;
		int order = getch();
		if (order == 27)
		{
			break;
		}
	}

	return 0;
}
