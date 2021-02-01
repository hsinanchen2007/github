#include<stdio.h>
int main(void)
{
    char ch;
    printf("1.80以上,\n2.60~79,\n3.59以下\n");
    printf("請輸入分數群組: ");
    scanf("%c",&ch);
    /*switch 條件敘述開始*/
    switch(ch)
    {
        /* 此處不加大括號*/
        case '1':
          printf("繼續保持!\n");
          break;
        case '2':
          printf("還有進步空間!!\n");
          break;
        case '3':
          printf("請多多努力!!!\n");
          break;
        default:
          printf("error\n");
          break;
    }
    system("pause");
    return 0; 
} 
