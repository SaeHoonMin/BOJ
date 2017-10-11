#include <iostream>

using namespace::std;

int dp[31][31] = { 0, };

int main(void)
{
	int result;
	int testCases;
	cin >> testCases;

	for (int i = 1; i < 31; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i < 31; i++)
	{
		for (int j = i; j < 31; j++)
		{
			for (int k = j - 1; k >= i - 1; k--)
				dp[i][j] += dp[i - 1][k];
		}
	}

	for (int i = 0;i < testCases; i++)
	{
		int n, m;
		cin >> n >> m;

		cout << dp[n][m]<<endl;
	}
}