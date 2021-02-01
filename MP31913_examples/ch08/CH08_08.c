/* 基數排序法 由小到大排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void radix (int *,int);/* 基數排序法副程式 */
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	printf("請輸入陣列大小(100以下)：");
	scanf("%d",&size);
	printf("您輸入的原始資料是：\n");
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	int i;
	srand((unsigned)time(NULL));
	for (i=0;i<size;i++)
		data[i]=(rand()%999)+1;/*設定data值最大為3位數*/
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		printf("%5d",data[i]);
	printf("\n");
}
void radix(int data[],int size)
{  
	int i,j,k,n,m;
	for (n=1;n<=100;n=n*10)/*n為基數，由個位數開始排序 */
	{  
		int tmp[10][100]={0};/* 設定暫存陣列，[0~9位數][資料個數]，所有內容均為0 */
		for (i=0;i<size;i++)/* 比對所有資料 */
		{  
			m=(data[i]/n)%10;/* m為n位數的值，如 36取十位數 (36/10)%10=3 */
			tmp[m][i]=data[i];/* 把data[i]的值暫存於tmp 裡 */
		}
		k=0;
		for (i=0;i<10;i++)
		{  
			for(j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)	/* 因一開始設定 tmp ={0}，故不為0者即為 */
				{  
					data[k]=tmp[i][j];/* data暫存在 tmp 裡的值，把tmp 裡的值放 */
					k++;		      /* 回data[ ]裡 */
				}
			}
		}
		printf("經過%3d位數排序後：",n);
		showdata(data,size);
	}
  
}
