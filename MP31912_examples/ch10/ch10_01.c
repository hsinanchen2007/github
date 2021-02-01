/*   Sequential Search algorithm    */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
      int key;
      char data;
     /*   其他資料欄位 */
}record;

void SetData(record x[],int n)
{
    int key[8] = {7,9,4,8,11,3,2,4};
    int data[8] = {'A','F','G','E','J','Q','W','X'};
    int i;

    for(i=0;i<n;i++)             
    {
      x[i].key = key[i];      x[i].data = data[i];
    }
}

int SeqSearch(record x[],int n,int k)
{
    int index;
    x[n].key = k;
    for(index=0;x[index].key!=k;index++)
                 ;
    return ((index<n) ? index : -1); 

}

int main()
{
   int loc,n=8;
   record x[9];

   SetData(x,8);
   loc = SeqSearch(x,8,3); /*搜尋key=3的記錄 */
   if (loc==-1)
      printf("無此筆資料\n");
    else
      printf("x[%d]=%d \t %c\n",loc,x[loc].key,x[loc].data);
    system("pause");
    return 0;
}
