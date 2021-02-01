#include <stdio.h>
#include <stdlib.h>

int main ()
{  
	int i,j,NONZERO=0;
	int temp=1;
	int Sparse[6][6]={ 15,0,0,22,0,-15,0,11,3,0,0,0,
                       0,0,0,-6,0,0,0,0,0,0,0,0,91,0
                       ,0,0,0,0,0,0,28,0,0,0};		/*宣告稀疏矩陣,稀疏矩陣的所有元素設為0*/
	int Compress[9][3];		/*宣告壓縮矩陣*/
    
    
	printf("[稀疏矩陣的各個元素]\n"); /*印出稀疏矩陣的各個元素*/
	for (i=0;i<6;i++)
	{  
		for (j=0;j<6;j++)
		{
			printf("[%d]\t ",Sparse[i][j]);
			if (Sparse[i][j] !=0) NONZERO++;
        }
		printf("\n");
	}
	/*開始壓縮稀疏矩陣*/
	Compress[0][0] = 6;
	Compress[0][1] = 6;
	Compress[0][2] = NONZERO;
	for (i=0;i<6;i++)
		for (j=0;j<6;j++)
			if (Sparse[i][j] != 0)
			{  
				Compress[temp][0]=i;
				Compress[temp][1]=j;
				Compress[temp][2]=Sparse[i][j];
				temp++;
			}
	printf("[稀疏矩陣壓縮後的內容]\n"); /*印出壓縮矩陣的各個元素*/
	for (i=0;i<NONZERO+1;i++)
	{  
		for (j=0;j<3;j++)
			printf("[%d] ",Compress[i][j]);
		printf("\n");
	}
	system("pause");
}
