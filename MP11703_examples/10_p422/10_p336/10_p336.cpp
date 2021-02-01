// 10_p336.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  
#include "Dictionary.h"  

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Dictionary dic;

	dic.Add("box", "盒子");
	dic.Add("apple", "蘋果");
	dic.Add("tree", "樹");
	dic.Add("good", "好的");
	dic.Add("swim", "游泳");
	dic.Add("interesting", "有趣的");

	cout << dic.Search("good").c_str() << endl;
	cout << dic.Search("interesting").c_str() << endl;

	dic.Del("box");
	dic.Del("interesting");

	cout << dic.Search("box").c_str() << endl;
	cout << dic.Search("interesting").c_str() << endl;
	cout << dic.Search("apple").c_str() << endl;

	cout << endl;
	system("PAUSE");
	return 0;
}
