#include <cstdlib>
#include <iostream>
#define n 10
int A[n]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //�ŧi����10�ӶüƭȪ��Ƶ{��
    void QuickSort(int A[], int left, int right,int index);       //�ŧi�ֳt�ƧǪk���Ƶ{��
};
int main(int argc, char *argv[])
{ 
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch8-5a.cpp                =\n";
    cout<<"= �{���ت��G�l�ܡu�ֳt�ƧǪk�v���L�{  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";
    fun obj;
    obj.RandomNum();           //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n"; 
    cout<<"=================��X==================\n";  
    obj.QuickSort(A, 0, n-1, n);     //�I�s�ֳt�Ƨǫ᪺���G���Ƶ{��
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}

void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL)); //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG\n";
  for (i = 0; i <= n-1; i++)
    {
       A[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<A[i]<<"  ";
    }
}

void fun::QuickSort(int A[], int left, int right,int index)
{ 
   int lower,upper,t,k,key,temp,done;
   lower=left; 
   upper=right+1;                      
   t=1;
   key=A[left];                      
   if  ( lower < upper )
   { do
      {
	   do                              
        { lower ++;
	    } while (A[lower] <= key && lower <= right);
	   do                                
        { upper--;
	    } while (A[upper] >= key && upper > left);

	   if ( lower < upper )		     
	   {
	       temp=A[lower];
	       A[lower]=A[upper];
	       A[upper]=temp;
	    }
     }while ( lower < upper );
   if ( lower > upper)
       printf("\n"); 
       {
        temp=A[left];          
	    A[left]=A[upper];
	    A[upper]=temp;
        for (k=0;k<index;k++)
          printf("%d ",A[k]);
       }
        QuickSort(A, left, upper-1,index);   // �索��i�滼�j 
        QuickSort(A, upper+1, right,index);  // ��k��i�滼�j 
    } 
}
