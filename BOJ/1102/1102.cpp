#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#define INT_MAX 2147483647

using namespace::std;

string s;
int n, p;
int plants;
int arr[16][16];
int dp[1 << 16];


int main(void)
{
	/**
		1102 : 발전소

		적어도 P개의 발전소가 고장나 있지 않도록 발전소
		고치는 비용의 최솟값

		arr[i][j]  = i를 이용해 j를 켜는 비용

		dp[i] = i의 상태를 만들기 위한 최솟값
	*/

	/*****  입력 ********/
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'Y')
		{
			plants |= 1 << (i);
		}
	}
	cin >> p;

	memset(dp, -1, sizeof(dp));	


	/*      풀기         */

	dp[plants] = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		if (dp[i] == -1) continue;
		for (int j = 0; j < n; j++)
		{
			if (i&(1 << j))
			{
				for (int k = 0; k < n; k++)
				{
					if ((i&(1 << k)) == 0)
					{
						if (dp[i | (1 << k)] == -1 || dp[i | (1 << k)] > dp[i] + arr[j][k])
							dp[i | (1 << k)] = dp[i] + arr[j][k];
					}
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < (1 << n); i++)
	{
		if (dp[i] == -1) continue;
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i&(1 << j))
				cnt++;
		}
		if (cnt >= p)
		{
			if (ans == -1 || ans > dp[i])
				ans = dp[i];
		}
	}

	printf("%d\n", ans);


	return 0;
}