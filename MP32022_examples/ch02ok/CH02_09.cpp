#include <iostream>
using namespace std;
#define ARRAY_SIZE 5  // 矩陣的維數大小 
int getValue(int ,int);
int A[ARRAY_SIZE][ARRAY_SIZE]={  //下三角矩陣的內容 
                			{76, 0, 0, 0, 0}, 
               			 	{54, 51, 0, 0, 0}, 
              				{23, 8, 26, 0, 0}, 
                			{43, 35, 28, 18, 0}, 
                			{12, 9, 14, 35, 46}};  
//一維陣列的陣列宣告 
int B[ARRAY_SIZE*(1+ARRAY_SIZE)/2];  
int main()
{
    int i=0,j=0;
    int index;    
		cout<<"=========================================="<<endl;
		cout<<"下三角形矩陣："<<endl;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			    cout<<"\t"<<A[i][j];
		    cout<<endl;  
		}
		/* 將左下三角矩陣壓縮為一維陣列 */
		index=0;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			{
                if(A[i][j]!=0) B[index++]=A[i][j];
            }
        }
		cout<<"==========================================\n";
		cout<<"以一維的方式表示："<<endl;
		cout<<"\t[";
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = i ; j < ARRAY_SIZE ; j++ ) 
		        cout<<" "<<getValue(i,j);
		}
		cout<<" ]";
		cout<<endl;   
}
int getValue(int i, int j) {
        int index = ARRAY_SIZE*i-i*(i+1)/2+j;
        return B[index];
}
