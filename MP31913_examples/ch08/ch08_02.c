/*
[名稱]:ch08_02.c
[示範]:改良氣泡排序法
*/
#include <stdio.h>
void bubble (int *);   /*宣告氣泡排序副程式*/
void showdata (int *); /*宣告列印陣列副程式*/
int main(void)
{
	int data[6]={4,6,2,7,8,9};	  /*原始資料*/
	printf("改良氣泡排序法\n原始資料為：");
	showdata (data);
	bubble (data);
	system("pause");
	return 0;
}
void showdata (int data[])     /*利用迴圈列印資料*/
{
	int i;
	for (i=0;i<6;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void bubble (int data[])
{
	int i,j,tmp,flag;
	for(i=5;i>=0;i--)
	{
		flag=0;           /*flag用來判斷是否有執行交換的動作*/
		for (j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    /*如果有執行過交換，則flag不為0*/
			}
		}
		if (flag==0)
			break;
		/*
		當執行完一次掃描就判斷是否做過交換動作，如果沒有交換過資料
		，表示此時陣列已完成排序，故可直接跳出迴圈
		*/
		printf("第 %d 次排序：",6-i);
		for (j=0;j<6;j++)
			printf("%3d",data[j]);
		printf("\n");		    
	}
	printf("排序後結果為：");
	showdata (data);
}
