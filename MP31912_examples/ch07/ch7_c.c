/*  ch7_c.c   */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */
#define TRUE 1
#define FALSE 0


#define MaxSize 201            /* 累堆可以最多有200個元素 */
#define HeapFull(n) (n==MaxSize-1)/* n代表目前累堆有幾個元素  */
#define HeapEmpty(n) (!n)      /* n為0時,!0=1 -> 相當於回傳TRUE */

typedef struct
{
    int key; 
    /* 其他欄位 */
}element;

element heap[MaxSize];       /* 宣告存放累堆的陣列 */
int n=0; 

void insert_maxheap(element item,int *n) /* 插入新元素到累堆 */
{
  int i;
  if(HeapFull(*n)) { printf("Heap is Full!\n"); exit(1); }
  
  (*n)++;

  i = *n;

  while(i!=1)
  {
    if(!(item.key > heap[i/2].key))  break;
    heap[i] = heap[i/2];        /* 將父節點往下降 */
    i = i/2;                    /* 由於宣告為int,所以自動轉型相當於取下高斯 */
  }
  heap[i] = item;
}


element delete_maxheap(int *n)  /* 刪除最大鍵值元素 */
{
  int parent,child;
  element item,temp;
  
  if(HeapEmpty(*n)) { printf("Heap is Empty!\n"); exit(1); }
  
  item = heap[1];                  /* */
  
  temp = heap[(*n)];               /* 取出編號最後的節點放入temp */
  (*n)--;                        /* 整棵樹的節點數量應該少一個 */
  
  parent = 1;                      /* 由根節點開始比較 */
  child = 2;                       /* 根的左子節點編號 */    
  while(child <= *n)
  {
     if ((child <*n) && (heap[child].key < heap[child+1].key))
        child++;             /* 右子節點較大,所以應該比較的是右子節點 */ 
     
     if(temp.key >= heap[child].key)  
        break;
     else
     {
        heap[parent] = heap[child];        /* 與較大的子節點互換 */
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
