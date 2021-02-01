#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)             
       printf("%2d  ",x[i]);
     printf("\n");
} 

void TwoListMergeSort(int x[],int xSize,int y[],int ySize,int z[],int zSize)
{
    int i=0,j=0,k,a;


    for(k=0; i<xSize && j<ySize; k++)
    {
      if(x[i]<=y[j])
      {
          z[k] = x[i];
          i++;
      }
      else
      {
          z[k] = y[j];
          j++;
      }
    }
    if(i>=xSize)
      for(a=j;a<ySize;a++)
          z[k+a-j] = y[a];     
    else
      for(a=i;a<xSize;a++)
          z[k+a-i] = x[a];  
}


int main()
{
    int x[5] = {20,24,27,46,57};
    int y[6] = {15,23,29,48,62,65};
    int z[11] = {0};

    printf("排序前 x[]="); PrintData(x,5);
    printf("排序前 y[]="); PrintData(y,6);
    TwoListMergeSort(x,5,y,6,z,5+6);
    printf("排序後 z[]="); PrintData(z,11);
    system("pause");
    return 0;
}

