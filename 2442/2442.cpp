#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	std::cin>>n;

	int l = 2*n-1;
	int star=1;

	for(int i=0;i<n;i++)
	{
		for(int k=0; k< (l-star)/2 ;k++)
			cout<<" ";
		for(int j= 0; j<star;j++)
			cout<<"*";
		cout<<endl;
		star+=2;
	}
}