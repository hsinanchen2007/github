// 05_p145.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <queue>  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	queue<int> picture;
	char a;
	float pow = 0;
	float oriSize;
	cout << "請輸入01序列(以#結束)：";
	do {
		cin >> a;
		if (a != '#')
			picture.push(a);
	} while (a != '#');

	char pic = picture.front();
	picture.pop();
	int size = picture.size() + 1;
	oriSize = size;

	cout << "編碼後：";
	while (!picture.empty()) {
		if (pic == picture.front()) {
			pic = picture.front();
			picture.pop();
		}
		else {
			cout << size - picture.size();
			pow++;
			size = picture.size();
			pic = picture.front();
			picture.pop();
		}
	}
	cout << size << endl;
	pow++;
	cout << "壓縮率為：" << pow / oriSize << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
