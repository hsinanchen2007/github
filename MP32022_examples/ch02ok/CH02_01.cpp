#include <iostream>
using namespace std;

int main()
{
    int Score[5]={ 87,66,90,65,70 };    
    //定義整數陣列 Score[5],並設定5筆成績 
    int count, Total_Score=0;
    for (count=0; count < 5; count++)   //執行 for 迴圈讀取學生成績 
    {
        cout<<"第"<<count+1<<"位學生的分數:"<<Score[count]<<endl;  
        Total_Score+=Score[count];  //由陣列中讀取分數計算總合 
    }
    cout<<"-------------------------"<<endl;
    cout<<"5位學生的總分:"<<Total_Score<<endl;  
    //輸出成績總分 
                
    return 0;
}