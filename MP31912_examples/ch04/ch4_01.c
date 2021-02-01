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

  if(NewNode==NULL) /*�w�L�O����i�t�m�Amalloc�|�^��NULL��NewNode */
     printf("�O���餣��!");

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

nodePointer CreateAll(int *data,int n)  /* �p�ը���  4-2 */
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
       printf("�b��C�}�Y�B���J�@�Ӹ`�I%d.....OK!\n",data[i]);       
    }    
    return L;
}

int main()
{

    nodePointer first=NULL;
    int data[6] = {26,18,15,29,32,12};
    
    first = CreateAll(data,6);       /* �p�ը���  4-2 */
    LinkListTraverse(first); 
    
    system("pause");
    return 0; 

}
