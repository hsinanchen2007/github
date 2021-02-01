// 04_p107.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include "CirList.h"  
#include <iostream>  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CirList<int> jos; //新建單向循環串列，模擬約瑟夫問題

					  //向串列加入1~15，代表編號為1~15的人
	for (int i = 1; i<16; i++) {
		jos.AddTail(i);
	}

	jos.SetBegin();//開始模擬約瑟夫問題

				   //記錄原始佇列的人數，將此人數減一即可得到要刪去多少人  
				   //本例要刪除14人
	int length = jos.GetCount();
	for (int i = 1; i<length; i++)
	{
		for (int j = 0; j<3; j++)
			jos.GetNext();
		jos.RemoveThis();
	}

	cout << jos.GetNext() << endl << endl;

	system("PAUSE");
	return 0;
}
