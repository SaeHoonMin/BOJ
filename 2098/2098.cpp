#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define INT_MAX 2147483647

using namespace::std;

int n;
int arr[16][16];
int dp[1 << 16][16];

int main(void)
{
	/**
		2098 : 외판원 순회

		dp[i][j] : 현재 위치가 j이고 방문했던 도시들이 i일때의 최소값

		i -> bitmask 로 쓰면 2^16
	*/
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = 100000000;
		}
	}

	dp[1][0] = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 1; j < n; j++)
		{
			//i라는 상태(방문했던 도시들의 비트마스크)에서 j로 가는 경우들의 최소값 구하기
			// ->    이전에 방문한 도시들 중 최소값.
			if (i&(1 << j))
			{
				for (int k = 0; k < n; k++)
				{
					if (k != j && (i&(1 << k)) && arr[k][j])
					{
						dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + arr[k][j]);
					}
				}
			}
		}
	}

	int ans = 1000000000;
	for (int i = 1; i < n; i++) {
		if (arr[i][0])	// i를 마지막으로, 첫 번째노드로 가는 길이 있는경우
		{
			// [모든것을 방문한상태][i] + arr[i][0](첫번째노드로가는 코스트)
			ans = min(ans, dp[(1 << n) - 1][i] + arr[i][0]);
		}
	}

	cout << ans;
	return 0;
}