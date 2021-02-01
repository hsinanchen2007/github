
/* file name : Stack.cpp */
/* 使用堆疊處理資料--新增、刪除、輸出 */

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

#define MAX 5

class Stack {
	private:
		char item[MAX][20];
		int top;
	public:
		Stack();
		void push_f(void);   // 新增函數
		void pop_f(void);    // 刪除函數
		void list_f(void);   // 輸出函數
};

Stack::Stack()
{
	top = -1;
}

void Stack::push_f(void)
{
	if(top >= MAX-1)   // 當堆疊已滿，則顯示錯誤
		cout << "\n堆疊已滿!\n";
	else {
		top++;
		cout << "\n 請輸入一個物件：: ";
		cin.getline(item[top], 21);
	}
}

void Stack::pop_f(void)
{
	if(top < 0)  // 當堆疊沒有資料存在，則顯示錯誤
		cout << "\n 堆疊是空的 !\n";
	else {
		cout << "\n " << item[top] << "已被刪除\n";
		top--;
	}
}

void Stack::list_f(void)
{
	int count = 0, i;

	if(top < 0)
		cout << "\n 堆疊是空的\n";
	else {
		cout << "\n  ITEM\n";
		cout << " ------------------\n";
		cout.setf(ios::left, ios::adjustfield);
		for(i = 0; i <= top; i++) {
			cout << "  ";
			cout.width(20);
			cout << item[i] << "\n";
			count++;
		}
		cout.setf(ios::right, ios::adjustfield);
		cout << " ------------------\n";
		cout << "  總共有: " << count << "\n";
	}
}

int main()
{
	Stack obj;
	char option;

	while(1) {
		cout << "\n *****************************\n";
		cout << "        <1> 插入 (push)\n";
		cout << "        <2> 刪除 (pop)\n";
		cout << "        <3> 列出\n";
		cout << "        <4> 退出\n";
		cout << " *****************************\n";
		cout << " 請輸入選項...";
		while(cin.get(option) && option == '\n');
		cin.get();
		switch(option) {
			case '1': obj.push_f();
					  break;
			case '2': obj.pop_f();
					  break;
			case '3': obj.list_f();
					  break;
			case '4': system("PAUSE");
	                             return 0;;
		}
	}
 
}
