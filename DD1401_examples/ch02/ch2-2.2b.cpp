#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{   //宣告
    int A[6]={60,70,80,85,90,100};
    int i,sum=0;
    //處理
    for (i = 0; i<=5;i++ )
       sum+=A[i];
    //輸出
    cout<<"總和為："<<sum;    
    cout<<"\n";  
    system("PAUSE");
    return(0);
}
