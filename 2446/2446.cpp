#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	std::cin>>n;

	
	int total = n*2-1;
	int stars = total;
	int flag=0;
	int blanks=0;

	for(int i=0; i< n*2-1 ;i++)
	{
		for(int j=0; j< (total-stars)/2 ;j++)
			cout<<" ";
		for(int k =0 ; k<stars; k++)
			cout<<"*";
		cout<<endl;

		if(stars<=1)
			flag=1;

		if(flag==0)
			stars-=2;
		else
			stars+=2;
		
	}
}