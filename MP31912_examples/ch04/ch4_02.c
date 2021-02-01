/*  ch4_02.c   */
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

nodePointer GetNode()
{
  nodePointer NewNode;

  NewNode = (nodePointer) malloc(sizeof(node)); 

  if(NewNode==NULL) /*已無記憶體可配置，malloc會回傳NULL給NewNode */
     printf("記憶體不足!");

  return  NewNode;
}

void LinkListTraverse(nodePointer L)
{
   nodePointer w=L;
   while(w != NULL)
   {
     printf("%d \t",w->data);
     w = w->link;
   }
}


nodePointer CreateAll(int *data,int n)  /* 小試身手  4-2 */
{
    nodePointer L=NULL;
    int i;
    for(i=n-1;i>=0;i--)
    {
       nodePointer n = GetNode();
       if(n == NULL)    exit(1);
       n->data = data[i];
       n->link = L;
       L = n;
       printf("在串列開頭處插入一個節點%d.....OK!\n",data[i]);       
    }    
    return L;
}

nodePointer Concatenate(nodePointer L1,nodePointer L2)
{
   nodePointer w=L1;
   if(w != NULL)  /* L1不為空串列 */
   {
      while(w->link != NULL)  
         w = w->link;
      w->link = L2;
   }
   else  /* L1為空串列 */
      L1 = L2;
   return L1;   
}

int main()
{

    nodePointer L1=NULL,L2=NULL;
    int d1[3] = {26,18,15};
    int d2[3] = {26,18,15};
    L1 = CreateAll(d1,3);       /* 小試身手  4-2 */
    L2 = CreateAll(d2,3);       /* 小試身手  4-2 */
    L1 = Concatenate(L1,L2);
    LinkListTraverse(L1); 
        
    system("pause");
    return 0; 

}
