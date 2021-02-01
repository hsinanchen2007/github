/*  ch6_a.c   */

#include <stdio.h>
#include <stdlib.h>



typedef struct{
    int ItemKey;
    /*   佇列元素的其它欄位  */
}element;

struct Queue_Node{
    element Item;
    struct Queue_Node *link;
};

typedef struct Queue_Node Q_Node;
typedef Q_Node *Q_Node_P;


int main()
{     
    system("pause");
    return 0; 
}
