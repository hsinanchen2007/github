#pragma once
//#ifndef _CIRLIST_H_  
//#define _CIRLIST_H_  

#include "ListNode.h"  

template <class T > class CirList {

	ListNode<T>* head;
	ListNode<T>* tail;
	ListNode<T>* cur;

public:
	CirList();
	~CirList();

	bool AddTail(T value);
	void RemoveThis();
	void RemoveAll();
	void SetBegin();
	int GetCount();
	ListNode<T>* GetCur();

	bool IsEmpty();
	T GetNext();
};

template <class T >
CirList<T>::CirList() {//預設的建構函數  
	head = tail = new ListNode<T>; //新建節點，並初始化head與tail
	cur = head;
	head->SetLink(head);
}

template <class T>
CirList<T>::~CirList() {
	RemoveAll();
	delete head;
}

template <class T>
bool CirList< T >::AddTail(T value) { //在串列尾端插入新節點
									  //新建節點，儲存資料value
	ListNode<T>* add = new ListNode<T>(value);

	tail->SetLink(add);          //把新節點設入串列
	tail = tail->GetLink();      //移動tail至新串列尾處
	tail->SetLink(head);     //將串列尾指標指向串列頭

	if (tail != NULL)
		return true;
	else
		return false;
}

template <class T>
void CirList<T>::RemoveThis() {//刪除cur指到的節點  
	if (cur == head) {
		//如果目前cur在head處，由於串列頭節點不可刪除，依序移動cur至下一節點處
		cur = cur->GetLink();
	}

	//用指標preCur標記cur的前一節點，node_del標記要刪除的節點  
	ListNode<T>* node_del = cur;
	ListNode<T>* preCur = cur;
	//尋找cur的前一節點，並用preCur記錄下來
	for (int i = 0; i<this->GetCount(); i++) {
		preCur = preCur->GetLink();
	}

	//使cur前一節點的指標指到cur後一節點，亦即跳過cur所在的節點  
	preCur->SetLink(cur->GetLink());
	delete node_del;
	//刪除後cur依序移動一個節點
	cur = preCur->GetLink();
	preCur = NULL;
}

template <class T>
void CirList< T >::RemoveAll() {//刪除所有即點  
	SetBegin();//開始從第一個節點刪除
	int length = GetCount();//抓取串列表度  
	for (int i = 0; i<length; i++) {
		RemoveThis();
	}
	cur = head;  //將cur設為head處
}

template <class T>
void CirList< T >::SetBegin() {//將cur設為head處，表示串列的開始  
	cur = head;
}

template <class T>
int CirList<T>::GetCount() {//取得串列長度
	int num = 0;
	if (cur == NULL)
		this->SetBegin();
	ListNode<T>* here = cur;  //記錄目前節點位置
	while (cur->GetLink() != here) { //遍覽整個串列，記錄節點個數  
		cur = cur->GetLink();
		++num;
	}
	//cur = cur->GetLink();//讓cur回到遍覽前的位置
	cur = here;
	return
		num;
}

template <class T>
ListNode<T>* CirList< T >::GetCur() {//返回目前指標cur  
	return cur;
}

template <class T >
bool CirList< T >::IsEmpty() {//判斷串列是否為空
	return
		head->GetLink() == head;
}

//返回目前節點中的資料，並使cur依序移動一個位置
template <class T>
T CirList< T >::GetNext() {
	if (cur == head) {
		//跳過串列頭節點，因為該節點中未儲存有效資料 
		cur = cur->GetLink();
	}
	T num = cur->GetData();  //取得資料
	cur = cur->GetLink();    //依序移動cur至下一個節點 
	return
		num;
}

//#endif  
