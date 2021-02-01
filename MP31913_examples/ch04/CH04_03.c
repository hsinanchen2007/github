#include <stdio.h>
#include <stdlib.h>

struct Node /*堆疊鏈結節點的宣告*/
{
   int data; /*堆疊資料的宣告*/
   struct Node *next;/*堆疊中用來指向下一個節點*/
};
typedef struct Node Stack_Node;/*定義堆疊中節點的新型態*/
typedef Stack_Node *Linked_Stack;/*定義串列堆疊的新型態*/
Linked_Stack top=NULL;/*指向堆疊頂端的指標*/
int isEmpty();
int pop();
void push(int data);
/*判斷是否為空堆疊*/

/*主程式*/
int main()
{
    int value;
    int i;
    
    do
     {
       printf("要推入堆疊,請輸入1,彈出則輸入0,停止操作則輸入-1: ");
       scanf("%d",&i);
       if(i==-1)
         break;
       else if (i==1)
       { 
        printf("請輸入元素值:"); 
        scanf("%d",&value);
        push(value);
       }
       else if(i==0)
        printf("彈出的元素為%d\n",pop());
       } while(i!=-1);

    printf("============================\n");
    while(!isEmpty()) /*將資料陸續從頂端彈出*/
       printf("堆疊彈出的順序為:%d\n",pop()); 
    printf("==========================\n");
    
    system("pause");      
    return 0; 
}
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
/*將指定的資料存入堆疊*/
void push(int data)
{
    Linked_Stack new_add_node; /*新加入節點的指標*/
    /*配置新節點的記憶體*/
    new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
    new_add_node->data=data;/*將傳入的值指定為節點的內容*/
    new_add_node->next=top;/*將新節點指向堆疊的頂端*/
    top=new_add_node;/*新節點成為堆疊的頂端*/
}
/*從堆疊取出資料*/
int pop()
{
    Linked_Stack ptr; /*指向堆疊頂端的指標*/
    int temp;
    if(isEmpty()) /*判斷堆疊是否為空,如果是則傳回-1*/
    {
       printf("===目前為空堆疊===\n");
       return -1;
    }
    else
    {
        ptr=top;/*指向堆疊的頂端*/
        top=top->next;/*將堆疊頂端的指標指向下一個節點*/
        temp=ptr->data;/*取出堆疊的資料*/
        free(ptr);/*將節點佔用的記憶體釋放*/
        return temp;/*將從堆疊取出的資料回傳給主程式*/
    }
}
