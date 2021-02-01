/* File name: BinSearchTree.cpp */
/* August, 2017 */
/* 利用二元搜尋樹處理資料－新增、刪除、修改、輸出 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 定義student結構
typedef struct student {
    char name[20];  // 學生姓名
    int score;       // 學生成績
    struct student *llink;  // 左子鏈結
    struct student *rlink;  // 右子鏈結
} Node_type;

class Bintree {
private:
    Node_type *root;
    Node_type *ptr;
public:
    Bintree();  // 建構子
    void insert_f(void);    // 新增函數
    void delete_f(void);    // 刪除函數
    void modify_f(void);    // 修改函數
    void show_f(void);      // 輸出函數
    void access(char [], int);  // 將資料加入二元搜尋樹
    void removing(char []);  // 將資料從二元搜尋樹中移除
    Node_type *replace(Node_type *);  // 尋找替代節點
    void connect(Node_type *, char);  // 調整鏈結
    void inorder(Node_type *);  // 資料以中序法輸出
    void preorder(Node_type *);  // 資料以前序法寫入檔案
    Node_type *search(char []);  // 搜尋節點
    Node_type *search_re_r(Node_type *);  // 搜尋右子樹替代節點
    Node_type *search_re_l(Node_type *);  // 搜尋左子樹替代節點
    Node_type *search_p(Node_type *);  // 搜尋父節點
};


// 建構子
Bintree::Bintree()
{
    root = NULL;
}

// 新增函數，新增一筆新的資料
void Bintree::insert_f(void)
{
    char name[20], temp[4];
    int score;
    
    cout << "=====INSERT DATA=====\n";
    cout << "Enter student name: ";
    cin.getline(name, 20);
    cout << "Enter student score: ";
    cin.getline(temp, 4);
    score = atoi(temp);
    access(name, score);
}

// 刪除函數，將資料從二元搜尋樹中刪除
void Bintree::delete_f(void)
{
    char name[20];
    
    if(root == NULL) {
        cout << "No student record!\n";
        return;
    }
    cout << "=====DELETE DATA=====\n";
    cout << "Enter student name: ";
    cin.getline(name, 20);
    removing(name);
}

// 修改資料，修改學生成績
void Bintree::modify_f(void)
{
    Node_type *node;
    char name[20], temp[4];
    
    if(root == NULL) {  // 判斷根節點是否為NULL
        cout << "No student record!\n";
        return;
    }
    cout << "=====MODIFY DATA=====\n";
    cout << "Enter student name: ";
    cin.getline(name, 20);
    if((node = search(name)) == NULL)
        cout << "Student " << name << " not found!\n";
    else {
        // 列出原資料狀況
        cout << "Original student name: " << node->name << "\n";
        cout << "Original student score: " << node->score << "\n";
        cout << "Enter new score: ";
        cin.getline(temp, 4);
        node->score = atoi(temp);
        cout << "Data of student " << name << " modified\n";
    }
}

// 輸出函數，將資料輸出至螢幕
void Bintree::show_f(void)
{
    if(root == NULL) {  // 判斷根節點是否為NULL
        cout << "No student record!\n";
        return;
    }
    cout << "=====SHOW DATA=====\n";
    inorder(root);  // 以中序法輸出資料
}

// 處理二元搜尋樹，將新增資料加入至二元搜尋樹中
void Bintree::access(char name[], int score)
{
    Node_type *node, *prev;
    if(search(name) != NULL){  // 資料已存在則顯示錯誤
        cout << "Student " << name << " has existed!\n";
        return;
    }
    ptr = new Node_type;
    strcpy(ptr->name, name);
    ptr->score = score;
    ptr->llink = ptr->rlink = NULL;
    if(root == NULL)  // 當根節點為NULL的狀況
        root = ptr;
    else { // 當根節點不為NULL的狀況
        node = root;
        while(node != NULL) {  // 搜尋資料插入點
            prev = node;
            if(strcmp(ptr->name, node->name) < 0)
                node = node->llink;
            else
                node = node->rlink;
        }
        if(strcmp(ptr->name, prev->name) < 0)
            prev->llink = ptr;
        else
            prev->rlink = ptr;
    }
}

// 將資料從二元搜尋樹中移除
void Bintree::removing(char name[])
{
    Node_type *del_node;
    
    if((del_node = search(name)) == NULL) { // 找不到資料則顯示錯誤
        cout << "Student " << name << " not found!\n";
        return;
    }
    // 節點不為樹葉節點的狀況
    if(del_node->llink != NULL || del_node->rlink != NULL)
        del_node = replace(del_node);
    else if(del_node == root) // 節點為樹葉節點的狀況
        root = NULL;
    else
        connect(del_node, 'n');
    delete del_node;  // 釋放記憶體
    cout << "Data of student " << name << " deleted!\n";
}

// 尋找刪除非樹葉節點的替代節點
Node_type *Bintree::replace(Node_type *node)
{
    Node_type *re_node;
    // 當右子樹找不到替代節點，會搜尋左子樹是否存在替代節點
    if((re_node = search_re_r(node->rlink)) == NULL)
        re_node = search_re_l(node->llink);
    if(re_node->rlink != NULL)  // 當替代節點有右子樹存在的狀況
        connect(re_node, 'r');
    else if(re_node->llink != NULL)  // 當替代節點有左子樹存在的狀況
        connect(re_node, 'l');
    else  // 當替代節點為樹葉節點的狀況
        connect(re_node, 'n');
    strcpy(node->name, re_node->name);
    node->score = re_node->score;
    return re_node;
}

// 調整二元搜尋樹的鏈結，link為r表示處理右鏈結，為l表處理左鏈結，
// 為m則將鏈結指向NULL
void Bintree::connect(Node_type *node, char link)
{
    Node_type *parent;
    parent = search_p(node);  // 搜尋父節點
    if(strcmp(node->name, parent->name) < 0)  // 節點為父節點左子樹的狀況
        if(link == 'r')  // link為r
            parent->llink = node->rlink;
        else if(link == 'l')  // link為l
            parent->llink = node->llink;
        else  // link為m
            parent->llink = NULL;
        else  // 節點為父節點右子樹的狀況
            if(link == 'r')  // link為r
                parent->rlink = node->rlink;
            else
                if(link == 'l')  // link為l
                    parent->rlink = node->llink;
                else  // link為m
                    parent->rlink = NULL;
}

// 以中序法輸出資料，採遞迴方式
void Bintree::inorder(Node_type *node)
{
    if(node != NULL) {
        inorder(node->llink);
        cout.setf(ios::left, ios::adjustfield);
        cout.width(10);
        cout << node->name << " ";
        cout.setf(ios::right, ios::adjustfield);
        cout << node->score << "\n";
        inorder(node->rlink);
    }
}

// 以前序法將資料寫入檔案，採遞迴方式
void Bintree::preorder(Node_type *node)
{
    if(node != NULL) {
        cout << node->name << " " << node->score << "\n";
        preorder(node->llink);
        preorder(node->rlink);
    }
}

// 搜尋target所在節點
Node_type *Bintree::search(char target[])
{
    Node_type *node;
    node = root;
    while(node != NULL) {
        if(strcmp(target, node->name) == 0)
            return node;
        else
            if(strcmp(target, node->name) < 0)  // target小於目前節點，往左搜尋
                node = node->llink;
            else  // target大於目前節點，往右搜尋
                node = node->rlink;
    }
    return node;
}

// 搜尋右子樹替代節點
Node_type *Bintree::search_re_r(Node_type *node)
{
    Node_type *re_node;
    
    re_node = node;
    while(re_node != NULL && re_node->llink != NULL)
        re_node = re_node->llink;
    return re_node;
}

// 搜尋左子樹替代節點
Node_type *Bintree::search_re_l(Node_type *node)
{
    Node_type *re_node;
    
    re_node = node;
    while(re_node != NULL && re_node->rlink != NULL)
        re_node = re_node->rlink;
    return re_node;
}

// 搜尋node的父節點
Node_type *Bintree::search_p(Node_type *node)
{
    Node_type *parent;
    
    parent = root;
    while(parent != NULL) {
        if(strcmp(node->name, parent->name) < 0)
            if(strcmp(node->name, parent->llink->name) == 0)
                return parent;
            else
                parent = parent->llink;
            else
                if(strcmp(node->name, parent->rlink->name) == 0)
                    return parent;
                else
                    parent = parent->rlink;
    }
    return NULL;
}

int main()
{
    Bintree obj;
    char option;
    
    while(1) {
        cout << "\n";
        cout << "********************\n";
        cout << "     <1> insert\n";
        cout << "     <2> delete\n";
        cout << "     <3> modify\n";
        cout << "     <4> show\n";
        cout << "     <5> quit\n";
        cout << "********************\n";
        cout << "Enter your choice: ";
        cin>>option;
        cin.get();
        cout << "\n\n";
        switch(option) {
            case '1': obj.insert_f();
                break;
            case '2': obj.delete_f();
                break;
            case '3': obj.modify_f();
                break;
            case '4': obj.show_f();
                break;
            case '5': system("PAUSE");
                return 0;
            default : cout << "Wrong option!\n";
        }
    }
}