#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MaxCQueueSize 5

typedef struct{
    int ItemKey;
    /*   ������C�������䥦���  */
}element;

typedef struct{
   element cqueue[MaxCQueueSize];
   int front;
   int rear;
}CQueueADT;

bool isEmpty(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

bool isFull(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

void addCQ(CQueueADT *CQ,element item)
{
  CQ->rear = (CQ->rear+1) % MaxCQueueSize;
  if(isFull(*CQ)==true)
  {
     printf("������C�w��!");
     exit(1);
  }
  else
     CQ->cqueue[CQ->rear] = item;
}

element deleteCQ(CQueueADT *CQ)
{
  if(isEmpty(*CQ)==true)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
  {
     CQ->front = (CQ->front+1) % MaxCQueueSize;
     return  CQ->cqueue[CQ->front];
  }
}

void PrintCQueue(CQueueADT *CQ)
{
    int i;
    printf("front�ȥثe=%d,rear�ȥثe=%d,������C�p�U:\n",
                                      CQ->front,CQ->rear);

    if(isEmpty(*CQ)==true)
    {
        printf("��C�w��!\n");
        return;
    }

    for(i=0;i<5;i++)
        printf("  CQ[%d] ",i);
    printf("\n");

    for(i=0;i<5;i++)
    {
        if(i==CQ->front)
            printf("|   N\t");
        else
            printf("|%4d\t",CQ->cqueue[i]);
    }
    printf("|\n");
}

int main(void)
{
    element Item;
    int i;
    CQueueADT CQ1;
    char ch='I';

    CQ1.front = 0;
    CQ1.rear = 0;
    
    for(i=0;i<MaxCQueueSize;i++)
        CQ1.cqueue[i].ItemKey = 0;
    while(ch!='E')
    {
       fflush(stdin);
       printf("[A]=addCQ,[D]=deleteCQ,[E] and [Others]=Exit:");
       scanf("%c",&ch);
       switch(ch)
       {
        case 'A':
          printf("addCQ :");
          scanf("%d",&Item.ItemKey);
          addCQ(&CQ1,Item);
          printf("addCQ�J%d\n",Item.ItemKey);
          break;
        case 'D':
          printf("deleteCQ�X%d\n",deleteCQ(&CQ1).ItemKey);
          break;
        default:
          ch = 'E';
          PrintCQueue(&CQ1);
          printf("byebye!!\n");
          break;
      }
    }

    system("pause");
    return 0;
}
