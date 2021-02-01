#pragma once
#include"BinaryTreeNode.h"  
#include<queue>  

using namespace std;

template<class T>
class BinaryTree
{
	BinaryTreeNode<T> *m_root;

public:

	BinaryTree() { m_root = NULL; };
	BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); };
	virtual ~BinaryTree();

	bool IsEmpty() const { return m_root == NULL ? true : false; }; //判斷樹是否為空

	//判斷該節點是否為左孩子
	bool IsLeftChild(BinaryTreeNode<T> *p)
	{
		return p == GetParent(p)->GetLeftChild() ? true : false;
	};
	//判斷該節點是否為右孩子
	bool IsRightChild(BinaryTreeNode<T> *p)
	{
		return p == GetParent(p)->GetRightChild() ? true : false;
	};

	//取得整棵樹的樹根
	BinaryTreeNode<T>* GetRoot() { return m_root; };
	//取得某節點的父節點指標
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T> *p) { return Parent(m_root, p); };
	//取得某節點的左子樹根指標
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T> *root) const
	{
		return root == NULL ? NULL : root->GetLeftChild();
	};
	//取得某節點的右子樹根指標
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T> *root) const
	{
		return root == NULL ? NULL : root->GetRightChild();
	};

	//取得一個節點的左兄弟指標
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T> *leftChild);
	//取得一個節點的右兄弟指標
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T> *rightChild);

	//返回一個節點的資料
	T Retrieve(BinaryTreeNode<T> *p) const { return p->GetData(); };

	//設定一個節點的資料
	void Assign(BinaryTreeNode<T> *p, const T &d) const { p->SetData(d); };
	//插入右孩子到目前節點下
	void InsertRightChild(BinaryTreeNode<T> *p, const T &d) const;
	//插入左孩子到目前節點下
	void InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const;

	//刪除目前節點的右孩子
	void DeleteRightChild(BinaryTreeNode<T> *p) { Destroy(p->GetRightChild()); };
	//刪除目前節點的左孩子
	void DeleteLeftChild(BinaryTreeNode<T> *p) { Destroy(p->GetLeftChild()); };

	virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;	//先序遍覽整棵樹  
	virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;	//中序遍覽整棵樹
	virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const;	//後序遍覽整棵樹

	virtual void LevelOrderTraverse(BinaryTreeNode<T> *root) const;	//逐層遍覽整棵樹

protected:

	BinaryTreeNode<T>* Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *p);
	void Destroy(BinaryTreeNode<T> *p);
};

template<class T>
BinaryTree<T>::~BinaryTree(void)
{
	Destroy(m_root);
	m_root = NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q = Parent(m_root, p);
	if ((NULL == q) || (p == q->GetRightChild()))
		return NULL;
	else
		return q->GetRightChild();
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	q = Parent(m_root, p);
	if ((NULL == q) || (p == q->GetLeftChild()))
		return NULL;
	else
		return q->GetLeftChild();
}

template<class T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->SetLeftChild(p->GetLeftChild());
	p->SetLeftChild(q);
}

template<class T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T> *p, const T &d) const
{
	BinaryTreeNode<T> *q = new BinaryTreeNode<T>(d);
	q->SetRightChild(p->GetRightChild());
	p->SetRightChild(q);
}

template<class T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *p)
{
	if (NULL != p)
	{
		Destroy(p->GetLeftChild());
		Destroy(p->GetRightChild());
		delete p;
	}
}

template<class T> BinaryTreeNode<T>*
BinaryTree<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *p)
{
	BinaryTreeNode<T> *q;
	if (NULL == root)
		return NULL;

	if ((p == root->GetLeftChild()) || (p == root->GetRightChild()))
		return root;

	if (NULL != (q = Parent(root->GetLeftChild(), p)))
		return q;
	else
		return Parent(root->GetRightChild(), p);
}

template<class T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T> *root) const
{
	queue<BinaryTreeNode<T> *> q;
	if (NULL != root)
		q.push(root);

	while (!q.empty())
	{
		root = q.front(), q.pop();
		cout << root->GetData();
		if (root->GetLeftChild())
			q.push(root->GetLeftChild());
		if (root->GetRightChild())
			q.push(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T> *root) const
{

	if (NULL != root)
	{
		cout << root->GetData();

		PreOrderTraverse(root->GetLeftChild());
		PreOrderTraverse(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T> *root) const
{
	if (NULL != root)
	{
		InOrderTraverse(root->GetLeftChild());
		cout << root->GetData();
		InOrderTraverse(root->GetRightChild());
	}
}

template<class T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T> *root) const
{
	if (NULL != root)
	{
		PostOrderTraverse(root->GetLeftChild());
		PostOrderTraverse(root->GetRightChild());

		cout << root->GetData();
	}
}

/*
template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T> *root) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = root;
	while (!s.empty() || p != NULL)
	{
		while (p)
		{
			s.push(p);
			cout << p->GetData();
			p = p->GetLeftChild();
		}
		p = s.top();
		s.pop();
		p = p->GetRightChild();
	}
}

template<class T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T> *root) const
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T> *p = root;
	while (!s.empty() || p != NULL)
	{
		while (p)
		{
			s.push(p);
			p = p->GetLeftChild();
		}

		p = s.top();
		s.pop();
		cout << p->GetData();
		p = p->GetRightChild();
	}
}
*/

