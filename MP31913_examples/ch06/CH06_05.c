#include <stdio.h>
#include <stdlib.h>

struct tree
{  int data;
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
btree search(btree ptr,int val)     /*搜尋二元樹副程式*/
{  
	int i=1;                     /*判斷執行次數的變數*/
	while(1)
	{  
		if(ptr==NULL)            /*沒找到就傳回NULL*/
			return NULL;
		if(ptr->data==val)       /*節點值等於搜尋值*/
		{  
			printf("共搜尋 %3d 次\n",i);
			return ptr;
		}
		else if(ptr->data > val)  /*節點值大於搜尋值*/
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}

int main()
{  
	int i,data,arr[]={7,1,4,2,8,13,12,11,15,9,5};
	btree ptr=NULL;
	printf("[原始陣列內容]\n");
	for (i=0;i<11;i++)              
	{  
		ptr=creat_tree(ptr,arr[i]);  /*建立二元樹*/
		printf("[%2d] ",arr[i]);
	}
	printf("\n");
	printf("請輸入搜尋值：\n");
	scanf("%d",&data);
	if((search(ptr,data)) !=NULL)        /*搜尋二元樹*/
		printf("你要找的值 [%3d] 有找到!!\n",data);
	else
		printf("您要找的值沒找到!!\n");
	
    system("pause");
	return 0;
}
