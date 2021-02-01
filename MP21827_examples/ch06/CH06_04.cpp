/*
[示範]:壓縮稀疏矩陣並輸出結果
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int _ROWS = 8;		//定義列數
const int _COLS = 9;		//定義行數
const int _NOTZERO = 8;		//定義稀疏矩陣中不為0的個數

int main ()
{  
    int i,j,tmpRW,tmpCL,tmpNZ;
    int temp=1;
    int Sparse[_ROWS][_COLS];		//宣告稀疏矩陣
    int Compress[_NOTZERO][3];		//宣告壓縮矩陣
    srand(time(NULL));
    for (i=0;i<_ROWS;i++)			//將稀疏矩陣的所有元素設為0
        for (j=0;j<_COLS;j++)
            Sparse[i][j]=0;
    tmpNZ=_NOTZERO;
    for (i=1;i<tmpNZ+1;i++)
    {
        tmpRW = rand()%_ROWS;
        tmpCL = rand()%_COLS;
        if(Sparse[tmpRW][tmpCL]!=0)	//避免同一個元素設定兩次數值而造成壓縮矩陣中有0
            tmpNZ++;
        Sparse[tmpRW][tmpCL]=i; //隨機產生稀疏矩陣中非零的元素值
    }
    cout<<"[稀疏矩陣的各個元素]"<<endl; //印出稀疏矩陣的各個元素
    for (i=0;i<_ROWS;i++)
    {  
        for (j=0;j<_COLS;j++)
            cout<<"["<<Sparse[i][j]<<"] ";
        cout<<endl;
    }
    //開始壓縮稀疏矩陣
    Compress[0][0] = _ROWS;
    Compress[0][1] = _COLS;
    Compress[0][2] = _NOTZERO;
    for (i=0;i<_ROWS;i++)
        for (j=0;j<_COLS;j++)
            if (Sparse[i][j] != 0)
            {  
                Compress[temp][0]=i;
                Compress[temp][1]=j;
                Compress[temp][2]=Sparse[i][j];
                temp++;
           }
    cout<<"[稀疏矩陣壓縮後的內容]"<<endl; //印出壓縮矩陣的各個元素
    for (i=0;i<_NOTZERO+1;i++)
    {  
        for (j=0;j<3;j++)
            cout<<"["<<Compress[i][j]<<"] ";
        cout<<endl;
    }
}
