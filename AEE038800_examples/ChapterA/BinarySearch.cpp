/* File name: binarySearch.cpp */
/* August, 2017 */
#include <iostream>
using namespace std;

class BinarySearch {
private:
    int A[10]= {2,4,6,8,10,12,14,16,18,20};
    int count=0;
public:
    int binarySearch(int);
};

int main()
{
    BinarySearch obj;
	   cout << "Search 1 , " << obj.binarySearch(1) << " times\n";
	   cout << "Search 3 , " << obj.binarySearch(3) << " times\n";
	   cout << "Search 13 , " << obj.binarySearch(13) << " times\n";
	   cout << "Search 21 , " << obj.binarySearch(21) << " times\n";
	   cout << "Total " << obj.binarySearch(1)+obj.binarySearch(3)+obj.binarySearch(13)+obj.binarySearch(21) << " times";
	   cout << "\n";
	   return 0;
}

int BinarySearch::binarySearch(int key)
{
    int i=1;
    int j=10;
    int k;
    count=0;
    do{
	       count++;
	       k = (i+j)/2;
	       if(A[k] == key)
               break;
           else if(A[k] < key)
               i = k+1;
           else
               j = k-1;
    } while(i<=j);
    return count;
}