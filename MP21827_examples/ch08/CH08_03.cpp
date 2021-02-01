#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Node //堆疊鏈結節點的宣告
{
   public:
   int data; //堆疊資料的宣告
   class Node *next;//堆疊中用來指向下一個節點
};
typedef class Node Stack_Node;//定義堆疊中節點的新型態
typedef Stack_Node *Linked_Stack;//定義串列堆疊的新型態
Linked_Stack top=NULL;//指向堆疊頂端的指標

//判斷是否為空堆疊
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
//將指定的資料存入堆疊
void push(int data)
{
    Linked_Stack new_add_node; //新加入節點的指標
    //配置新節點的記憶體
    new_add_node=new Stack_Node;
    new_add_node->data=data;//將傳入的值指定為節點的內容
    new_add_node->next=top;//將新節點指向堆疊的頂端
    top=new_add_node;//新節點成為堆疊的頂端
}
//從堆疊取出資料
int pop()
{
    Linked_Stack ptr; //指向堆疊頂端的指標
    int temp;
    if(isEmpty()) //判斷堆疊是否為空,如果是則傳回-1
    {
        cout<<"===目前為空堆疊==="<<endl;
        return -1;
    }
    else
    {
        ptr=top;//指向堆疊的頂端
        top=top->next;//將堆疊頂端的指標指向下一個節點
        temp=ptr->data;//取出堆疊的資料
        free(ptr);//將節點佔用的記憶體釋放
        return temp;//將從堆疊取出的資料回傳給主程式
    }
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
