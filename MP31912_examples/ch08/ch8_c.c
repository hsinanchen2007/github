/*  ch8_c.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MaxVertexSize 101  /* �̦h100�ӳ��I */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;     
    struct node *next;
}graphnode;

node_pointer graph[MaxVertexSize];

int n=1;  /* �ثe���b�B�z�����I�s�� */

#define FALSE 0
#define TRUE 1

short int visited[MaxVertexSize]; 



struct Queue_Node{
    int vertex;
    struct Queue_Node *link;
};

typedef struct Queue_Node Q_Node;
typedef Q_Node *Q_Node_P;

void addQ(Q_Node_P *front,Q_Node_P *rear,int vertex)
{
   Q_Node_P temp;
   temp=(Q_Node_P) malloc(sizeof(Q_Node));
   if(temp==NULL)
   {
     printf("�O���餣��!");
     exit(1);
   }
   temp->vertex = vertex;
   temp->link = NULL;
   if (*front==NULL)
      *front = temp;
   else
     (*rear)->link = temp;
   *rear = temp;
 
}

int deleteQ(Q_Node_P *front)
{
   Q_Node_P temp=*front;
   int vertex;
   if(temp==NULL)
   {
     printf("��C�w��!");
     exit(1);
   }
   vertex = temp->vertex;
   *front = temp->link;
   free(temp);
   return vertex;
}

void bfs(int v)
{
  node_pointer w;
  Q_Node_P front,rear;
  front = rear = NULL;
  printf("%d\n",v);
  visited[v] = TRUE;
  addQ(&front,&rear,v);

  while(front!=NULL)          /* �Ĥ@�h�j��P�_��C�O�_���� */
  {
      v = deleteQ(&front);        /* ���X��C���� */
      w = graph[v];
      while(w!=NULL)  
      {
        if(visited[w->vertex]!=TRUE)
        {
              printf("%d\n",w->vertex);
              visited[w->vertex]=TRUE; 
              addQ(&front,&rear,w->vertex); 
        }
        w = w->next;
      }
  }
}



int main(void)
{
   
      

      system("pause");
      return 0;
}
