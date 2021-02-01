#include <cstdlib>
#include <iostream>
using namespace std;
class fun
{
  public:
  int InfixToPostfix(char []);  // 宣告中序轉後序
  int Priority(char);   // 宣告決定運算子優先順序   
};

int main(int argc, char *argv[])
{
   fun obj;
   char itemset[20];
   cout<<"===============程式描述================\n";
   cout<<"= 程式名稱：ch3-3.4.cpp               =\n";
   cout<<"= 程式目的：中序轉後序                =\n"; 
   cout<<"=======================================\n"; 
   cout<<"=================輸入==================\n";
   cout<<"請輸入中序運算式：";     
   scanf("%s", itemset);     
   cout<<"=================輸出==================\n"; 
   obj.InfixToPostfix(itemset);     
   return 0; 
}

//中序轉後序之副程式 
int fun::InfixToPostfix(char Infix[]) 
{   
   int i = 0, Top = 0;
   char Stack[20] = {'0'};     
   char op; 
   cout<<"輸出後序式結果：";    
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
              system("pause");     //使程式暫停在執行畫面讓我們看到結果              
              return 0;             
         // 運算子堆疊             
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
           // 存入堆疊                 
            if(Top < (sizeof(Stack) / sizeof(char))) 
            {                   
             Top++;                    
             Stack[Top] = op;           
            }                
            break;            
            // 遇 ) 輸出至 (     
          case ')':                 
               while(Stack[Top] != '(') 
               {                
                 cout<<Stack[Top];                    
                 Top--;               
               }                 
               Top--;  // 不輸出(                 
               break;             
               // 運算元直接輸出            
          default:                
               cout<<op;   
               break;     
         }       
         i++;    
    }
} 

//決定運算子優先順序之副程式
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

