#include <stdio.h>
int main(void)
{
    int iVal;
    printf("請輸入8進制數值:");
    scanf("%o",&iVal);
    printf("您所輸入8進制數值，代表10進制:%d\n",iVal);
    printf("\n");

    printf("請輸入10進制數值:");
    scanf("%d",&iVal);
    printf("您所輸入10進制數值，代表8進制:%o\n",iVal);
    printf("\n");

    printf("請輸入16進制數值:");
    scanf("%x",&iVal);
    printf("您所輸入16進制數值，代表10進制:%d\n",iVal);
    printf("\n");

    printf("請輸入10進制數值:");
    scanf("%d",&iVal);
    printf("您所輸入10進制數值，代表16進制:%x\n",iVal);
    printf("\n");    
    system("pause");
    return 0;
}
