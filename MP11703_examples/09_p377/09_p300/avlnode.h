#pragma once
#ifndef AVLNODE_H  
#define AVLNODE_H  

#include <iostream>  

using namespace std;

template <class T> class AvlTree; //宣告AvlTree類別 

template <class T>
class AvlNode {

	T data;                 //關鍵碼
	AvlNode *leftChild;     //左孩子
	AvlNode *rightChild;    //右孩子
	int balance;            //平衡因子

public:

	//建構函數
	AvlNode() :left(NULL), right(NULL), balance(0) {};

	AvlNode(const T& e, AvlNode<T> *lt = NULL, AvlNode<T> *rt = NULL)
		:data(e), leftChild(lt), rightChild(rt), balance(0) {};

	int getBalance() const
	{
		return balance;
	}
	AvlNode<T>* getLeftChild() const
	{
		return leftChild;
	}
	AvlNode<T>* getRightChild() const
	{
		return rightChild;
	}
	T getData() const
	{
		return data;
	}

	friend class AvlTree<T>;
};
#endif  
