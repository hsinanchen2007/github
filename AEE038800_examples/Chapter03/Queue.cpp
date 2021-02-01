/* File name: Queue.cpp */
/* August, 2017 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define MAX 20

class Queue {
private:
    char item[MAX][20];
    int front = 0, rear = -1;
public:
    void enqueueFunction(void);   /* 加入佇列 */
    void dequeueFunction(void);   /* 從佇列刪除 */
    void listFunction(void);   /* 印出佇列 */
};

int main()
{
    Queue obj;
    char option;
    while(1){
        cout << "\n *****************************\n";
        cout << "       <1> insert (enqueue)\n";
        cout << "       <2> delete (dequeue)\n";
        cout << "       <3> list\n";
        cout << "       <4> quit\n";
        cout << " *****************************\n";
        cout << " Please enter your choice...";
        option = getchar();
        while (getchar()!='\n') continue;
        switch(option)	{
            case '1':
                obj.enqueueFunction();
                break;
            case '2':
                obj.dequeueFunction();
                break;
            case '3':
                obj.listFunction();
                break;
            case '4':
                exit(0);
        }
    }
}

void Queue::enqueueFunction(void)
{
    if(rear >= MAX-1)
        cout << "\n\nQueue is full !\n";
    else{
        rear++;
        cout << "\n\n Please enter item to insert: ";
        cin >> item[rear];
        while (getchar()!='\n') continue;
    }
}

void Queue::dequeueFunction(void)
{
    if(front > rear)
        cout << "\n\n No item, queue is empty !\n";
    else{
        cout << "\n\n Item " << item[front] << " deleted\n";
        front++;
    }
}

void Queue::listFunction(void)
{
    int count = 0, i;
    if(front > rear)
        cout << "\n\n No item, queue is empty\n";
    else{
        cout << "\n\n  ITEM\n";
        cout << " ------------------\n";
        for(i = front; i <= rear; i++){
            cout << "  " << left << setw(20) << item[i] << "\n";
            count++;
            if(count % 20 == 0) getchar();
        }
        cout << " ------------------\n";
        cout << "  Total item: " << count << "\n";
    }
}