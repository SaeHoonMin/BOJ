#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	bool * arr;
	int result=0;
	int added_score=0;
	cin>>n;
	arr = new bool[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i==0 && arr[i]==1)
		{
			added_score+=1;
			result+=added_score;
		}
		else if( arr[i]==1 )
		{
			added_score+=1;
			result+=added_score;
		}
		if(arr[i]==0)
			added_score=0;
	}
	cout<<result;
}