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

void inorder(bt_pointer ptr) /* 中序走訪 */
{
  if(ptr)
  {
      inorder(ptr->left_child);   
      printf("%c ",ptr->data);        /* 如為數值資料改為%d */
      inorder(ptr->right_child);  
  }
}

void preorder(bt_pointer ptr) /* 前序走訪 */
{
  if(ptr) 
  {
       printf("%c ",ptr->data);          /* 如為數值資料改為%d */
       preorder(ptr->left_child);    
       preorder(ptr->right_child);   
  } 
}

void postorder(bt_pointer ptr) /* 後序走訪 */
{
  if(ptr)   
  {    
       postorder(ptr->left_child);    
       postorder(ptr->right_child);   
       printf("%c ",ptr->data);               /* 如為數值資料改為%d */
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
      inorder(T);
      printf("\n二元樹的前序走訪結果:");      
      preorder(T);
      printf("\n二元樹的後序走訪結果:"); 
      postorder(T);    

      system("pause");
      return 0;
}


   
