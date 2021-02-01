/*
[示範]:實作以鏈結串列建立佇列
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node
{
    public:
        int data;
        class Node *next;
};
typedef class Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
//方法enqueue:佇列資料的存入
void enqueue(int value) {
    QueueByLinkedList node; //建立節點
    node=new QueueNode;
    node->data=value;
    node->next=NULL;
    //檢查是否為空佇列
    if (rear==NULL)
        front=node; //新建立的節點成為第1個節點
    else
        rear->next=node; //將節點加入到佇列的尾端
    rear=node; //將佇列的尾端指標指向新加入的節點
}
//方法dequeue:佇列資料的取出
int dequeue() 
{
    int value;
    //檢查佇列是否為空佇列
    if (!(front==NULL)) 
    {
        if(front==rear) rear=NULL;
        value=front->data; //將佇列資料取出
        front=front->next; //將佇列的前端指標指向下一個
        return value;
    }
    else return -1;
}
int main(void)
{
    int temp;
    cout<<"以鏈結串列來實作佇列"<<endl;
    cout<<"===================================="<<endl;
    cout<<"在佇列前端加入第1筆資料，此資料值為1"<<endl;
    enqueue(1);
    cout<<"在佇列前端加入第2筆資料，此資料值為3"<<endl;
    enqueue(3);
    cout<<"在佇列前端加入第3筆資料，此資料值為5"<<endl;
    enqueue(5);
    cout<<"在佇列前端加入第4筆資料，此資料值為7"<<endl;
    enqueue(7);
    cout<<"在佇列前端加入第5筆資料，此資料值為9"<<endl;
    enqueue(9);
    cout<<"===================================="<<endl;
    while (1) 
    {
        if (!(front==NULL)) 
        {
            temp=dequeue();
            cout<<"從佇列前端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
        }
      else
         break;
    }
    cout<<endl;
    return 0;
}
