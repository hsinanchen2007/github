#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

typedef struct nodestr *bt_pointer;
typedef struct nodestr
{
    char data;   /* ��ƶ����r��  */ 
    bt_pointer left_child,right_child;
}treenode;

bt_pointer CreateBTree(char *list)
{
    bt_pointer NewNode=NULL;
    static int i=-1;
    i++;
    if(list[i]!='\0')
    {
        if(list[i]=='0')
           return NULL;
        NewNode = (bt_pointer)malloc(sizeof(treenode));
        NewNode->data = list[i];
        NewNode->left_child = CreateBTree(list);
        NewNode->right_child = CreateBTree(list);        
    }    
    return NewNode;
}

void inorder(bt_pointer ptr) /* ���Ǩ��X */
{
  if(ptr)
  {
      inorder(ptr->left_child);   
      printf("%c ",ptr->data);        /* �p���ƭȸ�Ƨאּ%d */
      inorder(ptr->right_child);  
  }
}

void preorder(bt_pointer ptr) /* �e�Ǩ��X */
{
  if(ptr) 
  {
       printf("%c ",ptr->data);          /* �p���ƭȸ�Ƨאּ%d */
       preorder(ptr->left_child);    
       preorder(ptr->right_child);   
  } 
}

void postorder(bt_pointer ptr) /* ��Ǩ��X */
{
  if(ptr)   
  {    
       postorder(ptr->left_child);    
       postorder(ptr->right_child);   
       printf("%c ",ptr->data);               /* �p���ƭȸ�Ƨאּ%d */
  }    
}

int main(void)
{
      char *list = "AB0D00CE0G00F00";  // char *list = "ABDH00I00E00CF0JK00L00G00";
      bt_pointer T;
      printf("�G����إߤ�..."); 
      T = CreateBTree(list);
      printf("...�إߧ���"); 
      printf("\n�G���𪺤��Ǩ��X���G:"); 
      inorder(T);
      printf("\n�G���𪺫e�Ǩ��X���G:");      
      preorder(T);
      printf("\n�G���𪺫�Ǩ��X���G:"); 
      postorder(T);    

      system("pause");
      return 0;
}


   
