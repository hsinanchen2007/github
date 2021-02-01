#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,tmp;
	int data[8]={16,25,39,27,12,8,45,63};	/* 原始資料 */
	printf("氣泡排序法：\n原始資料為：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");

	for (i=7;i>=0;i--)		/* 掃瞄次數 */
	{
		for (j=0;j<i;j++)/*比較、交換次數*/
		{
			if (data[j]>data[j+1])	/* 比較相鄰兩數，如第一數較大則交換 */
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		printf("第 %d 次排序後的結果是：",8-i); /*把各次掃描後的結果印出*/
		for (j=0;j<8;j++)
			printf("%3d",data[j]);
		printf("\n");
	}
	printf("排序後結果為：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
	
    system("pause");
	return 0;
}

