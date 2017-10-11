#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define INT_MIN     (-2147483647 - 1)
using namespace::std;

int main()
{
	vector<int> ans;

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0;i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	ans.push_back(INT_MIN);
	int ansCnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ans[ans.size() - 1])
		{
			ans.push_back(arr[i]);
			ansCnt++;
		}
		else
		{
			vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), arr[i]);
			*it = arr[i];
		}

	}

	cout << ansCnt;


}