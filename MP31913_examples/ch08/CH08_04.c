#include <stdio.h>
#include <stdlib.h>
#define SIZE 8        /*定義陣列大小*/
void inser (int *);     /*宣告插入排序法副程式*/
void showdata (int *);  /*宣告列印陣列副程式*/

int main()
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	
	printf("原始陣列是：");
	showdata(data);
	printf("\n");
	inser(data);
	printf("排序後陣列是：");
	showdata(data);
	
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);   /*列印陣列資料*/
	printf("\n");
}
void inser(int data[])
{  
	int i;     /*i為掃描次數*/
	int no;     /*以j來定位比較的元素*/
	int tmp;   /*tmp用來暫存資料*/
	for (i=1;i<SIZE;i++)  /*掃描迴圈次數為SIZE-1*/
	{  
	 tmp=data[i];
     no=i-1;
     while (no>=0 && tmp<data[no]) /*如果第二元素小於第一元素*/
	{							 
			data[no+1]=data[no];		/*就把所有元素往後推一個位置*/		
			no--;
	} 
	 data[no+1]=tmp;              /*最小的元素放到第一個元素*/	
	}
}
