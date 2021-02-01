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



void ShiftTo(int x[],int Dest,int Src)  /* ShiftTo : ���Xx[Dest]~x[Src]�̤p����̫e,��l�V�Ჾ�@�� */
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

    i = left;             /* i�O�n�X�֪��Ĥ@�Ӥl��C�}�Y��m */
    
    j = middle + 1;         /* j�O�n�X�֪��ĤG�Ӥl��C�}�Y��m */
    
    while((j!=right+1)&&(i!=j))
    {
     if(x[j]<=x[i])
     {
         ShiftTo(x,i,j);    /* x[i],x[i+1]..x[j-1],x[j] -> x[j],x[i],x[i+1],...x[j-1] */
         
         /* x[i]~x[j]���Ĥ@�Ӥw�w��,�~��B�zx[i+1]~x[j+1]���w�� */
         i++;
         j++;
     }
     else
         i++;   /* x[i]~x[j]���Ĥ@�Ӥw�w��,�~��B�zx[i+1]~x[j]���w�� */
   }
}
 
void MergeR(int x[], int left, int middle, int right)
{
    if(left == right)
       return;
    else
    {
       MergeR(x,left,(left+middle)/2,middle);          /* �e�b���X�� */
       MergeR(x,middle+1,(middle+1+right)/2,right);    /* ��b���X�� */
    }
    SortingX(x,left,middle,right);  /* �Nx[left]~x[right]�Ƨ� */
}
 
int main(void)
{
    int x[10]={0};

    SetData(x,0,9);
    printf("�Ƨǫe x[]="); PrintData(x,0,9);
    MergeR(x,0,10/2,9);
    printf("�Ƨǫ� x[]="); PrintData(x,0,9);

    system("pause");
    return 0;
}
