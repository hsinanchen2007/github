#include <stdio.h>
#include <stdlib.h>
struct Node/*二元樹的節點宣告*/
{
    int value;/*節點資料*/
    struct Node *left_Node;/*指向左子樹的指標*/
    struct Node *right_Node;/*指向左右子樹的指標*/
};
typedef struct Node TreeNode;/*定義新的二元樹節點資料型態*/
typedef TreeNode *BinaryTree;/*定義新的二元樹鏈結資料型態*/
BinaryTree rootNode;//*二元樹的根節點的指標 */
BinaryTree rootNode2;
/*將指定的值加入到二元樹中適當的節點*/
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;/*用來紀錄是否插入新的節點*/
    newnode=(BinaryTree) malloc(sizeof(TreeNode));
    /*建立節點內容*/
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    /*如果為空的二元樹,便將新的節點設定為根節點*/
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;/*指定一個指標指向根節點*/
        while(!flag)
          if (value<currentNode->value) 
          { /*在左子樹*/
             if(currentNode->left_Node==NULL)
             {
                currentNode->left_Node=newnode;
                flag=1;
             }
             else
                currentNode=currentNode->left_Node;
          }
          else
          { /*在右子樹*/
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
BinaryTree create(char sequence[100],int index,int ArraySize)
{
      BinaryTree tempNode;            
      if ( sequence[index]==0 ||index >= ArraySize )/*作為出口條件*/
         return NULL;
      else  { 
         tempNode=(BinaryTree)malloc(sizeof(TreeNode));
         tempNode->value=(int)sequence[index];
         tempNode->left_Node=NULL;
         tempNode->right_Node=NULL;
         /*建立左子樹*/
         tempNode->left_Node = create(sequence, 2*index,ArraySize);
         /*建立右子樹*/
         tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
         return tempNode;
      }
}
/*preOrder(前序走訪)方法的程式內容*/
void preOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         printf("%c",(char)node->value);
         preOrder(node->left_Node);  
         preOrder(node->right_Node); 
      }
}
/*inOrder(中序走訪)方法的程式內容*/
void inOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         inOrder(node->left_Node);  
         printf("%c",(char)node->value);
         inOrder(node->right_Node); 
      }
}
/*postOrder(後序走訪)方法的程式內容*/
void postOrder(BinaryTree node) 
{
      if ( node != NULL ) {
         postOrder(node->left_Node);  
         postOrder(node->right_Node); 
         printf("%c",(char)node->value);
      }
}
/*判斷運算式如何運算的方法宣告內容*/
int condition(char oprator, int num1, int num2)
{
      switch ( oprator ) {
         case '*': return ( num1 * num2 ); /*乘法請回傳num1 * num2*/
         case '/': return ( num1 / num2 ); /*除法請回傳num1 / num2*/
         case '+': return ( num1 + num2 ); /*加法請回傳num1 + num2*/
         case '-': return ( num1 - num2 ); /*減法請回傳num1 - num2*/
         case '%': return ( num1 % num2 ); /*取餘數法請回傳num1 % num2*/
      }
      return -1;
}
/*傳入根節點,用來計算此二元運算樹的值*/
int answer(BinaryTree node) 
{
      int firstnumber = 0;       
      int secondnumber = 0;      
      /*遞迴呼叫的出口條件*/
      if ( node->left_Node == NULL && node->right_Node == NULL )
        /*將節點的值轉換成數值後傳回*/
        return node->value-48;
      else {
        firstnumber = answer(node->left_Node);/*計算左子樹運算式的值*/
        secondnumber = answer(node->right_Node); /*計算右子樹運算式的值*/
        return condition((char)node->value, firstnumber, secondnumber);
      }
   }
int main(void)
{
    /* 第一筆運算式 */
    char information1[] = {' ','+','*','%','6','3','9','5' };
    /* 第二筆運算式 */
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode2=(BinaryTree) malloc(sizeof(TreeNode));                      
    // create方法可以將二元樹的陣列表示法轉換成鏈結表示法
    rootNode = create(information1,1,8);
    printf("====二元運算樹數值運算範例 1: ====\n");
    printf("=================================\n");
    printf("===轉換成中序運算式===:  ");
    inOrder(rootNode);     
    printf("\n===轉換成前序運算式===:  ");
    preOrder(rootNode);    
    printf("\n===轉換成後序運算式===:  ");
    postOrder(rootNode);   
    // 計算二元樹運算式的運算結果
    printf("\n此二元運算樹,經過計算後所得到的結果值: ");
    printf("%d",answer(rootNode));
    //建立第二棵二元搜尋樹物件
    rootNode2 = create(information2,1,16);
    printf("\n\n");
    printf("====二元運算樹數值運算範例 2: ====\n");
    printf("=================================\n");
    printf("===轉換成中序運算式===:  ");
    inOrder(rootNode2);     
    printf("\n===轉換成前序運算式===:  ");
    preOrder(rootNode2);    
    printf("\n===轉換成後序運算式===:  ");
    postOrder(rootNode2);   
    // 計算二元樹運算式的運算結果
    printf("\n此二元運算樹,經過計算後所得到的結果值: ");
    printf("%d",answer(rootNode2)); 
    printf("\n");
	system("pause");
	return 0;
}
