/*  Fibonacci Search algorithm  */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
        int key;
        char data;
        /*   其他資料欄位 */
}record;

void SetData(record x[],int n)
{
   int key[] = {13,21,23,26,28,29,32,33,42,47,52,54,63,74,79,86,88,91,92,95};
   int data[] = {'A','F','G','E','J','Q','W','X','B','Y','O','T','S','C','V','N','L','M','H','R'};
   int i;

   for(i=0;i<n;i++)
   {
     x[i+1].key = key[i];      x[i+1].data = data[i];
   }
}

void CreateFib(int Fib[],int n)
{
    int i;
    Fib[0] = 0;
    Fib[1] = 1;
    for(i = 2; i < n; i++)
       Fib[i] = Fib[i-1] + Fib[i-2];
}

int FibSearch(record x[],int n,int k)
{
    int i, root, m;
    int p,q,temp;
    int Fib[21];
    CreateFib(Fib,21);  /* Fib[0]~Fib[20]存放 0,1,1,2,3,5.... */

    for(root=0;Fib[root]<=n;root++)
      ;
    root--;              /* 尋找費氏樹的樹根 */

    i = Fib[root-1];
    p = Fib[root-2];
    q = Fib[root-3];
    m = n + 1 - Fib[root];

    if(x[i].key < k)     /* 調整第一次比較的位置 */
        i = i+ m;

    while(Fib[i] > 0)
    {
       printf("i=%d\t",i);
       if(x[i].key == k) return i;
       if(x[i].key < k)
       {
         printf("x[i].key=%d < %d\n",x[i].key,k);
         if(p==1)
           i = 0;
         else
         {
           i = i + q;
           p = p - q;         q = q - p;
         }
       }
       else
       {
         printf("x[i].key=%d > %d\n",x[i].key,k);
         if(q==0)
           i=0;
         else
         {
           i = i - q;
           temp = p;         p = q;           q = temp - q;
         }
       }
     }
     return -1;
}

int main()
{
    int loc,n=20;
    record x[21];

    SetData(x,21);
    loc = FibSearch(x,20,88); 
    if (loc==-1)
        printf("\n無此筆資料\n");
    else
        printf("\nx[%d]=%d \t %c\n",loc,x[loc].key,x[loc].data);
    system("pause");
    return 0;
}
