#include <iostream>
#include <vector>
using std::vector;
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

typedef struct _pair{
	lli a;
	lli b;
}Pair;


int main()
{
	int testCase;
	vector<Pair> pairArr;
	cin>>testCase;
	pairArr.reserve(testCase);
	for(int i=0;i<testCase;i++)
	{
		lli a, b;
		cin>>a>>b;
		Pair P;
		P.a=a;
		P.b=b;
		pairArr.push_back(P);
	}

	for(int i=0;i<testCase;i++)
	{
		int a = modpow(pairArr[i].a,pairArr[i].b,10);
		if(a!=0)
		cout<<a<<endl;
		if(a==0)
			cout<<10<<endl;
	}
}