// 04_p109.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "CirList.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	cout << "請輸入拉丁方階數(2 <= N <= 9):";
	cin >> num;
	CirList<int> latin;
	for (int i = 1; i <= num; i++) {
		latin.AddTail(i);               //建立循環串列  
	}

	latin.SetBegin();
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cout << latin.GetNext() << " ";     //輸出循環串列中的資料
		}
		cout << endl;
		latin.GetNext();                //依序移動循環串列中的所有資料
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
