#pragma once
#include "avlnode.h"  

template <class T>
class AvlTree {

	AvlNode<T> *root;

	bool Insert(AvlNode<T> *& rt, T x, bool &taller);
	bool Remove(AvlNode<T> *& rt, T x, bool &shorter);

	void RotateLeft(AvlNode<T> * &node);  //左旋函數
	void RotateRight(AvlNode<T> * &node); //右旋函數

	void RightBalanceAfterInsert(AvlNode<T> * &sRoot, bool &taller);
	void LeftBalanceAfterInsert(AvlNode<T> * &sRoot, bool &taller);
	void RightBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter);
	void LeftBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter);

public:

	AvlTree() :root(NULL) {}
	AvlNode<T>* getRoot() const
	{
		return root;
	}

	bool Insert(T x)
	{
		bool taller = false;
		return Insert(root, x, taller);
	}

	bool Remove(T x)
	{
		bool shorter = false;
		return Remove(root, x, shorter);
	}

	//輸出樹形結構
	void DisplayTree(AvlNode<T> *t, int layer) const;
};

template <typename T>
void AvlTree<T>::RotateLeft(AvlNode<T> * & node)
{
	if ((node == NULL) || (node->rightChild == NULL)) return;

	AvlNode<T> * tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->leftChild = node->leftChild;
	node->leftChild = tmpNode;
	tmpNode->rightChild = node->rightChild->leftChild;

	AvlNode<T> *toDelete = node->rightChild;
	node->data = toDelete->data;
	node->rightChild = toDelete->rightChild;

	delete toDelete;
}

template <typename T>
void AvlTree<T>::RotateRight(AvlNode<T> * & node)
{
	if ((node == NULL) || (node->leftChild == NULL)) return;

	AvlNode<T> *tmpNode = new AvlNode<T>(node->data);
	if (tmpNode == NULL) return;

	tmpNode->rightChild = node->rightChild;
	node->rightChild = tmpNode;
	tmpNode->leftChild = node->leftChild->rightChild;

	AvlNode<T> *toDelete = node->leftChild;
	node->data = toDelete->data;
	node->leftChild = toDelete->leftChild;

	delete toDelete;
}

//如果插入節點後，rt的右高度增加，則呼叫此函數進行平衡化
template <typename T>
void AvlTree<T>::RightBalanceAfterInsert(AvlNode<T> *&sRoot, bool &taller)
{
	if ((sRoot == NULL) || (sRoot->rightChild == NULL)) return;
	AvlNode<T> *rightsub = sRoot->rightChild, *leftsub;
	switch (rightsub->balance) {
	case 1:
		sRoot->balance = rightsub->balance = 0;
		RotateLeft(sRoot);
		taller = false; break;
	case 0:
		cout << "樹已經平衡化。" << endl; break;
	case -1:
		leftsub = rightsub->leftChild;
		switch (leftsub->balance) {
		case 1:
			sRoot->balance = -1; rightsub->balance = 0; break;
		case 0:
			sRoot->balance = rightsub->balance = 0; break;
		case -1:
			sRoot->balance = 0; rightsub->balance = 1; break;
		}
		leftsub->balance = 0;
		RotateRight(rightsub);
		RotateLeft(sRoot);
		taller = false; break;
	}
}

//如果插入節點後，rt的左高度增加，則呼叫此函數進行平衡化
template <typename T>
void AvlTree<T>::LeftBalanceAfterInsert(AvlNode<T> *&sRoot, bool &taller)
{
	AvlNode<T> *leftsub = sRoot->leftChild, *rightsub;
	switch (leftsub->balance) {
	case -1:
		sRoot->balance = leftsub->balance = 0;
		RotateRight(sRoot);
		taller = false; break;
	case 0:
		cout << "樹已經平衡化。" << endl; break;
	case 1:
		rightsub = leftsub->rightChild;
		switch (rightsub->balance) {
		case -1:
			sRoot->balance = 1; leftsub->balance = 0; break;
		case 0:
			sRoot->balance = leftsub->balance = 0; break;
		case 1:
			sRoot->balance = 0; leftsub->balance = -1; break;
		}
		rightsub->balance = 0;
		RotateLeft(leftsub);
		RotateRight(sRoot);
		taller = false; break;
	}
}

//如果刪除節點後，rt的左高度減少，則呼叫此函數進行平衡化
template <typename T>
void AvlTree<T>::RightBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter)
{
	AvlNode<T> *rightsub = sRoot->rightChild, *leftsub;
	switch (rightsub->balance) {
	case 1: sRoot->balance = sRoot->balance = 0; RotateLeft(sRoot); break;
	case 0: sRoot->balance = 0; rightsub->balance = -1; RotateLeft(sRoot); break;
	case -1:
		leftsub = rightsub->leftChild;
		switch (leftsub->balance) {
		case -1: sRoot->balance = 0; rightsub->balance = 1; break;
		case 0: sRoot->balance = rightsub->balance = 0; break;
		case 1: sRoot->balance = -1; rightsub->balance = 0; break;
		}
		leftsub->balance = 0;
		RotateRight(rightsub);
		RotateLeft(sRoot);
		shorter = false; break;
	}
}

