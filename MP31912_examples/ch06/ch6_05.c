#include <stdio.h>

#define MaxStackSize 100
#define MaxExprSize 100

typedef enum {LPAREN,RPAREN,PLUS,MINUS,TIMES,DIVIDE,EOE,OPERAND} TokenType;
TokenType stack[MaxStackSize];
char expr[MaxExprSize];          /* �ΨӦs��ϥΪ̿�J�����ǹB�⦡  */
int isp[] = {0,19,12,12,13,13,0};
int icp[] = {20,19,12,12,13,13,0};   /* �Ÿ����O�� (, ), +,-,  *,/, EOE */

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
      printf("���|�w��!");
      exit(1);
    }
    stack[++(*top)] = token_operator;
  }

TokenType pop(int *top)
{
    if(*top==-1)
    {
      printf("���|�w��!");
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
     if(token==OPERAND)   /* �J��B�⤸  */
        printf("%c",symbol);
     else
        if(token==RPAREN)
        {
          while(stack[top]!=LPAREN)
              PrintTokenOperator(pop(&top));
          pop(&top);  /* �N(pop�X��,�����L�X */
        }
        else                /* �J��D)������B��l */
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
    printf("�п�J���Ǫ�ܪk,�����r����@:");
    scanf("%s",expr);   /* ��Ū�̦ۦ�[�J�ˬd���ݦr����@ */ 
    printf("��Ǫ�ܪk��:");
    TransToPostfix();
    system("pause");
    return 0;
}
