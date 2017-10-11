#include <iostream>
using namespace::std;

typedef long long int lli;

lli modpow(lli a, lli b, lli m)

{
	a %= m;
	lli result = 1;
	while(b>0)
	{
		if ( b&1 )
			result= (result * a) % m;
		a =(a*a)%m;
		b>>=1;

	}
	return result;
}


int main()
{
	lli a, b, c;

	cin>>a>>b>>c;

	cout<<modpow(a,b,c);
}
