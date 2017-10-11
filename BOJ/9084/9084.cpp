#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>

#define DIVIDER 15746

using namespace::std;
int dp[10001];
int coins[21];

int main(void)
{
	/*
		9084: 동전

		동전의 종류가 주어질 때 주어진 금액을 만드는 모든 경우의수

		while(testCase)
			dp초기화
			foreach( all coins )
				for( j<k )
				{
					if( dp[j - coins[i]] != 0)
					  dp[j] = dp[j]+dp[j-coins[i]];
				}
		
		
	*/
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n, k;
		cin >> n;
		memset(dp, 0, sizeof(int) * 10001);

		for (int c = 0; c < n; c++)
		{
			scanf("%d", &coins[c]);
		}
		cin >> k;

		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = coins[i] ; j <= k; j++)
			{
				if (dp[j - coins[i]] != 0)
					dp[j] = dp[j] + dp[j - coins[i]];
			}
		}

		cout << dp[k] << endl;
	}
}