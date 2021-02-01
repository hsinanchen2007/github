/* File name: MWayTree.cpp */
/* August, 2017 */
/* 建立一棵M-WAY的TREE來處理資料--載入、儲存、插入、刪除、輸出 */

#include <iostream>
#define MAX 3    // 設定M-WAY TREE的最大節點數
using namespace std;

typedef struct mway_tree {            // 定義資料欄位
    char id;                            // 輸出時識別節點
    int n;                               // 節點內的鍵值數
    int key[MAX];                      // 節點鍵值
    struct mway_tree *link[MAX];   // 節點子鏈節
} Node_type;

class Mwaytree {
private:
    Node_type *ptr;
    Node_type *root;
    Node_type *node;
    Node_type *prev;
    Node_type *parent;
    Node_type *replace;
    char id_seq;
public:
    Mwaytree();
    void insert_f(void);    // 插入函數
    void delete_f(void);    // 刪除函數
    void display_f(void);   // 輸出函數
    void create(int num);   // 加入資料後調整為M-WAY TREE
    // 移除資料後調整為M-WAY TREE
    void removes(Node_type *node_temp, int location);
    void initial(void);     // 節點初始化
    int search_num(int num);   // 搜尋鍵值所在節點位置
    Node_type *search_node(int num);  // 搜尋鍵值所在節點
    void moveright(int index, int num); // 節點內資料往右移
    void moveleft(int index);           // 節點內資料往左移
    Node_type *find_next(Node_type *node_temp);  // 尋找後繼節點
    Node_type *find_prev(Node_type *node_temp);  // 尋找前行節點
    void preorder_id(Node_type *tree);   // 給予每個節點識別編號
    void preorder_num(Node_type *tree);  // 輸出節點
};
Mwaytree::Mwaytree()
{
    root = NULL;
}

// 插入函數--新增一筆資料
void Mwaytree::insert_f(void)
{
    int add_num;
    
    cout << "\n Please enter insert number: ";
    cin >> add_num;
    create(add_num);
}

// 刪除函數--刪除一筆資料
void Mwaytree::delete_f(void)
{
    int del_num, ans;
    
    if(root == NULL)  // 當樹根為NULL，顯示錯誤訊息
        cout << "\n No data found!!\n";
    else {
        cout << "\n Please enter delete number: ";
        cin >> del_num;
        ans = search_num(del_num);  // 搜尋資料是否存在
        if(ans == 0)  // 當資料不存在，顯示錯誤訊息
            cout << " Number " << del_num << " not found!!\n";
        else {
            removes(node, ans);
            cout << " Number " << del_num << " deleted!!\n";
        }
    }
}

// 輸出函數--將M-WAY TREE內的所有資料輸出
void Mwaytree::display_f(void)
{
    if(root == NULL)  // 當樹根為NULL，顯示錯誤訊息
        cout << "\n No data found!!\n";
    else {
        id_seq = 'a';  // 節點編號由a開始
        preorder_id(root);  // 給予每個節點編點
        cout << "\n =================================================\n";
        preorder_num(root); // 輸出節點資料
        cout << " =================================================\n";
    }
}

// 將資料加入，並調整為M-WAY TREE，NUM為新增之資料鍵值
void Mwaytree::create(int num)
{
    int ans, i;
    
    if(root == NULL) { // 樹根為NULL的狀況
        initial();
        ptr->key[1] = num;
        ptr->n++;
        root = ptr;
    }
    else {
        ans = search_num(num);  // 搜尋資料是否已存在
        if(ans != 0)  // 資料存在，則顯示錯誤訊息
            cout << " Number " << num << " has existed!!\n";
        else {
            node = search_node(num);  // 找尋插入點
            if(node != NULL) {  // 插入點還有空間存放資料的狀況
                for(i = 1; i < MAX-1; i++)
                    if(num < node->key[i]) break;
                moveright(i, num);
            }
            else { // 新增加一個節點加入資料的狀況
                initial();
                ptr->key[1] = num;
                ptr->n++;
                for(i = 1; i < MAX; i++)
                    if(num < prev->key[i]) break;
                prev->link[i-1] = ptr;
            }
        }
    }
}

// 將資料移除，並調整為M-WAY TREE，NODE_TEMP為刪除資料所在節點，
// LOCATION為資料在節點中的位置
void Mwaytree::removes(Node_type *node_temp, int location)
{
    int i;
    
    node = node_temp;
    replace = find_next(node->link[location]); // 找尋替代之後繼節點
    if(replace == NULL) { // 沒有後繼節點的狀況
        replace = find_prev(node->link[location-1]); // 找尋替代之前行節點
        if(replace == NULL) { // 沒有前行節點的狀況
            moveleft(location);
            replace = node;
            if(node->n == 0) {  // 刪除資料後，節點內資料為0的處理
                if(node == root)  // 當節點為根的狀況
                    root = NULL;
                else  // 節點不是根，則調整鏈結
                    for(i = 0; i <= parent->n; i++)
                        if(node == parent->link[i]) {
                            parent->link[i] = NULL;
                            break;
                        }
                delete replace;
            }
        }
        else { // 有前行節點的狀況
            // 以前行節點的資料代替刪除資料
            node->key[location] = replace->key[replace->n];
            parent = prev;
            removes(replace, replace->n);  // 移除替代資料
        }
    }
    else { // 有後繼節點的狀況
        // 以後繼節點的資料代替刪除資料
        node->key[location] = replace->key[1];
        parent = prev;
        removes(replace, 1);  // 移除替代資料
    }
}

