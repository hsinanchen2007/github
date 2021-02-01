/*
[示範]:運算兩個矩陣相乘的結果
*/
#include <iostream>
using namespace std;

void MatrixMultiply(int*,int*,int*,int,int,int);
int main()
{
	int M,N,P;
	int i,j;
	//矩陣A部分 
 	cout<<"請輸入矩陣A的維數(M,N): "<<endl;
 	cout<<"M= ";
	cin>>M;
	cout<<"N= ";
	cin>>N;
	int *A = new int[M*N];
	cout<<"[請輸入矩陣A的各個元素]"<<endl;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		    {
               cout<<"a"<<i<<j<<"=";
			   cin>>A[i*N+j];
            }
	//矩陣B部分 
 	cout<<"請輸入矩陣B的維數(N,P): "<<endl;
	cout<<"N= ";
	cin>>N;
	cout<<"P= ";
	cin>>P;
	int *B = new int [N*P];
	cout<<"[請輸入矩陣B的各個元素]"<<endl;
	for(i=0;i<N;i++)
		for(j=0;j<P;j++)
        {
           cout<<"b"<<i<<j<<"=";
		   cin>>B[i*P+j];
        }	
	int *C = new int [M*P];
	MatrixMultiply(A,B,C,M,N,P); //呼叫函數 
	cout<<"[AxB的結果是]"<<endl;
	for(i=0;i<M;i++)
	{
		for(j=0;j<P;j++)
			cout<<C[i*P+j]<<"\t";
		cout<<endl;
	}
}
//進行矩陣相乘 
void MatrixMultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P)
{
	if(M<=0||N<=0||P<=0)
	{
		cout<<"[錯誤:維數M,N,P必須大於0]"<<endl;
		return;
	}
	for(int i=0;i<M;i++)
		for(int j=0;j<P;j++)
		{
			int Temp;
			Temp = 0;
			for(int k=0;k<N;k++)
				Temp = Temp + arrA[i*N+k]*arrB[k*P+j];
			arrC[i*P+j] = Temp;
		}
}
