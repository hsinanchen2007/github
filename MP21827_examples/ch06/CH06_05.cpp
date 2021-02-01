/*
[示範]:將兩個最高次方相等的多項式相加後輸出結果
*/
#include <iostream>
using namespace std; 

const int ITEMS = 6;
void PrintPoly(int Poly[],int items);
void PolySum(int Poly1[ITEMS],int Poly2[ITEMS]);
int main()
{  
	int PolyA[ITEMS]={4,3,7,0,6,2};	//宣告多項式A
	int PolyB[ITEMS]={4,1,5,2,0,9};	//宣告多項式B
	cout<<"多項式A=>";
	PrintPoly(PolyA,ITEMS);			//印出多項式A
	cout<<"多項式B=>";
	PrintPoly(PolyB,ITEMS);			//印出多項式B
	cout<<"A+B =>";
	PolySum(PolyA,PolyB);//多項式A+多項式B
}
void PrintPoly(int Poly[],int items)
{  
	int MaxExp;
	MaxExp=Poly[0];
	for(int i=1;i<=Poly[0]+1;i++)
	{  
		MaxExp--;
		if(Poly[i]!=0)	//如果該項式0就跳過
		{  
			if((MaxExp+1)!=0)
				cout<<" "<<Poly[i]<<"X^"<<MaxExp+1<<" ";
			else
				cout<<" "<<Poly[i];
			if(MaxExp>=0)
				cout<<"+";      
		}
	}
	cout<<endl;
}
void PolySum(int Poly1[ITEMS],int Poly2[ITEMS])
{  
	int result[ITEMS];
	result[0] = Poly1[0];
	for(int i=1;i<=Poly1[0]+1;i++)
		result[i]=Poly1[i]+Poly2[i];//等羃的係數相加
	PrintPoly(result,ITEMS);
}
