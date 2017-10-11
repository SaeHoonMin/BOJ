#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define INT_MAX 2147483647
#define DIVIDER 1000000000
using namespace::std;


int n;
long long int dp[101][10][1 << 10];

int main(void)
{
	/**
		1562: 계단 수

		0~9가 모두 등장하는 계단 수 몇개?

		dp[i][j][s] = i자리의 j로 끝나는 s상태의 계단 수
		결국 s는 0x01 부터 0x01<<10 까지 계산해야 함. (루프에서는 0 ~ (1<<10-1) )


		1) dp[1][j][1<<j] = 1
		  1의자리의 j로 끝나는 s상태란 유일하므로..


		2) dp[i][j][s] = dp[i-1][j-1][ s - (1<<(j-1)] +
					     dp[i-1][j+1][ s - (1<<(j+1)]    // j가 처음 등장 

           dp[i][j][s] = dp[i-1][j-1][s] + dp[i-1][j+1][s] // j가 이미 등장한적이 있음

	*/

	cin >> n;

	for (int i = 1; i <= 9; i++) // 처음 수는 1부터 등장가능하니까
	{
		dp[1][i][1 << i] = 1;
	}

	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k < (1 << 10); k++)
			{
				if ((k&(1 << j)) == 0) // k상태에서 j가 들어갈 수 없는 숫자면
					continue;
				if (dp[i][j][k] == 0) //존재하지 않는 상태(from 기저)
					continue;

				if (j + 1 <= 9)
				{
					dp[i + 1][j + 1][k | (1 << (j + 1))] += dp[i][j][k];
					dp[i + 1][j + 1][k | (1 << (j + 1))] %= DIVIDER;
				}
				if (j - 1 >= 0)
				{
					dp[i + 1][j - 1][k | (1 << (j - 1))] += dp[i][j][k];
					dp[i + 1][j - 1][k | (1 << (j - 1))] %= DIVIDER;
				}
			}
		}
	}



	long long int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = (ans + dp[n][i][(1 << 10) - 1]) % DIVIDER;
	}
	printf("%lld\n", ans);


	return 0;
}