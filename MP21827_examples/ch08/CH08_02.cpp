#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
void Swap(int*,int*);
void push(int statck[],int MAX,int val);
int pop(int stack[]);
int top=-1;
int main(void)
{  
	int card[52],stack[52]={0};
	int i,j,k=0;
	char ascVal;
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	cout<<"[洗牌中...請稍後!]"<<endl;
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);//洗牌
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);//將52張牌推入堆疊
		i++;
	}
	cout<<"[逆時針發牌]"<<endl;
	cout<<"[顯示各家牌子]"<<endl;
 	cout<<" 東家\t 北家\t 西家\t 南家"<<endl;
	cout<<"================================="<<endl;
	while (top >=0)
	{  
		style = stack[top]/13;//計算牌子花色
		switch(style)  //牌子花色圖示對應
		{
			case 0:	   //梅花
				ascVal=5;
				break;
			case 1:	   //方塊
				ascVal=4;
				break;
			case 2:	   //紅心
				ascVal=3;
				break;
			case 3:	   //黑桃
				ascVal=6;
				break;
		}
		cout<<"["<<ascVal<<setw(3)<<stack[top]%13+1<<"] \t";
		if(top%4==0)
			cout<<endl;
		top--;
	}
    return 0;
}
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		cout<<"[堆疊已經滿了]"<<endl;
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		cout<<"[堆疊已經空了]"<<endl;
	else
		top--;
	return stack[top];
}
void Swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
