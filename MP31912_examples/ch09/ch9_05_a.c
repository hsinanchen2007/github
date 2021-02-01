#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int i,int n)
{
    int data[]={20,24,27,46,57,15,23,29,48,62,65};
    int j;
    for(j=i;j<=n;j++)
       x[j] = data[j-i];
}

void PrintData(int x[],int i,int n)
{
    int j;
    for(j=i;j<=n;j++)
       printf("%2d  ",x[j]);
    printf("\n");
} 

void MergeSort(int x[],int sorted[],int i,int m,int n)
{
    int j,k,a;
    j = m + 1;
    
    for(k=i;i<=m && j<=n;k++)
    {
      if(x[i]<=x[j])
      {
       sorted[k] = x[i];
       i++;
      }
      else
      {
       sorted[k] = x[j];
       j++;
      }
    }
    if(i>m)
      for(a=j;a<=n;a++)
         sorted[k+a-j] = x[a];         /* 補上x[j]~x[n] */
    else
      for(a=i;a<=m;a++)
         sorted[k+a-i] = x[a];         /* 補上x[i]~x[m] */
}

int main()
{
    int x[100]={0};
    int sorted[100]={0};

    SetData(x,15,25);
    printf("排序前      x[15:19]="); PrintData(x,15,19);
    printf("排序前      x[20:25]=                    ");
    PrintData(x,20,25);
    
    MergeSort(x,sorted,15,19,25);
    
    printf("排序後 sorted[15:25]="); PrintData(sorted,15,25);
    system("pause");
    return 0;
}
