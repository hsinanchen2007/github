/*  ch8_a.c   */

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



int main(void)
{
   
      

      system("pause");
      return 0;
}
