#include <iostream>
#include <cstdlib>
using namespace std;

// 設定類別樣版的型態參數Type的預設值為整數int,非型態參數的型別為整數int,預設值為5
template <class Type = int, int size = 5>	// 類別樣版宣告
class Stack
{
      private:
        Type st[size];// 宣告一陣列作為堆疊的儲存空間
        int top;		// 堆疊資料頂端的索引
      public:
        Stack()
         {
          top = -1;
          }
       void push(Type data);	// 將資料放入堆疊
       Type pop();// 將資料由堆疊中取出
   };
   template < class Type, int size >
   void Stack< Type, size > :: push ( Type data )
   {
    st[ ++top ] = data;
  	}
   template < class Type, int size >
   Type Stack<Type, size> :: pop()
   {
        return st[ top-- ];
    }
int main()
{
    Stack<> stk_1;// 宣告一堆疊物件,並使用其預設值
    Stack<char*, 4> stk_2;	// 宣告堆疊物件,其型態為字串,大小為4
    stk_1.push( 11 );
    stk_1.push( 22 );
    stk_1.push( 33 );
    cout << "stack_1 [1] = " << stk_1.pop() << endl;
    cout << "stack_1 [2] = " << stk_1.pop() << endl;
    cout << "stack_1 [3] = " << stk_1.pop() << endl;
    cout << endl;
    stk_2.push( "第一名" );
    stk_2.push( "第二名" );
    stk_2.push( "第三名" );
    cout << "stack_2 [1] = " << stk_2.pop() << endl;
    cout << "stack_2 [2] = " << stk_2.pop() << endl;  
    cout << "stack_2 [3] = " << stk_2.pop() << endl;
    cout << endl;
    
    return 0;	
}
