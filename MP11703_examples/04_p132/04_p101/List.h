#pragma once
#ifndef _LIST_H_  
#define _LIST_H_  

#include "ListNode.h"  

template <class T> class List {

	ListNode<T>* head;
	ListNode<T>* tail;

public:

	List();
	virtual ~List();

	bool AddTail(T value);
	bool RemoveTail();
	bool InsertAt(int index, T value);
	bool RemoveAt(int index);

	T& GetAt(int index);
	bool IsEmpty();
	int GetCount();
	void RemoveAll();

	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	ListNode<T>* GetNodeAt(int index);
	ListNode<T>* GetCur();
	ListNode<T>* TowardCur();
};

template<class T>
List<T>::List()
{
	head = new ListNode<T>();
	tail = head;
	tail->SetLink(NULL);
}

template<class T>
List<T>::~List()
{
	RemoveAll();
	delete head;
}

template <class T>
bool List<T> ::AddTail(T value) {
	ListNode<T>* add = new ListNode<T>(value);
	tail->SetLink(add);     //把新建節點鏈加入表表，成為新表尾  
	tail = tail->GetLink();      //移動表尾指標至新表尾處
	tail->SetLink(NULL);
	if (tail != NULL)
		return true;
	else
		return false;
}

template <class T >
bool List< T >::InsertAt(int index, T value) {
	//判斷索引值是否正確
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
		return false;
	}

	ListNode<T>* current = head;      //從頭開始尋找出入地點  

	while (index) {
		current = current->GetLink();  //如果找不到，則依序移動cur  
		--index;
	}

	ListNode<T>* add = new ListNode<T>(value);
	add->SetLink(current->GetLink());           //將新建節點鏈加入連結串列
	current->SetLink(add);

	if (current->GetLink() != NULL)
		return true;
	else
		return false;
}

template <class T>
bool List<T>::RemoveTail() {//刪除表尾節點  
							//透過RemoveAt（int index）完成  
	return RemoveAt(this->GetCount() - 1);
}

template <class T>
bool List<T>::RemoveAt(int index) { //依照索引值刪除節點
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
		return false;
	}

	//用兩個節點指標協作完成刪除。其中，cur指向要刪除節點的前一個節點  
	//preCur指向要刪除的節點
	ListNode<T>* cur, *curPre;
	cur = head;                 //從鏈表頭開始尋找index指到的節點  
	curPre = cur->GetLink();    //置preCur到cur後  

	while (index) {
		cur = cur->GetLink();   //如果沒找到，則cur 與preCur繼續後移 
		curPre = curPre->GetLink();
		--index;
	}

	//如果要刪除的節點位於鏈表尾，則把cur 設為新的表尾
	if (tail == curPre)
		tail = cur;
	cur->SetLink(curPre->GetLink());  //將被刪除節點從鏈表中移除
	delete curPre;

	if (curPre != NULL)
		return true;
	else
		return false;
}

template <class T>
T&  List<T>::GetAt(int index) {    //返回索引值節點中的value  
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
	}

	ListNode<T>* cur;
	cur = head->GetLink();
	while (index) {            //如果沒找到，cur依序後移  
		cur = cur->GetLink();
		--index;
	}
	return cur->GetData(); //返回節點中的value
}

template <class T>
bool List< T >::IsEmpty() { //判空函數
	return head->GetLink() == NULL;
}

template <class T>
int List< T >::GetCount() {     //返回鏈表中節點的個數（表頭節點除外）  
	int count = 0;              //用count記錄節點個數
								//初始化指標指到第一個節點（不是表頭節點）  
	ListNode<T>* current = head->GetLink();
	while (current != NULL) {
		++count;
		current = current->GetLink();  //依序移動cur
	}
	return count;
}

template <class T>
void List< T >::RemoveAll() { //刪除所有節點
	ListNode<T>* cur;
	//當表頭節點後還有其他節點時，刪除這些節點  
	while (head->GetLink() != NULL) {
		cur = head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail = head; //將表尾設為表頭處 
}

template <class T>
ListNode<T>* List<T>::GetHead() {//返回頭指標 
	return head;
}

template <class T>
ListNode<T>* List<T>::GetTail() {//返回尾指標  
	return tail;
}

//返回指向索引值為index的節點的指標
template <class T >
ListNode< T >* List< T >::GetNodeAt(int index) {

	//判斷索引值是否正確
	if (index > this->GetCount() - 1 || index<0) {
		cout << "A wrong position!\n";
	}
	//handle 即為所求指標，它指向索引值是index的節點 
	ListNode< T >* handle = head->GetLink();
	while (index) { //尋找索引值為index的節點
		handle = handle->GetLink();
		--index;
	}
	return handle;
}

template <class T>
ListNode<T>* List<T>::GetCur() {
	return cur;
}

template <class T>
ListNode<T>* List<T>::TowardCur() {
	cur = cur->GetLink();
	return cur
}

#endif  
