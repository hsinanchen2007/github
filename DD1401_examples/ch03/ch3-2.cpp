#include <cstdlib>
#include <iostream>
#define MaxNum 5     //�w�q���|�j�p
int Stack[MaxNum];   //�H�}�CStack��@���|
int Top = -1;   //Top�����ثe���|���ݪ����ޭȡA��l�ȳ]��-1��ܰ��|����

using namespace std;
class fun
{
  public:
  int number;
  void get_input();
  void Push(int);  //�ŧiPush�Ƶ{�� 
  int Pop(void);   //�ŧiPop�Ƶ{�� 
  void PrintStack(void);  //�ŧi�C�L�ثe���|�����e���Ƶ{��   
};

int main(int argc, char *argv[])
{
  int op=0,item;
  fun obj;
  cout<<"===============�{���y�z=======================\n";
  cout<<"= �{���W�١Gch3-2.cpp                        =\n";
  cout<<"= �{���ت��G�ϥΰ��|�i��push�H��pop          =\n"; 
  cout<<"==============================================\n"; 

  while(1)
  {
   obj.get_input();
   op=obj.number;
   switch(op)
    {
      case 1: cout<<"�п�J�A�npush����ơG";
              cin>>item;
              obj.Push(item); //�I�sPush�Ƶ{�� 
              break;
      case 2: cout<<obj.Pop( )<<"�O�q���|�u�X�����\n"; //�I�sPop�Ƶ{�� 
              break;
      case 3: obj.PrintStack( );  //��ܥثeStack�����e 
              break;
    }
  }
  system("pause");     //�ϵ{���Ȱ��b����e�����ڭ̬ݨ쵲�G
  return 0;
}

void fun::get_input()
{
    cout<<"=================================================\n";
    cout<<"=   1.push(�[�J)                                =\n";
    cout<<"=   2.pop(���X)                                 =\n";
    cout<<"=   3.��ܥثeStack�����e(�q�ѤW�ӤUTop-Down)   =\n";
    cout<<"=   4.����                                      =\n";    
    cout<<"=================================================\n";
    cout<<"�п�J�A���ާ@�G";
    cin>>number;    
}

void fun:: Push(int item)  //Push�Ƶ{�� 
{
  if(Top == MaxNum -1)
    cout<<"���|�O����!";
  else
    Stack[++Top] = item;
}

int fun:: Pop(void)         //Pop�Ƶ{�� 
{
  if(Top == -1) 
    cout<<"���|�O�Ū�!";
  else
    return Stack[Top--];
}
void fun:: PrintStack(void)  //�C�L�ثe���|�����e
{
  int i;
  if(Top == -1) {
    cout<<"���|�O�Ū�!\n";
  } else {
    cout<<"�ثe���|�����e��: ";
    for(i=Top;i>=0;i--)
      cout<<"  "<<Stack[i];
    cout<<"\n";
  }
}
