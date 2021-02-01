/*  ch4_01.c   */
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

int main()
{

    nodePointer first=NULL;
    int data[6] = {26,18,15,29,32,12};
    
    first = CreateAll(data,6);       /* 小試身手  4-2 */
    LinkListTraverse(first); 
    
    system("pause");
    return 0; 

}
