#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

typedef enum {head,entry,matrix} nodetype;
nodetype tag;

typedef struct matrix_node MatrixNode;
typedef MatrixNode *MatrixNode_P;
struct entry_node
{
    int value;   /* 重要，必須放在第一項 */ 
    int row;
    int col;
};

struct matrix_node
{
    MatrixNode_P down;
    MatrixNode_P right;
    nodetype tag;
    union
    {
        MatrixNode_P Next;
        struct entry_node element;
    }u;
};

int main(void)
{
   system("pause");
   return 0;
}
