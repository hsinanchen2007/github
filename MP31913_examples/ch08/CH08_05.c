#include <stdio.h>
#include <stdlib.h>
#define SIZE 8           

void shell (int *,int);   /*宣告排序法副程式*/
void showdata (int *);   /*宣告列印陣列副程式*/

int main(void)
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	printf("原始陣列是：     ");	
	showdata (data);
	printf("-----------------------------------------\n");
	shell(data,SIZE);
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void shell(int data[],int size)
{  
	int i;        /*i為掃描次數*/
	int j;        /*以j來定位比較的元素*/
	int k=1;      /*k列印計數*/
	int tmp;      /*tmp用來暫存資料*/
	int jmp;      /*設定間距位移量*/
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  /*插入排序法*/
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		printf("第 %d 次排序過程：",k++);
		showdata (data);
		printf("-----------------------------------------\n");
		jmp=jmp/2;    /*控制迴圈數*/
	}
}
