#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int top=-1;
void push(int stack[],int MAX,int val)
{
	if(top>=MAX-1)
		printf("[堆疊已經滿了]\n");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	if(top<0)
		printf("[堆疊已經空了]\n");
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


int main()
{  
	int card[52],stack[52]={0};
	int i,j,k=0;
	char ascVal;
	int style;
	srand((unsigned)time(NULL));
	for (i=0;i<52;i++)
		card[i]=i+1;
	printf("[洗牌中...請稍後!]\n");
	while(k<30)
	{
		for(i=0;i<51;i++)
			for(j=i+1;j<52;j++)
				if(rand()%52==2)
					Swap(&card[i],&card[j]);  /*洗牌*/
		k++;
	}
	i=0;
	while(i!=52)
	{
		push(stack,52,card[i]);		/*將52張牌推入堆疊*/
		i++;
	}
	printf("[逆時針發牌]\n");
	printf("[顯示各家牌子]\n 東家\t  北家\t   西家\t    南家\n");
	printf("=================================\n");
	while (top >=0)
	{  
		style = stack[top]/13;	/*計算牌子花色*/
		switch(style)			/*牌子花色圖示對應*/
		{
			case 0:				/*梅花*/
				ascVal=5;
				break;
			case 1:				/*方塊*/
				ascVal=4;
				break;
			case 2:				/*紅心*/
				ascVal=3;
				break;
			case 3:				/*黑桃*/
				ascVal=6;
				break;
		}
		printf("[%c%3d]\t",ascVal,stack[top]%13+1);
		if(top%4==0)
			printf("\n");
		top--;
	}
	system("pause");
	return 0;
}
