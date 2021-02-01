#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arrB[4][4],i,j;
    int arrA[4][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	printf("[請輸入矩陣內容]\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",arrA[i][j]);
		}
		printf("\n");
	}
	/*進行矩陣轉置的動作*/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arrB[i][j]=arrA[j][i];

	printf("[轉置矩陣內容為]\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",arrB[i][j]);
		}
		printf("\n");/* 列印轉置矩陣內容 */ 
	}
	system("pause");
}
