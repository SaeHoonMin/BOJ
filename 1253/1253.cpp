#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

int goodnum=0;

bool myBsearch( vector<int> & arr, int excIndex1, int excIndex2, int val);

int main()
{
	int n,t;
	
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());

	for(int i=0; i<n ;i++)
	{
		for(int j=0; j<n;j++)
		{
			if(i!=j)
			{
				if(myBsearch(arr, i,j,arr[i]-arr[j]))
				{
					goodnum++;
					break;
				}
			}
		}
	}
	cout<<goodnum;
}

bool myBsearch( vector<int> & arr, int excIndex1, int excIndex2, int val)
{
	int mid,high, low;
	high = (arr.size()-1);
	low=0;

	while(1)
	{
		mid = (low+high)/2;
		if(arr[mid]==val && mid!=excIndex1 && mid!= excIndex2)
			return true;
		else if(arr[mid] < val)
			low = mid+1;
		else
			high = mid-1;

		if(low>high)
			return false;
	}
}