#include <cstdlib>
#include <iostream>
#define MaxNum 10      //�w�q���|�j�p
int Stack[MaxNum];    //�H�}�CStack��@���|
int Top = -1;        //Top�����ثe���|���ݪ����ޭȡA��l�ȳ]��-1��ܰ��|����

using namespace std;
class fun
{
  public:
  void Push(int);         //�ŧiPush�Ƶ{��
  int Pop(void);          //�ŧiPop�Ƶ{��
  int Transfer(char*);    //�ŧi��ǹB�⦡���Ƶ{�� 
};

int main(int argc, char *argv[])
{
  fun obj;
  char itemset[20];
  cout<<"===============�{���y�z================\n";
  cout<<"= �{���W�١Gch3-3.6.cpp               =\n";
  cout<<"= �{���ت��G��ǹB��                  =\n"; 
  cout<<"=======================================\n"; 
  cout<<"=================��J==================\n"; 

  while(1) {
    cout<<"�п�J�@�ӫ�Ǧ�:";
    gets(itemset);
    cout<<itemset<<"="<<obj.Transfer(itemset);
    cout<<"\n";
  }
  system("pause");     //�ϵ{���Ȱ��b����e�����ڭ̬ݨ쵲�G
  return 0;
}

int fun:: Transfer(char itemset[])  //��ǹB�⦡���Ƶ{��
{
  cout<<"=================��X==================\n";    
  cout<<"�B�⵲�G�G";   

    fun obj;
  char *pt=itemset;
  while(*pt) {
    if(*pt >= '0' && *pt <= '9')
      Push(*pt-'0');
    else {
      switch(*pt) {
        case '+': obj.Push(Pop( ) + obj.Pop( ));
                  break; 
        case '-': obj.Push(Pop( ) - obj.Pop( ));
                  break;
        case '*': obj.Push(Pop( ) * obj.Pop( ));
                  break;
        case '/': obj.Push(Pop( ) / obj.Pop( ));
                  break;
        default: return -1;
      }
    }
    pt++;  
  }  
  return obj.Pop( );
}

void fun:: Push(int n)    //Push�Ƶ{��
{
  if(Top == MaxNum -1) {
    cout<<"���|�w���I";
    return;
  }
  Stack[++Top] = n;
}

int fun:: Pop(void)       //Pop�Ƶ{�� 
{
  if(Top == -1) {
    cout<<"���|�O�šI";
   }
  return Stack[Top--];
}
