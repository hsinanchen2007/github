#include <cstdlib>
#include <iostream>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 
int A[10]={0};
using namespace std;
class fun
{
  public:
    void RandomNum();                //�ŧi����10�ӶüƭȪ��Ƶ{��
    void Shellsort(int A[]);        //�ŧi�¦ձƧǪk���Ƶ{��
};
int main(int argc, char *argv[])
{ 
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch8-7.cpp                 =\n";
    cout<<"= �{���ت��G�l�ܡu�¦ձƧǪk�v���L�{  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";    
    fun obj;
    obj.RandomNum();                //�I�s����10�ӶüƭȪ��Ƶ{��
    cout<<"\n"; 
    obj.Shellsort(A);               //�I�s�¦ձƧǪk���Ƶ{��
    cout<<"\n";
    system("PAUSE");
    return(0);
} 
void fun::RandomNum()  //����10�ӶüƭȤ��Ƶ{��
{
  int i;
  srand((unsigned)time(NULL));   //�üƭȪ�l��
  cout<<"����10�ӶüƭȡG\n";
  for (i = 0; i < MAX; i++)
    {
       A[i] = rand() % 90+10;    //����10~100����ƶüƭ�
       cout<<A[i]<<"  ";
    }
}
 //�¦ձƧǪk���Ƶ{��
void fun::Shellsort(int A[]) 
{ 
    int i, j, k, Gap, t; 
    Gap = MAX / 2; 
    while(Gap > 0)
     { 
        for(k = 0; k < Gap; k++) 
        { 
            for(i = k+Gap; i < MAX; i+=Gap) 
            { 
                for(j = i - Gap; j >= k; j-=Gap) 
                { 
                    if(A[j] > A[j+Gap]) 
                    { 
                        SWAP(A[j], A[j+Gap]); 
                    } 
                    else 
                        break; 
                } 
            } 
        } 
        cout<<"\nGap ="<<Gap<<"�G"; 
        for(i = 0; i < MAX; i++) 
            cout<<A[i]<<"  ";
        Gap /= 2; 
    } 
}
