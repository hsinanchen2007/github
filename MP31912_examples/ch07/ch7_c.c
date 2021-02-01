/*  ch7_c.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */
#define TRUE 1
#define FALSE 0


#define MaxSize 201            /* �ְ�i�H�̦h��200�Ӥ��� */
#define HeapFull(n) (n==MaxSize-1)/* n�N��ثe�ְ靈�X�Ӥ���  */
#define HeapEmpty(n) (!n)      /* n��0��,!0=1 -> �۷��^��TRUE */

typedef struct
{
    int key; 
    /* ��L��� */
}element;

element heap[MaxSize];       /* �ŧi�s��ְ諸�}�C */
int n=0; 

void insert_maxheap(element item,int *n) /* ���J�s������ְ� */
{
  int i;
  if(HeapFull(*n)) { printf("Heap is Full!\n"); exit(1); }
  
  (*n)++;

  i = *n;

  while(i!=1)
  {
    if(!(item.key > heap[i/2].key))  break;
    heap[i] = heap[i/2];        /* �N���`�I���U�� */
    i = i/2;                    /* �ѩ�ŧi��int,�ҥH�۰��૬�۷����U���� */
  }
  heap[i] = item;
}


element delete_maxheap(int *n)  /* �R���̤j��Ȥ��� */
{
  int parent,child;
  element item,temp;
  
  if(HeapEmpty(*n)) { printf("Heap is Empty!\n"); exit(1); }
  
  item = heap[1];                  /* */
  
  temp = heap[(*n)];               /* ���X�s���̫᪺�`�I��Jtemp */
  (*n)--;                        /* ��ʾ𪺸`�I�ƶq���Ӥ֤@�� */
  
  parent = 1;                      /* �Ѯڸ`�I�}�l��� */
  child = 2;                       /* �ڪ����l�`�I�s�� */    
  while(child <= *n)
  {
     if ((child <*n) && (heap[child].key < heap[child+1].key))
        child++;             /* �k�l�`�I���j,�ҥH���Ӥ�����O�k�l�`�I */ 
     
     if(temp.key >= heap[child].key)  
        break;
     else
     {
        heap[parent] = heap[child];        /* �P���j���l�`�I���� */
        parent = child;
        child = child*2;   
     }
  }
  heap[parent] = temp; 
  return item;
}


int main(void)
{
    
      

      system("pause");
      return 0;
}
