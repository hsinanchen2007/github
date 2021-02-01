/* File name: BinaryTreeSort.cpp */
/* August, 2017 */
/* 二元樹排序 */

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct data {
    int num;
    struct data *lbaby, *rbaby;
} Node_type;

template <class Type>
class Binarytree {
private:
    Node_type *root;
    Node_type *tree;
    Node_type *leaf;
public:
    void binarytree_sort(Type data[]);
    void find(int input, Node_type *papa);
    void output(Node_type *node);
};

template <class Type>
void Binarytree<Type>::binarytree_sort(Type data[])
{
    int i;
    
    cout << "\n<< Binary tree sort >>\n";
    cout << "\nNumber : ";
    for(i = 0; i < 10; i++)
        cout << data[i] << "  ";
    cout << "\n";
    for(i = 0; i < 60; i++) cout << "-";
    root = new Node_type;
    root->num = data[0];     // 建樹根
    root->lbaby = NULL;
    root->rbaby = NULL;
    cout << "\nAccess : ";
    output(root);
    leaf = new Node_type;
    for(i = 1; i < 10; i++) { // 建樹枝
        leaf->num = data[i];
        leaf->lbaby = NULL;
        leaf->rbaby = NULL;
        find(leaf->num, root);
        if(leaf->num > tree->num)  // 若比父節點大，則放右子樹
            tree->rbaby = leaf;
        else                       // 否則放在左子樹
            tree->lbaby = leaf;
        cout << "\nAccess : ";
        output(root);
        leaf = new Node_type;
    }
    cout << "\n";
    for(i = 0; i < 60; i++) cout << "-";
    cout << "\nSorting: ";
    output(root);
}

// 尋找新節點存放的位置
template <class Type>
void Binarytree<Type>::find(int input, Node_type *papa)
{
    if((input > papa->num) && (papa->rbaby != NULL))
        find(input, papa->rbaby);
    else if((input < papa->num) && (papa->lbaby != NULL))
        find(input, papa->lbaby);
    else
        tree = papa;
}

// 印出資料
template <class Type>
void Binarytree<Type>::output(Node_type *node)  // 用中序追蹤將資料印出
{
    if(node != NULL) {
        output(node->lbaby);
        cout << node->num << "  ";
        output(node->rbaby);
    }
}

int main()
{
    Binarytree<int> obj;
    int data[10] = {15, 35, 4, 48, 57, 1, 29, 64, 37, 82};
    
    obj.binarytree_sort(data);
    cout << endl;
    system("PAUSE");
    return 0;
}