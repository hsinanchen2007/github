#include <cstdlib>
#include <iostream>
#define MAX 10
int A[MAX]={0};
using namespace std;
class fun
{
  public:
  int intsrch(int A[], int find);  
};
int main(int argc, char *argv[])
 { 
    fun obj;
    int  A[MAX] = {0,1,2,3,4,5,6,7,8,9}; 
    int i, find; 
    cout<<"�Ƨǫ᪺�ƦC���G"; 
    for(i = 0; i < MAX; i++) 
        cout<<A[i]<<"   "; 
    cout<<"\n�п�J�Ʀr(0~9)�G"; 
    cin>>find; 
    if((i = obj.intsrch(A, find)) >= 0) 
        cout<<"�ӼƦr�O�Ʀb��"<<i+1<<"�Ӷ���"; 
    else 
        cout<<"\n�䤣��!"; 
    
    cout<<"\n"; 
    system("PAUSE");
    return 0; 
} 
//�����j�M�k
int fun:: intsrch(int A[], int find) { 
    int low, mid, high; 

    low = 0; 
    high = MAX - 1; 

    while(low <= high) { 
        mid = (high-low)* (find-A[low])/(A[high]-A[low])+ low; 
        if(mid < low || mid > high) 
            return -1; 
        if(find < A[mid]) 
            high = mid - 1; 
        else if(find > A[mid]) 
            low = mid + 1; 
        else 
            return mid; 
     } 
     return -1;
} 
