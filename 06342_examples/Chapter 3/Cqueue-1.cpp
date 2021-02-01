/* File name: Cqueue-1.cpp */
// 使用環狀佇列加上TAG處理資料--新增、刪除、輸出

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 5

class Cqueue {
	private:
		char item[MAX][20];
		int front;
		int rear;
		int tag;  /* TAG為記憶FRONT所在是否有儲存資料
					 0時為沒有存放資料，1時為有存放資料 */
	public:
		Cqueue();
		void enqueue_f(void);   // 新增函數
		void dequeue_f(void);   // 刪除函數
		void list_f(void);       // 輸出函數
};

Cqueue::Cqueue()
{
	front = MAX - 1;
	rear = MAX - 1;
	tag = 0;
}

void Cqueue::enqueue_f(void)
{
	if(front == rear && tag == 1) // 當佇列已滿，則顯示錯誤
		cout << "\n佇列已滿 !\n";
	else {
		rear = (rear + 1) % MAX;
		cout << "\n 請輸入一個物件: ";
		cin.getline(item[rear], 21);
		if(front == rear) tag = 1;
	}
}

void Cqueue::dequeue_f(void)
{
	if(front == rear && tag == 0)   // 當資料沒有資料存在，則顯示錯誤
		cout << "\n 佇列是空的 !\n";
	else {
		front = (front + 1) % MAX;
		cout << "\n " << item[front] << "已被刪除\n";
		if(front == rear) tag = 0;
	}
}

void Cqueue::list_f(void)
{
	int count = 0, i;

	if(front == rear && tag == 0)
		cout << "\n 佇列是空的\n";
	else {
		cout << "\n  ITEM\n";
		cout << " ------------------\n";
		cout.setf(ios::left, ios::adjustfield);
		for(i = (front + 1) % MAX; i != rear; i = ++i % MAX) {
			cout << "  ";
			cout.width(20);
			cout << item[i] << "\n";
			count++;
		}
		cout << "  ";
		cout.width(20);
		cout << item[i] << "\n";
		cout.setf(ios::right, ios::adjustfield);
		cout << " ------------------\n";
		cout << "  總共有: " << ++count << "\n";
	}
}

int main()
{
	Cqueue obj;
	char option;
	
	while(1) { 
		cout << "\n *****************************\n";
		cout << "       <1> 插入 (enqueue)\n";
		cout << "       <2> 刪除 (dequeue)\n";
		cout << "       <3> 列出\n";
		cout << "       <4> 退出\n";
		cout << " *****************************\n";
		cout << " 請輸入選項...";
		while(cin.get(option) && option == '\n');
		cin.get();
		switch(option) {
			case '1':
				obj.enqueue_f();
				break;
			case '2':
				obj.dequeue_f();
				break;
			case '3':
				obj.list_f();
				break;
			case '4':
				exit(0);
		}
	}
	system("PAUSE");
	return 0;
}

