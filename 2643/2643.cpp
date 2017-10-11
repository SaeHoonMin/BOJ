#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace::std;

#define PAIR std::pair<int, int>
vector< PAIR > v;

int comp( PAIR v1, PAIR v2)
{
	if (v1.first == v2.first)
		return v1.second > v2.second;
	else
		return v1.first > v2.first;
}

int dp[101];

int main(void)
{

	/*

	2643 : 색종이 올려 놓기

	*/
	int n, ans=1;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)
		{
			int t = a;
			a = b;
			b = t;
		}
		v.push_back( make_pair(a, b) );
	}
	sort(v.begin(), v.end(), comp);

	for(int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if( (v[j].first >= v[i].first && v[j].second >= v[i].second) )
				dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}