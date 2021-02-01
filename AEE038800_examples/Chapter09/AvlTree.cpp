/* File name: AvlTree.cpp */
/* August, 2017 */
/* 利用AVL-TREE 處理資料--新增、刪除、修改、輸出 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct student {
    char name[20];   // 姓名
    int score;        // 分數
    int bf;            // 節點BF值
    struct student *llink, *rlink;  // 節點子鏈結
} Node_type;

class Avltree {
private:
    Node_type *ptr;
    Node_type *root;
    Node_type *current;
    Node_type *prev;
    Node_type *pivot;
    Node_type *pivot_prev;
    ifstream fin;
    ofstream fout;
public:
    Avltree();            // CONSTRUCTOR
    void insert_f(void);  // 插入函數
    void delete_f(void);  // 刪除函數
    void modify_f(void);  // 修改函數
    void list_f(void);    // 輸出函數
    void sort_f(char name_t[20], char score_t[4]);  // 插入檔案後排序
    void inorder(Node_type *trees);   // 輸出使用中序追蹤
    void preorder(Node_type *trees);  // 存檔使用前序追蹤
    void bf_count(Node_type *trees);  // 計算節點BF值
    int height_count(Node_type *trees);  // 計算節點高度
    Node_type *pivot_find(void);  // 找出pivot所在節點
    int type_find(void);  // 找出改善方法
    void type_ll(void);   // 使用LL型態
    void type_rr(void);   // 使用RR型態
    void type_lr(void);   // 使用LR型態
    void type_rl(void);   // 使用RL型態
};

Avltree::Avltree()
{
    root = NULL;
    prev = NULL;
    pivot_prev = NULL;
}

void Avltree::insert_f(void)
{
    char name_t[20], score_t[4];
    cout << " Please enter student name: ";
    cin.getline(name_t, 21);
    cout << " Please enter student score: ";
    cin.getline(score_t, 5);
    sort_f(name_t, score_t);   // 呼叫SORT_F函數作排序及平衡
}

void Avltree::sort_f(char name_t[20], char score_t[4])
{
    int op;
    current = root;
    while((current != NULL) && (strcmp(name_t, current->name) != 0)) {
        if(strcmp(name_t, current->name) < 0) { // 插入資料小於目前位置，則往左移
            prev = current;
            current = current->llink;
        }
        else {  // 若大於目前位置，則往右移
            prev = current;
            current = current->rlink;
        }
    }
    // 找到插入位置，無重覆資料存在
    if(current == NULL || strcmp(name_t, current->name) != 0) {
        ptr = new Node_type;  // 配置記憶體
        strcpy(ptr->name, name_t);
        ptr->score = atoi(score_t);
        ptr->llink = NULL;
        ptr->rlink = NULL;
        if(root == NULL) root = ptr;   // ROOT不存在，則將ROOT指向插入資料
        else if(strcmp(ptr->name, prev->name) < 0)
            prev->llink = ptr;
        else
            prev->rlink = ptr;
        bf_count(root);
        pivot = pivot_find();
        if(pivot != NULL) {  // PIVOT存在，則須改善為AVL-TREE
            op = type_find();
            switch(op) {
                case 11: type_ll();
                    break;
                case 22: type_rr();
                    break;
                case 12: type_lr();
                    break;
                case 21: type_rl();
                    break;
            }
        }
        bf_count(root);  // 重新計算每個節點的BF值
    }
    else   // 欲插入資料KEY已存在，則顯示錯誤
        cout << " Student " << name_t << " has existed\n";
}

void Avltree::delete_f(void)
{
    Node_type *clear;
    char name_t[20];
    int op;
    // 若根不存在，則顯示錯誤
    if(root == NULL)
        cout << " No student record\n";
    else {
        cout << " Please enter student name to delete: ";
        cin.getline(name_t, 21);
        current = root;
        while(current != NULL && strcmp(name_t, current->name) != 0) {
            // 若刪除資料鍵值小於目前所在資料，則往左子樹
            if(strcmp(name_t, current->name) < 0) {
                prev = current;
                current = current->llink;
            }
            // 否則則往右子樹
            else {
                prev = current;
                current = current->rlink;
            }
        }
        // 找不到刪除資料，則顯示錯誤
        if(current == NULL) {
            cout << " student " << name_t << " not found\n";
            return;
        }
        // 找到欲刪除資料的狀況
        if(strcmp(name_t, current->name) == 0) {
            // 當欲刪除資料底下無左右子樹存在的狀況
            if(current->llink == NULL && current->rlink == NULL) {
                clear = current;
                if(strcmp(name_t, root->name) == 0)  // 欲刪除資料為根
                    root = NULL;
                else {
                    // 若不為根，則判斷其為左子樹或右子樹
                    if(strcmp(name_t, prev->name) < 0)
                        prev->llink = NULL;
                    else
                        prev->rlink = NULL;
                }
                delete clear;  // 釋放記憶體
            }
            else {
                // 以左子樹最大點代替刪除資料
                if(current->llink != NULL) {
                    clear = current->llink;
                    while(clear->rlink != NULL) {
                        prev = clear;
                        clear = clear->rlink;
                    }
                    strcpy(current->name, clear->name);
                    current->score = clear->score;
                    if(current->llink == clear)
                        current->llink = clear->llink;
                    else
                        prev->rlink = clear->llink;
                }
                // 以右子樹最小點代替刪除資料
                else {
                    clear = current->rlink;
                    while(clear->llink != NULL) {
                        prev = clear;
                        clear = clear->llink;
                    }
                    strcpy(current->name, clear->name);
                    current->score = clear->score;
                    if(current->rlink == clear)
                        current->rlink = clear->rlink;
                    else
                        prev->llink = clear->rlink;
                }
                delete clear;   // 釋放記憶體
            }
            bf_count(root);
            if(root != NULL) {    // 若根不存在，則無需作平衡改善
                pivot = pivot_find();      // 尋找PIVOT所在節點
                if(pivot != NULL) {
                    op = type_find();
                    switch(op) {
                        case 11: type_ll();
                            break;
                        case 22: type_rr();
                            break;
                        case 12: type_lr();
                            break;
                        case 21: type_rl();
                            break;
                    }
                }
                bf_count(root);
            }
            cout << " Student data deleted\n";
        }
    }
}

void Avltree::modify_f(void)
{
    char name_t[20], score_t[4];
    cout << " Please enter student name to update: ";
    cin.getline(name_t, 21);
    current = root;
    // 尋找欲更改資料所在節點
    while((current != NULL) && (strcmp(name_t, current->name) != 0)) {
        if(strcmp(name_t, current->name) < 0)
            current = current->llink;
        else
            current = current->rlink;
    }
    // 若找到欲更改資料，則列出原資料，並要求輸入新的資料
    if(current != NULL) {
        cout << " ****************************\n";
        cout << "  Student name : " << current->name << "\n";
        cout << "  Student score: " << current->score << "\n";
        cout << " ****************************\n";
        cout << " Please enter new score: ";
        cin.getline(score_t, 5);
        current->score = atoi(score_t);
        cout << " Data update successfully\n";
    }
    // 沒有找到資料則顯示錯誤
    else
        cout << " Student " << name_t << " not found\n";
}

void Avltree::list_f(void)
{
    if(root == NULL)
        cout << " No student record\n";
    else {
        cout << " *****************************\n";
        cout << "   Name                Score\n";
        cout << "  ---------------------------\n";
        inorder(root);   // 使用中序法輸出資料
        cout << " *****************************\n";
    }
}

void Avltree::inorder(Node_type *trees)  // 中序使用遞迴
{
    if(trees != NULL) {
        inorder(trees->llink);
        cout << "   ";
        cout.setf(ios::left, ios::adjustfield);
        cout.width(20);
        cout << trees->name << " ";
        cout.setf(ios::right, ios::adjustfield);
        cout.width(3);
        cout << trees->score << "\n";
        inorder(trees->rlink);
    }
}

void Avltree::preorder(Node_type *trees) // 前序採遞迴法
{
    if(trees != NULL) {
        fout << trees->name << " " << trees->score << "\n";
        preorder(trees->llink);
        preorder(trees->rlink);
    }
}

void Avltree::bf_count(Node_type *trees)  // 計算BF值，使用後序法逐一計算
{
    if(trees != NULL) {
        bf_count(trees->llink);
        bf_count(trees->rlink);
        // BF值計算方式為左子樹高減去右子樹高
        trees->bf = height_count(trees->llink) - height_count(trees->rlink);
    }
}

int Avltree::height_count(Node_type *trees)
{
    if(trees == NULL)
        return 0;
    else 	if(trees->llink == NULL && trees->rlink == NULL)
        return 1;
    else
        return 1 + (height_count(trees->llink) > height_count(trees->rlink)?
                    height_count(trees->llink) : height_count(trees->rlink));
}


Node_type *Avltree::pivot_find(void)
{
    current = root;
    pivot = NULL;
    while(current != ptr) {
        // 當BF值的絕對值小於等於1，則將PIVOT指向此節點
        if(current->bf < -1 || current->bf > 1) {
            pivot = current;
            if(pivot != root)
                pivot_prev = prev;
        }
        if(strcmp(ptr->name, current->name) < 0) {
            prev = current;
            current = current->llink;
        }
        else {
            prev = current;
            current = current->rlink;
        }
    }
    return pivot;
}

int Avltree::type_find(void)
{
    int i, op_r = 0;
    
    current = pivot;
    for(i = 0; i < 2; i++) {
        if(strcmp(ptr->name, current->name) < 0) {
            current = current->llink;
            if(op_r == 0) op_r+=10;
            else op_r++;
        }
        else {
            current = current->rlink;
            if(op_r == 0) op_r+=20;
            else op_r+=2;
        }
    }
    // 傳回值11、22、12、21分別代表LL、RR、LR、RL型態
    return op_r;
}

void Avltree::type_ll(void)  // LL型態
{
    Node_type *pivot_next, *temp;
    pivot_next = pivot->llink;
    temp = pivot_next->rlink;
    pivot_next->rlink = pivot;
    pivot->llink = temp;
    if(pivot == root) 
        root = pivot_next;
    else if(pivot_prev->llink == pivot)
        pivot_prev->llink = pivot_next;
    else
        pivot_prev->rlink = pivot_next;
}

void Avltree::type_rr(void)  // RR型態
{
    Node_type *pivot_next, *temp;
    pivot_next = pivot->rlink;
    temp = pivot_next->llink;
    pivot_next->llink = pivot;
    pivot->rlink = temp;
    if(pivot == root) 
        root = pivot_next;
    else if(pivot_prev->llink == pivot)
        pivot_prev->llink = pivot_next;
    else
        pivot_prev->rlink = pivot_next;
}

void Avltree::type_lr(void)  // LR型態
{
    Node_type *pivot_next, *temp;
    pivot_next = pivot->llink;
    temp = pivot_next->rlink;
    pivot->llink = temp->rlink;
    pivot_next->rlink = temp->llink;
    temp->llink = pivot_next;
    temp->rlink = pivot;
    if(pivot == root) 
        root = temp;
    else if(pivot_prev->llink == pivot)
        pivot_prev->llink = temp;
    else
        pivot_prev->rlink = temp;
}

void Avltree::type_rl(void)  // RL型態
{
    Node_type *pivot_next, *temp;
    pivot_next = pivot->rlink;
    temp = pivot_next->llink;
    pivot->rlink = temp->llink;
    pivot_next->llink = temp->rlink;
    temp->rlink = pivot_next;
    temp->llink = pivot;
    if(pivot == root) 
        root = temp;
    else if(pivot_prev->llink == pivot)
        pivot_prev->llink = temp;	
    else
        pivot_prev->rlink = temp;
}

int main()
{
    Avltree objavl;
    char option;
    cout << endl;
    do {
        cout << " *****************************\n";
        cout << "         <1> insert\n";
        cout << "         <2> delete\n";
        cout << "         <3> modify\n";
        cout << "         <4> list\n";
        cout << "         <5> exit\n";
        cout << " *****************************\n";
        cout << "  Please input your choice: ";
        cin>>option;
        cin.get();
        switch(option) {
            case '1': objavl.insert_f();
                break;
            case '2': objavl.delete_f();
                break;
            case '3': objavl.modify_f();
                break;
            case '4': objavl.list_f();
                break;
            case '5': system("PAUSE");
                return 0;
        }
    } while(option != '5');
}