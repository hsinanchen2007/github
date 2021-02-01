/*  ch8_a.c   */

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



int main(void)
{
   
      

      system("pause");
      return 0;
}
