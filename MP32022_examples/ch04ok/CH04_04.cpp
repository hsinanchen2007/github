#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>	 // 定義鏈結串列中的節點
struct Node
{
  Type data;	// 紀錄資料
  Node* next;// 紀錄下一筆節點的位址
};
template <class Type>
class LinkedList	// 鏈結串列類別
{
  private:
   Node<Type>* first;	    // 指到第一個節點的指標
   public:
     LinkedList()			    // 建構子
     {
       first = NULL;
     }
   void addNode(Type data);	// 加入節點
   void display();			    // 顯示所有的節點23	
};
   template<class Type>
   void LinkedList<Type>::addNode(Type data)
   {
    Node<Type>* newNode = new Node<Type>;	// 新增一個節點
    newNode->data = data;			// 紀錄資料
    newNode->next = first;		// 指到前一個節點
    first = newNode;			// 指到新的節點
   }
   template<class Type>
   void LinkedList<Type>::display()
   {
     Node<Type>* currentNode = first;    // 由第一個節點開始顯示
     while( currentNode != NULL )
     {
     cout << currentNode->data << " -> ";
	 currentNode = currentNode->next;
     }
  }

int main()
{
    LinkedList<double> dblList;	    // 建立一個儲存double型態資料的鏈結串列
    double num;					// 紀錄輸入的資料
    char ch;						// 紀錄使用者的選擇
    	do{
           cout << endl <<"請輸入一個數字 : ";
           cin >> num;
           dblList.addNode( num );
           cout << "繼續輸入(y / n)?";
           cin >> ch;
         }while( ch != 'n' );
      cout << endl;
      dblList.display();				// 顯示所有的資料
      cout << endl << endl;
      
      return 0;
}
