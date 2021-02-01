/*  ch4_b.c   */

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct DNode  /* ���V�쵲��C���`�I���c�ŧi */
{
    int data;
    struct DNode *llink;
    struct DNode *rlink;
};
typedef struct DNode Dnode;
typedef Dnode *DnodePointer;


DnodePointer DLGetNode()
{
  DnodePointer NewNode;

  NewNode = (DnodePointer) malloc(sizeof(Dnode)); 

  if(NewNode==NULL) /*�w�L�O����i�t�m�Amalloc�|�^��NULL��NewNode */
     printf("�O���餣��!");

  return  NewNode;
}


int DLinsertAfter(DnodePointer L, DnodePointer m, int d)
{
  DnodePointer n = DLGetNode();
  if(n == NULL)    return false;
  n->data = d;
  n->llink = NULL; n->rlink = NULL; 
  if(m != NULL)
  {
    n->llink = m;  
    n->rlink = m->rlink;  
    if(m->rlink != NULL)
       m->rlink->llink = n;  
    m->rlink = n;  
  }
  else
    L = n;
  return true;
}

int DLDeleteNode(DnodePointer L,
                 DnodePointer m)
{
  if((m->llink == NULL) &&
     (m->rlink == NULL))
  {
    L = NULL;
    free(m);
    return true;
  }

  if((m->llink == NULL) ||
     (m->rlink == NULL))
     /*  return ERROR;  */
     exit(1);  
  if((m->llink != NULL) &&
     (m->rlink != NULL))
  {
    m->llink->rlink = m->rlink;
    m->rlink->llink = m->llink;
  }

  free(m);
  return true;
}

int main()
{
      
    system("pause");
    return 0; 

}
