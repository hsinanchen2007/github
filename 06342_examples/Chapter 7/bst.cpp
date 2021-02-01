/* file name: bst.cpp */
/* 利用二元搜尋樹處理資料－載入、儲存、新增、刪除、修改、輸出 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

/* 定義student結構 */
struct student {
    char name[20];  /* 學生姓名 */
    int score;  /* 學生成績 */
    struct student *llink;  /* 左子鏈結 */
    struct student *rlink;  /* 右子鏈結 */
};

class Bst {
private:
    struct student *root, *ptr;
public:
    void load_f(void);      /* 載入函數 */
    void save_f(void);      /* 儲存函數 */
    void insert_f(void);    /* 新增函數 */
    void delete_f(void);    /* 刪除函數 */
    void modify_f(void);    /* 修改函數 */
    void show_f(void);      /* 輸出函數 */
    void access(char [], int);  /* 將資料加入二元搜尋樹 */
    void removing(char []);  /* 將資料從二元搜尋樹中移除 */
    struct student *replace(struct student *);  /* 尋找替代節點 */
    void connect(struct student *, char);  /* 調整鏈結 */
    void inorder(struct student *);  /* 資料以中序法輸出 */
    void preorder(struct student *, FILE *);  /* 資料以前序法寫入檔案 */
    struct student *search(char []);  /* 搜尋節點 */
    struct student *search_re_r(struct student *);  /* 搜尋右子樹替代節點 */
    struct student *search_re_l(struct student *);  /* 搜尋左子樹替代節點 */
    struct student *search_p(struct student *);  /* 搜尋父節點 */
};

int main()
{
    Bst obj;
    char option;
    obj.load_f();  /* 載入檔案 */
    while(1)
    {
        puts("");
        puts("********************");
        puts("     <1> insert");
        puts("     <2> delete");
        puts("     <3> modify");
        puts("     <4> show");
        puts("     <5> quit");
        puts("********************");
        cout << "Enter your choice: ";
        option = getchar();
        while (getchar() != '\n') continue;
        cout << "\n\n";
        switch(option)
        {
            case '1':
                obj.insert_f();
                break;
            case '2':
                obj.delete_f();
                break;
            case '3':
                obj.modify_f();
                break;
            case '4':
                obj.show_f();
                break;
            case '5':
                obj.save_f();  /* 儲存檔案 */
                exit(0);
            default :
                puts("Wrong option!");
        }
    }
    system("PAUSE");
    return 0;
}
/* 載入函數，將資料檔dfile.dat載入到程式中 */
void Bst::load_f(void)
{
    FILE *fptr;
    char name[20];
    int score;
    cout << "File loading...";
    if((fptr = fopen("bst.dat", "r")) == NULL)  /* 開啟檔案 */
    {
        puts("failed!");
        puts("bst.dat not found!");
        return;
    }
    while(fscanf(fptr, "%s %d", name, &score) != EOF)  /* 讀取檔案資料 */
        if(strcmp(name, "") != 0)
            access(name, score);
    puts("OK!");
    fclose(fptr);  /* 關閉檔案 */
}

/* 儲存檔案，將二元搜尋樹中的資料儲存至資料檔dfile.dat中 */
void Bst::save_f(void)
{
    FILE *fptr;
    cout << "File saving...";
    if((fptr = fopen("bst.dat","w"))== NULL) /* 開啟檔案 */
    {
        puts("failed!");
        return;
    }
    preorder(root, fptr);  /* 以前序法寫入 */
    puts("OK!");
    fclose(fptr);  /* 關閉檔案 */
}

/* 新增函數，新增一筆新的資料 */
void Bst::insert_f(void)
{
    char name[20], temp[4];
    int score;
    puts("=====INSERT DATA=====");
    cout << "Enter student name: ";
    cin >> name;
    while (getchar() != '\n') continue;
    cout <<"Enter student score: ";
    cin >> temp;
    while (getchar() != '\n') continue;
    score = atoi(temp);
    access(name, score);
}
/* 刪除函數，將資料從二元搜尋樹中刪除 */
void Bst::delete_f(void)
{
    char name[20];
    if(root == NULL)
    {
        puts("No student record!");
        return;
    }
    puts("=====DELETE DATA=====");
    cout << "Enter student name: ";
    cin >> name;
    while (getchar() != '\n') continue;
    removing(name);
}

/* 修改資料，修改學生成績 */
void Bst::modify_f(void)
{
    struct student *node;
    char name[20], temp[4];
    if(root == NULL)  /* 判斷根節點是否為NULL */
    {
        puts("No student record!");
        return;
    }
    puts("=====MODIFY DATA===== ");
    cout << "Enter student name: ";
    cin >> name;
    while (getchar() != '\n') continue;
    if((node = search(name)) == NULL)
        cout << "Student " << name << " not found!\n";
    else
    {
        /* 列出原資料狀況 */
        cout << "Original student name: " << node->name << "\n";
        cout << "Original student score: " << node->score << "\n";
        cout << "Enter new score: ";
        cin >> temp;
        while (getchar() != '\n') continue;
        node->score = atoi(temp);
        cout << "Data of student " << name << " modified\n";
    }
}

