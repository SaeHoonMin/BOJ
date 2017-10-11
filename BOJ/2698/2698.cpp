#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <algorithm>


using namespace::std;

int dp[101][100][2];	

#define _1BIT(x) ((x)&(~0x01))

int main(void)
{

	/*
		2698 : 인접한 비트의 개수

		dp[길이][인접비트수][끝수] 

		1)
		dp[n][k][0] 인 경우 -> 이전 길이 수가 k이며, 끝나는 숫자는 0이든 1이든 상관 없음.
		( 0으로 끝나니까 k가 안늘어나므로 )
		dp[n][k][0] =   dp[n-1][k][0] + dp[n-1][k][1] 

		2)
		dp[n][k][1] 인경우 -> 이전 k가 1개 적고 1로 끝나는 경우 + 이전k는 같고 0으로 끝나는 경우
		dp[n][k][1] = dp[n-1][k-1][1] + dp[n][k][0]
	*/

	int t;
	scanf("%d", &t);

	//n k s
	dp[2][0][0] = 2;
	dp[2][0][1] = 1;
	dp[2][1][1] = 1;
	dp[2][1][0] = 0;

	for (int i = 3; i <= 100; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] += dp[i - 1][j - 1][1] + dp[i - 1][j][0];
		}
	}


	for (int T = 0; T < t; T++)
	{
		int  n, k;
		scanf("%d %d", &n, &k);

		printf("%d\n", dp[n][k][0] + dp[n][k][1]);

	}


}