/*   Merge Sort algorithm - Recursive version  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int i,int n)
{
    int data[] = {20,24,27,46,57,15,23,29,48,62,65};
    int j;
    for(j=i;j<=n;j++)
       x[j]=data[j-i];
}

void PrintData(int x[],int i,int n)
{
    int j;
    for(j=i;j<=n;j++)
       printf("%2d  ",x[j]);
    printf("\n");
} 



void ShiftTo(int x[],int Dest,int Src)  /* ShiftTo : 取出x[Dest]~x[Src]最小的放最前,其餘向後移一格 */
{
     int i,temp;

     temp = x[Src];
     for(i=Src;i>Dest;i--)
       x[i] = x[i-1];
     x[Dest] = temp;
}
 
void SortingX(int x[],int left,int middle,int right)
{
    int i,j;

    i = left;             /* i是要合併的第一個子串列開頭位置 */
    
    j = middle + 1;         /* j是要合併的第二個子串列開頭位置 */
    
    while((j!=right+1)&&(i!=j))
    {
     if(x[j]<=x[i])
     {
         ShiftTo(x,i,j);    /* x[i],x[i+1]..x[j-1],x[j] -> x[j],x[i],x[i+1],...x[j-1] */
         
         /* x[i]~x[j]中第一個已定位,繼續處理x[i+1]~x[j+1]的定位 */
         i++;
         j++;
     }
     else
         i++;   /* x[i]~x[j]中第一個已定位,繼續處理x[i+1]~x[j]的定位 */
   }
}
 
void MergeR(int x[], int left, int middle, int right)
{
    if(left == right)
       return;
    else
    {
       MergeR(x,left,(left+middle)/2,middle);          /* 前半部合併 */
       MergeR(x,middle+1,(middle+1+right)/2,right);    /* 後半部合併 */
    }
    SortingX(x,left,middle,right);  /* 將x[left]~x[right]排序 */
}
 
int main(void)
{
    int x[10]={0};

    SetData(x,0,9);
    printf("排序前 x[]="); PrintData(x,0,9);
    MergeR(x,0,10/2,9);
    printf("排序後 x[]="); PrintData(x,0,9);

    system("pause");
    return 0;
}
