#include <iostream>
#include <algorithm>
using namespace::std;

#define DIVIDER 1000000

int dp[1001][3][2];

int main(void)
{
	/*

	1563 : 개근상

	개근상을 받을 수 없는 사람은 지각을 두 번 이상 했거나, 결석을 세 번 연속으로 한 사람이다.
	한 학기가 4일이고, O를 출석, L을 지각, A를 결석이라고 했을 때, 개근상을 받을 수 있는 출결정보는 43개.

	dp[n]의 출결정보? -> 결석은 3번 연속일시 개근상 x
	지각은 2번 이상일시 개근상 x ( l<2 )

	a = 최근 2일 결석 상태 저장.
	01, 10, 00 -> 1가능, 11-> 1 불가
	l = 지각이 있었는지 유무, 있었으면 무조건 출석만 가능, 없었으면 결석 가능
	dp[n][a][l]

	*/
	int n;
	cin >> n;
	//n = 1 이면 3가지. O, A, L
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				//출석하는 경우 -> 연속결석 0
				dp[i][0][k] += dp[i - 1][j][k];
				dp[i][0][k] %= DIVIDER;
				//지각하는 경우 -> 이전 지각 0 만 가능
				if (k == 0)
				{
					dp[i][0][1] += dp[i - 1][j][k];
					dp[i][0][1] %= DIVIDER;
				}
				// 결석 하는 경우 -> 연속결석 수 2 미만일때 가능
				// 2일 이미 연속결석 한 상태면 당연히 3일 연속결석 되니까...
				if (j < 2)
				{
					dp[i][j+1][k] += dp[i - 1][j][k];
					dp[i][j+1][k] %= DIVIDER;
				}
			}
		}

	}

	int ans = 0;
	for (int i = 0;i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ans += dp[n][i][j];
			ans %= DIVIDER;
		}
	}

	cout << ans;
	return 0;
}