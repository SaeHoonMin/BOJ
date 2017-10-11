#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
using std::vector;
int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	arr.reserve(n);
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}