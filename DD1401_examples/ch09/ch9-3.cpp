#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{ //�D�{��
   int Temp[]={1,8,15,24,33,45,76,88,99};
   int Key;
   int Low, High, Middle, Searchtime;
   cout<<"�Ƨǫ᪺�ƦC���G1,8,15,24,33,45,76,88,99";
   cout<<"\n"; 
   cout<<"�п�J�H�W�����@�ռƦr�G";
   cin>>Key; 
   Low = 0;                                   //�]�w�Ĥ@�Ӧr��
   High = 9;                                  //�]�w�̫�@�Ӧr��
   Searchtime = 0;                            //�j�M���ƪ�ȳ]�w��
   Middle = (int)((Low + High)/2);            //�j�M������
   do
    {
      Searchtime = Searchtime + 1;
      if (Temp[Middle] == Key)              //�����
        {
          cout<<"�ӼƦr�O�Ʀb��"<<Middle<<"�Ӷ���";      //��ܸ�Ʀ�m
          cout<<"�@�@�j�M"<<Searchtime<<"��";            //��ܷj�M����
         break;                               //���X�j��
        }
      else if(Temp[Middle] < Key) 
        Low = Middle + 1;                     //���ܥ��b��
      else 
        High = Middle - 1;                    //���ܥk�b��
        Middle = (int)((Low + High) / 2);     //���ܤ�����
    }
    while(Low <= High);
    cout<<"\n"; 
    system("PAUSE");
    return(0);
}
