#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

struct PolynomialNode_Of_CircularList
{
    double coef;
    int expont;
    struct PolynomialNode_Of_CircularList *link;
};
typedef struct PolynomialNode_Of_CircularList P_Node;
typedef P_Node *P_Node_P;

P_Node_P avail;   /* avail為全域變數 */

P_Node_P GetNode(void)
{
   P_Node_P NewNode_P;
   if(avail!=NULL)
   {
      NewNode_P = avail;
      avail = avail->link;
   }
   else
   {
      NewNode_P = (P_Node_P)malloc(sizeof(P_Node));
      if (NewNode_P==NULL)  { printf("記憶體不足!");  exit(1);  }
   }
   return NewNode_P;
}
void RetNode(P_Node_P ReleaseNode_P)
{
    ReleaseNode_P->link = avail;
    avail = ReleaseNode_P;
}

void CircularListErase(P_Node_P *p)
{
    P_Node_P SecondNode;
    if((*p)!=NULL)
    {
      SecondNode = (*p)->link;
      (*p)->link = avail;
      avail = SecondNode;
      (*p) = NULL;
    }
}


int main(void)
{
   system("pause");
   return 0;
}
