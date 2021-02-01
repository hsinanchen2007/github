// 06_14.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;

//把迷宮表示為n個有路口編號的集合
//定義路口類別
class Crossing
{
public:
	//0為不通路口的三個方向
	int turn1;
	int turn2;
	int turn3;

public:
	Crossing(int turn1, int turn2, int turn3)
	{
		Crossing::turn1 = turn1;
		Crossing::turn2 = turn2;
		Crossing::turn3 = turn3;
	}
};

//定義迷宮類別
class Maze
{
private:
	int exit; //出口編號
	vector<Crossing> crossings; //路口集合
	vector<int> result;

public:
	Maze(int the_exit, vector<Crossing> the_crossings)
	{
		exit = the_exit;
		crossings = the_crossings;
	}
	int findExit(int entrance); //迷宮求解
	void getResult(); //解開迷宮並印出
};

//迷宮求解核心演算法
int Maze::findExit(int entrance)
{
	if (entrance > 0)
	{
		if (entrance == Maze::exit)
		{
			result.push_back(entrance);
			return 1;
		}
		if (findExit(crossings[entrance].turn1))
		{
			result.push_back(entrance);
			return 1;
		}
		if (findExit(crossings[entrance].turn2))
		{
			result.push_back(entrance);
			return 1;
		}
		if (findExit(crossings[entrance].turn3))
		{
			result.push_back(entrance);
			return 1;
		}
	}

	return 0;
}

void Maze::getResult()
{
	findExit(1);

	for (int i = result.size(); i>0; i--)
		cout << result[i - 1] << "->";
	cout << "Exit" << endl;
}

void main()
{
	//建立迷宮：9個路口，出口為10
	Crossing c1(2, 0, 0);
	Crossing c2(4, 0, 0);
	Crossing c3(0, 0, 0);
	Crossing c4(3, 5, 0);
	Crossing c5(6, 0, 0);
	Crossing c6(7, 0, 0);
	Crossing c7(8, 9, 0);
	Crossing c8(0, 0, 0);
	Crossing c9(10, 0, 0);
	Crossing c0(0, 0, 0);

	vector<Crossing> crossings;
	crossings.push_back(c0);
	crossings.push_back(c1);
	crossings.push_back(c2);
	crossings.push_back(c3);
	crossings.push_back(c4);
	crossings.push_back(c5);
	crossings.push_back(c6);
	crossings.push_back(c7);
	crossings.push_back(c8);
	crossings.push_back(c9);

	Maze newMaze(10, crossings);
	newMaze.getResult();

	cout << endl;
	system("PAUSE");

}

