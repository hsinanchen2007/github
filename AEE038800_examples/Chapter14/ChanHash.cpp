/* File name: ChanHash.cpp */
/* August, 2017 */
/* 雜湊法 : 使用鏈結串列處理碰撞 */

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

#define  MAX_NUM  100  // 最大資料筆數
#define  PRIME  97     // MAX_NUM之質數
#define  NOTEXISTED  NULL

using namespace std;

// 定義資料結構
typedef struct Person {
    long id ;
    char name[21];
    struct Person *link ;
}  Student ;

class Chan_hash {
private:
    Student  *Hashtab[MAX_NUM] ;  // 建立雜湊表串列
public:
    Chan_hash();
    long hashfun(long) ;
    void insert() ;
    void del() ;
    Student *search(Student *,Student *) ;
    void query() ;
    void show();
};

Chan_hash::Chan_hash()
{
    int i;
    
    for ( i = 0; i< MAX_NUM ; i++)// 起始雜湊串列，將各串列指向NULL
        Hashtab[i] = NULL ;
}

// 雜湊函數: 以除法運算傳求出記錄應儲存的位址
long Chan_hash::hashfun(long key)
{
    return ( key % PRIME ) ;
}

void Chan_hash::insert()
{
    Student  *newnode ;
    long index ;
    
    // 輸入記錄
    newnode = new Student ;
    newnode->link = NULL ;
    cout << "Enter id : " ;
    cin >> newnode->id ;
    cout << "Enter Name : " ;
    cin >> newnode->name ;
    // 利用雜湊函數求得記錄位址
    index = hashfun(newnode->id) ;
    // 判斷該串列是否為空，若為空則建立此鏈結串列
    if ( Hashtab[index] == NULL ) {
        Hashtab[index] = newnode ;
        cout << "Node insert ok!\n";
    }
    else {
        // 搜尋節點是否已存在串列中，如未存在則將此節點加入串列前端
        if ((search(Hashtab[index],newnode)) == NOTEXISTED) {
            newnode->link = Hashtab[index] ;
            Hashtab[index] = newnode ;
            cout << "Node insert ok!\n";
        }
        else
            cout << "Record existed...\n";
    }
}

// 刪除節點函數
void Chan_hash::del()
{
    Student *node ,*node_parent;
    long index ;
    
    node = new Student ;
    cout << "Enter ID : " ;
    cin >> node->id ;
    // 利用雜湊函數轉換記錄位址
    index  =  hashfun(node->id) ;
    // 搜尋節點是否存在並傳回指向該節點指標
    node  = search(Hashtab[index],node) ;
    if ( node == NOTEXISTED )
        cout << "Record not existed ...\n" ;
    else {
        // 如節點為串列首，則將串列指向NULL，否則找到其父節點，並將父節點link向節點後端
        cout << "ID : " << node->id << "   Name : " << node->name << "\n" ;
        cout << "Deleting record....\n" ;
        if ( node == Hashtab[index] )
            Hashtab[index] = NULL ;
        else {
            node_parent = Hashtab[index] ;
            while ( node_parent->link->id != node->id )
                node_parent = node_parent->link ;
            node_parent->link = node->link ;
        }
        delete node;
    }
}

// 搜尋節點函數，如找到節點則傳回指向該節點之指標，否則傳回NULL
Student *Chan_hash::search(Student *linklist,Student *Node)
{
    Student *ptr = linklist ;
    
    if ( ptr == NULL )
        return NOTEXISTED ;
    while (ptr->link != NULL && ptr->id != Node->id)
        ptr = ptr->link ;
    return ptr ;
}

// 查詢節點函數
void Chan_hash::query()
{
    Student *query_node ;
    long index;
    
    query_node = new Student ;
    cout << "Enter ID : " ;
    cin >> query_node->id ;
    index = hashfun(query_node->id) ;
    // 搜尋節點
    query_node = search(Hashtab[index],query_node) ;
    if ( query_node == NOTEXISTED )
        cout << "Record not existed...\n" ;
    else {
        cout << "ID : "<< query_node->id<< "  Name : " << query_node->name << "\n" ;
    }
}

// 顯示節點函數，從雜湊串列一一尋找是否有節點存在
void Chan_hash::show()
{
    int i ;
    Student *ptr ;
    
    cout << "ID                  NAME\n" ;
    cout << "------------------------\n" ;
    for ( i = 0 ; i < MAX_NUM ;i++ ) {
        // 串列不為空，則將整串列顯示出
        if ( Hashtab[i] != NULL ) {
            ptr = Hashtab[i] ;
            while (ptr) {
                cout.setf(ios::left, ios::adjustfield) ;
                cout.width(5);
                cout << ptr->id << "    " ;
                cout.setf(ios::right, ios::adjustfield) ;
                cout.width(15);
                cout << ptr->name << "\n" ;
                ptr = ptr->link ;
            }
        }
    }
}

int main()
{
    Chan_hash obj ;
    string menu_prompt =
    "=== Hashing Table Program ==\n"
    "  1. Insert\n"
    "  2. Delete\n"
    "  3. Show\n"
    "  4. Search\n"
    "  5. Quit\n"
    "Please input a number : " ;
    char menusele ;
    
    do {
        cout << endl << menu_prompt ;
        while(cin.get(menusele) && menusele == '\n');
        cin.get();
        menusele = toupper(menusele);
        cout << "\n";
        switch (menusele) {
            case '1' :
                obj.insert() ;
                break ;
            case '2' :
                obj.del() ;
                break ;
            case '3' :
                obj.show() ;
                break ;
            case '4' :
                obj.query() ;
                break ;
            case '5' :
                cout << "Bye Bye ^_^\n" ;
                system("PAUSE");
                return 0;
            default  :
                cout << "Invalid choice !!\n" ;
        }
    }  while (menusele != '5' ) ;
}