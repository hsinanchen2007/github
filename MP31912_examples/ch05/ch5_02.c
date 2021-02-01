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
      NewNode_P=(P_Node_P) malloc(sizeof(P_Node));
      if (NewNode_P==NULL)  { printf("記憶體不足!");  exit(1);  }
   }
   return NewNode_P;
}
void RetNode(P_Node_P ReleaseNode_P)
{
    ReleaseNode_P->link = avail;
    avail = ReleaseNode_P;
}

void NewCircularListErase(P_Node_P *p)
{
  P_Node_P Node;

  Node = (*p)->link;
  (*p)->link = avail;
  avail = Node;
  (*p) = NULL;
}

void CircularListPolyAttach(P_Node_P *rear,double coef,int expont)
{
    P_Node_P NewNode_P;
    NewNode_P = GetNode();
    NewNode_P->coef = coef;
    NewNode_P->expont = expont;
    NewNode_P->link = (*rear)->link;
    (*rear)->link = NewNode_P;
    (*rear) = NewNode_P;
}

P_Node_P CircularListPolyAdd(P_Node_P p1,P_Node_P p2)
{
  P_Node_P p3,p1_head,p3_tail;
  int OK=0;
  double sum;

  p1_head = p1;
  p1 = p1->link;     /*  指到p1的最高次方項目 */
  p2 = p2->link;     /*  指到p2的最高次方項目 */
  p3 = GetNode();    /*  取得p3的標頭節點  */
  p3->expont = -1;   /*  設定p3的標頭節點  */
  p3_tail = p3;

  do
  {
    if(p1->expont > p2->expont)
    {
       CircularListPolyAttach(&p3_tail,p1->coef,p1->expont);
       p1 = p1->link;
    }
    else if (p1->expont < p2->expont)
    {
       CircularListPolyAttach(&p3_tail,p2->coef,p2->expont);
       p2 = p2->link;
    }
    else if (p1->expont == p2->expont)
    {
       if(p1_head==p1)
            OK = 1;   
       sum = p1->coef + p2->coef;
       if(sum!=0)
            CircularListPolyAttach(&p3_tail,sum,p1->expont);
       p1 = p1->link;
       p2 = p2->link;
    }
  }while(OK!=1);
  p3_tail->link = p3;  /* 環狀最後一個鏈結指回標頭節點 */
  return p3;
}

void printPoly(P_Node_P p)
{
   p = p->link;
   while (p->expont!=-1)
   {
       if(p->expont!=0)
       {
           printf("%.0fx^%d",p->coef,p->expont);
           printf("+");
       }
       else
           printf("%.0f",p->coef);
       p = p->link;
   }
   printf("\n");
}

int main(void)
{
   P_Node_P F,F_tail,G,G_tail,H;

   avail = NULL;

   /***************建立F*************************/
   F = GetNode();   F->expont = -1;
   F->link = F;     F_tail = F;

   CircularListPolyAttach(&F_tail,5,1000);
   CircularListPolyAttach(&F_tail,7,387);
   CircularListPolyAttach(&F_tail,10,0); 
   printf("F(x)=");  printPoly(F);  /*列印F(x)*/
 
   /***************建立G*************************/
   G = GetNode();   G->expont = -1;
   G->link = G;     G_tail = G;
   CircularListPolyAttach(&G_tail,10,400);
   CircularListPolyAttach(&G_tail,6,387);
   CircularListPolyAttach(&G_tail,3,2);
   CircularListPolyAttach(&G_tail,1,0); 
   printf("G(x)=");  printPoly(G); /*列印G(x)*/
 
   H = CircularListPolyAdd(F,G);   /* H(x)=F(x)+G(x) */
   printf("H(x)=");  printPoly(H); /*列印H*/
 
   NewCircularListErase(&F);
   NewCircularListErase(&G);
   NewCircularListErase(&H);
 
   system("pause");
   return 0;
}
