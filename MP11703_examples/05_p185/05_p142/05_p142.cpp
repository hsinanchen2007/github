// 05_p142.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "LinkQueue.h"  
#include <string>  
#include <iostream>  

using namespace std;

struct dancer {
	string name;
	char sex;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "請輸入舞者總數：";
	int num;
	cin >> num;
	LinkQueue<dancer> Mdancer;
	LinkQueue<dancer> Fdancer;
	for (int i = 0; i<num; i++) {
		cout << "請輸入舞者性別(f or m)及姓名：";
		char sex;
		cin >> sex;
		string name;
		cin >> name;
		dancer newdancer;
		newdancer.name = name;
		newdancer.sex = sex;
		if (sex == 'f')
			Fdancer.EnQueue(newdancer);
		if (sex == 'm')
			Mdancer.EnQueue(newdancer);
	}

	while (!Mdancer.IsEmpty() && !Fdancer.IsEmpty()) {
		cout << Mdancer.DelQueue().name << "\t<---->\t" << Fdancer.DelQueue().name << endl;
	}

	if (!Mdancer.IsEmpty()) {
		cout << "Mr. " << Mdancer.GetFront().name << " is waiting!" << endl;
	}
	else if (!Fdancer.IsEmpty()) {
		cout << "Ms. " << Fdancer.GetFront().name << " is waiting!" << endl;
	}
	else
		cout << "OK!" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
