#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int x=1, sum=1000;
	while(sum>0) //while°j°é 
    {
	    sum-=x;
	    x++;
	}
	cout<<x-1<<endl;
	
    return 0;	
}
