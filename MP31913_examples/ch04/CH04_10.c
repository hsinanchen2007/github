#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char infix_q[MAX]; 
int compare(char stack_o, char infix_o); 
void infix_to_postfix();    
/*運算子優先權的比較，若輸入運算子小於堆疊中運算子*/
/*，則傳回值為1，否則為0                          */

/*主函數宣告*/
int main () 		
{ 
    int i=0;
    for (i=0; i<MAX; i++)
	infix_q[i]='\0';	
	printf("\t------------------------------------------\n");
	printf("\t中序運算式轉成後序運算式\n");
    printf("\t可以使用的運算子包括:^,*,+,-,/,(,)等 \n");
    printf("\t------------------------------------------\n");
    printf("\t請開始輸入中序運算式: ");
    infix_to_postfix();
    printf("\n");
    printf("\t--------------------------------------------\n");
    system("pause");      
    return 0; 
}
int compare(char stack_o, char infix_o)
{
/*在中序表示法佇列及暫存堆疊中，運算子的優先順序表，*/
/*其優先權值為INDEX/2                               */
    char infix_priority[9] ; 
	char stack_priority[8] ;
	int index_s=0, index_i=0;
	infix_priority[0]='q';infix_priority[1]=')';
	infix_priority[2]='+';infix_priority[3]='-';
	infix_priority[4]='*';infix_priority[5]='/';
	infix_priority[6]='^';infix_priority[7]=' ';
	infix_priority[8]='(';      
	stack_priority[0]='q';stack_priority[1]='(';
	stack_priority[2]='+';stack_priority[3]='-';
	stack_priority[4]='*';stack_priority[5]='/';
	stack_priority[6]='^';stack_priority[7]=' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}
void infix_to_postfix()
{
	int rear=0, top=0, flag=0,i=0;
	char stack_t[MAX];  
	for (i=0; i<MAX; i++)
			stack_t[i]='\0';
	    gets(infix_q);
	    i=0;
	    while(infix_q[i]!='\0') 
	    {
          i++;
          rear++;
        }
		infix_q[rear] = 'q';  
		printf("\t後序表示法 : ");
		stack_t[top]  = 'q';  
		for (flag = 0; flag <= rear; flag++)\
        {		
			switch (infix_q[flag]) 
            {
				/*輸入為)，則輸出堆疊內運算子，直到堆疊內為(*/
				case ')':
					while(stack_t[top]!='(') 			      
						printf("%c",stack_t[top--]);				   
					top--;
					break;
				/*輸入為q，則將堆疊內還未輸出的運算子輸出*/
				case 'q':
					while(stack_t[top]!='q')
						printf("%c",stack_t[top--]);
					break;
				/*輸入為運算子，若小於TOP在堆疊中所指運算子，*/
                /*則將堆疊所指運算子輸出，若大於等於TOP在堆疊*/
                /*中所指運算子，則將輸入之運算子放入堆疊     */
				case '(':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-': 
					while (compare(stack_t[top], infix_q[flag])==1)                       
						printf("%c",stack_t[top--]);			
					stack_t[++top] = infix_q[flag];
					break;
				/*輸入為運算元，則直接輸出*/
				default :
					printf("%c",infix_q[flag]);
					break;
			}
		}
}
