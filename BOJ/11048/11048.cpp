

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#include <stdio.h>
#include <math.h>

using namespace::std;

int dp[1001][1001];
int arr[1001][1001];

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	/*
		0 0 
		0 x
	dp[x] = arr[x] + max( dp[i-1][j-1], dp[i-1][j],dp[i][j-1] );
	
	*/


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int a = 0, b = 0, c = 0;
			
			if (i - 1 >= 1)
			{
				a = dp[i - 1][j];
			}
			if (j - 1 >= 1)
				b = dp[i][j - 1];
			if (i - 1 >= 1 && j - 1 >= 1)
				c = dp[i - 1][j - 1];

			dp[i][j] = arr[i][j] + max(max(a, b), c);
		}
	}
	

	cout << dp[n][m];

}
