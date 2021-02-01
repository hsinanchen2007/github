#define NUM 5
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
 float Average=0;
    int sum=0,i,Score[NUM]={60,70,80,85,90};  //宣告「陣列」資料結構 
    for (i = 0; i<NUM;i++ )                  //使用FOR迴圈的演算法 
       sum+=Score[i];
    Average=(float)(sum/NUM);
    cout<<"平均成績：\n"<<Average;
    system("PAUSE");	
    return 0;    
}
