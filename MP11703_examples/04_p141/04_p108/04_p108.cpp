// 04_p108.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "CirList.h"  
#include <iostream>  
//#include "vld.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CirList<int> poker;
	for (int i = 0; i<13; i++) {
		poker.AddTail(0);           //建立循環串列，儲存13張撲克牌 
	}
	cout << poker.GetCount() << endl;

	poker.SetBegin();
	poker.GetCur()->GetLink()->SetData(1);
	for (int i = 2; i<14; i++) {
		for (int j = 0; j<i; j++) {
			poker.GetNext();                //尋找插牌位置
			if (poker.GetCur()->GetData() != 0) {
				j--;            //若目前位置中已有牌，則依序找尋下一個位置 
			}
		}
		poker.GetCur()->SetData(i);
	}

	poker.SetBegin();
	for (int i = 0; i<13; i++) {
		cout << poker.GetNext() << "*";
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
