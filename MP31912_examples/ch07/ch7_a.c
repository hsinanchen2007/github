/*  ch7_a.c   */

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

typedef struct{
    int ItemKey;
    /*   ���|�������䥦���  */
}element;

#define MaxStackSize 100

int top=-1;
bt_pointer stack[MaxStackSize];    /* �H�}�C�ɰ����| */

bool isEmpty(int *top)
{
   if(*top<0) return true;
   else return false;
}

bool isFull(int *top)
{
   if(*top>=MaxStackSize-1) return true;
   else return false;
}

void push(int *top,bt_pointer item)
{
  
  if(isFull(top)==true)
  {
     printf("���|�w��!");
     exit(1);
  }
  else
     stack[++(*top)] = item;
     
}

bt_pointer pop(int *top)
{
   bt_pointer p=NULL;
  if(isEmpty(top)==true)
  {
    return p;  // ���|�Ū��ɭԡA�{�������~�����A�ҥH���n���_�{���A�����^��NULL�Y�i   printf("���|�w��!");    exit(1);
  }
  else
  { 
     p = stack[*top];   
    (*top)--;
    return p;
  }
}


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

void iterator_inorder(bt_pointer node) /* �D���j���Ǩ��X */
{
  /* node�@�}�l���ӫ��V�𪺮ڸ`�I */
  while(1)
  {
    while(node)
    {
       push(&top,node);         /* push ��6.2.1�` */
       node = node->left_child;
    }
    node = pop(&top);             /* pop ��6.2.1�` */

    if(!node)
        break;   

    printf("%c ",node->data);   /* �p���ƭȸ�Ƨאּ%d */
    node = node->right_child;
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
      iterator_inorder(T);
      

      system("pause");
      return 0;
}
