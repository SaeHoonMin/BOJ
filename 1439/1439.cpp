#include <iostream>
#include <string>
using namespace::std;

int main()
{
	string a;
	cin>>a;
	
	int n0zone=0;
	int n1zone=0;
	int flag=0;
	for(int i=0; i<a.length();i++)
	{
		if(a[i]=='1' && flag==0)
		{
			n0zone++;
			flag=1;
		}
		if(flag==1 && a[i]=='0')
			flag=0;
	}
	flag=0;
		for(int i=0; i<a.length();i++)
	{
		if(a[i]=='0' && flag==0)
		{
			n1zone++;
			flag=1;
		}
		if(flag==1 && a[i]=='1')
			flag=0;
	}
	cout<< ((n0zone<n1zone)? n0zone : n1zone);
}