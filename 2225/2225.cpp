#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define INT_MAX 2147483647
#define DIVIDER 1000000000
using namespace::std;

int n, k;
long long int dp[201][201];

int main(void)
{
	/**
	2225 : 합분해
	         [[N]] 
	  	 1   2   3   4    5
	1개: 1   1   1   1    1
	2개: 1   2   3   4    5
	3개: 1   3   6   10
	4개: 1   4


	1 을 n 개 이내로 사용해서 1로 만드는 수 -> 1
	1~2를 n개 이내로 사용해서 2로 만드는 경우의 수 -> 
	  1: 2
	  2: 1+1, 2
	  3: 1+2, 2+1, 1+1+1
	  4: 1+2+1, 2+1+1, 1+1+2, 2+2 

	dp[i][j] -> 0~j범위 수 j개로 j만드는 경우의 수 
	           = i-1개의 0~ (j-0) 범위로 만드는 경우의 수 +
			     i-1개의 0 ~ (j-1)범위로 만드는 경우의 수 +
			     i-1개의 0 ~ (j-2) 범위로 만드는 경우의 수 +
				 ...
	
	*/

	
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				dp[i][j] += dp[i - 1][j - l];
				dp[i][j] %= DIVIDER;
			}
		}
	}

	cout << dp[k][n];

	return 0;
}