#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	int count=0;
	cin>>n;
	int origin = n;

		int d,i;
		int dd;
		int sum;
		while(true)
		{
			d=n/10;
			i=n%10;
			sum = d+i;
			n = i*10 + (sum%10);
			count++;
			if(n==origin)
			{cout<<count; return 1;}
		}
	
	return 1;
}