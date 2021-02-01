#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int InfixToPostfix(char []);  // �ŧi��������
  int Priority(char);   // �ŧi�M�w�B��l�u������   
};

int main(int argc, char *argv[])
{
   fun obj;
   char itemset[20];
   cout<<"===============�{���y�z================\n";
   cout<<"= �{���W�١Gch3-3.4.cpp               =\n";
   cout<<"= �{���ت��G��������                =\n"; 
   cout<<"=======================================\n"; 
   cout<<"=================��J==================\n";
   cout<<"�п�J���ǹB�⦡�G";     
   scanf("%s", itemset);     
   cout<<"=================��X==================\n"; 
   obj.InfixToPostfix(itemset);     
   return 0; 
}

//�������Ǥ��Ƶ{�� 
int fun::InfixToPostfix(char Infix[]) 
{   
   int i = 0, Top = 0;
   char Stack[20] = {'0'};     
   char op; 
   cout<<"��X��Ǧ����G�G";    
   while(1) 
   {        
     op = Infix[i];         
     switch(op) 
     {             
         case '\0':                 
              while(Top > 0) 
              {                     
                 cout<<Stack[Top];                     
                 Top--;                 
              }                 
              cout<<"\n";   
              system("pause");     //�ϵ{���Ȱ��b����e�����ڭ̬ݨ쵲�G              
              return 0;             
         // �B��l���|             
         case '(':                 
              if(Top < (sizeof(Stack) / sizeof(char)))
               {                     
                 Top++;                     
                 Stack[Top] = op;                
               }                
               break;             
         case '+': case '-': case '*': case '/':
               while(Priority(Stack[Top]) >= Priority(op)) 
               {                    
                  cout<<Stack[Top];                   
                  Top--;             
               }              
           // �s�J���|                 
            if(Top < (sizeof(Stack) / sizeof(char))) 
            {                   
             Top++;                    
             Stack[Top] = op;           
            }                
            break;            
            // �J ) ��X�� (     
          case ')':                 
               while(Stack[Top] != '(') 
               {                
                 cout<<Stack[Top];                    
                 Top--;               
               }                 
               Top--;  // ����X(                 
               break;             
               // �B�⤸������X            
          default:                
               cout<<op;   
               break;     
         }       
         i++;    
    }
} 

//�M�w�B��l�u�����Ǥ��Ƶ{��
int fun:: Priority(char op)         
{     
   int p;   
   switch(op) 
   {        
      case '+': case '-':            
            p = 1;             
            break;         
      case '*': case '/':             
           p = 2;             
           break;         
      default:             
           p = 0;             
           break;   
   }    
        return p;
}

