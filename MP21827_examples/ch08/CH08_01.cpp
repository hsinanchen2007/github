#include <iostream>
#include <iomanip>
#define MAXSTACK 100 //定義最大堆疊容量
using namespace std;
int stack[MAXSTACK];//堆疊的陣列宣告
int top=-1;//堆疊的頂端
//判斷是否為空堆疊
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
//將指定的資料存入堆疊
int push(int data)
{
    if(top>=MAXSTACK)
    {
        cout<<"堆疊已滿,無法再加入"<<endl;
        return 0; 
    }
    else
    {
        stack[++top]=data; //將資料存入堆疊
        return 1;
    }
}
//從堆疊取出資料
int pop()
{
    if(isEmpty()) //判斷堆疊是否為空,如果是則傳回-1
        return -1;
    else
        return stack[top--]; //將資料取出後,再將堆疊指標往下移
}
//主程式
int main(void)
{
    int value;
    int i;
    cout<<"請依序輸入10筆資料:"<<endl;
    for(i=0;i<10;i++)
    {
        cin>>value;
        push(value);
    }
    cout<<"===================="<<endl;
    while(!isEmpty()) //將資料陸續從頂端彈出
        cout<<"堆疊彈出的順序為:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;
    return 0; 
}
