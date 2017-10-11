#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::binary_search;
int main()
{
	int n,m,t;
	vector<int> mv;
	vector<int> nv;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		nv.push_back(t);
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>t;
		mv.push_back(t);
	}
	sort(nv.begin(),nv.end());

	for(int i=0;i<m;i++)
	{
		if(binary_search(nv.begin(),nv.end(),mv[i]))
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
}


