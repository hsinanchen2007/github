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

  if(NewNode==NULL) /*�w�L�O����i�t�m�Amalloc�|�^��NULL��NewNode */
     printf("�O���餣��!");

  return  NewNode;
}



nodePointer CreateAllC(int *data,int n)  /* ������C���إ� */
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
       printf("�b��C�}�Y�B���J�@�Ӹ`�I%d.....OK!\n",data[i]);       
    }    
   /*  �s�@�̫���^�Ĥ@�Ӹ`�I���쵲 */ 
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
   if(w!=NULL)   /*�쵲��C�����Ŧ�C */
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
    
    first = CreateAllC(data,6);     /* ������C���إ� */
    CLinkListTraverse(first);  
    
    system("pause");
    return 0; 

}
