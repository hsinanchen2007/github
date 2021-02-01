// 04_p115.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "DouListNode.h"  
#include "DouList.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DouList<char> planText;
	DouList<char> cryptograph;
	DouList<int> key;
	DouList<char> trans;
	planText.SetBegin();
	planText.AddTail('y');
	planText.AddTail('o');
	planText.AddTail('u');
	//planText.AddTail(' ');
	planText.AddTail('a');
	planText.AddTail('r');
	planText.AddTail('e');
	//planText.AddTail(' ');
	planText.AddTail('s');
	planText.AddTail('o');
	//planText.AddTail(' ');
	planText.AddTail('l');
	planText.AddTail('o');
	planText.AddTail('v');
	planText.AddTail('e');
	planText.AddTail('l');
	planText.AddTail('y');

	planText.SetBegin();
	cout << "明文：" << '\t';
	for (int z = 0; z<planText.GetCount(); z++) {
		cout << planText.GetNext() << " ";
	}
	cout << endl << endl;

	key.SetBegin(); //產生密鑰串列  
	for (int i = 0; i<6; i++) {
		key.AddTail(1 + rand() % 9);
	}

	cout << "密鑰：" << '\t';
	for (int i = 0; i<key.GetCount(); i++) {
		cout << key.GetNext() << " ";
	}
	cout << endl << endl;

	planText.SetBegin();
	key.SetBegin();
	cryptograph.SetBegin();
	for (int i = 0; i<planText.GetCount(); i++) {

		char c = planText.GetNext();
		int num = key.GetNext();
		if ('a' <= c&&c <= 'z' - num)
			c = c + num;
		else if ('z' - num<c&&c <= 'z')
			c = c + num - 1 - 'z' + 'a';
		cryptograph.AddTail(c);
	}

	cryptograph.SetBegin();
	cout << "密文：" << '\t';
	for (int j = 0; j<cryptograph.GetCount(); j++) {
		cout << cryptograph.GetNext() << " ";
	}
	cout << endl << endl;

	trans.SetBegin();
	planText.SetBegin();
	key.SetBegin();
	for (int k = 0; k<planText.GetCount(); k++) {


		char c = cryptograph.GetNext();
		int num = key.GetNext();
		if ('a' <= c - num && c - num <= 'z')
			c = c - num;
		else if ('a'>c - num && c >= 'a')
			c = 'z' - ('a' - c + num) + 1;

		cryptograph.AddTail(c);
		trans.AddHead(c);
	}

	trans.SetBegin();
	cout << "解密：" << '\t';
	for (int k = 0; k<trans.GetCount(); k++) {
		cout << trans.GetPrior() << " ";
	}
	cout << endl << endl;

	system("PAUSE");
	return 0;
}
