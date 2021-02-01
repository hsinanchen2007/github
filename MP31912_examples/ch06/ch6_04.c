#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

typedef struct{
    int ItemKey;
    /*   ���|�������䥦���  */
}element;

struct Stack_Node{
    element Item;
    struct Stack_Node *link;
};

typedef struct Stack_Node S_Node;
typedef S_Node *S_Node_P;

int push(S_Node_P *top,element Item)    /*  �I�s�y�k�� int pushOK = push(&top,Item);  */
{ 
   S_Node_P temp = (S_Node_P)malloc(sizeof(S_Node));  
   if(temp==NULL)
   {
      printf("�O���餣��!");
      return false;
   }
   temp->Item = Item;  
   temp->link = *top;  
   *top = temp;       /*  top�û����V���|������  */
   return true;
}

int pop(S_Node_P *top,element *Item)    /*  �I�s�y�k�� int popOK = pop(&top,&Item);  */
{
   S_Node_P temp = *top;   
   
   if(temp==NULL)
   {
     printf("���|�w��!"); 
     return false;
   }
   *Item = temp->Item;   
   *top  = temp->link;              /*  top�û����V���|������  */
   free(temp);  
   return true;
}

void PrintStack(S_Node_P top)
{
    S_Node_P visitP;
    visitP = top;
    printf("���|����|");
    while(visitP!=NULL)
    {
       printf("%d|",visitP->Item.ItemKey);
       visitP = visitP->link;
    }
    printf("���|����\n");
}

int main(void)
{
    element Item;
    char ch='I';
    S_Node_P top = NULL; /* �@�}�l�ɡAtop���VNULL */ 
   
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
