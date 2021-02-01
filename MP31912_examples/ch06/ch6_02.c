#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxQueueSize 100

typedef struct{
    int ItemKey;
    /*   佇列元素的其它欄位  */
}element;

typedef struct{
   element queue[MaxQueueSize];
   int front;
   int rear;
}QueueADT;

bool isEmpty(QueueADT Q)
{
   if(Q.front>=Q.rear) return true;
   else return false;
}

bool isFull(QueueADT Q)
{
   if(Q.rear>=MaxQueueSize-1) return true;
   else return false;
}

void addQ(QueueADT *Q,element item)
{
  if(isFull(*Q)==true)
  {
     printf("佇列已滿!");
     exit(1);
  }
  else
     Q->queue[++Q->rear] = item;
}

element deleteQ(QueueADT *Q)
{
  if(isEmpty(*Q)==true)
  {
     printf("佇列已空!");
     exit(1);
  }
  else
     return  Q->queue[++Q->front];
}

void PrintQueue(QueueADT *Q)
{
    int i;
    printf("front值目前=%d,rear值目前=%d,佇列如下:\n",
                                     Q->front,Q->rear);

    if(Q->front>=Q->rear)
    {
      printf("佇列已空!\n");
      return;
    }

    for(i=0;i<=5;i++)
      printf("  Q[%d]  ",i);
    printf(".....\n");

    for(i=0;i<=5;i++)
    {
      if(i<=Q->front || i>Q->rear)
        printf("|  ==\t");
      else
        printf("|  %2d\t",Q->queue[i]);
    }
    printf("|.....\n");
}

int main(void)
{
    element Item;
    int i;
    QueueADT Q1;
    char ch='I';

    Q1.front = -1;
    Q1.rear = -1;

    while(ch!='E')
    {
      fflush(stdin);
      printf("[A]=addQ,[D]=deleteQ,[E] and [Others]=Exit:");
      scanf("%c",&ch);
      switch(ch)
      {
        case 'A':
          printf("addQ :");
          scanf("%d",&Item.ItemKey);
          addQ(&Q1,Item);
          printf("addQ入%d,",Item.ItemKey);
          PrintQueue(&Q1);
          break;
        case 'D':
          printf("deleteQ出%d,",deleteQ(&Q1).ItemKey);
          PrintQueue(&Q1);
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