// 初始化節點--新增一個節點，將其所有鏈結指向NULL，設其節點數為0
void Mwaytree::initial(void)
{
    int i;
    ptr = new Node_type;
    
    for(i = 0; i < MAX; i++)
        ptr->link[i] = NULL;
    ptr->n = 0;
}

// 搜尋節點位置--搜尋NUM，存在則回傳NUM在節點中的位置，不存在則回傳0
int Mwaytree::search_num(int num)
{
    int done, i;
    node = root;
    
    while(node != NULL) {
        parent = prev;
        prev = node;
        for(i = 1, done = 0; i <= node->n; i++) {
            if(num == node->key[i])
                return i;   // 找到NUM，回傳其在節點中的位置
            if(num < node->key[i]) {
                node = node->link[i-1];
                done = 1;
                break;
            }
        }
        if(done == 0)
            node = node->link[i-1];
    }
    return 0;   // 沒有找到則回傳0
}

// 搜尋節點--尋找插入NUM的節點，並回傳插入節點
Node_type *Mwaytree::search_node(int num)
{
    int i, done;
    Node_type *node_temp;
    
    node_temp = root;
    while(node_temp != NULL) {
        if(node_temp->n < MAX-1)
            return node_temp;  // 找到有多餘空間存放NUM，則回傳此節點
        else {
            for(i = 1, done = 0; i < MAX; i++) {
                if(node_temp->n < i)
                    break;
                if(num < node_temp->key[i]) {
                    node_temp = node_temp->link[i-1];
                    done = 1;
                    break;
                }
            }
            if(done == 0)
                node_temp = node_temp->link[i-1];
        }
    }
    return node_temp;  // 若沒有找到有多餘空間存放NUM的節點，回傳NULL
}

// 將節點內資料右移--將節點資料右移至INDEX位置，並將NUM插入
void Mwaytree::moveright(int index, int num)
{
    int i;
    
    for(i = node->n+1; i > index; i--) {  // 資料右移至INDEX處
        node->key[i] = node->key[i-1];
        node->link[i] = node->link[i-1];
    }
    node->key[i] = num;  // 插入NUM
    // 調整NUM左右鏈結
    if(node->link[i-1] != NULL && node->link[i-1]->key[0] > num) {
        node->link[i] = node->link[i-1];
        node->link[i-1] = NULL;
    }
    node->n++;
}
// 將節點內資料左移--將節點資料從INDEX位置左移
void Mwaytree::moveleft(int index)
{
    int i;
    
    for(i = index; i < node->n; i++) { // 節點資料左移
        node->key[i] = node->key[i+1];
        node->link[i] = node->link[i+1];
    }
    node->n--;
}

// 尋找後繼節點--尋找NODE_TEMP的後繼節點，回傳找到的後繼節點
Node_type *Mwaytree::find_next(Node_type *node_temp)
{
    prev = node;
    if(node_temp != NULL)
        while(node_temp->link[0] != NULL) {
            prev = node_temp;
            node_temp = node_temp->link[0];
        }
    return node_temp;
}

// 尋找前行節點--尋找NODE_TEMP的前行節點，回傳找到的前行節點
Node_type *Mwaytree::find_prev(Node_type *node_temp)
{
    prev = node;
    if(node_temp != NULL)
        while(node_temp->link[MAX-1] != NULL) {
            prev = node_temp;
            node_temp = node_temp->link[MAX-1];
        }
    return node_temp;
}

// 給予節點編號--使用前序遞迴方式給予每個節點編號
void Mwaytree::preorder_id(Node_type *tree)
{
    int i;
    
    if(tree != NULL) {
        tree->id = id_seq++;
        for(i = 0; i <= tree->n; i++)
            preorder_id(tree->link[i]);
    }
}

// 輸出資料--使用前予遞迴方式輸出節點資料
void Mwaytree::preorder_num(Node_type *tree)
{
    int i;
    char link_id;
    
    if(tree != NULL) {
        // 當節點鏈節為NULL，則顯示鏈結為0
        if(tree->link[0] == NULL) link_id = '0';
        else link_id = tree->link[0]->id;
        cout << "  " << tree->id << ", " << tree->n << ", " << link_id;
        for(i = 1; i <= tree->n; i++) {
            if(tree->link[i] == NULL) link_id = '0';
            else link_id = tree->link[i]->id;
            cout << ", (" << tree->key[i] << ", " << link_id << ")";
        }
        cout << "\n";
        for(i = 0; i <= tree->n; i++)
            preorder_num(tree->link[i]);
    }
}

int main()
{
        Mwaytree obj;
        char menusele;
        
        do {
                cout << "\n ***************************\n";
                cout << "        <1> insert\n";
                cout << "        <2> delete\n";
                cout << "        <3> display\n";
                cout << "        <4> quit\n";
                cout << " ***************************\n";
                cout << " Please enter your choice: ";
                while(cin.get(menusele) && menusele == '\n');
                cin.get();
                menusele = toupper(menusele);
                cout << "\n";
                switch(menusele) {
                            case '1': obj.insert_f();
                                break;
                            case '2': obj.delete_f();
                                break;
                            case '3': obj.display_f();
                                break;
                            case '4': system("PAUSE");
                                return 0;
                            default : cout << "\n Option error!!\n";
                    }
            } while(menusele != '4');
}