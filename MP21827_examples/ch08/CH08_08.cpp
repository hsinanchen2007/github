/*
[示範]:雙向佇列實作
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
void enqueue(int value) 
{
    QueueByLinkedList node; //建立節點
    node=new QueueNode;
    node->data=value;
    node->next=NULL;
    //檢查是否為空佇列
    if (rear==NULL)
        front=node;//新建立的節點成為第1個節點
    else
        rear->next=node;//將節點加入到佇列的尾端
    rear=node;//將佇列的尾端指標指向新加入的節點
}
//方法dequeue:佇列資料的取出
int dequeue(int action)
{
    int value;
    QueueByLinkedList tempNode,startNode;
    //從前端取出資料
    if (!(front==NULL) && action==1) 
    {
        if(front==rear) rear=NULL;
        value=front->data;//將佇列資料從前端取出
        front=front->next;//將佇列的前端指標指向下一個
        return value;
    }
   //從尾端取出資料
   else if(!(rear==NULL) && action==2) 
   {
        startNode=front;//先記下前端的指標值
        value=rear->data;//取出目前尾端的資料
        //找尋最尾端節點的前一個節點
        tempNode=front;
        while (front->next!=rear && front->next!=NULL) 
        { 
            front=front->next;
            tempNode=front;
        }
        front=startNode;//記錄從尾端取出資料後的佇列前端指標
        rear=tempNode;//記錄從尾端取出資料後的佇列尾端指標
        //下一行程式是指當佇列中僅剩下最節點時,
        //取出資料後便將front及rear指向NULL
        if ((front->next==NULL) || (rear->next==NULL)) 
        { 
            front=NULL;
            rear=NULL;
        }
        return value; 
   }
   else return -1;
}
int main(void)
{
    int temp;
    cout<<"以鏈結串列來實作雙向佇列"<<endl;
    cout<<"===================================="<<endl;
    cout<<"在雙向佇列前端加入第1筆資料，此資料值為1"<<endl;
    enqueue(1);
    cout<<"在雙向佇列前端加入第2筆資料，此資料值為3"<<endl;
    enqueue(3);
    cout<<"在雙向佇列前端加入第3筆資料，此資料值為5"<<endl;
    enqueue(5);
    cout<<"在雙向佇列前端加入第4筆資料，此資料值為7"<<endl;
    enqueue(7);
    cout<<"在雙向佇列前端加入第5筆資料，此資料值為9"<<endl;
    enqueue(9);
    cout<<"===================================="<<endl;
    temp=dequeue(1);
    cout<<"從雙向佇列前端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"從雙向佇列尾端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"從雙向佇列前端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"從雙向佇列尾端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"從雙向佇列前端依序取出的元素資料值為："<<setw(1)<<temp<<endl;
    cout<<endl;
    return 0;
}
