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
		11050 이항 계수 1

		이항 계수 2 먼저 풀었었으므로 이거는 뭐..
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
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
		}
	}

	cout << dp[n][k];
	
}