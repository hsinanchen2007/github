// 07_p226.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <vector>   
#include <iostream>  

using namespace std;

class TreeNode
{
	int num;
	vector<TreeNode*> * Sub;

public:

	TreeNode::TreeNode(int n)
	{
		num = n; Sub = NULL;
	}
	int getNum() { return num; }
	vector<TreeNode*> * getSub() { return Sub; }
	void setNum(int n)
	{
		this->num = n;
	}
	void setSub(vector<TreeNode*> * newSub)
	{
		this->Sub = newSub;
	}

	//其他成員方法略
};

class Tree
{
	TreeNode* root;

public:
	Tree(TreeNode* rt) { root = rt; }

	void DisplayTree(TreeNode * r)
	{
		cout << r->getNum() << endl;

		if (r->getSub() == NULL)
		{
			cout << "該節點為葉子節點！" << endl;
			return;
		}
		cout << "該節點的子節點為：";
		for (int i = 0; i < (r->getSub())->size(); i++)
		{
			cout << (r->getSub())->at(i)->getNum() << " ";
		}

		cout << endl;

		for (int i = 0; i < (r->getSub())->size(); i++)
		{
			DisplayTree((r->getSub())->at(i));
		}
	}

	//其他成員方法略
};

int main()
{
	TreeNode treenode0(0);
	TreeNode treenode1(1);
	TreeNode treenode2(2);
	TreeNode treenode3(3);
	TreeNode treenode4(4);
	TreeNode treenode5(5);
	TreeNode treenode6(6);

	vector<TreeNode*> subOfTreeNode0, subOfTreeNode1, subOfTreeNode2;

	subOfTreeNode0.push_back(&treenode1);
	subOfTreeNode0.push_back(&treenode2);

	subOfTreeNode1.push_back(&treenode3);

	subOfTreeNode2.push_back(&treenode4);
	subOfTreeNode2.push_back(&treenode5);
	subOfTreeNode2.push_back(&treenode6);

	treenode0.setSub(&subOfTreeNode0);
	treenode1.setSub(&subOfTreeNode1);
	treenode2.setSub(&subOfTreeNode2);

	Tree tree(&treenode0);
	tree.DisplayTree(&treenode0);

	cout << endl;
	system("PAUSE");
	return 0;
}
