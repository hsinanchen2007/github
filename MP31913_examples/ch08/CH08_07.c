#include <stdio.h>
void heap(int*,int);
void ad_heap(int*,int,int);
int main(void)
{  
	int i,size,data[9]={0,5,6,4,8,3,2,7,1};	/*原始陣列內容*/
	size=9;
	printf("原始陣列：");
	for(i=1;i<size;i++)
		printf("[%2d] ",data[i]);
	heap(data,size);/*建立堆積樹*/
	printf("\n排序結果：");
	for(i=1;i<size;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
	system("pause");
	return 0;
}
void heap(int *data,int size)
{  
	int i,j,tmp;
	for(i=(size/2);i>0;i--)	/*建立堆積樹節點*/	
		ad_heap(data,i,size-1);
	printf("\n堆積內容：");
	for(i=1;i<size;i++)	/*原始堆積樹內容*/
		printf("[%2d] ",data[i]);
	printf("\n");
	for(i=size-2;i>0;i--)/*堆積排序*/
	{  
		tmp=data[i+1];/*頭尾節點交換*/      
		data[i+1]=data[1];
		data[1]=tmp;
		ad_heap(data,1,i);/*處理剩餘節點*/
		printf("\n處理過程：");
		for(j=1;j<size;j++)
			printf("[%2d] ",data[j]);
	}
}
void ad_heap(int *data,int i,int size)
{  
	int j,tmp,post;
	j=2*i;
	tmp=data[i];
	post=0;
	while(j<=size && post==0)
	{  
		if(j<size)
		{
			if(data[j]<data[j+1])/*找出最大節點*/
				j++;
		}
		if(tmp>=data[j])/*若樹根較大，結束比較過程*/
			post=1;
		else
		{  
			data[j/2]=data[j];/*若樹根較小，則繼續比較*/
			j=2*j;
		}   
   }
   data[j/2]=tmp;/*指定樹根為父節點*/
}
