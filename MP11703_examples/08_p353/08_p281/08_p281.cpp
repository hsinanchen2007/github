// 08_p281.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "iostream"  

using namespace std;

#define MaxNumVer 10  
#define MaxWeight 100  

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "請注意：" << endl;
	cout << "\t本程式預設的最大頂點數為10" << endl;
	cout << "\t邊權值的取值範圍是介於0到99之間" << endl << endl;

	int G[MaxNumVer][MaxNumVer], in[MaxNumVer] = { 0 }, path[MaxNumVer][2];
	int i, j, k, min = MaxWeight;
	int v1, v2, num, tmpValue, status = 0, start = 0;

	//輸入圖點節的數目  
	while (true)
	{
		cout << "請輸入圖中頂點的數目：" << endl;
		cin >> num;
		if (num <= MaxNumVer&&num>0)
			break;
		cout << "錯誤！請確認後重新輸入。" << endl << endl;
	}

	//建立圖並使用鄰接矩陣G儲存圖
	for (j = 0; j<num; j++)
		for (k = 0; k<num; k++)
		{
			if (j == k)
				G[j][k] = MaxWeight;
			else if (j<k)
			{
				while (true)
				{
					cout << "請輸入邊(" << j + 1 << "," << k + 1 << ")的權值，如果改變不存在請輸入-1:" << endl;
					cin >> tmpValue;
					if (tmpValue >= -1 && tmpValue<MaxWeight)break;
					cout << endl << "輸入無！請確認後重新輸入。" << endl;
				}

				if (tmpValue == -1)
					tmpValue = MaxWeight;

				G[j][k] = G[k][j] = tmpValue;//矩陣是對稱的
			}
		}

	for (j = 0; j<num; j++)
	{
		status = 0;
		for (k = 0; k<num; k++)
			if (G[j][k]<MaxWeight)
			{
				status = 1;
				break;
			}
		if (status == 0)
			break;
	}

	//如果圖是非連通的則退出程式
	if (!status) {
		cout << "無法處理，因為該圖是非連通的！" << endl;
		return -1;
	}

	//選擇演算法的起始點
	while (true) {
		cout << "請選擇Prim演算法的起始點：" << endl;
		cin >> start;

		if (start>0 && start <= num)
			break;

		cout << "錯誤！請確認後重新輸入。" << endl << endl;
	}

	//Prim演算法求最小產生的樹
	in[start - 1] = 1; //標記

	for (i = 0; i<num - 1; i++)
	{
		for (j = 0; j<num; j++)
			for (k = 0; k<num; k++)
				if (G[j][k]<min&&in[j] && (!in[k]))
				{
					v1 = j;
					v2 = k;
					min = G[j][k];
				}

		if (!in[v2])
		{
			path[i][0] = v1;
			path[i][1] = v2;

			//標記
			in[v1] = 1;
			in[v2] = 1;

			min = MaxWeight;
		}

	}

	//輸出結果
	cout << "最小產生的樹如下：" << endl;
	for (i = 0; i<num - 1; i++)
		cout << "(" << path[i][0] + 1 << ", " << path[i][1] + 1 << ")" << endl;

	system("PAUSE");
	return 0;
}
