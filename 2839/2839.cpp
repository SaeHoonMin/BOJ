#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i=0;
	int j=-1;
	int r=-1;
	int five=0,three=0;

	if(n%5==0)
	{
		cout<<n/5;
		return 0;
	}

	while(1)
	{
		i++;
		if(5*i>n || 5*i>(n-3))
		{
			i--;
			break;
		}
		if((n-(5*i))%3==0)
			r=i;
	}
	if(r==-1)
	{
		if(n%3==0)
			r=n/3;
	}
	else
	{
		r+= (n-(r*5))/3;
	}
	cout<<r;
}