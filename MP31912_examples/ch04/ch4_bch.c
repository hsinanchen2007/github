/*  ch4_bch.c   */
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


int HCDLDeleteNode(DnodePointer L,
                   DnodePointer m)
{
  if(L == m)
     return false;
  m->llink->rlink = m->rlink;
  m->rlink->llink = m->llink;
  free(m);
  return true;
}

int main()
{
      
    system("pause");
    return 0; 

}
