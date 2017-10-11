#include <iostream>
using namespace::std;
int main()
{
	int n;

	cin>>n;
	int result=0;
	int before=0;
	int result_t;
	for(int i=0;i<=n;i++)
	{
		if(i==0)
			result=0;
		else if(i==1)
		{
			before=0;
			result=1;
		}
		else
		{
			result_t=result;
			result = result+before;
			before=result_t;
		}
	}
	cout<<result;
}
