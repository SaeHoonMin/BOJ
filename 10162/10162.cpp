#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int t;
	cin>>t;
	if( t%10 !=0)
		cout<<-1;
	else
	{
		int a = t/300;
		int b = (t-300*a)/60;
		int c = (t-300*a - 60*b)/10;
			cout<<a<<" "<<b<<" "<<c;
	}

}