#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	std::cin>>n;

	int blank=0;
	int stars = 2*n-1;
	for(int i=0;i<n;i++)
	{
		for(int k=0; k< blank ;k++)
			cout<<" ";
		for(int j= 0; j<stars;j++)
			cout<<"*";
		cout<<endl;
		blank++;
		stars-=2;
	}
}