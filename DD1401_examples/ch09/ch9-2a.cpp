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
{ //�D�{��
  fun obj;
  int list[10];
  int i,n,c,key;
  cout<<"����10�ӶüƭȡG";
  for (i = 1; i <= 10; i++)
    {
       list[i] = rand() % 90+10;  //����10~100����ƶüƭ�
       cout<<list[i]<<"   ";
    }
  cout<<"\n";
  cout<<"===========�`�Ƿj�M���G==========\n";
  cout<<"28�b�}�C������"<<obj.sequential_search(list, 10, 28)<<"��.\n";
  system("PAUSE");
  return(0);

}    

int fun:: sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 1; i <= n; i++)
    if (list[i] == key)	/* ���}�C������ƬO�_������j�M������ */
      return i;			/* �Y���ŦX���󪺸�ơA�N�Ǧ^����� */
    return(-1);		     /* �Y�䤣��ŦX���󪺸�ơA�N�Ǧ^ -1 */
}
