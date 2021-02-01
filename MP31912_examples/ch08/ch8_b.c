/*  ch8_b.c   */

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

void dfs(int v)    /*  v�����X�_�I */
{
   node_pointer w;
   printf("%d\n",v);     /* �L�X���I */
   visited[v] = TRUE;      /* �]�w���w���X */
    
   w = graph[v];
   while(w!=NULL)
   {
     if(visited[w->vertex]!=TRUE)
        dfs(w->vertex);
     w = w->next; 
   }   
}



int main(void)
{
   
      

      system("pause");
      return 0;
}