//如果刪除節點後，rt的右高度減少，則呼叫此函數進行平衡化
template <typename T>
void AvlTree<T>::LeftBalanceAfterDelete(AvlNode<T> * &sRoot, bool &shorter)
{
	AvlNode<T> *leftsub = sRoot->leftChild, *rightsub;
	switch (leftsub->balance) {
	case 1: sRoot->balance = sRoot->balance = 0; RotateRight(sRoot); break;
	case 0: sRoot->balance = 0; leftsub->balance = -1; RotateRight(sRoot); break;
	case -1:
		rightsub = leftsub->rightChild;
		switch (rightsub->balance) {
		case -1: sRoot->balance = 0; leftsub->balance = 1; break;
		case 0: sRoot->balance = leftsub->balance = 0; break;
		case 1: sRoot->balance = -1; leftsub->balance = 0; break;
		}
		rightsub->balance = 0;
		RotateLeft(leftsub);
		RotateRight(sRoot);
		shorter = false; break;
	}
}

//插入值為x的節點，實作方式採用遞迴
template <typename T>
bool AvlTree<T>::Insert(AvlNode<T> *& rt, T x, bool &taller)
{
	bool success;

	//遞迴函數的「基本條件」
	if (rt == NULL)
	{
		rt = new AvlNode<T>(x);
		success = rt != NULL ? true : false;
		if (success) taller = true;
	}
	//如果x的值小於rt的關鍵碼
	else if (x < rt->data)
	{
		//Insert的遞迴呼叫，從rt的左子樹尋找合適的位置插入
		success = Insert(rt->leftChild, x, taller);

		if (taller) {//如果插入後使得rt的左高度增加
			switch (rt->balance) {
			case -1: LeftBalanceAfterInsert(rt, taller); break;
			case 0:  rt->balance = -1; break;
			case 1:  rt->balance = 0;  taller = false; break;
			}
		}
	}
	//如果x的值大於rt的關鍵碼
	else if (x > rt->data)
	{
		//Insert的遞迴呼叫，從rt的右子樹尋找合適的位置插入
		success = Insert(rt->rightChild, x, taller);

		if (taller) {//如果插入後使得rt的右高度增加 
			switch (rt->balance) {
			case -1:
				rt->balance = 0;
				taller = false;
				break;
			case 0:
				rt->balance = 1;
				break;
			case 1:
				RightBalanceAfterInsert(rt, taller);
				break;
			}
		}
	}
	return success;
}

//刪除值為x的節點，實作方式採用遞迴
template <typename T>
bool AvlTree<T>::Remove(AvlNode<T> *& rt, T x, bool &shorter)
{
	bool success = false;
	if (rt == NULL) return false;

	//如果rt就是要刪除的節點
	if (x == rt->data) {
		if (rt->leftChild != NULL && rt->rightChild != NULL)
		{

			//尋找rt的中序遍覽的前一節點，以r表示
			AvlNode<T> *r = rt->leftChild;
			while (r->rightChild != NULL) {
				r = r->rightChild;
			}

			//交換rt和r的值
			T temp = rt->data;
			rt->data = r->data;
			r->data = temp;

			//遞迴函數，從rt的左子樹中刪除關鍵碼為x的節點
			success = Remove(rt->leftChild, x, shorter);
			if (shorter) {//如果刪除後引起rt的左高度減少
				switch (rt->balance) {
				case -1: rt->balance = 0; break;
				case 0: rt->balance = 1; shorter = 0; break;
				case 1: RightBalanceAfterDelete(rt, shorter); break;
				}
			}
		}
		else {//rt最多只有一個子女，這是遞迴的出口
			AvlNode<T> *p = rt;
			rt = rt->leftChild != NULL ? rt->leftChild : rt->rightChild;
			delete p;
			success = true;
			shorter = true;
		}
	}

	else if (x < rt->data) {
		//遞迴函數呼叫，從rt的左子樹中刪除關鍵碼為x的節點
		success = Remove(rt->leftChild, x, shorter);
		if (shorter) {//如果刪除後引起rt的左高度減少
			switch (rt->balance) {
			case -1: rt->balance = 0; break;
			case 0: rt->balance = 1; shorter = 0; break;
			case 1: RightBalanceAfterDelete(rt, shorter); break;
			}
		}
	}

	else if (x > rt->data) {
		//遞迴函數呼叫，從rt的右子樹中刪除關鍵碼為x的節點
		success = Remove(rt->rightChild, x, shorter);
		if (shorter) {//如果刪除後引起rt的右高度減少
			switch (rt->balance) {
			case -1: LeftBalanceAfterDelete(rt, shorter); break;
			case 0: rt->balance = -1; shorter = 0; break;
			case 1: rt->balance = 0; break;
			}
		}
	}
	return success;
}

template <typename T>
void AvlTree<T>::DisplayTree(AvlNode<T> *t, int layer) const
{
	if (t == NULL)
		return;
	if (t->rightChild)
		DisplayTree(t->rightChild, layer + 1);
	for (int i = 0; i<layer; i++)
		cout << "    ";
	cout << t->data << endl;
	if (t->leftChild)
		DisplayTree(t->leftChild, layer + 1);
}
