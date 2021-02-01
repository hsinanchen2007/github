//計算10! 的值
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int i,sum=1;
    for (i=1;i<=10;i++)  //定義for迴圈
    {
        sum*=i;   //sum=sum+*i
    } 
    cout<<i-1<<"!="<<sum<<endl;  //印出i和sum的值 
    return 0;
}
