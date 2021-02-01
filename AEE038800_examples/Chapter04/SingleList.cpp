/* File name: SingleList.cpp */
/* August, 2017 */
/* 單向鏈結串列，按照分數由大至小排序--新增、刪除、修改、輸出 */

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct student {
    char name[20];
    int score;
    struct student *next;
} Node_type;

class Single_link_list {
private:
    Node_type *ptr;
    Node_type *head;
    Node_type *tail;
    Node_type *current;
    Node_type *prev;
public:
    Single_link_list();
    void insert_f(void);
    void delete_f(void);
    void display_f(void);
    void modify_f(void);
};

Single_link_list::Single_link_list()
{
    head = new Node_type;
    head->next = NULL;
    tail = NULL;
}

void Single_link_list::insert_f(void)
{
    char s_temp[4];
    ptr = new Node_type;
    cout << " Student name : ";
    cin>>ptr->name;
    cout << " Student score: ";
    cin>>s_temp;
    ptr->score = atoi(s_temp);
    current = new Node_type;
    prev = head;
    current = head->next;
    while ((current != NULL) && (current->score > ptr->score)) {
        prev = current;
        current = current->next;
    }
    ptr->next = current;
    prev->next = ptr;
}

void Single_link_list::delete_f(void)
{
    char del_name[20];
    
    if (head->next == NULL)
        cout << " No student recond\n"; // 無資料顯示錯誤
    else {
        cout << " Delete student name: ";
        cin>>del_name;
        prev = head;
        current = head->next;
        while ((current != NULL) && (strcmp(current->name , del_name)!=0)) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {
            prev->next = current->next;
            delete current;
            cout << " " << del_name << " student record(s) deleted\n";
        }
        else
            cout << " Student " << del_name << " not found\n";
    }
}

void Single_link_list::modify_f(void)
{
    char n_temp[20],s_temp[4];
    
    if(head->next == NULL)
        cout << " No student recond\n"; // 無資料顯示錯誤
    else {
        cout << " Modify student name: ";
        cin>>n_temp;
         prev=head;
         current=head->next;
        while ((current != NULL) && (strcmp(current->name , n_temp)!=0)){
            prev = current;
            current = current->next;
        }
        if (current != NULL)  {
            cout << " **************************\n";
            cout << "  Student name : " << current->name << "\n";
            cout << "  Student score: " << current->score << "\n";
            cout << " **************************\n";
            cout << " Please enter new score: ";
            cin >> s_temp;
            prev->next = current->next;
            delete current;
            //重新加入
            ptr = new Node_type;
            strcpy(ptr->name, n_temp);
            ptr->score = atoi(s_temp);
            ptr->next = NULL;
            prev = head;
            current = head->next;
            while ((current != NULL) && (current->score > ptr->score)) {
                prev = current;
                current = current->next;
            }
            ptr->next = current;
            prev->next = ptr;

            cout << " " << n_temp << " student record modified\n";
        }
        else     // 找不到資料則顯示錯誤
            cout << " Student " << n_temp << " not found\n";
    }
}

void Single_link_list::display_f(void)
{
    int count=0;
    
    if(head->next == NULL)
        cout << " No student record\n";
    else {
        cout << "  NAME                SCORE\n";
        cout << " ---------------------------\n";
        current=head->next;
        while(current != NULL) {
            cout << "  ";
            cout.setf(ios::left, ios::adjustfield);
            cout.width(20);
            cout << current->name << " ";
            cout.setf(ios::right, ios::adjustfield);
            cout.width(3);
            cout << current->score << "\n";
            count++;
            current=current->next;
        }
        cout << " ---------------------------\n";
        cout << " Total " << count << " record(s) found\n";
    }
}

int main()
{
	Single_link_list obj;
	char option1;

	while(1) {
		cout << "\n****************************************\n";
		cout << "              1.insert\n";
		cout << "              2.delete\n";
		cout << "              3.display\n";
		cout << "              4.modify\n";
		cout << "              5.quit\n";
		cout << "****************************************\n";
		cout << "   Please enter your choice (1-5)...";
		cin>>option1;
		cout << "\n";
		switch(option1) {
			case '1': obj.insert_f();
					break;
			case '2': obj.delete_f();
					break;
			case '3': obj.display_f();
					break;
			case '4': obj.modify_f();
					break;
			case '5':	system("PAUSE");
	return 0;
		}
	}
}