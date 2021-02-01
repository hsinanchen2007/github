#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

struct PolynomialNode
{
    double coef;
    int expont;
    struct PolynomialNode *link;
};
typedef struct PolynomialNode P_Node;
typedef P_Node *P_Node_P;

   
void Attach(P_Node_P *rear,double coef,int expont)
{
   P_Node_P NewNode_P = (P_Node_P)malloc(sizeof(P_Node));
   if (NewNode_P==NULL)
   {
      printf("記憶體不足!");
      exit(1);
   }

   NewNode_P->coef = coef;
   NewNode_P->expont = expont;

   (*rear)->link = NewNode_P;
   (*rear) = NewNode_P;
   (*rear)->link = NULL;
}

   
P_Node_P PolyAdd(P_Node_P p1,P_Node_P p2)
{
    P_Node_P p3=NULL, head=NULL, tail=NULL;
    
    if ((p1==NULL)&&(p2==NULL)) return p3;
    tail = (P_Node_P)malloc(sizeof(P_Node));
    if (tail==NULL)
    {
       printf("記憶體不足!");
       exit(1);
    }
    tail->link = NULL;
    p3 = head = tail;  /* 全部指向首節點  */

    while((p1!=NULL) && (p2!=NULL))
    {
       if(p1->expont > p2->expont)
       {
          Attach(&tail,p1->coef,p1->expont);
          p1 = p1->link;
       }
       else if (p1->expont < p2->expont)
       {
          Attach(&tail,p2->coef,p2->expont);
          p2 = p2->link;
       }
       else if (p1->expont == p2->expont)
       {
          if(p1->coef+p2->coef!=0)
            Attach(&tail, p1->coef+p2->coef,p1->expont);
          p1 = p1->link;
          p2 = p2->link;
       }
    }

    while(p1!=NULL)   /* 一一加入p1的剩餘項目  */
    {
        Attach(&tail,p1->coef,p1->expont);
        p1 = p1->link;
    }
    while(p2!=NULL)   /* 一一加入p2的剩餘項目  */
    {
         Attach(&tail,p2->coef,p2->expont);
         p2=p2->link;
    }
    p3 = head->link;
    free(head);
    return p3;
}

void printPoly(P_Node_P p)
{
  while (p!=NULL)
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

void ErasePoly(P_Node_P p)
{
   P_Node_P freeone;
   while(p!=NULL)
   {
     freeone = p;
     p = p->link;
     free(freeone);
   }
}

int main(void)
{
   P_Node_P F,F_head,F_tail,G,G_head,G_tail,H;

   /************************建立F************************/
   F_tail = (P_Node_P)malloc(sizeof(P_Node));
   if (F_tail==NULL)  {  printf("記憶體不足!");  exit(1);  }
   F_head = F_tail;
   Attach(&F_tail,5,1000);   Attach(&F_tail,7,387);   Attach(&F_tail,10,0);
   F = F_head->link;
   free(F_head);
   printf("F(x)=");  printPoly(F);  /*列印F(x)*/

   /************************建立G************************/
   G_tail = (P_Node_P)malloc(sizeof(P_Node));
   if (G_tail==NULL)  {  printf("記憶體不足!");  exit(1);  }
   G_head = G_tail;
   Attach(&G_tail,10,400);    Attach(&G_tail,6,387);
   Attach(&G_tail,3,2);       Attach(&G_tail,1,0);
   G = G_head->link;
   free(G_head);
   printf("G(x)=");  printPoly(G); /*列印G(x)*/
   
   /************************計算H************************/
   H = PolyAdd(F,G);   /* H(x)=F(x)+G(x) */
   printf("H(x)=");  printPoly(H); /*列印H*/

   ErasePoly(F);   ErasePoly(G);   ErasePoly(H);
   system("pause");
   return 0;
}
