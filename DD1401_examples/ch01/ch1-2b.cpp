#define NUM 5
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
 float Average=0;
    int sum=0,i,Score[NUM]={60,70,80,85,90};  //�ŧi�u�}�C�v��Ƶ��c 
    for (i = 0; i<NUM;i++ )                  //�ϥ�FOR�j�骺�t��k 
       sum+=Score[i];
    Average=(float)(sum/NUM);
    cout<<"�������Z�G\n"<<Average;
    system("PAUSE");	
    return 0;    
}
