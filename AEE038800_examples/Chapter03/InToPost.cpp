/* File name: InToPost.cpp */
/* August, 2017 */
/* 將數學式子由中序表示法轉為後序表示法 */

#include <iostream>
#include <stdlib.h>

#define MAX 20

using namespace std;

class In_to_post {
private:
    char infix_q[MAX];   // 儲存使用者輸入中序式的佇列
    public :
    void infix_to_postfix(void); // 由中序轉後序函數
    int compare(char stack_o, char infix_o); // 比較兩個運算子函數
};

void In_to_post::infix_to_postfix(void)
{
    int rear = -1, top = 0, ctr;
    char stack_t[MAX];  // 用以儲存還不必輸出的運算子
    
    while(infix_q[rear] != '\n')
        cin.get(infix_q[++rear]);
    infix_q[rear] = '#';  // 於佇列結束時加入#為結束符號
    cout << "Postfix expression: ";
    stack_t[top] = '#'; // 於堆疊最底下加入#為結束符號
    for(ctr = 0; ctr <= rear; ctr++) {
        switch(infix_q[ctr]) {
                // 輸入為)，則內輸出堆疊內運算子，直到堆疊內為(
            case ')':
                while(stack_t[top] != '(')
                    cout << stack_t[top--];
                top--;
                break;
                // 輸入為#，則將堆疊內還未輸出的運算子輸出
            case '#':
                while(stack_t[top] != '#')
                    cout << stack_t[top--];
                break;
                // 輸入為運算子，若小於TOP在堆疊中所指運算子，則將堆疊
                // 所指運算子輸出，若大於等於TOP在堆疊中所指運算子，則
                // 將輸入之運算子放入堆疊
            case '(':
            case '^':
            case '*':
            case '/':
                
            case '+':
            case '-':
                while(compare(stack_t[top], infix_q[ctr]))
                    cout << stack_t[top--];
                stack_t[++top] = infix_q[ctr];
                break;
                // 輸入為運算元，則直接輸出
            default :
                cout << infix_q[ctr];
                break;
        }
    }
}

// 比較兩運算子優先權，若輸入運算子小於堆疊中運算子，則傳回值為1，否則為0
int In_to_post::compare(char stack_o, char infix_o)
{
    // 在中序表示法佇列及暫存堆疊中，運算子的優先順序表，其優先權值為INDEX/2
    char infix_priority[9] = {'#', ')', '+', '-', '*', '/', '^', ' ', '('};
    char stack_priority[8] = {'#', '(', '+', '-', '*', '/', '^', ' '};
    int index_s = 0, index_i = 0;
    
    while(stack_priority[index_s] != stack_o)
        index_s++;
    while(infix_priority[index_i] != infix_o)
        index_i++;
    return index_s/2 >= index_i/2 ? 1 : 0;
}

int main()
{
    In_to_post obj;
    
    cout << "\n*********************************\n";
    cout << "      -- Usable operator --\n";
    cout << " ^: Exponentiation\n";
    cout << " *: Multiply      /: Divide\n";
    cout << " +: Add            -: Subtraction\n";
    cout << " (: Left Brace    ): Right Brace\n";
    cout << "*********************************\n";
    cout << "Please enter infix expression: ";
    obj.infix_to_postfix();
    
    system("PAUSE");
    return 0;
}
