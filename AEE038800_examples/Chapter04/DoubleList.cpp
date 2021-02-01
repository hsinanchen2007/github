/* File name: DoubleList.cpp */
/* August, 2017 */
/* 雙向鏈結串列，按照分數由大至小排序--新增、刪除、修改、輸出 */

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct student {
    char name[20];           // 姓名
    int score;                // 分數
    struct student *llink;  // 節點左鏈結
    struct student *rlink;  // 節點右鏈結
} Node_type;

class Double_link_list {
private:
    Node_type *ptr;
    Node_type *head;
    Node_type *tail;
    Node_type *prev;
    Node_type *current;
public:
    Double_link_list();   // 初始化串列，建立一空節點為HEAD
    void insertFunction(void);  // 插入函數
    void deleteFunction(void);  // 刪除函數
    void displayFunction(void); // 輸出函數
    void modifyFunction(void);  // 修改函數
};

Double_link_list::Double_link_list() // 設一HEAD，將左右鏈結皆指向本身
{
    ptr = new Node_type;
    
    strcpy(ptr->name, "0");
    ptr->llink = ptr;
    ptr->rlink = ptr;
    head = ptr;
    tail = ptr;
}

void Double_link_list::insertFunction(void)
{
    char s_temp[4];
    ptr = new Node_type;
    
    cout << " Student name : ";
    cin>>ptr->name;
    cout << " Student score: ";
    cin>>s_temp;
    ptr->score = atoi(s_temp);
    prev = head;
    current = head->rlink;
    while((current != head) && (current->score >= ptr->score)) {
        prev = current;
        current = current->rlink;
    }
    ptr->rlink = current;
    ptr->llink = prev;
    prev->rlink = ptr;
    current->llink = ptr;
}

void Double_link_list::deleteFunction(void)
{
    char del_name[20];
    int count = 0;
    
    if(head->rlink == head)
        cout << " No student recond\n"; // 無資料顯示錯誤
    else {
        cout << " Delete student name: ";
        cin>>del_name;
        prev = head;
        current = head->rlink;
        while ((current != head) && (strcmp(current->name , del_name)!=0)) {
            prev = current;
            current = current->rlink;
        }
        if (current != head) {
            prev->rlink = current->rlink;
            current->rlink->llink = prev;
            delete current;
            cout << " " << del_name << " student record(s) deleted\n";
        }
        else
            cout << " Student " << del_name << " not found\n";
    }
}



void Double_link_list::modifyFunction(void)
{
    int count = 0;
    char n_temp[20], s_temp[4];
    
    if(head->rlink == head)
        cout << " No student recond\n"; // 無資料顯示錯誤
    else {
        cout << " Modify student name: ";
        cin>>n_temp;
        prev=head;
        current=head->rlink;
        while ((current != head) && (strcmp(current->name , n_temp)!=0)){
            prev = current;
            current = current->rlink;
        }
        if (current != head)  {
            cout << " **************************\n";
            cout << "  Student name : " << current->name << "\n";
            cout << "  Student score: " << current->score << "\n";
            cout << " **************************\n";
            cout << " Please enter new score: ";
            cin>>s_temp;
            prev->rlink = current->rlink;
            current->rlink->llink = prev;
            delete current;
            //重新加入
                             ptr = new Node_type;
                             strcpy(ptr->name, n_temp);
                             ptr->score = atoi(s_temp);
                             ptr->rlink = head;
                             prev = head;
                             current = head->rlink;
                             while ((current != head) && (current->score > ptr->score)) {
                                    prev = current;
                                    current = current->rlink;
                                 }
            ptr->rlink = current;
            ptr->llink = prev;
            prev->rlink = ptr;
            current->llink = ptr;
            
            cout << " " << n_temp << " student record modified\n";
        }
        else     // 找不到資料則顯示錯誤
            cout << " Student " << n_temp << " not found\n";
    }
}

void Double_link_list::displayFunction(void)
{
    int count = 0;
    
    if(head->rlink == head) cout << " No student record\n";
    else {
        cout << "  NAME                SCORE\n";
        cout << " ---------------------------\n";
        current = head->rlink;
        while(current != head) {
            cout << "  ";
            cout.setf(ios::left, ios::adjustfield);
            cout.width(20);
            cout << current->name << " ";
            cout.setf(ios::right, ios::adjustfield);
            cout.width(3);
            cout << current->score << "\n";
            count++;
            current = current->rlink;
        }
        cout << " ---------------------------\n";
        cout << " Total " << count << " record(s) found\n";
    }
}

int main()
{
    Double_link_list obj;
    char option1;
    
    while(1) {
        cout << " \n****************************************\n";
        cout << "              1.insert\n";
        cout << "              2.delete\n";
        cout << "              3.display\n";
        cout << "              4.modify\n";
        cout << "              5.quit\n";
        cout << " ****************************************\n";
        cout << "   Please enter your choice (1-5)...";
        cin>>option1;
        cout << "\n";
        switch(option1) {
            case '1':
                obj.insertFunction();
                break;
            case '2':
                obj.deleteFunction();
                break;
            case '3':
                obj.displayFunction();
                break;
            case '4':
                obj.modifyFunction();
                break;
            case '5':
                system("PAUSE");
                return 0;
        }
    }
}