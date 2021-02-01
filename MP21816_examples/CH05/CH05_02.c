/*
[示範]:運算兩個矩陣相乘的結果
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void MatrixMultiply(int*,int*,int*,int,int,int);
int main()
{
	int *A,*B,*C;
	int M,N,P;
	int i,j;
	printf("請輸入矩陣A的維數(M,N): \n");
	printf("M= ");
	scanf("%d",&M);
	printf("N= ");
	scanf("%d",&N);
	A = (int*)malloc(M*N*sizeof(int));
	printf("[請輸入矩陣A的各個元素]\n");
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
            printf("a%d%d=",i,j);
			scanf("%d",&A[i*N+j]);
      }
	printf("請輸入矩陣B的維數(N,P): ");
	printf("\nN= ");
	scanf("%d",&N);
	printf("P= ");
	scanf("%d",&P);
	B = (int*)malloc(N*P*sizeof(int));
	printf("[請輸入矩陣B的各個元素]\n");
	for(i=0;i<N;i++)
		for(j=0;j<P;j++)
		{
            printf("b%d%d=",i,j);
			scanf("%d",&B[i*P+j]);
        }
	C = (int*)malloc(M*P*sizeof(int));
	MatrixMultiply(A,B,C,M,N,P);
	printf("[AxB的結果是]\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<P;j++)
			printf("%d\t",C[i*P+j]);
		printf("\n");
	}
	system("pause");
}
void MatrixMultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P)
{
	int i,j,k,Temp;
	if(M<=0||N<=0||P<=0)
	{
		printf("[錯誤:維數M,N,P必須大於0]\n");
		return;
	}
	for(i=0;i<M;i++)
		for(j=0;j<P;j++)
		{
			Temp = 0;
			for(k=0;k<N;k++)
				Temp = Temp + arrA[i*N+k]*arrB[k*P+j];
			arrC[i*P+j] = Temp;
		}
}
