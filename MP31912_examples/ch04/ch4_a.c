/*  ch4_a.c   */

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node; 
typedef node *nodePointer;
node n1,n2;
nodePointer first;

nodePointer GetNode()
{
  nodePointer NewNode;

  NewNode = (nodePointer)malloc(sizeof(node)); 

  if(NewNode==NULL) /*�w�L�O����i�t�m�Amalloc�|�^��NULL��NewNode */
     printf("�O���餣��!");

  return  NewNode;
}

int insertAfter(nodePointer L, nodePointer m, int d)
{
  nodePointer n = GetNode();
  if(n == NULL)    return false;
  n->data = d;     n->link = NULL;  

  if(m != NULL)
  {
    n->link = m->link; 
    m->link = n; 
  }
  else  /*  ��C�쬰�Ŧ�C */
    L = n;
  return true;
}

nodePointer PreNode(nodePointer L, nodePointer m)
{
  nodePointer B=L;
  while((B != NULL) &&
        (B->link != m))
     B = B->link;
  return B;
}

int DeleteNode(nodePointer L,
               nodePointer m)
{
  nodePointer B;
  if (L == m)
     /*  return ERROR;  */
     exit(1);  
  B = PreNode(L,m);
  if (B == NULL) return false;
  B->link = m->link;
  free(m);
  return true;
}

int main()
{     
    system("pause");
    return 0; 
}
