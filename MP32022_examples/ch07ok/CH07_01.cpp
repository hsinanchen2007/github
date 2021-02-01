#include <iostream>
using namespace std;
int main(void)
{  
	int arr[6][6];//宣告矩陣arr
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, //圖形各邊的起點值及終點值
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	for (int i=0;i<6;i++)//把矩陣清為0
		for (int j=0;j<6;j++)
			arr[i][j]=0;
	for (int i=0;i<14;i++)//讀取圖形資料
		for (int j=0;j<6;j++)//填入arr矩陣
			for (int k=0;k<6;k++)
			{  
				int tmpi, tmpj;
				tmpi=data[i][0];//tmpi為起始頂點
				tmpj=data[i][1];//tmpj為終止頂點
				arr[tmpi][tmpj]=1;//有邊的點填入1
			}
	cout<<"無向圖形矩陣："<<endl;
	for (int i=1;i<6;i++)
	{  
		for (int j=1;j<6;j++)
	    cout<<"["<<arr[i][j]<<"] ";  //列印矩陣內容
		cout<<endl;
	}
}
