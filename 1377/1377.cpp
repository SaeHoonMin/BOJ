#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>

#define PAIR  std::pair<int,int> 

using namespace::std;


int mySort( PAIR & a, PAIR  & b)
{
	return a.first < b.first;
}

int main(void)
{
	/**
	1377 버블소트
	*/

	int n;
	cin >> n;
	vector< PAIR > v(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, v[i].second - i);
	}

	cout << ans + 1;

	return 0;
}