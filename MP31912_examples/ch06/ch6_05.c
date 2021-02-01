#include <stdio.h>

#define MaxStackSize 100
#define MaxExprSize 100

typedef enum {LPAREN,RPAREN,PLUS,MINUS,TIMES,DIVIDE,EOE,OPERAND} TokenType;
TokenType stack[MaxStackSize];
char expr[MaxExprSize];          /* 用來存放使用者輸入的中序運算式  */
int isp[] = {0,19,12,12,13,13,0};
int icp[] = {20,19,12,12,13,13,0};   /* 符號分別為 (, ), +,-,  *,/, EOE */

TokenType GetOneToken(char *symbol,int *c)
{
    *symbol = expr[*c];
    (*c)++;
    switch (*symbol)
    {
      case '(': return LPAREN;
      case ')': return RPAREN;
      case '+': return PLUS;
      case '-': return MINUS;
      case '*': return TIMES;
      case '/': return DIVIDE;
      case '@': return EOE;
      default: return OPERAND;
    }
}

void PrintTokenOperator(TokenType token_operator)
{
    switch (token_operator)
    {
      case PLUS:    printf("+");  break;
      case MINUS:   printf("-");  break;
      case TIMES:   printf("*");  break;
      case DIVIDE:  printf("/");  break;
      default: break;
    }
}

void push(int *top,TokenType token_operator)
{
    if(*top>=MaxStackSize-1)
    {
      printf("堆疊已滿!");
      exit(1);
    }
    stack[++(*top)] = token_operator;
  }

TokenType pop(int *top)
{
    if(*top==-1)
    {
      printf("堆疊已空!");
      exit(1);
    }
    return stack[(*top)--];
}

void TransToPostfix(void)
{
  char symbol;
  TokenType token;
  int top=0;
  int c=0;
  stack[0] = EOE;

  token = GetOneToken(&symbol,&c);
  while(token!=EOE)
  {
     if(token==OPERAND)   /* 遇到運算元  */
        printf("%c",symbol);
     else
        if(token==RPAREN)
        {
          while(stack[top]!=LPAREN)
              PrintTokenOperator(pop(&top));
          pop(&top);  /* 將(pop出來,但不印出 */
        }
        else                /* 遇到非)的任何運算子 */
        {
          while(isp[stack[top]]>=icp[token])
              PrintTokenOperator(pop(&top));  
          push(&top,token);                  
        }
     token = GetOneToken(&symbol,&c);
  }

  while((token=pop(&top))!=EOE)
      PrintTokenOperator(token);
}


int main(void)
{
    printf("請輸入中序表示法,結尾字元為@:");
    scanf("%s",expr);   /* 請讀者自行加入檢查末端字元為@ */ 
    printf("後序表示法為:");
    TransToPostfix();
    system("pause");
    return 0;
}
