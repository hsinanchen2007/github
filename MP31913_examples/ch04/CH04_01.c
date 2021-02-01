#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*定義最大堆疊容量*/

int stack[MAXSTACK];/*堆疊的陣列宣告*/
int top=-1;/*堆疊的頂端*/
/*判斷是否為空堆疊*/
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
/*將指定的資料存入堆疊*/
int push(int data)
{
    if(top>=MAXSTACK)
    {
       printf("堆疊已滿,無法再加入\n");
       return 0; 
    }
    else
    {
       stack[++top]=data; /*將資料存入堆疊*/
       return 1;
        
    }
}
/*從堆疊取出資料*/
int pop()
{
    if(isEmpty()) /*判斷堆疊是否為空,如果是則傳回-1*/
       return -1;
    else
       return stack[top--]; /*將資料取出後,再將堆疊指標往下移*/
}
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
