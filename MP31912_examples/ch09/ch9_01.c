#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int x[],int n)
{
    int i,k,flag,temp;
    
    k = n-1;
    while(k!=0)
    { 
      flag = 0; 
      for(i=0;i<=k-1;i++)
      {
         if(x[i] > x[i+1])
         {
              temp = x[i]; x[i] = x[i+1]; x[i+1] = temp;  /* �洫��� */
              flag = i;
         }
      }
      k = flag;
    }
}

void PrintData(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)             
       printf("%2d  ",x[i]);
     printf("\n");
} 

int main()
{
    int x[5] = {24,7,36,2,65};
    printf("�Ƨǫe  "); PrintData(x,5);
    BubbleSort(x,5);
    printf("�Ƨǫ�  "); PrintData(x,5);
    system("pause");
    return 0;
}
