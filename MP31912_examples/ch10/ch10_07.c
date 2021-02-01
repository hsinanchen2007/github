/*  OBST with Knuth's Optimization algorithm  */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void SetData(int p[],int q[],int n)
{
    int success[] = {0,2,2,1,2};
    int fail[] = {3,1,2,1,1};
    int i;

    for(i=0;i<n;i++)
    {
      p[i] = success[i];  
      q[i] = fail[i];
    }
}

PrintData(int w[][MAX],int c[][MAX],int r[][MAX],int n)
{
    int i,j,x;
    for(x=0;x<n;x++)
    {
     for(i=0;i<n-x;i++)
     {
       j = i + x;     printf(" W%d%d=%d\t| ",i,j,w[i][j]);
     }
     printf("\n");
     for(i=0;i<n-x;i++)
     {
       j = i + x;     printf(" C%d%d=%d\t| ",i,j,c[i][j]);
     }
     printf("\n");
     for(i=0;i<n-x;i++)
     {
       j = i + x;     printf(" R%d%d=a%d\t| ",i,j,r[i][j]);
     }
     printf("\n--------------------------------------");
     printf("------------------------------------\n");
    }
}

int find_min(int c[][MAX],int i,int j)
{
   int min,m=0,k=0;
   min = c[i][i+1] + c[i+1][j];
   for(m=i+1;m<=j;m++)
   {
      if(min >= c[i][m-1]+c[m][j])
      {
        min = c[i][m-1] + c[m][j];
        k = m;
      }
   }
   return k;
}

void OBST(int p[],int q[],int n,int w[][MAX],int c[][MAX],int r[][MAX])
{
    int i,j,k,x;
    for(i=0;i<n;i++)
    {
      w[i][i] = q[i];
      c[i][i] = 0;
      r[i][i] = 0;
    }
    for(i=0;i<n-1;i++)
    {
      w[i][i+1] = q[i] + q[i+1] + p[i+1];
      c[i][i+1] = w[i][i+1];
      r[i][i+1] = i + 1;
    }
    for(x=2;x<n;x++)
    {
      for(i=0;i<n-x;i++)
      {
        j = i + x;
        w[i][j] = w[i][j-1] + p[j] + q[j];
        k = find_min(c,i,j);
        c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
        r[i][j] = k;
      }
    }
}

int main()
{
    int p[MAX],q[MAX],c[MAX][MAX],r[MAX][MAX],w[MAX][MAX];

    SetData(p,q,MAX);
    OBST(p,q,MAX,w,c,r);
    PrintData(w,c,r,MAX);
    system("pause");
    return 0;
}
