#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  int C_Score, E_Score, Average;
  C_Score=60;
  E_Score=70;
  Average = (C_Score + E_Score) / 2;
  if (Average >= 60)
     cout<<"�ή�";
  else
     cout<<"���ή�";
  system("PAUSE");	
  return 0;
}
