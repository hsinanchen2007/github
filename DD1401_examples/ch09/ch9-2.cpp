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
{
    fun obj;
  int list[] = {90, 80, 40, 50, 65, 100, 10, 20};    
  cout<<"100在陣列中的第"<<obj.sequential_search(list, 8, 100)<<"筆.\n";
  system("PAUSE");
  return(0);
}

int fun:: sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
    if (list[i] == key)		//比對陣列內的資料是否等於欲搜尋的條件
      return i+1;			//若找到符合條件的資料，就傳回其索引
    return(-1);		    	//若找不到符合條件的資料，就傳回 -1
}
