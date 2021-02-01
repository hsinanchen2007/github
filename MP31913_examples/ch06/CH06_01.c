#include <stdio.h>
#include <stdlib.h>

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	
    for(i=1;i<length;i++) /*把原始陣列中的值逐一比對*/
	{  
		for(level=1;btree[level]!=0;)/*比較樹根及陣列內的值*/
		{  
			if(data[i]>btree[level]) /*如果陣列內的值大於樹根，則往右子樹比較*/
				level=level*2+1;
			else /*如果陣列內的值小於或等於樹根，則往左子樹比較*/
				level=level*2;
		}        /*如果子樹節點的值不為0，則再與陣列內的值比較一次*/
		btree[level]=data[i]; /*把陣列值放入二元樹*/
	}
}
int main()
{  
	int i,length=9;
	int data[]={0,6,3,5,4,7,8,9,2};/*原始陣列*/
	int btree[16]={0}; /*存放二元樹陣列*/
	printf("原始陣列內容：\n");	
	for(i=0;i<length;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
	Btree_create(btree,data,9);
	printf("二元樹內容：\n");
	for (i=1;i<16;i++)
		printf("[%2d] ",btree[i]);
	printf("\n");
	system("pause");
	return 0;
}
