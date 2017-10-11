#include <iostream>
#include <string>
using namespace::std;

int getDif(string & a, string & b,int b_start);

int main()
{
	int bestIdx =0;
	int bestDif;
	string a;
	string b;

	cin>>a>>b;

	for(int i=0; i+a.length()-1 < b.length() ; i++)
	{
		if(i==0)
		{
			bestDif=getDif(a,b,i);
			bestIdx=i;
		}
		else if(i!=0 && bestDif > getDif(a,b,i))
		{
			bestDif=getDif(a,b,i);
			bestIdx=i;
		}
	}
	cout<<bestDif;
}

int getDif(string & a, string & b, int b_start )
{
	int ret=0;
	int j =0;

	for(int i=b_start;j<a.length();i++)
	{
		if(a[j]!=b[i])
			ret++;
		j++;
	}
	return ret;
}
