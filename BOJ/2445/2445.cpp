#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	std::cin>>n;

	int stars=1;
	int total = n*2-1;
	int flag=0;
	int blanks=1;

	for(int i=0; i< n*2-1 ;i++)
	{
		for(int j=0; j< blanks ; j++)
		{
			cout<<"*";
		}
		for(int k =0; k< total-(blanks*2)+1 ; k++)
		{
			cout<<" ";
		}
		for(int j=0; j< blanks ; j++)
		{
			cout<<"*";
		}
		cout<<endl;
		
		if(flag==0)
			blanks++;
		else
			blanks--;

		if(blanks*2 >=total)
		{flag=1; }
	}
}