/*
[示範]:求出MxN矩陣的轉置矩陣
*/
#include <iostream>
using namespace std;

int main()
{
	int M,N,row,col;
	cout<<"[輸入MxN矩陣的維度]"<<endl;
	cout<<"請輸入維度M: ";
	cin>>M;
	cout<<"請輸入維度N: ";
	cin>>N;
	
   	int *arrA = new int[M*N];//宣告動態陣列 
	int *arrB = new int[M*N];
 	cout<<"[請輸入矩陣內容]"<<endl;
	for(row=1;row<=M;row++)
	{
		for(col=1;col<=N;col++)
		{
			cout<<"a"<<row<<col<<"=";
			cin>>arrA[(row-1)*N+(col-1)];
		}
	}
	cout<<"[輸入矩陣內容為]"<<endl;
	for(row=1;row<=M;row++)
	{
		for(col=1;col<=N;col++)
		{
			cout<<arrA[(row-1)*N+(col-1)]<<"\t";
		}
		cout<<endl;
	}
	//進行矩陣轉置的動作
	for(row=1;row<=N;row++)
		for(col=1;col<=M;col++)
			arrB[(col-1)*N+(row-1)]=arrA[(row-1)+(col-1)*N];

	cout<<"[轉置矩陣內容為]"<<endl;
	for(row=1;row<=N;row++)
	{
		for(col=1;col<=M;col++)
		{
			cout<<arrB[(col-1)*N+(row-1)]<<"\t";
		}
		cout<<endl;
	}
}
