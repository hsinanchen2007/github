#include <iostream>
using namespace std;

class tree //節點串列結構宣告
{  
	public:
	int data; //節點資料
	class tree *left,*right; //節點左指標及右指標
};
typedef class tree node;
typedef node *btree;
void Inorder(btree ptr);
int main(void)
{  
	int i,level;
	int data[]={0,6,3,5,9,7,8,4,2}; //原始陣列
	int btree[16]={0}; //存放二元數陣列
	cout<<"原始陣列內容："<<endl;
	for (i=1;i<9;i++)
		cout<<"["<<data[i]<<"] ";
	cout<<endl;
	for(i=1;i<9;i++)   //把原始陣列中的值逐一比對
	{  
		for(level=1;btree[level]!=0;)
		//比較樹根及陣列內的值
		{  
			if(data[i]>btree[level])
			//如果陣列內的值大於樹根，則往右子樹比較
				level=level*2+1;
			else  //如果陣列內的值小於或等於樹根，則往左子樹比較
				level=level*2;
		}     //如果子樹節點的值不為0，則再與陣列內的值比較一次
		btree[level]=data[i];  //把陣列值放入二元樹
	}
	cout<<"二元樹內容："<<endl;
	for (i=1;i<16;i++)
		cout<<"["<<btree[i]<<"] ";
	cout<<endl;
	return 0;
}
void Inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->left); //走訪左子樹
		cout<<"["<<ptr->data<<"]"; //走訪列印樹根
		Inorder(ptr->right); //走訪右子樹
	}
}
