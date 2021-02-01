/* File name: Hashtable.cpp */
/* August, 2017 */
/* 雜湊法: 使用線性探測法處理碰撞 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define  MAX_NUM  100  // 最大資料筆數
#define  PRIME  97   // 最接近MAX_NUM的質數

using namespace std;

// 定義資料結構
typedef struct  Person {
    long  id;
    char name[21];
} Student;

class Linear_hash {
private:
    Student Hashtab[MAX_NUM];  // 建立雜湊表
public:
    Linear_hash();
    long hashfun(long);
    void insert();
    void del();
    void show();
    long search();
    void solve_collision(Student,long);
};

// 建構子
Linear_hash::Linear_hash()
{
    int i;
    // 清除雜湊表中id的內容,id為0代表該桶為空的
    for ( i = 0; i< MAX_NUM; i++)
        Hashtab[i].id = 0;
}

// 雜湊函數: 以除法運算傳求出記錄應儲存的位址
long Linear_hash::hashfun(long key)
{
    return ( key % PRIME );
}

void Linear_hash::insert()
{
    Student node;
    long index;
    
    // 輸入記錄
    cout << "Enter ID : ";
    cin >> node.id;
    cout << "Enter Name : ";
    cin >> node.name;
    // 利用雜湊函數取得儲存記錄位址
    index = hashfun(node.id);
    // 判斷雜湊表該(index)位址是否已有資料
    //	0代表該位址為空，否則即發生碰撞
    if ( Hashtab[index].id == 0 ) {
        Hashtab[index].id = node.id;
        strcpy(Hashtab[index].name,node.name);
        cout << "Node insert ok!\n";
    }
    else
        solve_collision(node,index);
}

// 利用線性探測解決碰撞
void Linear_hash::solve_collision(Student col_node,long i)
{
    long j;
    
    j = i;
    while ( Hashtab[j].id != col_node.id && Hashtab[j].id !=0 ) {
        j = (j+1) % PRIME;  /*將雜湊表視為環狀*/
        if ( j == i ) {
            cout << "Hashtab is overflow...\n";
            return;
        }
    }
    /* 判斷該位址是否已有資料*/
    if ( Hashtab[j].id == 0 ) {
        Hashtab[j].id = col_node.id;
        strcpy(Hashtab[j].name,col_node.name);
        cout << "Node insert ok!\n";
    }
    else
        cout << "Record existed in Hashtab!\n";
}

// 顯示雜湊表中之資料，從雜湊表第0桶開始尋找至最後一桶，一一比對是否該桶有存放資料
void Linear_hash::show()
{
    long i;
    
    cout << "Bucket         ID            Name\n";
    cout << "---------------------------------\n";
    for ( i = 0; i < MAX_NUM; i++ ) {
        // 判斷該位址是否有資料
        if (Hashtab[i].id != 0 ) {
            cout.width(5);
            cout << i << "  ";
            cout.width(10);
            cout << Hashtab[i].id << " ";
            cout.width(15);
            cout << Hashtab[i].name << "\n";
        }
    }
}

void Linear_hash::del()
{
    long  index;
    
    // 先搜尋記錄
    index = search();
    //判斷記錄是否存在
    if ( index != 0 ) {
        cout << "Deleting record....\n";
        Hashtab[index].id = 0;
    }
}

// 搜尋記錄函數
long Linear_hash::search()
{
    long id,index ,j;
    
    // 輸入欲搜尋記錄之學生id
    cout << "Enter ID : ";
    cin >> id;
    /*轉換該記錄在雜湊表中之位址*/
    index = hashfun(id);
    j = index;
    while ( Hashtab[j].id != id && j != index ) {
        j = (j + 1) % PRIME;
    }
    // 判斷資料是否存在,有則傳回該記錄在雜湊表中
    // 之位址以作刪除函數參考，否則傳回0
    if ( Hashtab[j].id == id) {
        cout << "ID : "<< Hashtab[j].id<< "    Name : " << Hashtab[j].name << "\n";
        return  j;
    }
    else {
        cout << "Can't find record !\n";
        return 0;
    }
}

int main()
{
    Linear_hash obj;
    string menu_prompt =
    "=== Hashing Table Program ==\n"
    "  1. Insert\n"
    "  2. Delete\n"
    "  3. Show\n"
    "  4. Search\n"
    "  5. Quit\n"
    "Please input a number : ";
    char menusele;
    
    do {
        cout << endl << menu_prompt;
        while(cin.get(menusele) && menusele == '\n');
        cin.get();
        menusele = toupper(menusele);
        cout << "\n";
        switch (menusele) {
            case '1' :
                obj.insert();
                break;
            case '2' :
                obj.del();
                break;
            case '3' :
                obj.show();
                break;
            case '4' :
                obj.search();
                break;
            case '5' :
                cout << "Bye Bye ^_^\n";
                system("PAUSE");
                return 0;
            default  :
                cout << "Invalid choice !!\n";
        }
    }  while (menusele != '5' );
}