#include <stdio.h>
#include <stdlib.h>
void select (int *);     /*宣告排序法副程序*/
void showdata (int *);   /*宣告列印陣列副程序*/

int main()
{
	int data[8]={16,25,39,27,12,8,45,63};
	printf("原始資料為：");
	int i;
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
	printf("\n-------------------------------------");
	select (data);
	printf("排序後資料：");
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
    printf("\n");
    
	system("pause");
	return 0;
}
void showdata (int data[])
{
	int i;
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
}

void select (int data[])
{
	int i,j,tmp,k;
	for(i=0;i<7;i++)    /*掃描5次*/
	{   
		for(j=i+1;j<8;j++)  /*由i+1比較起，比較5次*/
		{	
			if(data[i]>data[j])  /*比較第i及第j個元素*/
			{	
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
	}
	printf("\n");
}
