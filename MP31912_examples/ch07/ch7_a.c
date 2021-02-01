/*  ch7_a.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

typedef struct nodestr *bt_pointer;
typedef struct nodestr
{
    char data;   /* 資料項為字元  */ 
    bt_pointer left_child,right_child;
}treenode;

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

#define MaxStackSize 100

int top=-1;
bt_pointer stack[MaxStackSize];    /* 以陣列時做堆疊 */

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
     printf("堆疊已滿!");
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
    return p;  // 堆疊空的時候，程式仍應繼續執行，所以不要中斷程式，直接回傳NULL即可   printf("堆疊已空!");    exit(1);
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

void iterator_inorder(bt_pointer node) /* 非遞迴中序走訪 */
{
  /* node一開始應該指向樹的根節點 */
  while(1)
  {
    while(node)
    {
       push(&top,node);         /* push 見6.2.1節 */
       node = node->left_child;
    }
    node = pop(&top);             /* pop 見6.2.1節 */

    if(!node)
        break;   

    printf("%c ",node->data);   /* 如為數值資料改為%d */
    node = node->right_child;
  }
}




int main(void)
{
      char *list = "AB0D00CE0G00F00";  // char *list = "ABDH00I00E00CF0JK00L00G00";
      bt_pointer T;
      printf("二元樹建立中..."); 
      T = CreateBTree(list);
      printf("...建立完畢"); 
      printf("\n二元樹的中序走訪結果:"); 
      iterator_inorder(T);
      

      system("pause");
      return 0;
}
