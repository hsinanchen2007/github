#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{   //�ŧi
    int A[6]={60,70,80,85,90,100};
    int i,sum=0;
    //�B�z
    for (i = 0; i<=5;i++ )
       sum+=A[i];
    //��X
    cout<<"�`�M���G"<<sum;    
    cout<<"\n";  
    system("PAUSE");
    return(0);
}
