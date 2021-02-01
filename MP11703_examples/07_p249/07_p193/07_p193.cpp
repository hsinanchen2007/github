// 07_p193.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "BinaryTreeNode.h"  
#include "BinaryTree.h"  
#include "iostream"  

using namespace std;

int main()
{

	BinaryTree<char> myBinTree('a');

	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'D');
	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'G');

	myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'B');
	myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'E');

	myBinTree.InsertRightChild(myBinTree.GetRoot(), 'C');
	myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'F');


	cout << "該二元樹是否為空：" << myBinTree.IsEmpty() << endl;
	cout << "該二元樹的根節點中儲存的資料是："
		<< myBinTree.Retrieve(myBinTree.GetRoot());
	cout << endl << "將二元樹的根節點中的資料指定為 A！";
	myBinTree.Assign(myBinTree.GetRoot(), 'A');
	cout << "目前二元樹的根節點中儲存的資料是："
		<< myBinTree.Retrieve(myBinTree.GetRoot()) << endl;

	cout << endl << "逐層遍覽的結果如下：" << endl;
	myBinTree.LevelOrderTraverse(myBinTree.GetRoot());

	cout << endl << endl;
	system("PAUSE");

	return 0;
}
