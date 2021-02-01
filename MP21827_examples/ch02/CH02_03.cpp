#include <iostream>

using namespace std;

int main()
{
    char Str_1[40];                     
    char Str_2[40];                    
    char Str_3[80];                                  
    int count, s_record;
    
        cout<<"字串 Str_1 的內容:";
        cin>>Str_1;                                   
        cout<<"字串 Str_2 的內容:";
        cin>>Str_2;                               

        s_record=0;     
	    //把整數變數 s_record 歸 0，用來記錄 Str_3 所指的陣列元素 

    for (count=0; Str_1[count] != '\0'; count++, s_record++)  
	    //將 Str_1 字串複製到 Str_3 
		Str_3[s_record]=Str_1[count];

	for (count=0; Str_2[count] != '\0'; count++, s_record++)  
	    // 將 Str_2 字串複製到 Str_3 
		Str_3[s_record]=Str_2[count];

    Str_3[s_record]='\0';                                     
	//字串最後要加上 NULL 字元 

    cout<<"連結後的字串 Str_3:"<<Str_3<<endl;                   
	//顯示字串連結的結果 
	    
    return 0;                                       
}
