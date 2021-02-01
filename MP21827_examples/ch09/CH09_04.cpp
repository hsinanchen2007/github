#include <iostream>
#include <iomanip>
using namespace std;
class tree
{  
    public:
        int data;
        class tree *left,*right;
};
typedef class tree node;
typedef node *btree;

btree creat_tree(btree,int);
btree pre(btree,int); //搜尋二元樹副程式

int main(void)
{  
	int data,arr[]={7,4,1,5,13,8,11,12,15,9,2};
	btree ptr=NULL;
	cout<<"[原始陣列內容]"<<endl;
	for (int i=0;i<11;i++)              
	{  
	    ptr=creat_tree(ptr,arr[i]);//建立二元樹
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"請輸入搜尋值："<<endl;
	cin>>data;
	if((pre(ptr,data)) !=NULL)//搜尋二元樹
		cout<<"你要找的值 ["<<setw(3)<<data<<"] 有找到!!"<<endl;
	else
		cout<<"您要找的值沒找到!!"<<endl;
	return 0;
}
btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode = new node;
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}
btree pre(btree ptr,int val)//搜尋二元樹副程式
{  
	int i=1;//判斷執行次數的變數
	while(1)
	{  
		if(ptr==NULL) //沒找到就傳回NULL
			return NULL;
		if(ptr->data==val)//節點值等於搜尋值
		{  
			cout<<"共搜尋 "<<setw(3)<<i<<" 次"<<endl;
			return ptr;
		}
		else if(ptr->data > val)//節點值大於搜尋值
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}
