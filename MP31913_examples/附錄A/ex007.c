#include<stdio.h>
int main(void)
{
    int product=1;
    int i=1;
    while(i<6)
    {
        product=i*product;
        printf("i=%d",i); 
        printf("\tproduct=%d\n",product);
        i++;
    }
    printf("\n連乘積的結果=%d",product);
    printf("\n");
    system("pause");
    return 0; 
} 
