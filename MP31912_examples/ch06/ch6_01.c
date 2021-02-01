#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

#define MaxStackSize 100
typedef struct{
   element stack[MaxStackSize];
   int top;
}StackADT;

bool isEmpty(StackADT S)
{
   if(S.top<0) return true;
   else return false;
}

bool isFull(StackADT S)
{
   if(S.top>=MaxStackSize-1) return true;
   else return false;
}

void push(StackADT *S,element item)
{
  if(isFull(*S)==true)
  {
     printf("堆疊已滿!");
     exit(1);
  }
  else
     S->stack[++S->top] = item;
}

element pop(StackADT *S)
{
  if(isEmpty(*S)==true)
  {
     printf("堆疊已空!");
     exit(1);
  }
  else
    return  S->stack[S->top--];
}

void PrintStack(StackADT *S)
{
    int i;
    printf("堆疊的top值目前為%d,堆疊內容如下:\n",S->top);

    if(S->top < 0)
    {
        printf("堆疊已空!\n");
        return;
    }
    printf("     |   :  |\n",S->stack[S->top-i]);
    printf("      ------ \n");
    for(i=S->top;i>=0;i--)
    {
        printf("S[%d] |  %2d  |\n",i,S->stack[i]);
        printf("      ------ \n");
    }
}

int main(void)
{
    element Item;
    int i;
    StackADT S1;
    char ch='I';

    S1.top = -1;   /* 堆疊初始化 */ 

    while(ch!='E')
    {
      fflush(stdin);
      printf("[I]=push,[O]=pop,[E] and [Others]=Exit:");
      scanf("%c",&ch);
      switch(ch)
      {
        case 'I':
          printf("push :");
          scanf("%d",&Item.ItemKey);
          push(&S1,Item);
          printf("push入%d,",Item.ItemKey);
          PrintStack(&S1);
          break;
        case 'O':
          printf("pop出%d,",pop(&S1).ItemKey);
          PrintStack(&S1);
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
