#pragma once
#ifndef ARRAY_H  
#define ARRAY_H  

#include <iostream>  

using namespace std;

const int DefaultSize = 20;

template <class Type>
class Array
{
	Type *elements;         //陣列存放空間
	int ArraySize;          //目前長度
public:
	Array(int Size = DefaultSize);                  //建構函數
	Array(const Array<Type>& x);                    //複製建構函數 
	~Array() { delete[]elements; }                  //建構函數
	Array<Type> & operator = (const Array<Type> & rhs);     //複製陣列  
	Type& operator [] (int i);						//取元素值  
	int Length() const { return ArraySize; }        //取陣列長度  
	void ReSize(int sz);							//擴充陣列
};

template <class Type>
Array<Type>& Array<Type >::operator= (const Array<Type >& rhs)
{
	int n = rhs.ArraySize;			// 取rhs的陣列大小
	if (ArraySize != n)
	{
		delete[] elements;			// 刪除陣列原有記憶體  
		elements = new Type[n];     // 重新分配n個元素的記憶體 
		if (elements == NULL)       // 如果分配記憶體不成功，則輸出錯誤訊息 
		{
			ArraySize = 0;
			cerr << "記憶體分配錯誤！" << endl;
			exit(1);
		}
		ArraySize = n;          //記錄本物係的陣列大小  
	}
	// 從rhs向本物件複制元素
	Type* destptr = elements;
	Type* srcptr = rhs.elements;
	while (n--)
		*destptr++ = *srcptr++;
	return *this; // 返回目前物件的參照  
}

template <class Type>
Array<Type> ::Array(int sz)
{
	if (sz <= 0) {
		ArraySize = 0;
		cerr << "非法陣列大小" << endl;
		return;
	}
	elements = new Type[sz];
	if (elements == NULL) {
		ArraySize = 0;
		cerr << "記憶體分配錯誤！" << endl;
		exit(1);
	}
	ArraySize = sz;
}


template <class Type>
Array<Type> ::Array(const Array<Type> & x)
{
	int n = x.ArraySize;
	ArraySize = n;
	elements = new Type[n];
	if (elements == NULL) {
		ArraySize = 0;
		cerr << "記憶體分配錯誤！" << endl;
		exit(1);
	}
	Type *srcptr = x.elements;
	Type *destptr = elements;
	while (n--) * destptr++ = *srcptr++;
}

template <class Type>
Type& Array<Type> :: operator [] (int i) {
	if (i < 0 || i > ArraySize - 1) {
		cerr << "超出陣列下標！" << endl;
		exit(1);
	}
	return elements[i];
}

template <class Type>
void Array<Type> ::ReSize(int sz) {
	if (sz >= 0 && sz != ArraySize) {
		Type * newarray = new Type[sz];         //建立新陣列  
		if (newarray == NULL) {
			cerr << "記憶體分配錯誤！" << endl;
			return;
		}
		int n = (sz <= ArraySize) ? sz : ArraySize;  //按照新的大小確定傳送元素個數  
		Type *srcptr = elements;            //來源陣列指標
		Type *destptr = newarray;           //目的陣列指標   
		while (n--) * destptr++ = *srcptr++;
		delete[] elements;
		elements = newarray;
		ArraySize = sz;
	}
}

#endif  
