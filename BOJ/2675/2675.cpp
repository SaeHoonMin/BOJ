#include <iostream>
#include <string>
#include <vector>
using namespace::std;

typedef struct _testCase
{
	int r;
	string s;
}testCase;

int main()
{
	testCase t;
	vector<testCase> v;
	string buf;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t.r>>t.s;
		v.push_back(t);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<v[i].s.length();j++)
		{
			for(int k=0;k<v[i].r;k++)
				cout<<v[i].s[j];
		}
		cout<<endl;
	}
}