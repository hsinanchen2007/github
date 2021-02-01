#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
	int i=2;
	while (i<=n)
	{
		if(n%i==0) //如果整除,i是n的因數,回傳 false
		    return false;
		i=i+1;
		return true;
	}
}
int main()
{
	int n;
	cout<<"請輸入一個大於等於2的數字: "; 
	cin>>n;
	cout<<endl;
	if(n==2)
	{ 
	    cout<<n<<"是質數";
	    return 0;
	} 
	if(is_prime(n))
	    cout<<n<<"是質數";
	else
	    cout<<n<<"不是質數";

    return 0;	
}
