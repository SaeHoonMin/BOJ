#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace::std;

int n;
int arr[101][101];
long long int dp[101][101];

long long int solve()
{
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 0 || dp[i][j] == 0)
				continue;
			if ( i + arr[i][j] <= n)
			{
				dp[i + arr[i][j]][j] += dp[i][j];
			}
			if ( j + arr[i][j] <= n)
				dp[i][j + arr[i][j]] += dp[i][j];
		}
	}

	 return dp[n][n];
}

int main(void)
{
	
	cin >> n;

	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout<<solve();

}