// 09_p317.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <cstring>  

using namespace std;

const int num_chars = 26;

class Trie {

protected:
	struct Trie_node {
		char* word;     //儲存的字元
		Trie_node* branch[num_chars];
		Trie_node();
	};
	Trie_node* root;

public:
	Trie();
	int search(const char* word) const; //找尋字串
	int insert(const char* word);   //插入字串
	int remove(const char* word);
	void printall(char *pre, Trie_node *p); //印出所有字串
	void printpre(char *pre);       //印出符合條件的字串
};

Trie::Trie() :root(NULL)
{
}

Trie::Trie_node::Trie_node()
{
	word = NULL;
	for (int i = 0; i<num_chars; ++i)      //重新釋放Tire樹
		branch[i] = NULL;
}

int Trie::search(const char* word) const
{
	char char_code;
	Trie_node *location = root;
	while (location != NULL && *word != 0)
	{//逐級找尋標記位
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;
		location = location->branch[char_code];
		word++;
	}

	if (location != NULL && location->word != NULL)
		return 1;
	else
		return 0;       //沒有找到
}

int Trie::insert(const char* word)
{
	cout << "插入" << word << endl;
	int result = 1;
	if (root == NULL) root = new Trie_node;
	char char_code;
	Trie_node *location = root;

	while (location != NULL && *word != 0)
	{   //透過標記位找尋
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;   //沒有找到合適位置，插入失敗
		if (location->branch[char_code] == NULL)
			location->branch[char_code] = new Trie_node;
		location = location->branch[char_code];
		word++;
	}

	if (location->word != NULL)
		result = 0;
	else
	{
		location->word = new char[strlen(word) + 1];
		strcpy(location->word, word);
	}
	return result;
}

int Trie::remove(const char* word)
{
	cout << "刪除" << word << endl;
	int result = 1;
	char char_code;
	Trie_node *location = root;

	while (location != NULL && *word != 0)
	{
		if (*word >= 'A' && *word <= 'Z')
			char_code = *word - 'A';
		else if (*word >= 'a' && *word <= 'z')
			char_code = *word - 'a';
		else
			return 0;
		location = location->branch[char_code];  //刪除前置字元，修改標記
		word++;
	}

	if (location)
	{
		delete location->word;
		location->word = NULL;
	}
	else
		result = 0; //刪除失敗

	return result;
}

//針對對的全部節點，印出前置字元
void Trie::printall(char *pre, Trie_node *p)
{
	if (p->word != NULL) {
		cout << pre << endl;
	}

	for (int i = 0; i<num_chars; ++i)
	{
		if (p->branch[i] != NULL)
		{
			char ch = 'a' + i;
			char *prestr = new char[strlen(pre) + 2];
			sprintf(prestr, "%s%c", pre, ch);
			printall(prestr, p->branch[i]);
			delete[] prestr;       //釋放記憶體
		}
	}
}

void Trie::printpre(char *pre)
{
	char char_code;
	char *p = pre;
	Trie_node *location = root;

	while (location != NULL && *pre != 0)
	{   //判斷是否符合前置字元
		if (*pre >= 'A' && *pre <= 'Z')
			char_code = *pre - 'A';
		else if (*pre >= 'a' && *pre <= 'z')
			char_code = *pre - 'a';
		else
			return;     //非法字元
		location = location->branch[char_code];
		pre++;
	}
	if (location != NULL)
		printall(p, location);
	return;
}

int main(int argc, char** argv) {

	Trie t;
	t.insert("blue");
	t.insert("blur");
	t.insert("car");
	t.insert("cat");
	t.insert("caw");
	t.insert("coin");
	t.insert("coim");
	t.remove("coim");
	cout << endl;

	cout << "印出樹中所有節點" << endl;
	t.printpre("");
	cout << endl;

	cout << "開始搜尋" << "cat" << endl;
	if (t.search("cat"))
		cout << "cat" << " was found." << endl;
	else
		cout << "cat" << " was not found." << endl;

	cout << "印出前置字元為ca的單字：" << endl;
	t.printpre("ca");

	cout << endl;
	system("PAUSE");
	return 0;
}
