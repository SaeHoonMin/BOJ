#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int n,t=1;
	int ti=1;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i % 10000 == 0)
		{
			ti=i/10000;
		}
		else if(i % 1000 ==0)
		{
			ti=i/1000;
		}
		else if(i % 100 == 0)
		{
			ti=i/100;
		}
		else if(i%10==0)
			ti=i/10;
		else
			ti=i;

		t= t*ti;


		if(t % 10000 == 0)
		{
			t=t/10000;
		}
		else if(t % 1000 ==0)
		{
			t=t/1000;
		}
		else if(t % 100 == 0)
		{
			t=t/100;
		}
		else if(t%10==0)
			t=t/10;

		t=t%10000;
	}
	if(t%10==0)
		t=t/10;
	else
		t=t%10;
	cout<<t;
	return 0;
}

