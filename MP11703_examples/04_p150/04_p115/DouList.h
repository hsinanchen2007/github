#pragma once
#ifndef _DOULIST_H  
#define _DOULIST_H  

#include "DouListNode.h"  

template <class T> class DouList {
	DouListNode<T>* head;
	DouListNode<T>* tail;
	DouListNode<T>* cur;

public:
	DouList();
	~DouList();

	bool AddTail(T value);
	bool AddHead(T value);
	void RemoveThis(bool direction);
	void RemoveAll();
	void SetBegin();
	int GetCount();
	void TowardCur();
	void BackCur();
	DouListNode<T>* GetCur();
	DouListNode<T>* GetHead();
	DouListNode<T>* GetTail();
	void InsertAfter(T value);

	bool IsEmpty();
	T GetNext();
	T GetPrior();
};


template <class T>
DouList<T>::DouList() {//預設的建構函數

					   //建立串列頭點即，並初始化head指標與tail指標   
	head = tail = new DouListNode<T>;
	cur = head;
	head->SetLink(head); //建立初始迴圈
	head->SetPrior(tail);
}

template <class T>
DouList<T>::~DouList() {
	RemoveAll();
	delete head;
}

template <class T>
bool DouList<T>::AddTail(T value) { //在串列尾插入一個新節點

									//建立新節點，節點儲存的資料由value決定 
	DouListNode<T>* add = new DouListNode<T>(value);
	tail->SetLink(add);		//使新節點成為串列尾節點的後一節點
	add->SetPrior(tail);
	tail = tail->GetLink();
	tail->SetLink(head);	//使串列尾節點指到串列順節點

	//設定串列頭節點的前一節點為尾端節點，至此插入操作完成
	head->SetPrior(add);
	//如果新的串列尾節點指標為空，則插入失敗
	if (tail != NULL) {
		return true;
	}
	else
		return false;
}

//此函數用來向串列頭節點與串列中第一個節點之間插入新節點 
template <class T>
bool DouList<T>::AddHead(T value) {

	//建立新節點，保存資料value
	DouListNode<T>* add = new DouListNode<T>(value);
	add->SetPrior(head);
	add->SetLink(head->GetLink());

	//將串列中第一個節點的前驅設為add
	//此時add成為串列中第一個節點
	head->GetLink()->SetPrior(add);
	head->SetLink(add);

	//如果對空串列應用此函數，則應該更新尾端指標tail
	if (tail == head) {
		tail = head->GetLink();
	}
	if (add != NULL) {
		return true;
	}
	else
		return false;
}

//把目前cur指到的節點刪除，刪除後cur的移動方向由direction決定
template <class T>
void DouList<T>::RemoveThis(bool direction) {
	//如果目前cur位於串列頭，由於不能刪除串列頭節點，
	//因此依序移動cur到下一個位置  
	if (cur == head) {
		//如果direction==0，順著link方向移動cur
		if (direction == 0)
			cur = cur->GetLink();
		//如果direction==1，順著prior方向移動cur
		if (direction == 1)
			cur = cur->GetPrior();
	}

	//新建指標preCu 與nextCur
	//preCur指到cur的前一節點
	//nextCur指到cur的後一節點  
	DouListNode<T>* preCur = NULL;
	DouListNode<T>* nextCur = NULL;
	preCur = cur->GetPrior();
	nextCur = cur->GetLink();
	DouListNode<T>* node_del = cur;
	preCur->SetLink(cur->GetLink());	//使cur的前一節點直接指到後一節點
	nextCur->SetPrior(cur->GetPrior());	//使cur的後一節點直接指到前一節點

	//根據direction的值判斷cur的移動方向
	//若direction ==0，則往link方向移動cur
	if (direction == 0)
		cur = nextCur;
	//若direction ==1，則往prior方向移動cur
	if (direction == 1)
		cur = preCur;
	delete node_del;
}

template <class T >
void DouList<T>::RemoveAll() {//刪除所有節點（保留串列頭節點）

	SetBegin();            //從頭開始刪除
	int length = GetCount();  //記錄目前串列長度
	for (int i = 0; i<length; i++) { //循環刪除
		RemoveThis(0);
	}
	cur = head;
}

template <class T >
void DouList<T>::SetBegin() {//置cur到串列頭處
	cur = head;
}

//取得目前串列中節點個數（不計串列頭節點）
template <class T >
int DouList<T>::GetCount() {
	int num = 0;   //記錄串列長度的變數
	DouListNode<T>* here = cur; //用here指標完成串列的遍覽
	while (cur->GetLink() != here) { //遍覽串列
		cur = cur->GetLink();
		++num;
	}

	cur = cur->GetLink();    //遍覽完畢後，置cur到原來的位置  
							 //返回串列長度
	return num;
}

template <class T>
void DouList<T>::TowardCur() {//使cur往link方向移動 
	cur = cur->GetLink();
}

template <class T >
void DouList<T>::BackCur() {//使cur往prior方向移動 
	cur = cur->GetPrior();
}

template <class T >
DouListNode<T>* DouList<T>::GetCur() {//返回指標cur
	return cur;
}

template <class T > DouListNode<T>* DouList<T>::GetHead() {
	return head;
}

template <class T > DouListNode<T>* DouList<T>::GetTail() {
	return tail;
}

//判斷串列是否為空 
template <class T >
bool DouList<T>::IsEmpty() {
	//串列為空的條件是僅有串列頭節點
	return
		head->GetLink() == head;
}

//向cur指到的節點後插入一個資料成員為value的新節點
//當對空串列應用此函數時，作用相當於AddTail（ T value ）
template <class T >
void DouList<T>::InsertAfter(T value) {

	DouListNode<T>* add = new DouListNode<T>(value);
	DouListNode<T>* nextCur = cur->GetLink();  //取得cur的後一節點 
	cur->SetLink(add);    //設定cur的一後節點為要加入的節點
	add->SetLink(nextCur);
	nextCur->SetPrior(add); //設定cur後一節點的前一節點為新加入節點
	add->SetPrior(cur);

	if (cur == tail) {
		tail = cur->GetLink();
	}
}

//取得cur指向節點中的資料，並將cur往link方向移動  
template <class T >
T DouList<T>::GetNext() {
	//如果cur位於串列頭，則依序移動cur
	if (cur == head) {
		cur = cur->GetLink();
	}
	T num = cur->GetData();  //返回目前節點中的資料
	cur = cur->GetLink();//返回資料後移動cur（link方向）
	return
		num;
}

//取得cur指向節點中的資料，並將cur往prior方向移動
template <class T >
T DouList<T>::GetPrior() {
	//如果cur位於串列頭，則依序移動cur
	if (cur == head) {
		cur = cur->GetPrior();
	}
	T num = cur->GetData();	//返回目前節點中的資料
	cur = cur->GetPrior();	//返回資料後移動cur（prior方向） 
	return
		num;
}

#endif  
