// 02_p55.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>  

using namespace std;

class Point
{
	int x;
	int y;

public:

	Point()
	{
		x = 0;
		y = 0;
	};
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	};
	~Point() { cout << "END" << endl; };

	int getX() { return x; };
	int getY() { return y; };
	void setX(int newX) { x = newX; };
	void setY(int newY) { y = newY; };
};

int main(int argc, char** argv) {

	Point * point1 = new Point;
	Point * point2 = new Point(3, 5);

	cout << point1->getX() << endl;
	cout << point2->getX() << endl;

	delete point1;
	delete point2;

	cout << endl;
	system("PAUSE");
	return 0;
}
