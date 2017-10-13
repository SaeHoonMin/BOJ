#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
using namespace::std;

int dp[1000][1000];
int arr[1000][1000];
int main(void)
{
	/*
	1915 : 가장 큰 정사각형

	m n <= 1000
	완전 탐색 : 1000 * 1000 * 1000 -> 10 0000 0000 (시간초과)

	입력 -> 0 1 1 0
	       1 1 1 0
		   1 1 1 1
		   1 1 1 1 이라고  할 때,

		 0 1 1 0
		 1 1 2 0 
		 1 2 2 1
		 1 2 3 2
	dp[i][j] = min( min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1] ) + 1;

	*/

	int m, n, ans=0;
	scanf("%d %d ", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &arr[i][j]);
			if (i >= 1 && j >= 1 && arr[i][j]-'0')
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			else
				dp[i][j] = arr[i][j] - '0';
			ans = max(dp[i][j], ans);
		}
		getchar();
	}
	printf("%d", ans*ans);

}