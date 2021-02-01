#pragma once
#ifndef BINARYTREENODE_H  
#define BINARYTREENODE_H  

#include "iostream"  

using namespace std;

template <class Type>
class BinaryTreeNode
{
	Type m_data;      // 儲存該節點的資料  
	BinaryTreeNode<Type> *m_leftChild; // 儲存該節點的左孩子指標
	BinaryTreeNode<Type> *m_rightChild;// 儲存該節點的右孩子指標

public:
	BinaryTreeNode() { m_leftChild = m_rightChild = NULL; };
	BinaryTreeNode(const Type &data,
		BinaryTreeNode *leftChild = NULL,
		BinaryTreeNode *rightChild = NULL)
	{
		m_data = data;
		m_leftChild = leftChild;
		m_rightChild = rightChild;
	};

	Type & GetData() { return m_data; };       // 返回該節點的資料

	// 返回該節點的左孩子指標
	BinaryTreeNode<Type>* GetLeftChild() { return m_leftChild; };

	// 返回該節點的右孩子指標
	BinaryTreeNode<Type>* GetRightChild() { return m_rightChild; };

	// 設定該節點的資料
	void SetData(const Type & data) { m_data = data; };

	// 設定該節點的左孩子指標域
	void SetLeftChild(BinaryTreeNode<Type> *leftChild) { m_leftChild = leftChild; };

	// 設定該節點的右孩子指標域
	void SetRightChild(BinaryTreeNode<Type> *rightChild) { m_rightChild = rightChild; };
};

#endif  
