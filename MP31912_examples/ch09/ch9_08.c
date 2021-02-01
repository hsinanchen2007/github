/*   Shell Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)             
        printf("%2d  ",x[i]);
     printf("\n");
} 

void ShellSort(int x[],int n)
{
    int i,j,increment,temp;

    increment = n / 2;  
    while(increment>0)
    {
      for(i=increment;i<n;i++)   /* 分組 */
      {
        j = i-increment;
        while(j>=0)
        {
            if(x[j] > x[j+increment])
            {
                temp = x[j];
                x[j] = x[j+increment];
                x[j+increment] = temp;
            }
            else
                j = j - increment;
        }
      }
      printf("        ");
      PrintData(x,9);
      increment = increment / 2;
    }
}

int main()
{
    int x[9] = {24,15,33,61,16,62,39,41,25};

    printf("排序前  "); PrintData(x,9);
    ShellSort(x,9);
    printf("排序後  "); PrintData(x,9);

    system("pause");
    return 0;
}
