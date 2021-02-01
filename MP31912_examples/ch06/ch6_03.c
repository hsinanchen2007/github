#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxCQueueSize 5

typedef struct{
    int ItemKey;
    /*   環狀佇列元素的其它欄位  */
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
     printf("環狀佇列已滿!");
     exit(1);
  }
  else
     CQ->cqueue[CQ->rear] = item;
}

element deleteCQ(CQueueADT *CQ)
{
  if(isEmpty(*CQ)==true)
  {
     printf("佇列已空!");
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
    printf("front值目前=%d,rear值目前=%d,環狀佇列如下:\n",
                                      CQ->front,CQ->rear);

    if(isEmpty(*CQ)==true)
    {
        printf("佇列已空!\n");
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
          printf("addCQ入%d\n",Item.ItemKey);
          break;
        case 'D':
          printf("deleteCQ出%d\n",deleteCQ(&CQ1).ItemKey);
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
