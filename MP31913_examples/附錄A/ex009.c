#include<stdio.h>
#include<string.h>
int main(void)
{
	int i;
	char choice;
	/*宣告字串陣列並初始化*/
 	char newspaper[5][20]={{"1.水果日報"},
 							{"2.聯合日報"},
        					{"3.自由報"},
             				{"4.中國日報"},
                 			{"5.不需要"}};
	/*字串陣列的輸出*/
	for(i=0; i<5; i++)
	{
		printf("%s  ",newspaper[i]);
	}
 	printf("請輸入選擇:");
 	choice=getche();
 	printf("\n");
 	choice=choice-'0';
 	/*輸入的判斷*/
 	if(choice>=0 && choice<4)
 	{
  		printf("%s",newspaper[choice-1]);
    	printf("\n謝謝您的訂購!!!\n");
    }	
    else if(choice==5)
  		printf("\n感謝您的參考!!!\n");
  	else
  		printf("輸入錯誤\n");
	system("pause");
	return 0;
}
