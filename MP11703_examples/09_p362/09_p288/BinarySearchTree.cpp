#include "stdafx.h"
#include "BinarySearchTree.h"  
#include <iostream>  
#include <cstddef>  

using namespace std;

// Construct the tree.  
BinarySearchTree::BinarySearchTree() : root(NULL)
{
}

// Destructor for the tree.  
BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

// Insert x into the tree;  
void BinarySearchTree::insert(int x)
{
	insert(x, root);
}

// Remove x from the tree.  
void BinarySearchTree::remove(int x)
{
	remove(x, root);
}

// Remove minimum item from the tree.  
void BinarySearchTree::removeMin()
{
	removeMin(root);
}

BinaryNode * BinarySearchTree::findMin() const
{
	return findMin(root);
}

BinaryNode * BinarySearchTree::findMax() const
{
	return findMax(root);
}

// Find item x in the tree.  
BinaryNode * BinarySearchTree::find(int x) const
{
	return find(x, root);
}

// Make the tree logically empty.  
void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}

// Test if the tree is logically empty.  
// Return true if empty, false otherwise.  
bool BinarySearchTree::isEmpty() const
{
	return root == NULL;
}

// Deep copy.  
const BinarySearchTree &
BinarySearchTree::
operator=(const BinarySearchTree & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

void BinarySearchTree::
insert(int x, BinaryNode * & t) const
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
	{
		cout << "ERROR!! Duplicate Element." << endl;
	}
}

void BinarySearchTree::
remove(int x, BinaryNode * & t) const
{
	if (t == NULL)
	{
		cout << "This node does not exist!!" << endl;
		return;
	}

	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) // Two children  
	{
		t->element = findMin(t->right)->element;
		removeMin(t->right);                   // Remove minimum  
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;  // Reroot t  
		delete oldNode;                         // delete old root  
	}
}

void BinarySearchTree::removeMin(BinaryNode * & t) const
{
	if (t == NULL)
	{
		cout << "Empty Tree!!" << endl;
		return;
	}
	else if (t->left != NULL)
		removeMin(t->left);
	else
	{
		BinaryNode *tmp = t;
		t = t->right;
		delete tmp;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t != NULL)
		while (t->left != NULL)
			t = t->left;

	return t;
}

BinaryNode* BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != NULL)
		while (t->right != NULL)
			t = t->right;

	return t;
}

BinaryNode * BinarySearchTree::
find(int x, BinaryNode *t) const
{
	while (t != NULL)
		if (x < t->element)
			t = t->left;
		else if (t->element < x)
			t = t->right;
		else
			return t;    // Match  

	return NULL;         // Not found  
}

void BinarySearchTree::makeEmpty(BinaryNode * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

// Internal method to clone subtree.  
BinaryNode * BinarySearchTree::clone(BinaryNode * t) const
{
	if (t == NULL)
		return NULL;
	else
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

