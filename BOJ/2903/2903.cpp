#include <iostream>
using namespace std;

int main()
{
	int n;

	cin>>n;
	int a=2;
	int t=1;
	for(int i=0;i<n;i++)
	{
		a+=t;
		t*=2;
	}
	cout<<a*a;
}