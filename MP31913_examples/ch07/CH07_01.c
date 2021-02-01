#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0},i,j,k,tmpi,tmpj;            /*宣告矩陣arr*/
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, /*圖形各邊的起點值及終點值*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3}};
	for (i=0;i<14;i++)         /*讀取圖形資料*/
		for (j=0;j<6;j++)      /*填入arr矩陣*/
			for (k=0;k<6;k++)
			{  
				tmpi=data[i][0];    /*tmpi為起始頂點*/
				tmpj=data[i][1];    /*tmpj為終止頂點*/
				arr[tmpi][tmpj]=1;  /*有邊的點填入1*/
			}
	printf("無向圖形矩陣：\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);  /*列印矩陣內容*/
		printf("\n");
	}
	system("pause");
	return 0;
}
