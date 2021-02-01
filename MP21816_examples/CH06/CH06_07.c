#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};
typedef struct Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
/*方法enqueue:佇列資料的存入*/
void enqueue(int value) 
{
   QueueByLinkedList node; /*建立節點*/
   node=(QueueByLinkedList)malloc(sizeof(QueueNode));
   node->data=value;
   node->next=NULL;
   /*檢查是否為空佇列*/
   if (rear==NULL)
      front=node;/*新建立的節點成為第1個節點*/
   else
      rear->next=node;/*將節點加入到佇列的尾端*/
   rear=node;/*將佇列的尾端指標指向新加入的節點*/
}
int dequeue(int action)/*方法dequeue:佇列資料的取出*/
{
   int value;
   QueueByLinkedList tempNode,startNode;
   /*從前端取出資料*/
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;/*將佇列資料從前端取出*/
     front=front->next;/*將佇列的前端指標指向下一個*/
     return value;
   }
   /*從尾端取出資料*/
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;/*先記下前端的指標值*/
     value=rear->data;/*取出目前尾端的資料*/
     /*找尋最尾端節點的前一個節點*/
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;/*記錄從尾端取出資料後的佇列前端指標*/
     rear=tempNode;/*記錄從尾端取出資料後的佇列尾端指標*/
     /*下一行程式是指當佇列中僅剩下最節點時,
     取出資料後便將front及rear指向null*/
     if ((front->next==NULL) || (rear->next==NULL)) 
     { 
         front=NULL;
         rear=NULL;
     }
     return value; 
   }
   else return -1;
}

int main()
{
   int temp,item;
   char ch;
   printf("以鏈結串列來實作雙向佇列\n");
   printf("====================================\n");
   
   do
     {
      printf("加入請按 a,取出請按 d,結束請按 e:");
      ch=getche();
      printf("\n");
      if(ch=='a')
      {
       printf("加入的元素值:"); 
       scanf("%d",&item);
       enqueue(item);
       }
       else if(ch=='d')
       {
       temp=dequeue(1);
       printf("從雙向佇列前端依序取出的元素資料值為：%d\n",temp);
       temp=dequeue(2);
       printf("從雙向佇列尾端依序取出的元素資料值為：%d\n",temp);
       }
       else 
         break;
        } while(ch!='e');
       
  system("pause");      
  return 0; 
}
