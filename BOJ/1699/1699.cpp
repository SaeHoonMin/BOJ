#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

int dp[100001];
int main(void)
{
	/*
	1699 : 제곱수의 합

	dp[i] = min(dp[i], dp[i-j]+dp[j]
	-> 100000* 100000 -> 시간 초과.

	제곱수의 합으로 표현되므로 두 수의 합으로 표현하지 말고,
	i - 제곱수 에서 찾아야 함

	12 -9 = 3 , dp[3] + 1 = 4
	12 -4 = 8,  dp[8] + 1 = 3

	dp[i] = min(dp[i], dp[i-j^2]+1)

	*/
	int n;
	cin >> n;

	for (int i = 1;i<314;i++)
	{
		dp[i*i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 1) continue;
		if (dp[i] == 0) dp[i] = 99999;
		for (int j = 1; j*j <= i; j++)
		{
			if (dp[i] > dp[i - j*j] + 1)
				dp[i] = dp[i - j*j] + 1;
		}
	}

	cout << dp[n];
}