/* 輸出函數，將資料輸出至螢幕 */
void Bst::show_f(void)
{
    if(root == NULL)  /* 判斷根節點是否為NULL */
    {
        puts("No student record!");
        return;
    }
    puts("=====SHOW DATA=====");
    inorder(root);  /* 以中序法輸出資料 */
}

/* 處理二元搜尋樹，將新增資料加入至二元搜尋樹中 */
void Bst::access(char name[], int score)
{
    struct student *node, *prev;
    if(search(name) != NULL)  /* 資料已存在則顯示錯誤 */
    {
        cout << "Student " << name << " has existed!\n";
        return;
    }
    ptr = (struct student *) malloc(sizeof(struct student));
    strcpy(ptr->name, name);
    ptr->score = score;
    ptr->llink = ptr->rlink = NULL;
    if(root == NULL)  /* 當根節點為NULL的狀況 */
        root = ptr;
    else  /* 當根節點不為NULL的狀況 */
    {
        node = root;
        while(node != NULL)  /* 搜尋資料插入點 */
        {
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

/* 將資料從二元搜尋樹中移除 */
void Bst::removing(char name[])
{
    struct student *del_node;
    if((del_node = search(name)) == NULL)  /* 找不到資料則顯示錯誤 */
    {
        cout << "Student " << name << " not found!\n";
        return;
    }
    /* 節點不為樹葉節點的狀況 */
    if(del_node->llink != NULL || del_node->rlink != NULL)
        del_node = replace(del_node);
    else  /* 節點為樹葉節點的狀況 */
        if(del_node == root)
            root = NULL;
        else
            connect(del_node, 'n');
    free(del_node);  /* 釋放記憶體 */
    cout << "Data of student " << name << " deleted!\n";
}

/* 尋找刪除非樹葉節點的替代節點 */
struct student * Bst::replace(struct student *node)
{
    struct student *re_node;
    /* 當右子樹找不到替代節點，會搜尋左子樹是否存在替代節點 */
    if((re_node = search_re_r(node->rlink)) == NULL)
        re_node = search_re_l(node->llink);
    if(re_node->rlink != NULL)  /* 當替代節點有右子樹存在的狀況 */
        connect(re_node, 'r');
    else
        if(re_node->llink != NULL)  /* 當替代節點有左子樹存在的狀況 */
            connect(re_node, 'l');
        else  /* 當替代節點為樹葉節點的狀況 */
            connect(re_node, 'n');
    strcpy(node->name, re_node->name);
    node->score = re_node->score;
    return re_node;
}

/* 調整二元搜尋樹的鏈結，link為r表示處理右鏈結，為l表處理左鏈結，
 為m則將鏈結指向NULL */
void Bst::connect(struct student *node, char link)
{
    struct student *parent;
    parent = search_p(node);  /* 搜尋父節點 */
    /* 節點為父節點左子樹的狀況 */
    if(strcmp(node->name, parent->name) < 0)
        if(link == 'r')  /* link為r */
            parent->llink = node->rlink;
        else  /* link為m */
            parent->llink = NULL;
        else  /* 節點為父節點右子樹的狀況 */
            if(link == 'l')  /* link為l */
                parent->rlink = node->llink;
            else  /* link為m */
                parent->rlink = NULL;
}

/* 以中序法輸出資料，採遞迴方式 */
void Bst::inorder(struct student *node)
{
    if(node != NULL)
    {
        inorder(node->llink);
        cout << left << setw(15) << node->name << node->score << "\n";
        inorder(node->rlink);
    }
}

/* 以前序法將資料寫入檔案，採遞迴方式 */
void Bst::preorder(struct student *node, FILE *fptr)
{
    if(node != NULL)
    {
        fprintf(fptr, "%s %d\n", node->name, node->score);
        preorder(node->llink, fptr);
        preorder(node->rlink, fptr);
    }
}

/* 搜尋target所在節點 */
struct student * Bst::search(char target[])
{
    struct student *node;
    node = root;
    while(node != NULL)
    {
        if(strcmp(target, node->name) == 0)
            return node;
        else
        /* target小於目前節點，往左搜尋 */
            if(strcmp(target, node->name) < 0)
                node = node->llink;
            else  /* target大於目前節點，往右搜尋 */
                node = node->rlink;
    }
    return node;
}

/* 搜尋右子樹替代節點 */
struct student * Bst::search_re_r(struct student *node)
{
    struct student *re_node;
    re_node = node;
    while(re_node != NULL && re_node->llink != NULL)
        re_node = re_node->llink;
    return re_node;
}
/* 搜尋左子樹替代節點 */
struct student * Bst::search_re_l(struct student *node)
{
    struct student *re_node;
    re_node = node;
    while(re_node != NULL && re_node->rlink != NULL)
        re_node = re_node->rlink;
    return re_node;
}
/* 搜尋node的父節點 */
struct student * Bst::search_p(struct student *node)
{
    struct student *parent;
    parent = root;
    while(parent != NULL)
    {
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
