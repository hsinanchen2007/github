/* File name: Mstack.cpp */
/* August, 2017 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define MAX  10
#define UNIT  2
void pushFunction(int number1);
void popFunction(int number2);
void listFunction(int number3);

char MS[MAX][20];
int t[(MAX/UNIT)], b[(MAX/UNIT)];

int main()
{
    int option, i;
    int  number1, number2, number3;
    
    for (i=0; i<= UNIT-1; i++){
        if (UNIT == 1) {
            t[i+1] = MAX-1;
            b[i+1] = MAX-1;
            t[i] = i*(MAX/UNIT)-1;
            b[i] = i*(MAX/UNIT)-1;
        }
        else {
            t[i] = i*(MAX/UNIT)-1;
            b[i] = i*(MAX/UNIT)-1;
        }
    }
    while(1){
        cout << "\n *****************************\n";
        cout << "        <1> insert (push)\n";
        cout << "        <2> delete (pop)\n";
        cout << "        <3> list\n";
        cout << "        <4> quit\n";
        cout << " *****************************\n";
        cout << " Please enter your choice...";
        cin >> option;
        switch(option) {
            case 1:
                cout << "\n The total number of Stack is " << UNIT << " !!";
                cout << "\n Please enter the number of stack ?";
                cin >> number1;
                if (number1 > UNIT)
                    cout << " Sorry, the number is out of Stack total 								number !!\n";
                else
                    pushFunction(number1);
                break;
            case 2:
                cout << "\n Please enter the number of stack ?";
                cin >> number2;
                if (number2 > UNIT)
                    cout << " Sorry, the number is out of Stack total number !!\n";
                else
                    popFunction(number2);
                break;
            case 3:
                cout << "\n Please enter the number of stack ?";
                cin >> number3;
                if (number3 > UNIT)
                    cout << " Sorry, the number is out of Stack total number !!\n";
                else
                    listFunction(number3);
                break;
            case 4:
                cout << "\n";
                return 0;
        }
    }
}

void pushFunction(int number1)
{
    if(t[number1-1] == b[number1]){
        cout << " Stack" << number1 << " is full !\n";
        cout << " Please choose another Stack to insert !!\n";
    }
    else{
        cout << " Please enter item to insert: ";
        cin >> MS[++t[number1-1]];
        cout << " You insert " << MS[t[number1-1]] << " to #" << number1 << " stack !!\n";
    }
}

void popFunction(int number2)
{
    if(t[number2-1] == b[number2-1])
        cout << "\n No item, stack" << number2 << " is empty !\n";
    else{
        cout << "\n Item " << MS[t[number2-1]] << " in Stack " << number2 << " is deleted\n";
        t[number2-1]--;
    }
}

void listFunction(int number3)
{
    int count = 0, i, startNumber = 0;
    if(t[number3-1] == b[number3-1])
        cout << "\n No item, stack is empty\n";
    else{
        startNumber = (number3-1)*(MAX/UNIT)-1;
        cout << "\n  ITEM\n";
        cout << " ------------------\n";
        for(i = startNumber+1 ; i <= t[number3-1]; i++){
            cout << "  " << setw(2) << MS[i] << "\n";
            count++;
            if(count % 20 == 0) getchar();
        }
        cout << " ------------------\n";
        cout << "  Total item: " << count << "\n";
    }
}
