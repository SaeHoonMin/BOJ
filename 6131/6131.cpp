#include <iostream>
#include <math.h>
using namespace::std;


int main()
{
	int n;
	cin>>n;

	int count=0;

	for(int i=1;i<=500;i++)
	{
		if(i*i+n <= 250000)
		{
			double t = sqrt((double)i*i+n);
			if(t-(int)t==0)
				count++;
		}

	}
	cout<<count;
}
