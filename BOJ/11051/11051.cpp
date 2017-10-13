#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

#define DIVIDER 10007

int dp[1001][1001];
int main(void)
{
	/*
		11051 이항 계수 2

		(n,k) + (n, k+1) = (n+1, k+1)

		1
		1 1
		1 2 1
		1 3 3 1

		(n, k ) = (n-1,k-1) + (n-1,k)
	*/

	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 0;i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == i) dp[i][j] = 1;
			else if (j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%DIVIDER;
		}
	}

	cout << dp[n][k];
	
}