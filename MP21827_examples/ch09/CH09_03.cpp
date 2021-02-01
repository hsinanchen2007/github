#include <iostream>
#include <iomanip>
using namespace std;
class tree //節點串列結構宣告
{  
    public :
	    int data; //節點資料 
	    class tree *left,*right; //節點左指標及右指標 
};
typedef class tree node;
typedef node *btree;
btree creat_tree(btree,int);
void pre(btree);
void in(btree);
void post(btree);
int main(void)
{  
	int arr[]={7,4,1,5,16,8,11,12,15,9,2};//原始陣列內容 
	btree ptr=NULL; //宣告樹根 
	cout<<"[原始陣列內容]"<<endl;
	for (int i=0;i<11;i++)//建立二元樹，並將二元樹內容列印出來 
	{  
	    ptr=creat_tree(ptr,arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"[二元樹的內容]"<<endl;
	cout<<"前序走訪結果："<<endl;//列印前、中、後序走訪結果 
	pre(ptr);
	cout<<endl;
	cout<<"中序走訪結果："<<endl;
	in(ptr);
	cout<<endl;
	cout<<"後序走訪結果："<<endl;
	post(ptr);
	cout<<endl;
	return 0;
}
btree creat_tree(btree root,int val)//建立二元樹的副程式 
{  
	btree newnode,current,backup;   //宣告一個新節點newnode存放陣列資料 
	newnode = new node; //current及backup存放暫存指標 
	newnode->data=val;  //指定新節點的資料及左右指標 
	newnode->left=NULL;
	newnode->right=NULL;
	if (root==NULL)//如果root為空值，把新節點傳回當作樹根 
	{  
		root=newnode;
		return root;
	}
	else //若root不是樹根，則建立二元樹 
	{  
		for(current=root;current!=NULL;) //current複製root，以保留目前的樹根值 
		{  
			backup=current; //保留父節點 
			if(current->data > val)//比較樹根節點及新節點資料 
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)//把新節點和樹根連結起來 
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root; //傳回樹指標 
}
void pre(btree ptr) //前序走訪 
{  
	if (ptr != NULL)
	{  
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		pre(ptr->left);
		pre(ptr->right);
	}
}
void in(btree ptr) //中序走訪 
{  
	if (ptr != NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
void post(btree ptr)//後序走訪
{  
	if (ptr != NULL)
	{  
		post(ptr->left);
		post(ptr->right);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
	}
}
