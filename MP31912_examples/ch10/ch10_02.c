/*  Binary Search algorithm  */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
      int key;
      char data;
     /*   其他資料欄位 */
}record;

void SetData(record x[],int n)
{
    int key[8] = {33,41,52,54,63,74,79,86};
    int data[8] = {'A','F','G','E','J','Q','W','X'};
    int i;

    for(i=0;i<n;i++)             
    {
      x[i].key = key[i];      x[i].data = data[i];
    }
}


int BinSearch(record x[],int n,int k)
{
    int left,right,middle;
    left = 0;
    right = n - 1;
    while(left<=right)
    {
         middle = (left + right) / 2;
         if(k==x[middle].key)  return middle;
         if(k>x[middle].key)   left = middle + 1;    /* 放棄左半部 */
         else                  right = middle - 1;   /* 放棄右半部 */
    }
    return -1;
}

int main()
{
    int loc,n=8;
    record x[9];

    SetData(x,8);
    loc = BinSearch(x,8,63); /*搜尋key=63的記錄 */
    if (loc==-1)
      printf("無此筆資料\n");
    else
      printf("x[%d]=%d \t %c\n",loc,x[loc].key,x[loc].data);
      
    system("pause");
    return 0;
}
