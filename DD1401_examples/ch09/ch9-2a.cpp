#include <cstdlib>
#include <iostream>
#define NUM 5
using namespace std;
class fun
{
  public:
  int sequential_search(int list[], int n, int key);  
};
int main(int argc, char *argv[])
{ //主程式
  fun obj;
  int list[10];
  int i,n,c,key;
  cout<<"產生10個亂數值：";
  for (i = 1; i <= 10; i++)
    {
       list[i] = rand() % 90+10;  //產生10~100的整數亂數值
       cout<<list[i]<<"   ";
    }
  cout<<"\n";
  cout<<"===========循序搜尋結果==========\n";
  cout<<"28在陣列中的第"<<obj.sequential_search(list, 10, 28)<<"筆.\n";
  system("PAUSE");
  return(0);

}    

int fun:: sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 1; i <= n; i++)
    if (list[i] == key)	/* 比對陣列內的資料是否等於欲搜尋的條件 */
      return i;			/* 若找到符合條件的資料，就傳回其索引 */
    return(-1);		     /* 若找不到符合條件的資料，就傳回 -1 */
}
