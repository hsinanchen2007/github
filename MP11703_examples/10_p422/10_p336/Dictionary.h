#pragma once
#ifndef _DICTIONARY_H_  
#define _DICTIONARY_H_  

#include "Item.h"  

class Dictionary {

	Item* head;
	Item* tail;

public:
	Dictionary();
	virtual ~Dictionary();

	bool Add(string en, string ch);
	bool Del(string en);
	string Search(string en);
	int GetCount();
	void RemoveAll();
};

Dictionary::Dictionary()
{
	head = new Item();
	tail = head;
	tail->SetLink(NULL);
}

Dictionary::~Dictionary()
{
	RemoveAll();
	delete head;
}

bool Dictionary::Add(string en, string ch) {
	Item* add = new Item(en, ch);
	tail->SetLink(add);
	tail = tail->GetLink();
	tail->SetLink(NULL);
	if (tail != NULL)
		return true;
	else
		return false;
}

bool Dictionary::Del(string en) {

	Item* cur, *curPre;
	cur = head;
	curPre = cur->GetLink();

	while (cur != NULL) {
		if (curPre->GetIndex() == en)
			break;
		cur = cur->GetLink();
		if (cur != NULL)
			curPre = curPre->GetLink();
	}

	if (tail == curPre)
		tail = cur;
	cur->SetLink(curPre->GetLink());  //將被刪除節點從串列中移除
	delete curPre;

	if (curPre != NULL)
		return true;
	else
		return false;
}

string  Dictionary::Search(string en) {

	Item* cur;
	cur = head->GetLink();
	while (cur != NULL) {
		if (en == cur->GetIndex())
			break;
		cur = cur->GetLink();
	}
	if (cur != NULL)
		return cur->GetValue(); //返回節點中的value
	else
		return "Cannot find";
}

int Dictionary::GetCount() {
	int count = 0;
	Item* current = head->GetLink();
	while (current != NULL) {
		++count;
		current = current->GetLink();  //依序移動cur
	}
	return count;
}

void Dictionary::RemoveAll() { //刪除所有節點
	Item* cur;
	while (head->GetLink() != NULL) {
		cur = head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail = head; //將串列尾設成頭部
}

#endif  
