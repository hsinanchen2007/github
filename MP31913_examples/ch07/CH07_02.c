#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0};
    int i,j,k,tmpi,tmpj;     /*宣告矩陣arr*/
	int data[7][2]={{1,2},{2,1},{2,3},{2,4},{4,3},{4,1}};  /*圖形各邊的起點值及終點值*/
	
	for (i=0;i<6;i++)       /*讀取圖形資料*/
		for (j=0;j<6;j++)   /*填入arr矩陣*/
		{  
			tmpi=data[i][0];     /*tmpi為起始頂點*/
			tmpj=data[i][1];     /*tmpj為終止頂點*/
			arr[tmpi][tmpj]=1;   /*有邊的點填入1*/
		}
	printf("有向圖形矩陣：\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);   /*列印矩陣內容*/
		printf("\n");
	}
	system("pause");
	return 0;
}
