/*   LSD Radix Sort algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct list_node *list_pointer;
typedef struct list_node *node_pointer;
typedef struct list_node{
      int data;
      list_pointer next;
}nodetype;

list_pointer SetData(int size)
{
    int i=1;
    node_pointer ptr,before,temp;

    ptr = NULL;
    srand((unsigned) time(NULL));
    temp = (node_pointer)malloc(sizeof(nodetype));
    if(temp==NULL) { printf("�O���餣��!");  exit(1); }
    temp->data = rand() % 1000; /* �H�����ͤT��Ƹ�� */
    temp->next = NULL;
    before = temp;
    ptr = before;

    for(i=2;i<=size;i++)
    {
      temp = (node_pointer)malloc(sizeof(nodetype));
      if(temp==NULL) { printf("�O���餣��!");  exit(1); }
      temp->data = rand() % 1000; /* �H�����ͤT��Ƹ�� */
      temp->next = NULL;
      before->next = temp;
      before = temp;
    }
    return ptr;
  }

void PrintData(list_pointer ptr)
{
    while(ptr!=NULL)
    {
        printf("%4d  ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

list_pointer LSD_RadixSort(list_pointer ptr, int compare_times)
{
    int i,x,d,s=1;
    list_pointer temp,front[10],rear[10];
    for (i=0;i<compare_times;i++)    /* �q�̫�@��}�l�B�zm�Ӧ�� */
    { 
        for (x=0;x<=9;x++)
        {
           front[x] = NULL; rear[x] = NULL;
        }
        while(ptr!=NULL)
        {
            d = ((int)(ptr->data/s)) % 10;
            temp = ptr;
            ptr = ptr->next;
            temp->next = NULL;
            if(front[d]!= NULL)  
            {     /* �YQueue[d]���� */
               rear[d]->next = temp; rear[d] = temp;
            }
            else  /* �YQueue[d]�D�� */
            {  
               front[d] = temp;      rear[d] = temp;
            }
        } 
        d = 0;
        while(front[d]==NULL)  /* ���L�e���Ū���C */
            d++;
        ptr = front[d];        temp=rear[d];
        d++;
        while(d<10)
        { 
           if (front[d]!=NULL)
           {
              temp->next = front[d];
              temp = rear[d];
           }
           d++;
        }
        s = s*10;
   }
   return ptr;
}

int main()
{
   list_pointer ptr=NULL;
   ptr = SetData(8); /* ����8���T��Ƹ�� */
   printf("�Ƨǫe �O����:"); PrintData(ptr);
   ptr = LSD_RadixSort(ptr,3);
   printf("�Ƨǫ� �O����:"); PrintData(ptr);
   system("pause");
   return 0;
}
