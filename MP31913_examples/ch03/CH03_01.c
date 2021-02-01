#include <stdio.h>
#include <stdlib.h>

int main()
{
    float* piF=(float*)malloc(sizeof(float));
    /* 將指標指向浮點數動態配置記憶空間 */
    
    printf("請輸入piF的值 =");
    scanf("%f",piF);/* 輸入piF的值 */ 
    printf("\n");
    printf("piF所指向的位址內容為 %f\n",*piF);
    printf("piF所指向的位址為 %p\n", piF);
    
    free(piF);/* 將指標piF的空間釋放 */ 
    
    system("pause");  
    return 0;
}

