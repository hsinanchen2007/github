#include <cstdlib>
#include <iostream>
#define Num 10
int data[10] = {79, 8, 6, 93, 59, 84, 55, 9, 71, 33}; 
int temp[10][10] = {0}; 
int order[10] = {0}; 
int i, j, k, n, lsd; 
using namespace std;
class fun
{
  public:
    void ShowData ();                    //�ŧi����10�ӶüƭȪ��Ƶ{��
    void Radix(int data[],int n);        //�ŧi��ƱƧǪk���Ƶ{��
};
int main(int argc, char *argv[])
{ //�D�{��
    k = 0; 
    n = 1; 
    cout<<"===============�{���y�z================\n";
    cout<<"= �{���W�١Gch8-9.cpp                 =\n";
    cout<<"= �{���ت��G�l�ܡu��ƱƧǪk�v���L�{  =\n"; 
    cout<<"=======================================\n"; 
    cout<<"=================��J==================\n";     
    fun obj;
  obj.ShowData();                    //�I�s��ܭ�l���
  cout<<"\n=================��X==================\n";  
  obj.Radix(data,n);                 //�I�s��ƱƧǪk���Ƶ{��
  cout<<"\n";
  system("PAUSE");
  return(0);
}

void fun::ShowData ()  //��ܭ�l���
{
    int i;
    cout<<"�Ƨǫe: "; 
    for(i = 0; i < 10; i++) 
        cout<<data[i]<<" "; 
}
//��ƱƧǪk���Ƶ{��
void fun::Radix(int data[],int n)  
{   int t=1;
    while(n <= 10)
     { 
        for(i = 0; i < 10; i++) 
        { 
            lsd = ((data[i] / n) % 10); 
            temp[lsd][order[lsd]] = data[i]; 
            order[lsd]++; 
        } 
        if (t==1) 
           cout<<"\n�u�Ӧ�ơv���D�ƧǡG"; 
        else 
           cout<<"\n�u�Q��ơv���D�ƧǡG"; 
        for(i = 0; i < 10; i++)
         { 
            if(order[i] != 0) 
                for(j = 0; j < order[i]; j++) 
                { 
                    data[k] = temp[i][j]; 
                    cout<<data[k]<<" ";
                    k++; 
                } 
            order[i] = 0; 
        } 
        n *= 10; 
        k = 0; 
        t+=1;
    } 
  }
