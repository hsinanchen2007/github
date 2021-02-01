#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{ //主程式
   int Temp[]={1,8,15,24,33,45,76,88,99};
   int Key;
   int Low, High, Middle, Searchtime;
   cout<<"排序後的數列為：1,8,15,24,33,45,76,88,99";
   cout<<"\n"; 
   cout<<"請輸入以上的任一組數字：";
   cin>>Key; 
   Low = 0;                                   //設定第一個字母
   High = 9;                                  //設定最後一個字母
   Searchtime = 0;                            //搜尋次數初值設定為
   Middle = (int)((Low + High)/2);            //搜尋中間值
   do
    {
      Searchtime = Searchtime + 1;
      if (Temp[Middle] == Key)              //找到資料
        {
          cout<<"該數字是排在第"<<Middle<<"個順位";      //顯示資料位置
          cout<<"一共搜尋"<<Searchtime<<"次";            //顯示搜尋次數
         break;                               //跳出迴圈
        }
      else if(Temp[Middle] < Key) 
        Low = Middle + 1;                     //改變左半部
      else 
        High = Middle - 1;                    //改變右半部
        Middle = (int)((Low + High) / 2);     //改變中間值
    }
    while(Low <= High);
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}
