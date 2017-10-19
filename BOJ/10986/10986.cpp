#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;

int dp[1000];

int main(void)
{
	/*
	10986 : 나머지 합

	sum(arr[n]...arr[j]) % d == 0인 n, j?

	1 2 3 4  5
	1 3 6 10 15

	sum(0, a) - sum(0,b) = sum (b, a)
	sum(0,a)mod(m) - sum(0,b)mod(m) = sum(b,a)mod(m)

	sum(b,a)mod(m) ==0 이려면 -> sum(0,a)mod(m)  =   sum(0,b)mod(m)

	sum(0,n)mod(m)이 0인것들의 개수
	sum(0,n)mod(m)이 0인것들의 개수에서 2개 고르기
	sum(0,n)mod(m)이 1인것들의 개수에서 2개 고르기
	.
	.
	*/
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, n, m;
	long long int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
		dp[sum%m]++;
	}


	long long int ans = 0;
	ans += dp[0];
	for (int i = 0; i < m; i++)
	{
		ans += ((long long int)dp[i] * (dp[i] - 1)) / 2;
	}
	cout << ans;

	return 0;
}