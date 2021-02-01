#include <iostream>
#include <cstdlib>
#include <iomanip>
#define ArraySize 10
using namespace std;
class Node//二元樹的節點宣告
{
    public:
    int value;//節點資料
    struct Node *left_Node;//指向左子樹的指標
    struct Node *right_Node;//指向左右子樹的指標
};
typedef class Node TreeNode;//定義新的二元樹節點資料型態
typedef TreeNode *BinaryTree;//定義新的二元樹鏈結資料型態
BinaryTree rootNode;//二元樹的根節點的指標 

//將指定的值加入到二元樹中適當的節點
void Add_Node_To_Tree(int value)
{
      BinaryTree currentNode;
      BinaryTree newnode;
      int flag=0;//用來紀錄是否插入新的節點
      newnode=(BinaryTree) malloc(sizeof(TreeNode));
      //建立節點內容
      newnode->value=value;
      newnode->left_Node=NULL;
      newnode->right_Node=NULL;
      //如果為空的二元樹,便將新的節點設定為根節點
      if(rootNode==NULL)
          rootNode=newnode;
      else 
      {
          currentNode=rootNode;//指定一個指標指向根節點
          while(!flag)
            if (value<currentNode->value) 
            { //在左子樹
               if(currentNode->left_Node==NULL)
               {
                  currentNode->left_Node=newnode;
                  flag=1;
               }
               else
                  currentNode=currentNode->left_Node;
            }
            else
            { //在右子樹
               if(currentNode->right_Node==NULL) 
               {
                  currentNode->right_Node=newnode;
                  flag=1;
              }
               else
                  currentNode=currentNode->right_Node;
            }
      }
}
int main(void)
{
    int tempdata;
    int content[ArraySize];
    int i=0;
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode=NULL;
    cout<<"請連續輸入10筆資料: "<<endl;
    for(i=0;i<ArraySize;i++)
    {
      cout<<"請輸入第"<<setw(1)<<(i+1)<<"筆資料: ";
      cin>>tempdata;       
      content[i]=tempdata;
    }
    for(i=0;i<ArraySize;i++) 
         Add_Node_To_Tree(content[i]);
    cout<<"完成以鏈結串列的方式建立二元樹";
    cout<<endl;  
	return 0;
}
