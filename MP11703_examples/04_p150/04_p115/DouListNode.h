#pragma once
#ifndef _DOULISTNODE_H  
#define _DOULISTNODE_H  

template <class T > class DouListNode {

	T data;
	DouListNode<T>* link;
	DouListNode<T>* prior;

public:

	DouListNode() : link(NULL), prior(NULL) {}
	DouListNode(T value) : link(NULL), prior(NULL), data(value) {}
	~DouListNode() {};
	void SetLink(DouListNode<T>* next);
	void SetPrior(DouListNode<T>* pre);
	DouListNode<T>* GetLink();
	DouListNode<T>* GetPrior();
	T& GetData();
};


template <class T >
void DouListNode< T >::SetLink(DouListNode<T>* next) { //設定link值
	link = next;
}

template <class T >
void DouListNode< T >::SetPrior(DouListNode<T>* pre) { //設定prior值
	prior = pre;
}

//返回指到目前節點的後一節點的指標
template <class T >
DouListNode<T>* DouListNode< T >::GetLink() {
	return link;
}

//返回指到目前節點的前一節點的指標
template <class T >
DouListNode<T>* DouListNode< T >::GetPrior() {
	return prior;
}

template <class T >
T& DouListNode< T >::GetData() {//返回節點中保存的資料
	return data;
}

#endif  
