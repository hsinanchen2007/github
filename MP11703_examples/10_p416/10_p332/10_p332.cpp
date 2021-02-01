// 10_p332.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "ListSet.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ListSet<int> listSetA;
	ListSet<int> listSetB;
	ListSet<int> listSetC;

	for (int i = 1; i <= 5; i++)
	{
		listSetA.Add(i);
	}
	//  cout << listSetA.IsEmpty()<<endl;  
	//  listSetA.MakeEmpty();  
	//  cout << listSetA.IsEmpty()<<endl;  
	//  listSetC = listSetA;  
	//  listSetC.Output();  

	ListSet<int> listSetD(listSetA);
	cout << (listSetA == listSetD) << endl;

	listSetB.Add(2);
	listSetB.Add(3);
	listSetB.Add(5);
	listSetB.Add(7);
	listSetB.Add(8);
	listSetB.Add(5);
	listSetB.Del(8);

	listSetC = listSetA + listSetB;
	listSetC.Output();

	listSetC = listSetA - listSetB;
	listSetC.Output();

	listSetC = listSetA * listSetB;
	listSetC.Output();

	cout << endl;
	system("PAUSE");
	return 0;
}
