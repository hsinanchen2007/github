/*  ch7_b.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* °O¿ý bool¦CÁ|­È */
#define TRUE 1
#define FALSE 0


typedef struct thread_T_node *thread_bt_pointer;
typedef struct thread_T_node
{
    short int left_thread,right_thread;
    char data;
    thread_bt_pointer left_child,right_child;
}threadTreenode;





thread_bt_pointer thread_inoder_successor(thread_bt_pointer temp)
{
   thread_bt_pointer ptr;
   ptr = temp->right_child;
   if(temp->right_thread!=TRUE)
   {
     while(temp->left_thread!=TRUE)  
     {        
        ptr = ptr->left_child;
     }
   }
   return ptr;
}

void thread_inorder(thread_bt_pointer tree)
{
  thread_bt_pointer temp = tree;
  while(1)
  {
     temp = thread_inoder_successor(temp);

     if(temp==tree) break;

     printf("%c ",temp->data);
  }  
}

void insert_right(thread_bt_pointer parent,thread_bt_pointer child)
{
  thread_bt_pointer temp;
 
  child->right_child = parent->right_child;
  child->right_thread = parent->right_thread;
  
  child->left_child = parent;
  child->left_thread = TRUE;
  
  parent->right_child = child;
  parent->right_thread = FALSE;
  
  if(child->right_thread==FALSE)
  {
     temp = thread_inoder_successor(child);
     temp->left_child = child;     
  }
}

int main(void)
{
    
      

      system("pause");
      return 0;
}
