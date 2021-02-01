/* File name : CircleList.cpp */
/* August, 2017 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
using namespace std;

void insertFunction(void);    /* 插入函數 */
void sortFunction(void);      /* 排序函數 */
void deleteFunction(void);    /* 刪除函數 */
void displayFunction(void);   /* 輸出函數 */
void modifyFunction(void);    /* 修改函數 */

struct student {
    char name[20];        /* 姓名 */
    int score;            /* 分數 */
    struct student *next; /* 下一個鏈結 */
};

class CircleList {
private:
    struct student *ptr, *head, *tail, *currentN, *prev;
public:
    CircleList();
    void sortFunction(void);
    void insertFunction(void);
    void deleteFunction(void);
    void modifyFunction(void);
    void displayFunction(void);
};

CircleList::CircleList(){
    head=(struct student *) malloc(sizeof(struct student));
    head->next = head;
}

int main()
{
    CircleList obj;
    char option1;
    
    while(1){
        cout << "\n ****************************************\n";
        cout << "               1.insert\n";
        cout << "               2.delete\n";
        cout << "               3.display\n";
        cout << "               4.modify\n";
        cout << "               5.quit\n";
        cout << " ****************************************\n";
        cout << "   Please enter your choice (1-5)...";
        option1=getchar();
        while (getchar()!='\n') continue;
        switch(option1){
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
                cout << "\n";
                return 0;
        }
    }
}

void CircleList::insertFunction(void)
{
    char sTemp[4];
    
    ptr = (struct student *) malloc(sizeof(struct student));
    cout << "\n Student name : ";
    cin >> ptr->name;
    while (getchar()!='\n') continue;
    cout << " Student score: ";
    cin >> sTemp;
    while (getchar()!='\n') continue;
    ptr->score = atoi(sTemp);
    sortFunction();
}
void CircleList::sortFunction(void)
{
    //插入資料
    prev = head;
    currentN = head->next;
    if (currentN != head) {
        while ((currentN != head) && (currentN->score > ptr->score)){
            prev = currentN;
            currentN = currentN->next;
        }
    }
    ptr->next = currentN;
    prev->next = ptr;
}

void CircleList::deleteFunction(void)
{
    char delName[20];
    
    cout << "\n Delete student name: ";
    cin >> delName;
    while (getchar()!='\n') continue;
    if(head->next == head) cout << " No student record\n";
    else{
        prev = head;
        currentN = head->next;
        while ((currentN != head) && (strcmp(currentN->name , delName)!=0)) {
            prev = currentN;
            currentN = currentN->next;
        }
        if (currentN != head){
            prev->next = currentN->next;
            delete(currentN);
            cout << " Student " << delName << " has been deleted\n";
        }
        else    /* 找不到資料則顯示錯誤 */
            cout << " Student " << delName << " not found\n";
    }
}

void CircleList::modifyFunction(void)
{
    char nTemp[20], sTemp[4];
    
    if(head->next == head) printf(" No student record\n");
    else{
        cout << "\n ModifyFunction student name: ";
        cin >> nTemp;
        while (getchar()!='\n') continue;
        prev = head;
        currentN=head->next;
        while ((currentN != head) && (strcmp(currentN->name , nTemp)!=0)) {
            prev = currentN;
            currentN = currentN->next;
        }
        if (currentN != head){
            cout << " **************************\n";
            cout << "  Student name : " << currentN->name << "\n";
            cout << "  Student score: " << currentN->score << "\n" ;
            cout << " **************************\n";
            cout << " Please enter new score: ";
            cin >> sTemp;
            while (getchar()!='\n') continue;
            prev->next = currentN->next;
            delete(currentN);
            ptr = (struct student *) malloc(sizeof(struct student));
            strcpy(ptr->name, nTemp);
            ptr->score = atoi(sTemp);
            ptr->next=NULL;
            prev = head;
            currentN = head->next;
            if (currentN != head) {
                while ((currentN != head) && (currentN->score > ptr->score)){
                    prev = currentN;
                    currentN = currentN->next;
                }
            }
            ptr->next = currentN;
            prev->next = ptr;
            cout << " Student " << nTemp << " has been modified\n";
        }
        else     /* 找不到資料則顯示錯誤 */
            cout << " Student " << nTemp << " not found\n";
    }
}

void CircleList::displayFunction(void)
{
    int count = 0;
    
    if(head->next == head ) cout << " No student record\n";
    else{
        cout << "\n  NAME                SCORE\n";
        cout << " ---------------------------\n";
        currentN=head->next;
        do{
            cout << "  " << left << setw(20) << currentN->name << " " << left << setw(3) << currentN->score << endl;
            count++;
            currentN=currentN->next;
            if(count % 20 == 0) getchar();
        }  while(currentN != head);
        cout << " ---------------------------\n";
        cout << " Total " << count << " record(s) found\n";
    }
}