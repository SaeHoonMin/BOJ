#include <iostream>
using namespace std;

int countOne(int n)
{
	int tmp=n;
	int count=0;
	if(tmp==0)
		return 0;
	else if(tmp==1)
		return 1;
	while(1)
	{
		if(tmp%2==1)
			count++;

		tmp>>=1;
		
		if(tmp==1)
		{
			count++;
			return count;
		}
	}

}

int main()
{
	int n, k;
	int a,t;
	cin>>n>>k;

	a=countOne(n);

	if(k>=n)
	{
		cout<<0;
		return 0;
	}


	if(a>k)
	{
		t=n;
		int i=0;
		while(1)
		{
			t++;
			if(countOne(t)<=k)
			{
				cout<<t-n;
				return 0;
			}
		}
	}
	else
		cout<<0;

}