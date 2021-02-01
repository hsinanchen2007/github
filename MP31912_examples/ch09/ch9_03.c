#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)             
       printf("%2d  ",x[i]);
     printf("\n");
} 

void InsertionSort(int x[],int n)
{
    int i,j,temp;
    for(j=1;j<n;j++)
    {
       temp = x[j];
       i = j-1;
       while(temp < x[i] && i>=0)  
       {
          x[i+1] = x[i];
          i--;
       }
       x[i+1] = temp;     
       printf("Step %d  ",j);
       PrintData(x,j+1);
    }
}

int main()
{
    int x[5]={24,21,16,42,25};    
   
    printf("排序前  "); PrintData(x,5);
    InsertionSort(x,5);
    printf("排序後  "); PrintData(x,5);
  
    system("pause");
    return 0;
}
