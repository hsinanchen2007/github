/*
[示範]:使用相鄰串列來表示圖形(a)及(b)
*/
#include <iostream>
using namespace std;
class list
{
	public:
	int val;
	class list *next;
};
class list head[6];//宣告一個節點型態陣列
int main(void)
{  
	list *ptr,*newnode;
 	int data[14][2]={{1,2},{2,1},{1,5},{5,1},//圖形陣列宣告
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	cout<<"圖形(a)的鄰接串列內容："<<endl;
	for (int i=1;i<6;i++)
	{  
		head[i].val=i; //串列首head
		head[i].next=NULL;
		cout<<"頂點 "<<i<<" =>";	//把頂點值列印出來
		ptr=&(head[i]);          	//暫存節點ptr
		for (int j=0;j<14;j++)      //走訪圖形陣列
		{  
			if (data[j][0]==i)    	//如果節點值=i，加入節點到串列首
			{  
				newnode = new list;
    			newnode->val=data[j][1];//宣告新節點，值為終點值
				newnode->next=NULL;
				while(ptr!=NULL)        //判斷是否為串列的尾端
					ptr=ptr->next;
				ptr=newnode;            //加入新節點
				cout<<"["<<newnode->val<<"] ";//列印相鄰頂點
			}
		}   
		cout<<endl;
	}
}
