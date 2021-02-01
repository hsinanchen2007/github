#include <cstdlib>
#include <iostream>
#define MAX 10
int A[10]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //�ŧi����10�ӶüƭȪ��Ƶ{��
    void Createheap(int A[],int root, int index);        //�ŧi�إ߰�n�𪺰Ƶ{��
    void Heapsort(int A[], int index);         //�ŧi��n�Ƨǫ᪺���G���Ƶ{��
};
int main(int argc, char *argv[])
 { 
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch8-6.cpp                 =\n";
    cout<<"= �{���ت��G�l�ܡu��n�ƧǪk�v���L�{  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";            
    fun obj;
    int number[MAX+1] = {-1}; 
    int i, num;  
    obj.RandomNum();                //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n=================��X==================\n";  
    cout<<"�إ߰�n��G\n"; 
    obj.Heapsort(A,MAX);              //�I�s��n�ƧǪk���Ƶ{��
    cout<<"\n";
    system("PAUSE");
    return(0);
} 

void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL)); //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG\n";
  for (i = 1; i <= MAX; i++)
    {
      A[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<A[i]<<"  ";
    }
}

//�إ߰�n�𪺰Ƶ{��
void fun::Createheap(int A[],int root, int index) { 
 int i, j , temp;
     int finish;              
     j=2*root;                
     temp=A[root];            
     finish=0;                
     while ( j<= index  &&  finish==0 )
     {
     //��̤j��
	 if ( j < index )
	       if ( A[j] < A[j+1] )
              j++;
	 if ( temp >= A[j] )
	     finish=1;         
        else
        {
	     A[j/2]=A[j];      
         j=2*j;
        }
     }
     A[j/2]=temp;        
} 

//�I�s��n�ƧǪk���Ƶ{��
void fun::Heapsort(int A[], int index) { 
    int i, j,t, temp;
    t=1;
    //�N����G�����ন��n�� 
    for ( i= (index/2); i >= 1; i--)
       Createheap(A, i , index);
    for(i = 1; i <= 10; i++) 
       printf("%4d",A[i]);
    //�ְ�Ƨ�
    cout<<"\n\n��n�ƧǪk�G"; 
    for  ( i = index-1; i >= 1; i--)
    {
	 temp=A[i+1];          
     A[i+1]=A[1];
     A[1]=temp;
	 Createheap(A,1,i);    
     printf("\n�� %d ���ƧǡG", t++);
     for ( j=1; j <= index; j++)
	       printf("%d ", A[j] );
   }
}
