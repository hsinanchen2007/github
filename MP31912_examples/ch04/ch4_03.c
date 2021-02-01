/*  ch4_03.c   */
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



nodePointer CreateAllC(int *data,int n)  /* 環狀串列的建立 */
{
    nodePointer L=NULL;
    nodePointer w;
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
   /*  製作最後指回第一個節點的鏈結 */ 
   w = L;
   while(w->link != NULL)
   {
     w = w->link;
   }
   w->link=L;
   
   return L;
}

void CLinkListTraverse(nodePointer L)
{
   nodePointer w=L;
   if(w!=NULL)   /*鏈結串列不為空串列 */
      do
      {
         printf("%d \t",w->data);
         w = w->link;
      }while(w!=L);
}

int main()
{

    nodePointer first=NULL;
    int data[6] = {26,18,15,29,32,12};
    
    first = CreateAllC(data,6);     /* 環狀串列的建立 */
    CLinkListTraverse(first);  
    
    system("pause");
    return 0; 

}
