#include<iostream>
#include<cstdio>
#include <vector>
#include <algorithm>

#define INT_MAX       2147483647    
using namespace::std;

int coins[101];
int dp[101][10001];
int main(void)
{
	/*
	** 동전 2 **
	n개의 동전으로 k개 ( 개수는 최소로!)

	dp[1][k] = 1번째 동전으로 k원을 만들 때 사용한 동전 수
	dp[i][k] = 1...i번째 동전까지 사용해서 k원을 만들때 사용할 동전 최소수

	ex) k = 15, coins = { 1, 3, 5, 7 }

	dp  0  1  2  3  4  5  6  7  8  9 10  11 12 13 14 15
	 1  0  1  2  3  4  5  6  7  8  9 10  11 12 13 14 15
	 3  0        1       (2)

	 dp[2][6] =  min ( dp[1....2-1][6 - 3] +1 , dp[2][6-3] )


	 메모리 ?  101 * 10001 * 4byte = 4,000,000 byte
	 
	 time ?  동전 : n, 수 : k
	         n*n*k = 10000 * 10000 = 1 0000 0000
	*/

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &coins[i]);
		
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++)
	{
		for (int j = coins[i]; j <= k; j++ )
		{
			if (j - coins[i] == 0)	// 첫 수인 경우.
				dp[i][j] = dp[i][j - coins[i]] + 1;
			else if (dp[i][j - coins[i]] != 0)	
				// 첫 수가 아니고 현재코인만으로 수를 만들수있는경우
				dp[i][j] = dp[i][j - coins[i]] + 1;

			if( i != 1 )
			{
				for (int l = 1; l < i; l++)
				{
					if (dp[l][j - coins[i]] != 0)
					{
						if (dp[i][j] == 0)
							dp[i][j] = dp[l][j - coins[i]] + 1;
						else
							dp[i][j] = min(dp[i][j],
								(dp[l][j - coins[i]] + 1));
					}
				}
			}

			if (j == k && dp[i][j] != 0)
			{
				//min value
				if (dp[i][j] < ans)
					ans = dp[i][j];
			}
		}
	}

	if (ans != INT_MAX)
		cout << ans;
	else
		cout << -1;
}