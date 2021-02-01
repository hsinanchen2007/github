#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* °O¿ý bool¦CÁ|­È */

struct SingleLinkList_Node
{
    int data;
    struct SingleLinkList_Node *link;
};
typedef struct SingleLinkList_Node S_Node;
typedef S_Node *S_Node_P;

S_Node_P InvertList(S_Node_P Lead)
{
  S_Node_P newLead=NULL, newLeadNext=NULL;  
  while(Lead != NULL)
  {
       newLeadNext = newLead;  
       newLead = Lead;  
       Lead = Lead->link;  
       newLead->link = newLeadNext;  
  }
  return newLead;
}



int main(void)
{
   system("pause");
   return 0;
}
