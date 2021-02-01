#pragma once
#ifndef BINARY_SEARCH_TREE_H_  
#define BINARY_SEARCH_TREE_H_  

class BinarySearchTree;

class BinaryNode
{
	int  element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(int theElement, BinaryNode *lt,
		BinaryNode *rt)
		: element(theElement), left(lt), right(rt) { }

public:
	int getElement() {
		return element;
	}

	friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	BinaryNode * findMin() const;
	BinaryNode * findMax() const;
	BinaryNode * find(int x) const;
	bool isEmpty() const;

	void makeEmpty();
	void insert(int x);
	void remove(int x);
	void removeMin();

	const BinarySearchTree & operator=(const BinarySearchTree & rhs);


protected:
	BinaryNode *root;

	virtual void insert(int x, BinaryNode * & t) const;
	virtual void remove(int x, BinaryNode * & t) const;
	virtual void removeMin(BinaryNode * & t) const;
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	BinaryNode * find(int x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t) const;
	BinaryNode * clone(BinaryNode *t) const;
};

#endif  
