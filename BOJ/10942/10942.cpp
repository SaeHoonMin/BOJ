#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;

int dp[2001][2001];

int main(void)
{
	/*
	10942 : 팰린드롬?

	dp[i][j] = i에서 j까지 수가 팰린드롬이냐?
	
	if(dp[i+1][j-1] && arr[i]==arr[j])
		dp[i][j] = p
		

	*/
	int n, t;
	cin >> n;
	vector<int> arr(n+1);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d", &arr[i]);
		dp[i][i] = 1;
	}

	for (int j = 2; j <= n; j++)
	{
		for (int i = 1; i <= n && i+j-1 <=n ; i++)
		{
			if (j == 2)
			{
				if (arr[i] == arr[i + j - 1])
					dp[i][i + j - 1] = 1;
			}
			else if (dp[i + 1][i + j - 2] && arr[i]==arr[i+j-1])
			{
				dp[i][i + j - 1] = 1;
			}
		}
	}
	scanf("%d", &t);
	for (int i = 0;i < t; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}