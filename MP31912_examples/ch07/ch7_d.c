/*  ch7_c.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */
#define TRUE 1
#define FALSE 0


typedef struct nodestr *bt_pointer;
typedef struct nodestr
{
    int data;   /* 資料項為數值  */ 
    bt_pointer left_child,right_child;
}treenode;

bt_pointer search(bt_pointer root,int k)
{                /* root指向子樹根節點,k為目標鍵值 */
  if(root == NULL) return NULL;       /* 已找到樹葉節點，仍未找到符合者 */

  if(k == root->data) return root; 

  if(k < root->data)
      return search(root->left_child,k); 
  else
      return search(root->right_child,k); 
}

bt_pointer iteration_search(bt_pointer BSTree,int k)
{
  /*   BSTree指向樹的根節點,k為目標鍵值   */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return BSTree;  
    
    if(k < BSTree->data)
       BSTree = BSTree->left_child;   
    else
       BSTree = BSTree->right_child; 
  }
  return NULL;            /*  已找到樹葉節點，仍未找到符合者  */
}

bt_pointer modify_search(bt_pointer BSTree,int k)
{                /* BSTree指向樹的根節點,k為目標鍵值 */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return NULL;
    if(k < BSTree->data)
    {
       if(BSTree->left_child==NULL) break;
       BSTree = BSTree->left_child; /* 往左子樹找 */
    }
    else
    {
       if(BSTree->right_child==NULL) break; 
       BSTree = BSTree->right_child;  /* 往右子樹找 */
    }
  }
  return BSTree; 
}

void insert_node(bt_pointer *wnode,int num)
{
  bt_pointer ptr;
  bt_pointer temp = modify_search(*wnode,num);

  if(temp || ((*wnode)==NULL))  
  {                    


    ptr = (bt_pointer)malloc(sizeof(treenode)); /* 可增配置是否成功,略 */
    ptr->data = num;
    ptr->left_child = NULL;
    ptr->right_child = NULL;


    if((*wnode)!=NULL)           /* 非空樹時 */
    {
        if(num < temp->data)
             temp->left_child = ptr;
        else
             temp->right_child = ptr;
    }
    else
    {
         *wnode = ptr;               /* 空樹時，新元素直接指定為根節點 */
    }
  }
}

void inorder(bt_pointer ptr) /* 中序走訪 */
{
  if(ptr)
  {
      inorder(ptr->left_child);   
      printf("%d ",ptr->data);        /* 數值資料 */
      inorder(ptr->right_child);  
  }
}

void preorder(bt_pointer ptr) /* 前序走訪 */
{
  if(ptr) 
  {
       printf("%d ",ptr->data);          /* 數值資料 */
       preorder(ptr->left_child);    
       preorder(ptr->right_child);   
  } 
}

int main(void)
{
    
        int i;
  int array[8] = {25,15,30,12,17,12,16,27};
  bt_pointer head=NULL;
  for(i=0;i<=7;i++)
        insert_node(&head,array[i]);

  printf("preoder\n");
  preorder(head);
  printf("\ninoder\n");
  inorder(head);


      system("pause");
      return 0;
}
