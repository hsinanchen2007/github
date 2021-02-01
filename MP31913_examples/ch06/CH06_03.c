#include <stdio.h>
#include <stdlib.h>

struct tree
{  int data;
   struct tree *left,*right;
};
typedef struct tree node;
typedef node *btree;

btree creat_tree(btree,int);
void inorder(btree ptr)       /*中序走訪副程式*/
{  
  if(ptr!=NULL)
     {  
      inorder(ptr->left);
      printf("[%2d] ",ptr->data);
      inorder(ptr->right);
      }
}
int main()
{  
	int i,data[]={5,6,24,8,12,3,17,1,9};
	btree ptr=NULL;
	btree root=NULL;
	
	for(i=0;i<9;i++)
	  ptr=creat_tree(ptr,data[i]);       /*建立二元樹*/
	
	
    printf("====================\n");
    printf("排序完成結果：\n");
    inorder(ptr);   /*中序走訪*/
    printf("\n");
	
    system("pause");
	return 0;
}
btree creat_tree(btree root,int val)    /*建立二元樹函數*/
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

