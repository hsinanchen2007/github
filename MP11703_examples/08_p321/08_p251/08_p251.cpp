// 08_p251.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "conio.h"  
#include <iostream>  

using namespace std;

class Board
{
private:
	int board[8][8];	//棋盤
	int step;			//目前走的步數
	int No;				//目前解的編號
	int direct[8][2];	//各前進方向的坐標偏移
	int wayCount[8][8];	//棋盤上每個位置可跳出的方向數目
	int startX;         //起始點坐標x
	int startY;         //起始點坐標y
	int dir[8][8][8];   //保存最佳的搜索方向順序


	void init()
	{
		int i, j, k;
		int x, y;
		//確定從棋盤上每個位置可跳出的方向數目
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				wayCount[j][i] = 0;
				for (k = 0; k<8; k++)
				{
					x = i + direct[k][0];
					y = j + direct[k][1];
					if (check(x, y))
						wayCount[j][i]++;
				}
			}
		}

		//為棋盤上每個位置確定搜索的方向順序
		for (y = 0; y<8; y++)
		{
			for (x = 0; x<8; x++)
			{
				//預設搜索順序為順時針方向
				for (k = 0; k<8; k++)
				{
					dir[y][x][k] = k;
				}
				//尋找最佳的搜索順序
				for (i = 0; i<7; i++)
				{
					k = i;
					int x1 = x + direct[dir[y][x][k]][0];
					int y1 = y + direct[dir[y][x][k]][1];
					//為各搜索方向依規則排序
					//希望搜索時優先到達下一步可能性較少的位置
					for (j = i + 1; j<8; j++)
					{
						int x2 = x + direct[dir[y][x][j]][0];
						int y2 = y + direct[dir[y][x][j]][1];
						//如果從目前位置出發，方向j優於方向k，則將k替換為j
						if ((!check(x1, y1) && check(x2, y2))
							|| (check(x1, y1) && check(x2, y2) &&
								wayCount[x1][y1]>wayCount[x2][y2]))
						{
							k = j;
							x1 = x + direct[dir[y][x][k]][0];
							y1 = y + direct[dir[y][x][k]][1];
						}
					}
					j = dir[y][x][k];
					dir[y][x][k] = dir[y][x][i];
					dir[y][x][i] = j;
				}
			}
		}
	}

	//檢查x,y是否為合法位置  
	int check(int x, int y)
	{
		if (x<0 || x>7 || y<0 || y>7)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	//從指定位置(x,y)出發尋找路徑  
	void dg(int x, int y)
	{
		int i, nx, ny;
		//如果目前為最後一步，則終止遞迴  
		if (step == 64)
		{
			printPath();
			return;
		}

		//依照最佳的搜索方向順序，依序向各可能方向搜尋
		for (i = 0; i<8; i++)
		{
			nx = x + direct[dir[y][x][i]][0];
			ny = y + direct[dir[y][x][i]][1];
			if (nx >= 0 && nx<8 && ny >= 0 && ny<8)
			{
				//如果成功到達下一位置，則從新位置開始繼續搜索
				if (board[ny][nx]<0)
				{
					board[ny][nx] = step;
					step++;
					dg(nx, ny);
					board[ny][nx] = -1;
					step--;
				}
			}
		}
	}

	void printPath()
	{
		int i, j;
		No++;
		cout << "No" << No << ":" << endl;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				cout << board[j][i] << " ";
				if (board[j][i]<10)
					cout << " ";
			}
			cout << endl;
		}
		cout << "Press q to exit, other key to continue...";
		//getch();
		if (getchar() == 'q')
			exit(0);

		cout << endl;
	}
	void printwc()
	{
		int i, j;
		No++;
		cout << "No" << No << ":" << endl;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				cout << wayCount[j][i] << " ";
				if (wayCount[j][i]<10)
					cout << " ";
			}
			cout << endl;
		}
		cout << "Press q to exit, other key to continue...";
		//getch();
		if (getchar() == 'q')
			exit(0);

		cout << endl;
	}

public:
	Board(int x, int y)
	{
		int i, j;
		startX = x;
		startY = y;
		direct[0][0] = 1;     direct[0][1] = -2;
		direct[1][0] = 2;     direct[1][1] = -1;
		direct[2][0] = 2;     direct[2][1] = 1;
		direct[3][0] = 1;     direct[3][1] = 2;
		direct[4][0] = -1;    direct[4][1] = 2;
		direct[5][0] = -2;    direct[5][1] = 1;
		direct[6][0] = -2;    direct[6][1] = -1;
		direct[7][0] = -1;    direct[7][1] = -2;
		step = 1;
		No = 0;
		for (j = 0; j<8; j++)
		{
			for (i = 0; i<8; i++)
			{
				board[j][i] = -1;
			}
		}
		board[y][x] = 0;
	}

	void GetPath()
	{
		init();
		dg(startX, startY);
		if (No == 0)
		{
			cout << "no result" << endl;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int x, y;
	cout << "Please input the start point (x,y)."
		<< endl << "x=";
	cin >> x;
	getchar();
	cout << "y=";
	cin >> y;
	getchar();
	Board board(x, y);
	board.GetPath();

	return 0;
}
