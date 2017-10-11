#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	std::cin>>n;

	
	int total = n*2-1;
	int stars = 1;
	int flag=0;
	int blanks=0;

	for(int i=0; i< n*2-1 ;i++)
	{
		for(int j=0; j< (n-stars) ;j++)
			cout<<" ";
		for(int k =0 ; k<stars; k++)
			cout<<"*";
		cout<<endl;

		if(stars>=n)
			flag=1;

		if(flag==0)
			stars++;
		else
			stars--;
		
	}
}