#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int t=n;
	int count=0;

	if(n==0)
	{
		cout<<0;
		return 1;
	}

	for(int i=n-1;i>0;i--)
	{
		t=t*i;
		if(t%10 != 0)
			t=t%10000;
		else
		{
			while(t%10==0)
			{
				t/=10;
				count++;
			}
		}
		//cout<<t<<endl;
	}
	cout<<count;
}