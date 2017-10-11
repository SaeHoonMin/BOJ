#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;
using std::sort;
using std::vector;
int main()
{
	int l,a,n;
	int low=-1, high=-1;
	vector <int> v;
	cin>>l;
	int result=0;
	for(int i=0;i<l;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cin>>n;

	if(find(v.begin(),v.end(),n)==v.end())
	{
		if( n > v[v.size()-1])
			result = n-1 - v[v.size()-1];
		else if( n< v[0])
			result = (n-1)*(v[0]-1-n)+v[0]-1-1;
		else
		{
		for(int i=0;i<v.size();i++)
		{
			if(v[i]>n)
			{
				low=v[i-1]+1; break;
			}
		}
		for(int i=v.size()-1;i>=0;i--)
		{
			if(v[i]<n)
			{
				high=v[i+1]-1; break;
			}
		}
			result= (n-low)*(high-n)+high-low;
		}
	}
	cout<<result;
}