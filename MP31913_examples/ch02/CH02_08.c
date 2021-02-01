/*
[示範]:上三角矩陣 
*/
#include <stdio.h>
#define ARRAY_SIZE 5  /* 矩陣的維數大小 */
int getValue(int ,int);
int A[ARRAY_SIZE][ARRAY_SIZE]={  /*上三角矩陣的內容 */
                			{7, 8, 12, 21, 9}, 
               			 	{0, 5, 14,  17, 6}, 
              				{0, 0, 7, 23, 24}, 
                			{0, 0, 0,  32, 19}, 
                			{0, 0, 0,  0,  8}};  
/* 一維陣列的陣列宣告 */
int B[ARRAY_SIZE*(1+ARRAY_SIZE)/2];  
int main()
{
    int i=0,j=0;
    int index;    
		printf("==========================================\n");
		printf("上三角形矩陣：\n");
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
		        printf("\t%d",A[i][j]);
		    printf("\n");    
		}
		/* 將右上三角矩陣壓縮為一維陣列 */
		index=0;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			{
                if(A[i][j]!=0) B[index++]=A[i][j];
            }
        }
		printf("==========================================\n");
		printf("以一維陣列的方式表示：\n");
		printf("\t[");
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = i ; j < ARRAY_SIZE ; j++ ) 
		        printf(" %d",getValue(i,j));
		}
		printf(" ]");
		printf("\n");    
		system("pause");
		return 0; 
}
int getValue(int i, int j) {
        int index = ARRAY_SIZE*i - i*(i+1)/2 + j;
        return B[index];
}
