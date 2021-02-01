/*  ch7_c.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */
#define TRUE 1
#define FALSE 0


typedef struct nodestr *bt_pointer;
typedef struct nodestr
{
    int data;   /* ��ƶ����ƭ�  */ 
    bt_pointer left_child,right_child;
}treenode;

bt_pointer search(bt_pointer root,int k)
{                /* root���V�l��ڸ`�I,k���ؼ���� */
  if(root == NULL) return NULL;       /* �w���𸭸`�I�A�������ŦX�� */

  if(k == root->data) return root; 

  if(k < root->data)
      return search(root->left_child,k); 
  else
      return search(root->right_child,k); 
}

bt_pointer iteration_search(bt_pointer BSTree,int k)
{
  /*   BSTree���V�𪺮ڸ`�I,k���ؼ����   */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return BSTree;  
    
    if(k < BSTree->data)
       BSTree = BSTree->left_child;   
    else
       BSTree = BSTree->right_child; 
  }
  return NULL;            /*  �w���𸭸`�I�A�������ŦX��  */
}

bt_pointer modify_search(bt_pointer BSTree,int k)
{                /* BSTree���V�𪺮ڸ`�I,k���ؼ���� */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return NULL;
    if(k < BSTree->data)
    {
       if(BSTree->left_child==NULL) break;
       BSTree = BSTree->left_child; /* �����l��� */
    }
    else
    {
       if(BSTree->right_child==NULL) break; 
       BSTree = BSTree->right_child;  /* ���k�l��� */
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


    ptr = (bt_pointer)malloc(sizeof(treenode)); /* �i�W�t�m�O�_���\,�� */
    ptr->data = num;
    ptr->left_child = NULL;
    ptr->right_child = NULL;


    if((*wnode)!=NULL)           /* �D�ž�� */
    {
        if(num < temp->data)
             temp->left_child = ptr;
        else
             temp->right_child = ptr;
    }
    else
    {
         *wnode = ptr;               /* �ž�ɡA�s�����������w���ڸ`�I */
    }
  }
}

void inorder(bt_pointer ptr) /* ���Ǩ��X */
{
  if(ptr)
  {
      inorder(ptr->left_child);   
      printf("%d ",ptr->data);        /* �ƭȸ�� */
      inorder(ptr->right_child);  
  }
}

void preorder(bt_pointer ptr) /* �e�Ǩ��X */
{
  if(ptr) 
  {
       printf("%d ",ptr->data);          /* �ƭȸ�� */
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
