#pragma once
template <typename T>
class Node {
public:
	bool color;         //RED - 1, BLACK - 0
	T key;              // 關鍵字(鍵值)
	Node *left;         // 左孩子
	Node *right;        // 右孩子
	Node *parent;       // 父節點

	Node(T value, bool c, Node *p, Node *l, Node *r) :
		key(value), color(c), parent(), left(l), right(r) {}
};

template <typename T>
class RBTree {
private:
	Node<T> *root;    // 根節點

public:
	RBTree();
	~RBTree();

	Node<T>* FindElement(T key);

	T GetMin();
	T GetMax();

	void RBTInsert(T key);
	//void RBTRemove(T key);  
	void Destroy();

private:

	Node<T>* FindElement(Node<T>* x, T key) const;

	Node<T>* GetMin(Node<T>* tree);
	Node<T>* GetMax(Node<T>* tree);

	void LeftRotate(Node<T>* &root, Node<T>* x);
	void RightRotate(Node<T>* &root, Node<T>* y);

	void RBTInsert(Node<T>* &root, Node<T>* node);
	void RBTInsertFixUp(Node<T>* &root, Node<T>* node);
	//void RBTRemove(Node<T>* &root, Node<T> *node);  
	//void RBTRemoveFixUp(Node<T>* &root, Node<T> *node, Node<T> *parent);  

	void Destroy(Node<T>* &tree);
};

//建構函數
template <typename T>
RBTree<T>::RBTree()
{
	root = NULL;
}

//建構函數
template <typename T>
RBTree<T>::~RBTree()
{
	Destroy();
}

//銷毀紅黑樹
template <typename T>
void RBTree<T>::Destroy(Node<T>* &tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <typename T>
void RBTree<T>::Destroy()
{
	Destroy(root);
}

template <typename T>
Node<T>* RBTree<T>::FindElement(Node<T>* x, T key) const
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return FindElement(x->left, key);
	else
		return FindElement(x->right, key);
}

//在樹中找尋一個元素
template <typename T>
Node<T>* RBTree<T>::FindElement(T key)
{
	FindElement(root, key);
}

template <typename T>
Node<T>* RBTree<T>::GetMin(Node<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

//取得樹中最小的關鍵碼
template <typename T>
T RBTree<T>::GetMin()
{
	Node<T> *p = GetMin(root);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

template <typename T>
Node<T>* RBTree<T>::GetMax(Node<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

//取得樹中最大的關鍵碼
template <typename T>
T RBTree<T>::GetMax()
{
	Node<T> *p = GetMax(root);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

//左旋函數
template <typename T>
void RBTree<T>::LeftRotate(Node<T>* &root, Node<T>* x)
{
	Node<T> *y = x->right;

	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y;
	}
	else
	{
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
}

//右旋函數
template <typename T>
void RBTree<T>::RightRotate(Node<T>* &root, Node<T>* y)
{
	Node<T> *x = y->left;

	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}

	x->right = y;
	y->parent = x;
}

//插入節點後調整樹結構以保持紅黑性質
template <typename T>
void RBTree<T>::RBTInsertFixUp(Node<T>* &root, Node<T>* node)
{
	Node<T> *parent, *gparent;

	while ((parent = node->parent) && (parent->color == 1))
	{
		gparent = node->parent;

		if (parent == gparent->left)
		{
			{
				Node<T> *uncle = gparent->right;
				if (uncle && (uncle->color == 1))
				{
					do { uncle->color = 0; } while (0);
					do { parent->color = 0; } while (0);
					do { gparent->color = 1; } while (0);
					node = gparent;
					continue;
				}
			}

			if (parent->right == node)
			{
				Node<T> *tmp;
				LeftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			do { parent->color = 0; } while (0);
			do { gparent->color = 1; } while (0);
			RightRotate(root, gparent);
		}
		else
		{
			{
				Node<T> *uncle = gparent->left;
				if (uncle && (uncle->color == 1))
				{
					do { uncle->color = 0; } while (0);
					do { parent->color = 0; } while (0);
					do { gparent->color = 1; } while (0);
					node = gparent;
					continue;
				}
			}

			if (parent->left == node)
			{
				Node<T> *tmp;
				RightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			do { parent->color = 0; } while (0);
			do { gparent->color = 1; } while (0);
			LeftRotate(root, gparent);
		}
	}

	do { root->color = 0; } while (0);
}

//節點插入函數
template <typename T>
void RBTree<T>::RBTInsert(Node<T>* &root, Node<T>* node)
{
	Node<T> *y = NULL;
	Node<T> *x = root;

	while (x != NULL)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	node->color = 1;
	RBTInsertFixUp(root, node);
}


template <typename T>
void RBTree<T>::RBTInsert(T key)
{
	Node<T> *z = NULL;

	if ((z = new Node<T>(key, 0, NULL, NULL, NULL)) == NULL)
		return;

	RBTInsert(root, z);
}
