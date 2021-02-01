#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int x[],int n)
{
    int i,j,minIndex,minValue,temp;


    for(i=0;i<n;i++)
    {
      minIndex = i;            /* minIndex存放未排序區間的最小值索引 */
      minValue = x[minIndex];  /* minValue存放未排序區間的最小值 */
      for(j=i+1;j<n; j++ )
      {
          if(x[j] < minValue)
          {
              minIndex = j;
              minValue = x[minIndex];
          }
      }
      temp = x[minIndex];  x[minIndex] = x[i];  x[i] = temp; /* 互換 */
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
      int x[5] = {24,21,36,42,25};  
      printf("排序前  ");
      PrintData(x,5);
      SelectionSort(x,5);
      printf("排序後  ");
      PrintData(x,5);
      
      system("pause");
      return 0;
}
