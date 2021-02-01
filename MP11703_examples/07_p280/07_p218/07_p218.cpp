// 07_p218.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <string>  
#include <queue>  
#include <map>  
#include <iterator>  
#include <algorithm>  

using namespace std;

typedef vector<bool> HuffCode;
typedef map<char, HuffCode> HuffCodeMap;

class INode
{
public:
	const int f;

	virtual ~INode() {}

protected:
	INode(int f) : f(f) {}
};

class InternalNode : public INode
{
public:
	INode *const left;
	INode *const right;

	InternalNode(INode* c0, INode* c1) : INode(c0->f + c1->f), left(c0),
		right(c1) {}

	~InternalNode()
	{
		delete left;
		delete right;
	}
};

class LeafNode : public INode
{
public:
	const char c;

	LeafNode(int f, char c) : INode(f), c(c) {}
};

struct NodeCmp
{
	bool operator()(const INode* lhs, const INode* rhs) const {
		return

			lhs->f > rhs->f;
	}
};

INode* BuildTree(map<char, int> frequs)
{
	priority_queue<INode*, vector<INode*>, NodeCmp> trees;

	map<char, int>::iterator it = frequs.begin();
	for (; it != frequs.end(); it++)
	{
		trees.push(new LeafNode(it->second, it->first));
	}

	while (trees.size() > 1)
	{
		INode* childR = trees.top();
		trees.pop();

		INode* childL = trees.top();
		trees.pop();

		INode* parent = new InternalNode(childR, childL);
		trees.push(parent);
	}
	return trees.top();
}

void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap&

	outCodes)
{
	if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node))
	{
		outCodes[lf->c] = prefix;
	}
	else if (const InternalNode* in = dynamic_cast<const InternalNode*>

		(node))
	{
		HuffCode leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		HuffCode rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//建立頻率表  
	map<char, int> frequs;
	cout << "請輸入一列文字資料：" << endl;
	string str;
	getline(cin, str);
	const char* ptr = str.c_str();

	while (*ptr != '\0')
	{
		if (frequs.find(*ptr) != frequs.end())
			frequs[*ptr] = frequs[*ptr] + 1;
		else
			frequs[*ptr] = 1;
		*ptr++;
	}

	INode* root = BuildTree(frequs);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);
	delete root;

	for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
	{
		cout << it->first << " ";
		copy(it->second.begin(), it->second.end(), ostream_iterator<bool>(cout));
		cout << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
