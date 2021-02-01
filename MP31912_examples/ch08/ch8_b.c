/*  ch8_b.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxVertexSize 101  /* 最多100個頂點 */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;     
    struct node *next;
}graphnode;

node_pointer graph[MaxVertexSize];

int n=1;  /* 目前正在處理的頂點編號 */

#define FALSE 0
#define TRUE 1

short int visited[MaxVertexSize]; 

void dfs(int v)    /*  v為拜訪起點 */
{
   node_pointer w;
   printf("%d\n",v);     /* 印出頂點 */
   visited[v] = TRUE;      /* 設定為已拜訪 */
    
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
