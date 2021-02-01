#include <stdio.h>
int main(void)
{
    int Val=123;
    printf("各種格式化字元的輸出\n");
    printf("  Val=%d\n",Val);
    printf("%%iVal=%i\n",Val);
    printf("%%oVal=%o\n",Val);
    printf("%%uVal=%u\n",Val);
    printf("%%xVal=%x\n",Val); 
    system("pause");     
    return 0;
}
