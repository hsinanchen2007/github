// 03_p64.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include <iomanip>  
#include <string>  

using namespace std;

int main(int argc, char** argv) {

	string  str = "高德納 美國 計算機科學家 計算機程式設計藝術";
	string  str_temp = "";
	str_temp.assign(str);

	string result[4] = { "","","","" };

	int position = 0;

	for (int i = 0; i < 3; i++)
	{
		position = str_temp.find(" ");
		result[i] = str_temp.substr(0, position);
		str_temp = str_temp.substr(position + 1, str_temp.length() - position);
	}

	result[3] = str_temp;

	cout << "姓名：" << setw(8) << result[0] << endl;
	cout << "國籍：" << setw(6) << result[1] << endl;
	cout << "職業：" << setw(14) << result[2] << endl;
	cout << "代表作：" << setw(18) << result[3] << endl;

	str_temp.swap(result[0]);

	for (int j = 1; j < 4; j++)
	{
		str_temp += " ";
		str_temp.append(result[j]);
	}

	int equal = str.compare(str_temp);

	cout << endl;
	if (equal == 0)
		cout << "配對成功！" << endl;
	else
		cout << "配對不成功！" << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
