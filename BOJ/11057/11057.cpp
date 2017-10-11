#include <iostream>

#define MODULER 10007

using namespace::std;
int dp[1001][10];

int main(void)
{
	/*
	
	중복수도 오름차순으로 치므로..

	dp[1][0to9] = 1
	dp[n][0to9] =  sum ( dp[n][0 to m] )
	*/

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][k];
			}
			dp[i][j] = dp[i][j] % MODULER;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (dp[n][i] + ans) % MODULER;
	}

	cout << ans;
}