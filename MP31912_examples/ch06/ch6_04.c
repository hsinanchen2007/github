#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

struct Stack_Node{
    element Item;
    struct Stack_Node *link;
};

typedef struct Stack_Node S_Node;
typedef S_Node *S_Node_P;

int push(S_Node_P *top,element Item)    /*  呼叫語法為 int pushOK = push(&top,Item);  */
{ 
   S_Node_P temp = (S_Node_P)malloc(sizeof(S_Node));  
   if(temp==NULL)
   {
      printf("記憶體不足!");
      return false;
   }
   temp->Item = Item;  
   temp->link = *top;  
   *top = temp;       /*  top永遠指向堆疊的頂端  */
   return true;
}

int pop(S_Node_P *top,element *Item)    /*  呼叫語法為 int popOK = pop(&top,&Item);  */
{
   S_Node_P temp = *top;   
   
   if(temp==NULL)
   {
     printf("堆疊已空!"); 
     return false;
   }
   *Item = temp->Item;   
   *top  = temp->link;              /*  top永遠指向堆疊的頂端  */
   free(temp);  
   return true;
}

void PrintStack(S_Node_P top)
{
    S_Node_P visitP;
    visitP = top;
    printf("堆疊頂端|");
    while(visitP!=NULL)
    {
       printf("%d|",visitP->Item.ItemKey);
       visitP = visitP->link;
    }
    printf("堆疊底端\n");
}

int main(void)
{
    element Item;
    char ch='I';
    S_Node_P top = NULL; /* 一開始時，top指向NULL */ 
   
    while(ch!='E')
    {
      fflush(stdin);
      printf("[I]=push,[O]=pop,[P]=print,[E]and[Others]=Exit:");
      scanf("%c",&ch);
      switch(ch)
      {
        case 'I':
          printf("push:");
          scanf("%d",&Item.ItemKey);
          if(push(&top,Item)==true)
             printf("push successful...\n");
          else
             printf("push unsuccessful...\n"); 
          break;
        case 'O':
          if(pop(&top,&Item)==true)
             printf("pop %d successful...\n",Item.ItemKey);
          else 
             printf("pop unsuccessful...\n");
          break;
        case 'P':
          PrintStack(top);
          break;
        default:
          ch = 'E';
          printf("byebye!!\n");
          break;
      }
    }
    system("pause");
    return 0;
}
