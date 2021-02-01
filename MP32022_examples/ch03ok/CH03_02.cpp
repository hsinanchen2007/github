#include <iostream>        
#include <cstdlib> 

using namespace std;

int main(){
    int no,count=0, Total=0;   // 定義整數變數 count 與 Total
    cout<<"要輸入計算的個數為:";
    cin>>no; 
    int *ptr=new int[no]; // 動態配置陣列為n個元素 
    cout<<endl;	
    for (count=0; count < no; count++)	 
    {	 
		cout << "輸入ptr[" << count << "]:";
   	 	cin >> ptr[count];            // 採用陣列索引來輸入陣列元素
    }
    for (count=0; count < no; count++)
      	Total+=*(ptr+count);       // 採用指標變數運算來存取陣列元素值
    cout<<"---------------------------------------"<<endl;
    cout << no<<"個數的總和=" << Total;    // 顯示結果
    cout << endl; 
    delete [] ptr;                // 釋放配置給 ptr 的記憶體空間	    
    ptr=NULL;	     
        
 	return 0; 
}
