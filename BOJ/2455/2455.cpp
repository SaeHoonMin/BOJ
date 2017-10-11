#include <iostream>
using namespace::std;

int main()
{
	int in, out, max,total;

	total=0;max=0;
	for(int i=0;i<4;i++)
	{
		cin>>in>>out;
		total= total-in+out;
		if(max<total)
			max=total;
	}
	cout<<max;
}

