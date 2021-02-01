/*  ch4_bch.c   */
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct DNode  /* 雙向鏈結串列的節點結構宣告 */
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

  if(NewNode==NULL) /*已無記憶體可配置，malloc會回傳NULL給NewNode */
     printf("記憶體不足!");

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
