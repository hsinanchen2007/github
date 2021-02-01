/*   Heap Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void PrintData(int x[],int i,int n)
{
    int j;
    for(j=i;j<=n;j++)
      printf("%2d  ",x[j]);
    printf("\n");
} 

void AdjustToHeap(int x[],int root,int n)
{
   int temp,parent,child;

   
   temp = x[root];               /* ���X�ڸ`�I��ȩ�Jtemp */
   parent = root;                /* ���`�I���s�� */
   child = 2 * root;               /* ���l�`�I���s�� */
    while(child <= n)
    {
       if ((child < n) && (x[child] < x[child+1]))
         child = child + 1;    /* �k�l�`�I���j,�ҥH���Ӥ�����O�k�l�`�I */ 
       
       if(temp >= x[child])  
          break;              /* �ץ��w�g���� */
       else
       {
          x[parent] = x[child];        /* �P���j���l�`�I���� */
          parent = child;              /* ����U�@�h */
          child = child * 2;
       }
    }
    x[parent] = temp;  /*  �ڸ`�I��ȩ�J���T����m   */
}

void HeapSort(int x[],int i,int n)
{
    int temp;
    for(i=n/2;i>=1;i--)
    {
      AdjustToHeap(x,i,n);    /* */
    }
    printf("�̤j�ְ�:\t");
    PrintData(x,1,10);        
    for(i=n-1;i>=1;i--)
    {
      temp = x[1];
      x[1] = x[i+1];
      x[i+1] = temp;
      AdjustToHeap(x,1,i); 
      printf("i=%d���̤j�ְ�:\t",i);
      PrintData(x,1,i); 
    }
}

int main()
{
    int x[11] = {0,24,17,36,55,63,72,12,65,89,54};

    printf("�Ƨǫe  x[1:10]="); PrintData(x,1,10);
    HeapSort(x,1,10);
    printf("�Ƨǫ�  x[1:10]="); PrintData(x,1,10);
    
    system("pause");
    return 0;
}
