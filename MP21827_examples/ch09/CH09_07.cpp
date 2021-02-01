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
void in(btree);
int main(void)
{  
	int data;
	btree ptr=NULL;
	cout<<"請輸入資料，結束請輸入-1："<<endl;
	while (1)                         
	{  
		cin>>data; //輸入資料
		if(data==-1)//結束輸入
			break;                      
		ptr=creat_tree(ptr,data);//建立二元樹
	}
	cout<<"=============="<<endl;
	cout<<"排序完成結果："<<endl;
	in(ptr); //中序走訪
	cout<<endl;
	return 0;
}
btree creat_tree(btree root,int val)//建立二元樹副程式
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
void in(btree ptr)//中序走訪副程式
{  
	if(ptr!=NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
