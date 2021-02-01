#include <iostream>
#include <malloc.h>
using namespace std;

struct tree
{  
    int data;
    struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode=(btree)malloc(sizeof(node));
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
btree search(btree ptr,int val) //搜尋二元樹副程式
{  
	while(1)
	{  
		if(ptr==NULL)      //沒找到就傳回NULL               
			return NULL;
		if(ptr->data==val) //節點值等於搜尋值
			return ptr;
		else if(ptr->data > val)  //節點值大於搜尋值
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}   
}
void inorder(btree ptr)    //中序走訪副程式
{  
    if(ptr!=NULL)
    {  
        inorder(ptr->left);
        cout<<"["<<ptr->data<<"]";
        inorder(ptr->right);
    }
}
int main()
{  
    int i,data,arr[]={7,1,4,2,8,13,12,11,15,9,5};
	btree ptr=NULL;
	cout<<"[原始陣列內容]"<<endl;
	for (i=0;i<11;i++)              
	{  
        ptr=creat_tree(ptr,arr[i]); //建立二元樹
        cout<<"["<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"請輸入搜尋鍵值："<<endl;
	cin>>data;
	if((search(ptr,data))!=NULL)    //搜尋二元樹
		cout<<"二元樹中有此節點了!"<<data<<endl;
	else
    {
        ptr=creat_tree(ptr,data);  
        inorder(ptr);
    }
	return 0;
}
