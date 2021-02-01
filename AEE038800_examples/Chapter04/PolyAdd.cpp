/* File name: PolyAdd.cpp */
/* August, 2017 */
/* 多項式相加--使用降冪排列輸入兩個格式為ax^b的多項式相加 */

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct poly {
    int coef;   // 多項式係數
    int exp;    // 多項式指數
    struct poly *next;
} Node_type;

class Polynomial_add {
private:
    Node_type *ptr;
    Node_type *ans_h;
    Node_type *eq_h1;
    Node_type *eq_h2;
    public :
    Polynomial_add();
    void input_message(void);
    void input(struct poly **eq_h);  // 輸入函數
    void poly_add(void);               // 多項式相加函數
    void show_ans(void);               // 顯示多項式相加結果函數
};

Polynomial_add::Polynomial_add()
{
    ans_h = eq_h1 = eq_h2 = NULL;
}

void Polynomial_add::input_message(void)
{
    cout << "\n****************************************\n";
    cout << " -- Polynomial add using format ax^b --\n";
    cout << "****************************************\n";
    cout << "Please enter the first equation: ";
    input(&eq_h1);
    cout << "Please enter the second equation: ";
    input(&eq_h2);
}


void Polynomial_add::input(struct poly **eq_h)
{
    Node_type *prev = NULL;
    char temp1, temp2, symbol = '+';
    
    do {
        ptr = new Node_type;
        ptr->next = NULL;
        cin >> ptr->coef >> temp1 >> temp2 >> ptr->exp;
        if(*eq_h == NULL)
            *eq_h = ptr;
        else {
            if(symbol == '-') ptr->coef = -(ptr->coef);
            prev->next = ptr;
        }
        prev = ptr;
        cin.get(symbol);
    }  while(symbol != '\n');
}

void Polynomial_add::poly_add(void)
{
    Node_type *current_n1, *current_n2, *prev;
    
    current_n1 = eq_h1;
    current_n2 = eq_h2;
    prev = NULL;
    while(current_n1 != NULL || current_n2 != NULL){// 當兩個多項式皆相加完畢則結束
        ptr = new Node_type;
        ptr->next = NULL;
        // 第一個多項式指數大於第二個多項式
        if(current_n1 != NULL && (current_n2 == NULL ||
                                  current_n1->exp > current_n2->exp)) {
            ptr->coef = current_n1->coef;
            ptr->exp = current_n1->exp;
            current_n1 = current_n1->next;
        }
        else
            // 第一個多項式指數小於第二個多項式
            if(current_n1 == NULL || current_n1->exp < current_n2->exp)	{
                ptr->coef = current_n2->coef;
                ptr->exp = current_n2->exp;
                current_n2 = current_n2->next;
            }
            else { // 兩個多項式指數相等，進行相加
                ptr->coef = current_n1->coef + current_n2->coef;
                ptr->exp = current_n1->exp;
                if(current_n1 != NULL) current_n1 = current_n1->next;
                if(current_n2 != NULL) current_n2 = current_n2->next;
            }
        
        if(ptr->coef != 0) {  // 當相加結果不等於0，則放入答案多項式中
            if(ans_h == NULL) ans_h = ptr;
            else prev->next = ptr;
            prev = ptr;
        }
        else delete ptr;
    }
}

void Polynomial_add::show_ans(void)
{
    Node_type *this_n;
    
    this_n = ans_h;
    cout << "The answer equation: ";
    while(this_n != NULL) {
        cout << this_n->coef << "x^" << this_n->exp;
        if(this_n->next != NULL && this_n->next->coef >= 0)
            cout << "+";
        this_n = this_n->next;
    }
    cout << "\n";
}

int main()
{
    Polynomial_add obj;
    obj.input_message();
    obj.poly_add();
    obj.show_ans();
    
    system("PAUSE");
    return 0;
}