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
  cout<<"100�b�}�C������"<<obj.sequential_search(list, 8, 100)<<"��.\n";
  system("PAUSE");
  return(0);
}

int fun:: sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
    if (list[i] == key)		//���}�C������ƬO�_������j�M������
      return i+1;			//�Y���ŦX���󪺸�ơA�N�Ǧ^�����
    return(-1);		    	//�Y�䤣��ŦX���󪺸�ơA�N�Ǧ^ -1
}
