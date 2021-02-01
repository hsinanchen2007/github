#include <cstdlib>
#include <iostream>
#define MAX1 10 
#define MAX2 10 
int A[10]={0};
int B[10]={0};
int C[20]={0};
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 
using namespace std;
class fun
{
  public:
    void RandomNum();                //�ŧi����10�ӶüƭȪ��Ƶ{��
    void Quicksort(int A[],int a,int b);        //�ŧi�ֳt�ƧǪk���Ƶ{��
    void PrintQuicksort(int A[],int B[]);        //�C�L�X�Ĥ@�P�G�ո�ƱƧǵ��G
    void Mergesort(int A[],int MAX_1,int B[],int MAX_2,int C[]); //�i��X�ֱƧ� 
    void PrintMergesort(int C[]);          //��ܦX�ֱƧǤ����G
};
int main(int argc, char *argv[]) 
{ 
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch8-8.cpp                 =\n";
    cout<<"= �{���ت��G�l�ܡu�X�ֱƧǪk�v���L�{  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";     
    fun obj;
    obj.RandomNum();                //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n";  
    obj.Quicksort(A, 0, MAX1-1);    //�Ĥ@�ո�ƱƧ� 
    obj.Quicksort(B, 0, MAX2-1);    //�ĤG�ո�ƱƧ�
    cout<<"\n=================��X==================\n";  
    obj.PrintQuicksort(A,B);        //�C�L�X�Ĥ@�P�G�ո�ƱƧǵ��G 
    cout<<"\n"; 
    obj.Mergesort(A,MAX1,B,MAX2,C); //�i��X�ֱƧ� 
    cout<<"\n";  
    obj.PrintMergesort(C);          //��ܦX�ֱƧǤ����G 
    cout<<"\n"; 
    system("PAUSE");
    return(0);
} 
void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL));   //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG\n"; 
  cout<<"�Ĥ@�ո�ơG";
  for (i = 0; i < MAX1; i++)
    {
       A[i] = rand() % 40+10;    //����10~50����ƶüƭ�
       cout<<A[i]<<"  ";
    }
  printf("\n"); 
   printf("�ĤG�ո�ơG");
  for (i = 0; i < MAX2; i++)
    {
       B[i] = rand() % 50+51;    //����51~100����ƶüƭ�
       cout<<B[i]<<"  ";
    }   
}

void fun::Quicksort(int A[], int left, int right)
 { 
    int q; 
    if(left < right) 
    { 
    int i, j, s; 
    s = A[right]; 
    i = left - 1; 
    for(j = left; j < right; j++) { 
        if(A[j] <= s) { 
            i++; 
            SWAP(A[i], A[j]); 
        } 
    } 
    SWAP(A[i+1], A[right]); 
    q = i+1; 
    
        Quicksort(A, left, q-1); 
        Quicksort(A, q+1, right); 
    } 
} 


//�ֳt�ƧǪk���Ƶ{�� 
void fun::PrintQuicksort(int A[], int B[])  
 {
    int i;
    cout<<"\n�Ƨǫ�G"; 
    cout<<"\n�Ĥ@�ո�ơG"; 
    for(i = 0; i < MAX1; i++) 
        cout<<A[i]<<"  ";
    cout<<"\n�ĤG�ո�ơG"; 
    for(i = 0; i < MAX2; i++) 
        cout<<B[i]<<"  ";
}
//�i��X�ֱƧ�
void fun::Mergesort(int A[], int M, int B[],int N, int C[])
 { 
    int i = 0, j = 0, k = 0; 
    while(i < M && j < N) 
    { 
        if(A[i] <= B[j]) 
            C[k++] = A[i++]; 
        else 
            C[k++] = B[j++]; 
    } 
    while(i < M) 
        C[k++] = A[i++]; 
    while(j < N) 
        C[k++] = B[j++]; 
}
//��ܦX�ֱƧǤ����G
void fun::PrintMergesort(int C[])  //�X�֫ᤧ�Ƶ{�� 
 {
    int i;
    cout<<"�X�֫�G\n"; 
    for(i = 0; i < MAX1+MAX2; i++) 
        cout<<C[i]<<" "; 
}
